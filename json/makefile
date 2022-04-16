c : json.c yyjson.c
	c89 json.c yyjson.c
c++ : json.cpp simdjson.cpp
	c++ -std=c++17 json.cpp simdjson.cpp
lua : lua/ldirlib.c
	cc -fPIC -llua -o dir.so -shared -std=c89 lua/ldirlib.c
clean :
	rm -f a.out
