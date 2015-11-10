#!/bin/sh

[ -z $1 ] && exit 1

git checkout -b $1-master master
git pull https://github.com/$1/dsp-practicum-2015-16.git master
git checkout master
git merge --no-ff $1-master
git push origin master
