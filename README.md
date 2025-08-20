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
* PHP
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

## Results
### Physical
*Last updated: Tue Aug 19 08:39:38 MST 2025*
```sh
% ./bench
minimal
 lua        real 0.00       user 0.00       sys 0.00	
 luajit     real 0.00       user 0.00       sys 0.00	
 js         real 0.02       user 0.01       sys 0.00	
 python3    real 0.02       user 0.01       sys 0.00	
 java       real 0.03       user 0.01       sys 0.01	
 php        real 0.05       user 0.03       sys 0.01	
 cpp        real 0.10       user 0.00       sys 0.00	
 c          real 0.14       user 0.00       sys 0.00	
 go         real 0.15       user 0.00       sys 0.00	
 rust       real 0.15       user 0.00       sys 0.00
 cs         real 0.95       user 0.79       sys 0.25	
record
 rust       real 0.23       user 0.04       sys 0.02
 c          real 0.24       user 0.07       sys 0.02	
 go         real 0.24       user 0.03       sys 0.04	
 java       real 0.46       user 2.00       sys 0.17	
 cpp        real 0.47       user 0.30       sys 0.02	
 cs         real 3.98       user 3.76       sys 0.47	
 js         real 4.41       user 5.67       sys 1.51	
 luajit     real 5.07       user 4.09       sys 0.97	
 php        real 5.57       user 4.86       sys 0.70	
 lua        real 9.96       user 8.94       sys 1.00	
 python3    real 35.71      user 33.66      sys 1.94	
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
