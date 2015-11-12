#!/usr/bin/python

from urllib2 import Request, urlopen
import json
from subprocess import call

r = Request("https://api.github.com/repos/rgeorgiev583/dsp-practicum-2015-16/pulls?state=open", headers={"Accept": "application/vnd.github.v3+json"})
pullData = urlopen(r).read()
pulls = json.loads(pullData)

for pull in pulls:
    subprocess.call(["./prmerge.sh", pull["user"]["login"]])
