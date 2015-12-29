#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int validInput (int n, int size){
	//return error code: 1-invalid input, 0-valid input
	if (n > (pow(2,size)-1)) return 1;
	else return 0;
}


void intToBin(unsigned int n, int* binary){
    unsigned int mask = 1U << (8-1);
    int i;
    for (i = 0; i < 8; i++) {
        binary[i] = (n & mask) ? 1 : 0;
        n <<= 1;
    }
}


int GetRand(int min, int max)
{
  static int Init = 0;
  int rc;
  
  if (Init == 0)
  {
    srand(time(NULL));
    Init = 1;
  }  
  rc = (rand() % (max - min + 1) + min);
  
  return (rc);
}







void iteractions (int n, int size, int binary[], int start[], int niteractions){

int matrix[2][2][2];
int news[size];
int i,j;

matrix[0][0][0]=binary[7];
matrix[0][0][1]=binary[6];
matrix[0][1][0]=binary[5];
matrix[0][1][1]=binary[4];
matrix[1][0][0]=binary[3];
matrix[1][0][1]=binary[2];
matrix[1][1][0]=binary[1];
matrix[1][1][1]=binary[0];


for (j=1;j<=niteractions;j++){
	news[0]=matrix[start[size-1]][start[0]][start[(1)]];
	for(i=1;i<size-1;i++)
		news[i]=matrix[start[i-1]][start[i]][start[i+1]];
	news[i]=matrix[start[(i-1)]][start[i]][start[0]];
	
	for (i=0;i<size;i++)
		start[i]=news[i];

	//Print the results
	for (i=0;i<size;i++)
		if(news[i]==0) printf("□ ");
		else printf("■ ");
	printf(" t=%d \n",j );


	
}
}


int main (){
int n, size, i, j, niteractions;
char grid;

printf("Hello there! This is a program to calculate Elementar Cellular Automatons.\n");

//Initial number
printf("NΦ (max is 255): ");
scanf("%d", &n);

//Size of start.
printf("Size: ");
scanf("%d", &size);
int binary[8];
int start[size];

//Number of iteractions
printf("Number of iteractions: ");
scanf("%d", &niteractions);

//Start array
printf("Press I to insert the initial grid or R for a random one: ");
fflush(stdin);
scanf(" %c", &grid);
if (grid=='I'){
for (j=0;j<size;j++){
	printf("Position %d:",j);
	scanf("%d",&start[j]);
}
}
if (grid=='R'){
for (j=0;j<size;j++){
	start[j]= GetRand(0, 1);
}
}
//END

//validate size
if (size <= 2) {
	printf("Increase size.\n"); return 0;
}
else intToBin(n,binary);
//

//t=0
for (i=0;i<8;i++){
	printf("%d",binary[i]);
}
printf("\n");

for (i=0;i<size;i++)
		if(start[i]==0) printf("□ ");
		else printf("■ ");
	printf(" t=0 \n \n" );

//t=0


//Iteractions
iteractions(n,size,binary,start,niteractions);

return 0;	
}