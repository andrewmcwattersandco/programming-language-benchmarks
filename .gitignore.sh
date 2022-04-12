#!/bin/sh
printf '' > .gitignore
languages="C C++ Go Java Node Lua"
for i in ${languages}
do
    curl -o- https://raw.githubusercontent.com/github/gitignore/main/${i}.gitignore >> .gitignore
done
uniq -u .gitignore
