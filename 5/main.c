#include<stdio.h>
#include<stdlib.h>

#define SIZE 250000000
#define MAX 100000000

int main(void)
{
    //init array
    _Bool * bits;
    bits = (_Bool *) malloc( sizeof (_Bool) * SIZE * 2 );
    int i = 0;
    for(; i<MAX; i++)
    {
	bits[i] = 0;
	bits[i+MAX] = 0;
    }
    //read and set 00 01 10
    i = 0;
    int n ;
    for(; i<SIZE; i++)
    {
	n = rand()%MAX;
        if(bits[n]==0)
	{
	    if(bits[n+MAX]==0)
		bits[n+MAX] = 1;
	    else
	    {
		bits[n] = 1;
		bits[n+MAX] = 0;
	    }
	}
    }
    //show 01
    i = 0;
    for(; i<MAX; i++)
    {
	if(bits[i]==0 && bits[i+MAX]==1)
	    printf("%d	", i);
    }
    free( bits );
    printf("\n");
    return 0;
}
