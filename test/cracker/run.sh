#!/bin/bash

set -v
./md5-test hello world fc5e038d38a57032085441e7fe7010b0
./md5-test "" world 7d793037a0760186574b0282f2f435e7
./md5-test hello "" 5d41402abc4b2a76b9719d911017c592
./sha256-test hello world 936a185caaa266bb9cbe981e9e05cb78cd732b0b3280eb944412bb6f8f8f07af
./sha256-test "" world 486ea46224d1bb4fb680f34f7c9ad96a8f24ec88be73ea8e5a6c65260e9cb8a7
./sha256-test hello "" 2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824
