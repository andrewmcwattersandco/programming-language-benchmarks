CFLAGS=-std=c89
CXXFLAGS=-std=c++17

# macOS Homebrew detection
ifeq ($(shell uname -s),Darwin)
	LUA_INCLUDE=-I/opt/homebrew/opt/lua/include/lua
	LUA_LIB=-L/opt/homebrew/opt/lua/lib
endif

LDFLAGS=-llua -shared -fpic

c : json.c yyjson.c
	$(CC) $(CFLAGS) json.c yyjson.c
c++ : json.cpp simdjson.cpp
	$(CXX) $(CXXFLAGS) json.cpp simdjson.cpp
lua : dir.so
luajit :
	$(MAKE) lua "LUA_LIB=-lluajit-5.1"
dir.so : lua/ldirlib.c
	$(CC) $(CFLAGS) $(LUA_INCLUDE) $(LUA_LIB) $(LDFLAGS) -o $@ $<
clean :
	rm -f a.out dir.so

.PHONY: c c++ lua luajit clean
