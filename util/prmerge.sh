#!/bin/sh

[ -z $ASSIGN_DIR ] && ASSIGN_DIR=8/solutions
[ -z $1 ] && exit 1
[ -z $2 ] && exit 1
action=$1
name=$2

if [ $action = init ]; then
    git checkout -b $name-master master
    git pull https://github.com/$name/dsp-practicum-2015-16.git master

    olddir=$(git diff --name-only master HEAD | head -1 | xargs dirname)
    [ -n $3 ] && fn=$3 || fn=$olddir
    newdir=$ASSIGN_DIR/$fn
    mkdir -p $newdir
    git mv $olddir $newdir

    git commit -m "automerge started: moved source files for FN $fn to the $newdir directory"
elif [ $action = commit ]; then
    git commit -m "automerge completed: assignment submission by FN $fn has been graded"

    git checkout master
    git merge --no-ff $name-master
    git push origin master
fi
