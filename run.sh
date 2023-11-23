#!/bin/bash
mkdir -p ./logs
rm -rf ./logs/*
unbuffer ./build/bin/main/Ex2 | tee ./logs/Ex2.log
