#! /bin/sh
make all
./push_swap a b c "a b c" "--1" "   " ++3 2147483648 -2147483649
./push_swap a b c
./push_swap "1 2 3"

