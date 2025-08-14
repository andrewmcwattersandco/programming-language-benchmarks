# programming-language-benchmarks
Benchmarks for programming languages

## Languages
* C
* C++
```sh
% cc -v
Apple clang version 13.1.6 (clang-1316.0.21.2)
Target: arm64-apple-darwin21.4.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```
* Go
```sh
% go version
go version go1.18 darwin/arm64
```
* Java
```sh
% javac -version
javac 1.8.0_321
```
```sh
% java -version
java version "1.8.0_321"
Java(TM) SE Runtime Environment (build 1.8.0_321-b07)
Java HotSpot(TM) 64-Bit Server VM (build 25.321-b07, mixed mode)
```
* JavaScript
```sh
% node -v
v18.1.0
```
* Lua
```sh
% lua -v
Lua 5.1.5  Copyright (C) 1994-2012 Lua.org, PUC-Rio
```
_Note: Lua 5.1 is used due LuaJIT's API-compatibility.[1]_

* LuaJIT
```sh
luajit % git branch --show-current
v2.1
```
```sh
% luajit
LuaJIT 2.1.0-beta3 -- Copyright (C) 2005-2021 Mike Pall. https://luajit.org/
JIT: ON fold cse dce fwd dse narrow loop abc sink fuse
>
```
* Python
```sh
% python3 --version
Python 3.9.6
```

## Philosophy
* **No warm-ups**  
  Users do not warm up programs before use.
* **Real-world tests only**  
  Most developers are not writing code that looks like the 1994 FANNKUCH
  Benchmark, nor running N-body simulations.
* **Use the most popular libraries**  
  The speed and memory efficiency of programming languages should not be
  evaluated without considering the ecosystems around them. When benchmarking
  an HTTPS server in Node.js, most developers will be considering the speed of
  Express, not `http.createServer()`.
* **Use idiomatic code/Do not optimize**  
  One can write inline assembly in C with the non-standard `asm` keyword or use
  `ffi.cdef` from LuaJIT to create C data structures instead of Lua tables, but
  the tests within this benchmark are designed to reflect typical usage of each
  respective language.

  Further, some implementations of languages rely on specific hinting to
  trigger optimizations, like knowing the exact layout of a record ahead of
  time to avoid growing or shrinking backing memory by powers of two.

  Most developers are not aware of such optimizations and this benchmark makes
  no attempts to catalog them. Instead, tests are written in a way that first
  reflects the documentation provided by the language authors, who themselves
  often do not publicize such optimizations.

## Run
```sh
./bench [-t tests...]
```

### macOS
#### node
`bench` runs from `/bin/sh`. If you have `node` installed through `nvm`, you may
need to create a symbolic link to the default installation path.
```
sudo ln -s $(command -v node) /usr/local/bin/node
```

#### lua
`brew` installs `lua` as `lua-5.1`. To install Lua with its default name, create
a symbolic link to `/opt/homebrew/bin/`.
```sh
cd /opt/homebrew/bin/
ln -s ../Cellar/lua@5.1/5.1.5_8/bin/lua-5.1 lua
```

## Tests
* **Minimal program**  
  Test initialization
* **Create a record/structure/object**  
  Test memory allocation

  _Note: Creates 112,813,858 records. As of node v17.9.0, this is the maximum
  array size. All other test languages have their tests calibrated to this
  number, which is the smallest array length of all of the test
  languages before one of the tests is terminated abnormally._
* **Parse JSON**  
  Test built-in or de facto standard JSON parser

  Reads and parses 13.76 GB of EDGAR API bulk data.  
  See https://www.sec.gov/edgar/sec-api-documentation for more information.
<!-- * **Encode JSON**  
  Test built-in or de facto standard JSON encoder
* **Send HTTPS request**  
  Test built-in or de facto standard HTTPS request overhead
* **Receive HTTPS request**  
  Test built-in or de facto standard HTTPS request overhead
* **Send HTTPS response**  
  Test built-in or de facto standard HTTPS response overhead
* **Receive HTTPS response**  
  Test built-in or de facto standard HTTPS response overhead
* **Query database**  
  Test built-in or de facto standard database connector/driver/bindings
* **Draw**  
  Test graphics API command overhead -->

## Results
```sh
% ./bench
json
 c	       31.66 real        27.86 user         3.63 sys
 cpp	      351.16 real       340.68 user         4.33 sys
 go	      133.40 real       205.27 user        10.96 sys
 java	       50.25 real        49.58 user         3.26 sys
 js	       57.25 real        53.87 user         4.69 sys
minimal
 c	        0.15 real         0.00 user         0.00 sys
 cpp	        0.10 real         0.00 user         0.00 sys
 go	        0.11 real         0.00 user         0.00 sys
 java	        0.08 real         0.06 user         0.02 sys
 js	        0.03 real         0.02 user         0.00 sys
 lua	        0.00 real         0.00 user         0.00 sys
 luajit	        0.00 real         0.00 user         0.00 sys
record
 c	        0.25 real         0.11 user         0.02 sys
 cpp	        0.42 real         0.27 user         0.02 sys
 go	        0.21 real         0.04 user         0.05 sys
 java	       32.08 real       259.28 user         4.94 sys
 js	       15.79 real        19.62 user         4.60 sys
 lua	       29.88 real        27.02 user         2.69 sys
 luajit	        9.81 real         8.16 user         1.65 sys
```

### Google Sheets
https://docs.google.com/spreadsheets/d/1oBtZTcp4UzRTWnTsBwxr465XAZhVuso33EJINMAKUQo/edit?usp=sharing

## Hardware
### Physical
MacBook Pro (16-inch, 2021)  
Apple M1 Max chip with 10-core CPU, 32-core GPU, and 16-core Neural Engine  
64GB unified memory  
1TB SSD storage  
https://www.apple.com/shop/buy-mac/macbook-pro/16-inch-space-gray-10-core-cpu-32-core-gpu-1tb#

### Cloud
GitHub Actions

## License
GNU General Public License v2.0

## References
\[1]: https://luajit.org/install.html#embed
