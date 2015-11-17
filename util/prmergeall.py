#!/usr/bin/python

from urllib2 import Request, urlopen
import json
from subprocess import call
import argparse

parser = argparse.ArgumentParser(description='Automatically merges all pull requests in a fork of the GitHub repo for the DSP 2015/16 practicum course @ FMI.')
parser.add_argument('assignment_id', metavar='assignment-id', type=int, help='the assignment to which the pull request contains a solution')
args = parser.parse_args()
aid = args.assignment_id

r = Request("https://api.github.com/repos/rgeorgiev583/dsp-practicum-2015-16/pulls?state=open", headers={"Accept": "application/vnd.github.v3+json"})
pullData = urlopen(r).read()
pulls = json.loads(pullData)

for pull in pulls:
    subprocess.call(["./prmerge.sh", pull["user"]["login"], aid])
