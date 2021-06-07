#include<stdio.h> 
#include <stdlib.h>
#include<windows.h>
#define M 1000 
#define MAX 100

typedef struct {
	int data[MAX];
	int count;
} stack;

void initialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(int x, stack *s);
int pop(stack *s);

int N;

void tampil(int data[N][N]);

void main(){ 
	stack sRute;
	initialisasi(&sRute);
	int asal, tujuan;
	int beban[MAX][MAX], jalur[MAX][MAX], rute[MAX][MAX];
	
	printf("%-18s", "Jumlah Node");
	printf(": ");
	scanf("%d", &N);
	fflush(stdin);
	system("cls");
	
	printf("%-18s", "Matrix Beban (Q)");
	printf(": \n");
	input(&beban);
	system("cls");
	printf("%-18s", "Matrix Jalur (P)");
	printf(": \n");
	input(&jalur);
	system("cls");
	printf("%-18s", "Matrix Rute (R)");
	printf(": \n");
	input(&rute); 
	system("cls");
	 
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
	
	printf("%-18s", "Masukkan Asal");
	printf(": ");
	scanf("%d", &asal);
	fflush(stdin);
	printf("%-18s", "Masukkan Tujuan");
	printf(": ");
	scanf("%d", &tujuan);
	fflush(stdin);
	cariRute(asal, tujuan, &sRute, rute, beban);
}

void gotoxy(int a, int b) {
    COORD c;
    c.X=a;        
    c.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);    
}

int input(int X[N][N]){
	int i, j;
	char x;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			gotoxy(j*2, i+1);
			scanf("%c", &x);
			fflush(stdin);
			if(x == 'M'){
				X[i][j] = M;
			} else {
				X[i][j] =  x-'0';
			}
		}
	}
}

int warshall(int Q[N][N], int P[N][N], int R[N][N]){ 
	int k, j, i;
	for(k=0; k<N; k++){
		for (i=0; i<N; i++){
			for (j=0; j<N; j++){ 
				P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
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

int cariRute(int asal, int tujuan, stack *s, int R[N][N], int Q[N][N]){
	int i, j, r;
	i = asal-1;
	j = tujuan-1;
	
	if(R[i][j] != M){
		r = R[i][j];
		while(r != 0){
			push(r, s);
			r = R[i][r-1];
		}
		
		printf("%-18s", "Rute Jalur");
		printf(": ");
		printf("%d - ", asal);
		while(!kosong(s)){
			printf("%d - ", pop(s));
		}
		printf("%d", tujuan);
		printf("\n");
		printf("%-18s", "Beban Jalur");
		printf(": %d", Q[asal-1][tujuan-1]);
	} else {
		printf("Jalur Tidak Ada!\n");
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

void initialisasi(stack *s) {
	s->count = 0;
}

int kosong(stack *s){
	if(s->count== 0)
		return(1);
	else
		return(0);
}

int penuh(stack *s) {
	if(s->count == MAX)
		return(1);
	else 
		return(0);
}

void push(int x, stack *s) {
	if(penuh(s))
		printf("Stack penuh, tidak bisa menyimpan data\n");
	else {
		s->data[s->count] = x;
		s->count++;
	}
}

int pop(stack *s) {
	int x;
	
	if(kosong(s)){
		printf("stack kosong, tidak ada data ");
		return(0);
	} else {
		x = s->data[--s->count];
		return(x);		
	}
}
