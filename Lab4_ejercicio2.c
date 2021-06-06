
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

int main ( ) {
	int done = FALSE;
	int j =0;
	
	while ( ! done ) {
		int n = 10; //modificación para 10 iteraciones
		int* a = ( int*)malloc(n * sizeof(int) ) ;
		int i;
		for( i = 0; i < n ; i++){
			a[i] = i ;
		}
		if(!a){
			perror(NULL); //lineas extras agregadas para atrapar error
			exit(1);
		}
		j++;
		printf("%d\n" , j ) ; 
		
		if (j > n -1){ //reduce las iteraciones a 10 y para el loop del while
			done = TRUE;
		}
		free(a); //libera a a 	
	}
	return 0 ;
}
