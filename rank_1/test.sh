cd ft_printf
make re
cd ..
cc test_ft_printf.c ft_printf/libftprintf.a -O
./a.out
