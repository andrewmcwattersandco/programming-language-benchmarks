#!/bin/sh
printf '' > .gitignore
langs="C C++ Go Java Node Lua"

for lang in ${langs}
do
    curl -o - https://raw.githubusercontent.com/github/gitignore/main/${lang}.gitignore >> .gitignore
done

for dir in */
do
    file=$(basename ${dir})
    echo ${file}/${file} >> .gitignore
done

echo '*.orig' >> .gitignore
