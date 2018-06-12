#!/bin/bash

set -v
./distribution-test wordlist > result
diff result dist_wordlist
