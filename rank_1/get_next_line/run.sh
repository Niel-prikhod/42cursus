make re 
echo "compiling with main"
cc gnl_main.c get_next_line.a -o gnl_test
echo "running test"
./gnl_test