#!/bin/sh
printf '' > .gitignore
langs="C C++ Go Java Maven Node Lua"

for lang in ${langs}
do
    curl -o - https://raw.githubusercontent.com/github/gitignore/main/${lang}.gitignore >> .gitignore
done

# go.mod
touch $TMPDIR/.gitignore
grep -v '^\*.mod' .gitignore > $TMPDIR/.gitignore
mv $TMPDIR/.gitignore .gitignore

for dir in */
do
    file=$(basename ${dir})
    echo ${file}/${file} >> .gitignore
done

echo '*.orig' >> .gitignore
