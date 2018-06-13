#!/usr/bin/env python2

import sys
import re


if len(sys.argv) < 3:
    print("USAGE: {} codebreaker.out codebreaker.found".format(sys.argv[0]))
    sys.exit(1)
with open(sys.argv[1], "r") as f:
    raw = f.read()

start, filtered, end = re.findall(r"End of prologue: \w+ \w+ (\d+ \d+:\d+:\d+)([\n\w\W\d\D\s\S]+)Starting epilogue... \w+ \w+ (\d+ \d+:\d+:\d+)", raw, re.MULTILINE)[0]

s_day, s_time = start.split(' ')
s_day = int(s_day)
s_hour, s_min, s_sec = map(int, s_time.split(':'))

e_day, e_time = end.split(' ')
e_day = int(e_day)
e_hour, e_min, e_sec = map(int, e_time.split(':'))

time_diff = (e_day-s_day)*24*3600 + (e_hour-s_hour)*3600 + (e_min-s_min)*60 + (e_sec-s_sec)

result = ''
total = 0
for line in filtered.split('\n')[1:-1]:
    try:
        salt, pwd, _hash = re.findall(r"NODE\[\d+\]: \|(.*)\|(.*)\|(.*)\|", line)[0]
    except IndexError:
        continue
    result += "|SALT='{}'|PWD='{}'|HASH={}|\n".format(salt, pwd, _hash)
    total += 1

header = 'Codebreaker recovered {} passwords in {} seconds:\n'.format(total, time_diff)

with open(sys.argv[2], "w") as f:
    f.write(header)
    f.write(result)
