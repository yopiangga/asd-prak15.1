#include<stdio.h> 
#define N 5 
#define M 1000 

void tampil(int data[N][N]);

void main(){ 
	 int beban[N][N] = {
	 M,1,3,M,M, 
	 M,M,1,M,5, 
	 3,M,M,2,M, 
	 M,M,M,M,1, 
	 M,M,M,M,M
	 }; 
	 
	 int jalur[N][N] = {
	 0,1,1,0,0, 
	 0,0,1,0,1, 
	 1,0,0,1,0, 
	 0,0,0,0,1, 
	 0,0,0,0,0
	 }; 
	 
	 int rute[N][N] = {
	 M,0,0,M,M, 
	 M,M,0,M,0, 
	 0,M,M,0,M, 
	 M,M,M,M,0, 
	 M,M,M,M,M
	 }; 
	 
	 printf("%-15s", "Matrix Beban");
	 printf(": \n");
	 tampil(beban);
	 printf("\n"); 
	 printf("%-15s", "Matrix Jalur");
	 printf(": \n");
	 tampil(jalur); 
	 printf("\n"); 
	 printf("%-15s", "Matrix Rute");
	 printf(": \n");
	 tampil(rute); 
	 printf("\n"); 
}

void tampil(int data[N][N]){ 
int i, j;
	for(i=0; i<N; i++) { 
		for(j=0; j<N; j++){
			if(data[i][j] >= M)  
			printf("M "); 
			else 
			printf("%d ", data[i][j]); 
		}
		printf("\n"); 
	} 
} 
