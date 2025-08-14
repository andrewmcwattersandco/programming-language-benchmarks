# programming-language-benchmarks
Benchmarks for programming languages

## Languages and Implementations
* C
* C++
* C#
* Go
* Java
* JavaScript
* Lua
* LuaJIT
* Python
* Rust

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
./bench [-t tests...] [-l languages...] [-s languages...]
```

### macOS
#### node
`bench` runs from `/bin/sh`. If you have `node` installed through `nvm`, you may
need to create a symbolic link to the default installation path.
```
sudo ln -s $(command -v node) /usr/local/bin/node
```

## Tests
* **Minimal program**  
  Test initialization
* **Create a record/structure/object**  
  Test memory allocation

  _Note: Creates 67,108,864 records. Last tested against node v24.3.0, this is
  the maximum array size. All other test languages have their tests calibrated
  to this number, which is the smallest array length of all of the test
  languages before one of the tests is terminated abnormally._
* **Parse JSON**  
  Test built-in or de facto standard JSON parser

  Reads and parses 13.76 GB of EDGAR API bulk data.  
  See https://www.sec.gov/edgar/sec-api-documentation for more information.

## Results
### Cloud
*Last updated: Thu Aug 14 10:52:08 MST 2025*
```sh
% ./bench
minimal
 c          real 0.00       user 0.00       sys 0.00	
 cpp        real 0.00       user 0.00       sys 0.00	
 go         real 0.00       user 0.00       sys 0.00	
 lua        real 0.00       user 0.00       sys 0.00	
 luajit     real 0.00       user 0.00       sys 0.00	
 python3    real 0.01       user 0.01       sys 0.00	
 js         real 0.03       user 0.02       sys 0.00	
 java       real 0.05       user 0.04       sys 0.01	
 cs         real 1.44       user 1.34       sys 0.17	
record
 c          real 0.19       user 0.08       sys 0.10	
 go         real 0.22       user 0.04       sys 0.18	
 cpp        real 1.03       user 0.96       sys 0.07	
 cs         real 6.13       user 5.33       sys 1.51	
 js         real 10.39      user 10.80      sys 2.82	
 java       real 13.79      user 52.76      sys 0.55	
 lua        real 16.60      user 12.68      sys 3.82	
 python3    real 31.53      user 28.20      sys 3.31	
json
 c          real 82.87      user 73.13      sys 3.54	
 java       real 83.42      user 71.20      sys 10.54	
 cs         real 101.48     user 75.97      sys 18.94	
 js         real 128.45     user 110.73     sys 13.17	
 python3    real 167.52     user 148.80     sys 11.08	
 cpp        real 195.10     user 184.63     sys 3.91	
 luajit     real 227.05     user 196.96     sys 18.00	
 go         real 284.91     user 394.26     sys 28.12	
 lua        real 2275.80    user 2258.55    sys 10.57	
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
