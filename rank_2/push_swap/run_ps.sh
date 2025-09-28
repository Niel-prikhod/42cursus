#! /bin/bash

int_max=1000000
int_min=-1000000
sizes=(3 5 100 500)
runs_per_size=5

for size in "${sizes[@]}"; do
	echo "Tesing stack of $size integers"
	total_ops=0
	for ((i=0; i<runs_per_size; i++)); do 
		input=$(shuf -i 1-1000000 -n $size | tr '\n' ' ')
		operations=$(./push_swap $input | wc -l)
		checker=$(./push_swap $input | ./checker_linux $input)
		echo "Run $i: $operations operations, $checker"
	done
done
