CFLAGS=-std=c89
CXXFLAGS=-std=c++17
c : json.c yyjson.c
	$(CC) $(CFLAGS) json.c yyjson.c
c++ : json.cpp yyjson.c
	$(CXX) $(CXXFLAGS) json.cpp yyjson.c
lua : dir.so
dir.so : lua/ldirlib.c
	$(CC) $(CFLAGS) -fPIC -llua -o dir.so -shared lua/ldirlib.c
clean :
	rm -f a.out dir.so
