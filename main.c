#include "header.h"

int validInput (int n, int size){
	//return error code: 1-invalid input, 0-valid input
if (n > (pow(2,size)-1)) return 1;
else return 0;
}


void intToBin(unsigned int n, int size, int* binary){
    unsigned int mask = 1U << (size-1);
    int i;
    for (i = 0; i < size; i++) {
        binary[i] = (n & mask) ? 1 : 0;
        n <<= 1;
    }
}


void matrix (int n, int size, int binary[], int start[]){

int matrix[size][size][size];
int iteraction;
int news[size];
int i;

matrix[0][0][0]=binary[7];
matrix[0][0][1]=binary[6];
matrix[0][1][0]=binary[5];
matrix[1][0][0]=binary[4];
matrix[1][1][0]=binary[3];
matrix[0][1][1]=binary[2];
matrix[1][0][1]=binary[1];
matrix[1][1][1]=binary[0];

printf("Number of iteractions: ");
scanf("%d", &iteraction);

//TODO: results not entire correct
for (;iteraction>0;iteraction--){
	news[0]=matrix[binary[7]][binary[0]][binary[1]];
	news[1]=matrix[binary[0]][binary[1]][binary[2]];
	news[2]=matrix[binary[1]][binary[2]][binary[3]];
	news[3]=matrix[binary[2]][binary[3]][binary[4]];
	news[4]=matrix[binary[3]][binary[4]][binary[5]];
	news[5]=matrix[binary[4]][binary[5]][binary[6]];
	news[6]=matrix[binary[5]][binary[6]][binary[7]];
	news[7]=matrix[binary[6]][binary[7]][binary[0]];
}

//Print the results
for (i=0;i<size-1;i++){
		printf("%d - ",news[i]);
}
printf("%d",news[i]);
printf("\n");

}



int main (){
int n;
int size;
int i;

printf("Hello there! This is a program to calculate Elementar Cellular Automatons.\n");

//Initial number
printf("N (max is 255 for this version): ");
scanf("%d", &n);

//Size of start. TODO: different sizes
printf("Size (8 for this first version): ");
scanf("%d", &size);
int binary[size];
int start[size];

printf("N: %d, Tam: %d\n",n,size);

//validate size
if (validInput(n,size) == 1) {
	printf("Increase size.\n"); return 0;
}
else intToBin(n,size,binary);

//Start array
for (int j=0;j<size;j++){
	printf("Grid Position %d : ",(j+1));
	scanf("%d",&start[j]);

}

//Begin of tests
for (i=0;i<size;i++){
	printf("%d",binary[i]);
}
printf("\n");
for (i=0;i<size-1;i++){
		printf("%d - ",start[i]);
}
printf("%d",start[i]);
printf("\n");
//End of Tests


//Iteractions
matrix(n,size,binary,start);

return 0;	
}