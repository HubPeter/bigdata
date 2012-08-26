#include<stdio.h>

#define MAX_SIZE 40
#define SIZE 5000000000
int hash(int);//hash an integer to a int
int getfile(int);//get file order by calling hash()

int main(void)
{
    int na,nb;//read from rand device
    int ha,hb;//file order of little file ha
    FILE* tfa;//file order of ha
    FILE* tfb;//file order of hb
    char nameha[MAX_SIZE];//filename of little file ha
    char namehb[MAX_SIZE];//filename of little file hb
    char *str;//to get short string for nameha and namehb
    int i = 0;
    while( i++<SIZE )
    {
	na = rand();
	nb = rand();
	ha = getfile( na );
	hb = getfile( nb );
	sprintf(nameha, "ha/_%d", ha);
	sprintf(namehb, "hb/_%d", hb);
	str = nameha;
	tfa = fopen( str, "a" );
	str = namehb;
	tfb = fopen( str, "a" );
	fprintf(tfa, "%d\n", na);
	fprintf(tfb, "%d\n", nb);
	if( fclose( tfa )!=0 )
	    printf("Error in lcosing fa/%d\n", ha);
	if( fclose( tfb )!=0 )
	    printf("Error in lcosing fb/%d\n", hb);
    }
    return 0;
}
int hash(int n)
{
    int h = n;
    return h;
}
int getfile(int n)
{
    int f = hash(n)%1000;
    return f;
}
