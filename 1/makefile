all:	gen hash merge test
gen:	gen.c
	gcc -w -o gen gen.c -g
hash:	hash.c
	gcc -w -o hash hash.c  -g
merge:	merge.c
	gcc -w -o merge merge.c -g
test:	test.c
	gcc -w -o test test.c -g
clean:		
	rm gen merge test hash
