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
	 
	 printf("Matrik Asal\n");
	 printf("%-18s", "Matrix Beban (Q)");
	 printf(": \n");
	 tampil(beban);
	 printf("\n"); 
	 printf("%-18s", "Matrix Jalur (P)");
	 printf(": \n");
	 tampil(jalur); 
	 printf("\n"); 
	 printf("%-18s", "Matrix Rute (R)");
	 printf(": \n");
	 tampil(rute); 
	 printf("\n"); 
	 
	 warshall(beban, jalur, rute);
	 printf("Hasil Matrik Baru\n");
	 
	 printf("%-18s", "Matrix Beban (Q)");
	 printf(": \n");
	 tampil(beban);
	 printf("\n"); 
	 printf("%-18s", "Matrix Jalur (P)");
	 printf(": \n");
	 tampil(jalur); 
	 printf("\n"); 
	 printf("%-18s", "Matrix Rute (R)");
	 printf(": \n");
	 tampil(rute); 
	 printf("\n"); 
}

int warshall(int Q[N][N], int P[N][N], int R[N][N]){ 
	int k, j, i;
	for(k=0; k<N; k++){
		for (i=0; i<N; i++){
			for (j=0; j<N; j++){ 
				P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
				if ((Q[i][k] + Q[k][j]) < Q[i][j]) { 
					Q[i][j] = Q[i][k] + Q[k][j]; 
					if (R[k][j] == 0) 
						R[i][j] = k+1; 
					else 
						R[i][j] = R[k][j]; 
				} 
			}
		}
	}	 
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
