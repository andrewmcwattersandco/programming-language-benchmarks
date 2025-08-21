# programming-language-benchmarks
Benchmarks for programming languages

## Languages and Implementations[*](#excluded-programming-languages)
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

  _Note: Creates 67,108,864 records. Last tested against node v24.3.0, this is
  the maximum array size. All other test languages have their tests calibrated
  to this number, which is the smallest array length of all of the test
  languages before one of the tests is terminated abnormally._
* **Parse JSON**  
  Test built-in or de facto standard JSON parser

## Results
### Physical
*Last updated: Thu Aug 21 14:20:27 MST 2025*
```sh
% ./bench
json
 js         real 0.03     user 0.02     sys 0.00
 python3    real 0.03     user 0.02     sys 0.00
 php        real 0.05     user 0.04     sys 0.01
 ruby       real 0.06     user 0.04     sys 0.01
 luajit     real 0.16     user 0.01     sys 0.00
 cpp        real 0.17     user 0.00     sys 0.00
 go         real 0.17     user 0.00     sys 0.00
 java       real 0.17     user 0.26     sys 0.02
 rust       real 0.16     user 0.00     sys 0.00
 lua        real 0.23     user 0.06     sys 0.00
 zig        real 0.28     user 0.00     sys 0.00
 c          real 0.38     user 0.00     sys 0.00
 cs         real 0.97     user 0.74     sys 0.19

minimal
 lua        real 0.00     user 0.00     sys 0.00
 luajit     real 0.00     user 0.00     sys 0.00
 js         real 0.02     user 0.01     sys 0.00
 python3    real 0.02     user 0.01     sys 0.00
 java       real 0.03     user 0.01     sys 0.01
 php        real 0.05     user 0.03     sys 0.00
 ruby       real 0.05     user 0.03     sys 0.01
 zig        real 0.15     user 0.00     sys 0.00
 c          real 0.16     user 0.00     sys 0.00
 cpp        real 0.16     user 0.00     sys 0.00
 go         real 0.16     user 0.00     sys 0.00
 rust       real 0.16     user 0.00     sys 0.00
 cs         real 0.94     user 0.78     sys 0.25

record
 zig        real 0.20     user 0.01     sys 0.02
 c          real 0.24     user 0.07     sys 0.02
 go         real 0.24     user 0.02     sys 0.03
 rust       real 0.41     user 0.04     sys 0.03
 java       real 0.46     user 1.92     sys 0.17
 cpp        real 0.50     user 0.30     sys 0.03
 cs         real 3.92     user 4.01     sys 0.59
 js         real 4.34     user 5.57     sys 1.47
 luajit     real 5.07     user 4.07     sys 0.98
 php        real 5.55     user 4.85     sys 0.69
 lua        real 9.48     user 8.48     sys 0.98
 ruby       real 11.86    user 11.18    sys 0.66
 python3    real 35.60    user 33.81    sys 1.75
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

###### Excluded Programming Languages
<sub>\* We do not benchmark Bash/Shell, TypeScript, or PowerShell. We do not
benchmark programming languages predominantly used for a single domain, like
Kotlin for Android development, Dart for Flutter, Swift for iOS development, or
MicroPython for embedded systems. We are unable to benchmark HTML/CSS, SQL, and
assembly. We do not benchmark programming languages that are not widely used in
production, like Groovy, Elixir, Scala, Delphi, Lisp, Erlang, Fortran, Ada, F#,
OCaml, Gleam, Prolog, COBOL, or Mojo. We do not benchmark programming languages
no longer supported, updated, or ones which "won't be extended to new workloads"
like Visual Basic (.NET) or VBA. We do not benchmark programming languages
predominantly used for statistical computing or data analysis, like R or MATLAB.
We do not benchmark custom scripting languages like GDScript. We do not
benchmark programming languages that are write-ins in the Stack Overflow
Developer Survey.</sub>

[1]: https://github.com/andrewmcwattersandco/web-server-benchmarks
