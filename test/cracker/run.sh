#!/bin/bash

set -v
./md5-test hello world fc5e038d38a57032085441e7fe7010b0
./md5-test "" world 7d793037a0760186574b0282f2f435e7
./md5-test hello "" 5d41402abc4b2a76b9719d911017c592

./sha256-test hello world 936a185caaa266bb9cbe981e9e05cb78cd732b0b3280eb944412bb6f8f8f07af
./sha256-test "" world 486ea46224d1bb4fb680f34f7c9ad96a8f24ec88be73ea8e5a6c65260e9cb8a7
./sha256-test hello "" 2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824

./sha512-test hello world 1594244d52f2d8c12b142bb61f47bc2eaf503d6d9ca8480cae9fcf112f66e4967dc5e8fa98285e36db8af1b8ffa8b84cb15e0fbcf836c3deb803c13f37659a60
./sha512-test "" world 11853df40f4b2b919d3815f64792e58d08663767a494bcbb38c0b2389d9140bbb170281b4a847be7757bde12c9cd0054ce3652d0ad3a1a0c92babb69798246ee
./sha512-test hello "" 9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caadae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043

./linux_crypt-test pzzxQ1Cg hello iCcwY.m.2hXdgR6FWGHo5/ md5
./linux_crypt-test /4yxkamn9nBX0NNJ hello cwuBAUUU1RQ7Q/8QqXGDxIIoUthYZApVpeabejZUJlC sha256
./linux_crypt-test VPVV5AWIl7uHsUY hello ORZ339EZ4IoTbwEDJt8vK23wpJR5xk3ZeUyI7BMTa4/OUtdDFQtsLF2JqN4qtRMDeQvREOXaU73I0PGUO6E3P. sha512

./cracker-test 1 hello world fc5e038d38a57032085441e7fe7010b0 regular
./cracker-test 5 hello world 936a185caaa266bb9cbe981e9e05cb78cd732b0b3280eb944412bb6f8f8f07af regular
./cracker-test 6 hello world 1594244d52f2d8c12b142bb61f47bc2eaf503d6d9ca8480cae9fcf112f66e4967dc5e8fa98285e36db8af1b8ffa8b84cb15e0fbcf836c3deb803c13f37659a60 regular
./cracker-test 1 pzzxQ1Cg hello iCcwY.m.2hXdgR6FWGHo5/ linux-crypt
./cracker-test 5 /4yxkamn9nBX0NNJ hello cwuBAUUU1RQ7Q/8QqXGDxIIoUthYZApVpeabejZUJlC linux-crypt
./cracker-test 6 VPVV5AWIl7uHsUY hello ORZ339EZ4IoTbwEDJt8vK23wpJR5xk3ZeUyI7BMTa4/OUtdDFQtsLF2JqN4qtRMDeQvREOXaU73I0PGUO6E3P. linux-crypt

./cracker-test2 wordlist passlist regular
./cracker-test2 wordlist passlist_crypt linux-crypt
