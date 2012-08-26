#include<stdio.h>
#include<stdlib.h>

#define SIZE 2500000000
int main(void)
{
    int i = 0;
    for(; i<SIZE; i++ )
    {
	printf("%d\n", rand() );
	printf("%d\n", rand() );
    }
    return 0;
}
