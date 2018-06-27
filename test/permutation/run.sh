#!/bin/bash

set -v
./permutation-test > permutation.res
diff permutation.correct permutation.res
