#!/bin/sh

[ -z $1 ] && exit 1
[ -z $2 ] && exit 1

git checkout -b $1-master master
git pull https://github.com/$1/dsp-practicum-2015-16.git master

cd ..
mkdir -p 8/solutions/$2
fn=$(git diff --name-only master HEAD | head -1 | xargs dirname)
git mv $fn 8/solutions/$2
git commit -m "pre-automerge: moved source files for FN $fn to the assignment $2 directory in \`solutions'"

git checkout master
git merge --no-ff $1-master
git push origin master
