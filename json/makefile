CFLAGS=-std=c89
CXXFLAGS=-std=c++17
LDFLAGS=-llua -shared -fpic
c : json.c yyjson.c
	$(CC) $(CFLAGS) json.c yyjson.c
c++ : json.cpp simdjson.cpp
	$(CXX) $(CXXFLAGS) json.cpp simdjson.cpp
lua : dir.so
dir.so : lua/ldirlib.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
clean :
	rm -f a.out dir.so
