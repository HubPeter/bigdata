#include<stdio.h>

int main(void)
{
    FILE * fd = fopen( "/mnt/sda3/bigdata/a", "r" );
    char n[30];
    
    while( fscanf( fd, "%s", n )==1 && fscanf(fd, "%d", n)==1 )
	printf( "%s\n", n );
    printf("\n");
    if( fclose(fd)!=0 )
	printf("Error in closing testdata\n");
    return 0;
}
