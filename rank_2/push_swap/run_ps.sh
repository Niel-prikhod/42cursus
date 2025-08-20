#! /bin/bash

ARG="1 2 3 4"
./push_swap $ARG
valgrind (./push_swap $ARG)
