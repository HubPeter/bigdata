#include<stdio.h>

#define FILE_CNT 1000
#define MAX_SIZE 25000 //22034
#define FILE_NAME_SIZE 20 //20
struct node{
    struct node* next;
    int key;
};
int gethash( int );
int main(void)
{
    int i = 0;
    char* str;
    FILE *fa, *fb, *fc;
    char filea[FILE_NAME_SIZE], fileb[FILE_NAME_SIZE], filec[FILE_NAME_SIZE];
    struct node* hashT;
    hashT = ( struct node* )malloc( MAX_SIZE * sizeof( struct node ) );
    while( i++<FILE_CNT )
    {
	//read a from little folder
	sprintf( filea, "ha/_%d", i );
	str = filea;
	fa = fopen(str, "r");
	sprintf( fileb, "hb/_%d", i );
	str = fileb;
	fb = fopen(str, "r");
	if( fa<=0 || fb<=0 )
	    continue ;
	int j = 0;
	struct node *p,*newP;
	for(; j<MAX_SIZE; j++ )
	{
	    hashT[ j ].key = -1;
	    hashT[ j ].next = NULL;
	}
	char sa[FILE_NAME_SIZE],sb[FILE_NAME_SIZE];
 	long int na,nb;
	int ha,hb;
	while( fscanf( fa, "%s", sa )==1 )
	{
	    printf("%s\n", sa);
	    na = atoi( sa );
	    if( na < 0 )
		na = -na;
	    ha = gethash(na);
	    p = &hashT[ ha ];//get hash index
	    if( p->key==-1 )
	    {
		p->key = na;
		p->next = NULL;//must because previous is -1, unsafe!
	    }
	    else
	    {
	    	newP = (struct node*) malloc( sizeof(struct node) );
	    	newP->key = na;//init
	    	newP->next = p->next;//insert:get after
	    	p->next = newP;
	    }
	}
	sprintf( filec, "h/_%d", i );
	str = filec;
	fc = fopen( str, "a" );//open new file fc
	while( fscanf( fb, "%s", sb )==1 )
	{
	    nb = atoi( sb );
	    hb = gethash( nb );
	    p = &hashT[ hb ];
	    while( p!=NULL && p->key>-1 && p->key!=nb )
	   	p = p->next;
	    if( p!=NULL && p->key==nb )
		fprintf(fc, "%d\n", nb  );
	}
	str = filea;
	if( fclose( fa ) )
	    printf("Error in closing %d\n", str);
	str = fileb;
	if( fclose( fb ) )
	    printf("Error in closing %d\n", str);
	str = filec;
	if( fclose( fc ) )
	    printf("Error in closing %d\n", str);
    }
    return 0;
}
int gethash(int na)
{
    return ( na % MAX_SIZE );
}
