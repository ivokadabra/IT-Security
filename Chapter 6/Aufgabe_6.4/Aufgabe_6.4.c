#include <stdio.h>
#include <string.h>
#include <malloc.h>

static char *cipher;

static char *xor( char *a, char *secret )
{
	char *ptr, *sptr;
	int secret_length = strlen( secret );

	if( strlen(a) > strlen(secret) ) {
		printf("WARNING: secret too small...\n");
	}
	cipher = malloc( strlen(a) );
	if (cipher==NULL) {
		perror("cipher-buffer");
		return NULL;
	}

    int j=0;
	for(int i=0;i<strlen(a);i++){
	    
	   int n=a[i];
	   int m=secret[i];
	   int num=n^m;
	    
	   
	    
	   if(j+1==strlen(secret))
	       j=0;
	   
	   cipher[i]=num;
	   j++;
	}







	return cipher;
}


int main(  )
{
	char *ptr;
	int i;

	

	ptr = xor("hello, world","secret");
    
    for(int i=0;i<strlen("hello, world");i++){
        
        printf("%c",ptr[i]);
    }
    
	return 0;
}