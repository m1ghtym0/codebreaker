#!/bin/bash

set -v
./md5-test hello world fc5e038d38a57032085441e7fe7010b0
./md5-test "" world 7d793037a0760186574b0282f2f435e7
./md5-test hello "" 5d41402abc4b2a76b9719d911017c592
