c : json.c yyjson.c
	c89 json.c yyjson.c
c++ : json.cpp simdjson.cpp
	c++ -std=c++17 json.cpp simdjson.cpp
lua : dir.so
dir.so: lua/ldirlib.c
	cc -fPIC -llua -o dir.so -shared lua/ldirlib.c
clean :
	rm -f a.out
