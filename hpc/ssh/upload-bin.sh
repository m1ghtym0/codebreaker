#!/bin/bash

ssh emmy-frontend 'mkdir -p bin'
scp ../src/codebreaker emmy-frontend:bin/
