#include <stdio.h>

char sim[5]="ABCDE";
int A[5][5]={
				0,1,0,1,0,
				0,0,1,0,1,
				0,0,0,0,0,
				0,1,0,0,1,
				0,0,1,0,0
				};

main(){
	int i, j;
	printf("{}{}{}Adjencency Matrix{}{}{}\n");
	printf("=============================\n");
	printf("Graf terdiri dari simpul :  \n");
	int x;
	for(x=0; x<5 ; x++){
		printf(" %c ", sim[x]);
	}
	printf("\n=============================\n");
		for(i=0; i<=4; i++){
			printf("\nSimpul %c terhubung dengan : ",sim[i]);
			for(j=0;j<=5;j++){
				if(A[i][j]==1)
				{
					printf("%c ",sim[j]);
				}
			}
		}
		printf("\n");
		getch();
}
