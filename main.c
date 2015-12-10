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






int main (){
int n;
int size;
	printf("Hello there! This is a program to calculate Elementar Cellular Automatons.\n");
	
	printf("N: ");
	scanf("%d", &n);

   printf("Size: ");
   scanf("%d", &size);
   int binary[size];

printf("N: %d, Tam: %d\n",n,size);

if (validInput(n,size) == 1) printf("Increase size.\n");
else intToBin(n,size,binary);

for (int i=0;i<size;i++) printf("%d",binary[i]);
printf("\n");
	return 0;	
}