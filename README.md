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
% java -version
java version "1.8.0_321"
Java(TM) SE Runtime Environment (build 1.8.0_321-b07)
Java HotSpot(TM) 64-Bit Server VM (build 25.321-b07, mixed mode)
```
```sh
% javac -version
javac 1.8.0_321
```
* JavaScript
```sh
% node -v
v17.9.0
```
* Lua
```sh
% lua5.1 -v
Lua 5.1.5  Copyright (C) 1994-2012 Lua.org, PUC-Rio
```
_Note: Lua 5.1 is used due LuaJIT's API-compatibility.[1]_

* LuaJIT
```sh
% luajit
LuaJIT 2.1.0-beta3 -- Copyright (C) 2005-2021 Mike Pall. https://luajit.org/
JIT: ON fold cse dce fwd dse narrow loop abc sink fuse
>
```

## Tests
* **Minimal program**  
  Test initialization
* **Create a record/structure/object**  
  Test memory allocation

  _Note: Creates 112,813,858 records. As of node v17.9.0, this is the maximum
  array size. All other test languages have their tests calibrated to this
  number, which is the smallest array length of all of the test
  languages before one of the tests "terminate[s] abnormally."_ (`time`)
* **Parse JSON**  
  Test built-in or de facto standard JSON parser
* **Encode JSON**  
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
  Test graphics API command overhead

## Hardware
### Physical
MacBook Pro (16-inch, 2021)  
Apple M1 Max chip with 10-core CPU, 32-core GPU, and 16-core Neural Engine  
64GB unified memory  
1TB SSD storage  
https://www.apple.com/shop/buy-mac/macbook-pro/16-inch-space-gray-10-core-cpu-32-core-gpu-1tb#

<!-- ### Cloud
GitHub Actions -->

## License
GNU General Public License v3.0

## References
\[1]: https://luajit.org/install.html#embed
