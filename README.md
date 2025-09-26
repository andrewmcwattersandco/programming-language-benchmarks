# programming-language-benchmarks
Benchmarks for programming languages

## Languages and implementations[*](#excluded-programming-languages)
* C
* C++
* C#
* Go
* Java
* JavaScript
* Lua
* LuaJIT
* PHP
* Python
* Ruby
* Rust
* Zig

## Philosophy
* **Real-world tests only**  
  Most developers are not writing code that looks like the 1994 FANNKUCH
  Benchmark, nor running N-body simulations.
* **Use the most popular libraries**  
  The speed and memory efficiency of programming languages should not be
  evaluated without considering the ecosystems around them. When benchmarking
  an HTTPS server in Node.js, most developers will be considering the speed of
  Express, not `http.createServer()`.

  **NEW** For web server benchmarks, see
  [andrewmcwattersandco/web-server-benchmarks][1].
* **Use idiomatic code/Do not use micro-optimizations**  
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

  _Note: Creates 8,388,608 records. Last tested against node v24.3.0, 67,108,864
  is the maximum array size. All other test languages have their tests
  calibrated to this number, which is the smallest array length of all of the
  test languages before one of the tests is terminated abnormally._

  _Edit: This test previously created 67,108,864 records._
* **Parse JSON**  
  Test built-in or de facto standard JSON parser

## Results
Our findings confirm conventional wisdom that low-level compiled languages are
faster than managed code, and that managed code runs faster than interpreted
code. The results also show that the performance of a programming language
is not solely determined by its implementation, but also by the libraries and
frameworks that are used with it.

### Physical
*Last updated: Thu Aug 21 21:34:46 MST 2025*
```sh
% ./bench
json
 cpp            mean 1738.3 µs	
 c              mean 3054.0 µs	
 rust           mean 3692.2 µs	
 zig            mean 3906.9 µs	
 go             mean 6968.4 µs	
 luajit         mean 9938.0 µs	
 python3        mean 30460.8 µs	
 js             mean 33187.1 µs	
 cs             mean 35628.1 µs	
 lua            mean 49366.6 µs	
 php            mean 52403.9 µs	
 ruby           mean 59341.7 µs	
 java           mean 170049.5 µs	
minimal
 c              mean 1217.1 µs	
 zig            mean 1534.4 µs	
 go             mean 1542.4 µs	
 cpp            mean 1549.0 µs	
 rust           mean 1550.7 µs	
 luajit         mean 1602.0 µs	
 lua            mean 1747.0 µs	
 python3        mean 21472.0 µs	
 cs             mean 22668.2 µs	
 js             mean 28519.2 µs	
 java           mean 31884.8 µs	
 php            mean 50319.9 µs	
 ruby           mean 51489.4 µs	
record
 cpp            mean 738.2 µs	
 c              mean 1215.0 µs	
 zig            mean 4460.7 µs	
 rust           mean 7152.0 µs	
 go             mean 9709.3 µs	
 java           mean 80830.2 µs	
 cs             mean 378984.8 µs	
 js             mean 626475.8 µs	
 luajit         mean 658569.1 µs	
 php            mean 762029.6 µs	
 lua            mean 1279559.3 µs	
 ruby           mean 1446871.1 µs	
 python3        mean 4236537.6 µs	
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

* * *

###### Excluded programming languages
<sub>\* We do not benchmark Bash/Shell, TypeScript, or PowerShell. We do not
benchmark **programming languages predominantly used for a single domain**,
like Kotlin for Android development, Dart for Flutter, Swift for iOS
development, or MicroPython for embedded systems. We are unable to benchmark
HTML/CSS, SQL, and assembly. We do not benchmark **programming languages that
are not widely used in production,** like Groovy, Elixir, Scala, Delphi, Lisp,
Erlang, Fortran, Ada, F#, OCaml, Gleam, Prolog, COBOL, or Mojo. We do not
benchmark **programming languages that are no longer supported, updated, or
ones which "won't be extended to new workloads"** like Visual Basic (.NET) or
VBA. We do not benchmark **programming languages predominantly used for
statistical computing or data analysis**, like R or MATLAB. We do not benchmark
**custom scripting languages** like GDScript. We do not benchmark **programming
languages that are write-ins in the Stack Overflow Developer Survey.**</sub>

## License
GNU General Public License v2.0

[1]: https://github.com/andrewmcwattersandco/web-server-benchmarks
