#include <stdio.h>
main(){
	#define TAM 10
	int m[TAM][TAM], x, y, i, j, max;
	
	max=TAM-1;
	for (i=0;i<TAM;i++)
		for (j=0;j<TAM;j++)
			m[i][j]=0;
	
	do{
		printf("Entre com o valor de x: ");
		scanf("%d",&x);
		if ((x<0)||(x>max))
			printf("\nValor de x invalido.\n");
	}while ((x<0)||(x>max));
	
	printf("\n\n");
	
	do{
		printf("Entre com o valor de y: ");
		scanf("%d",&y);
		if ((y<0)||(y>max))
			printf("\nValor de y invalido.\n");
	}while ((y<0)||(y>max));
	
	if ((x-1)>=0){
		m[x-1][y]=1;
		if ((y-1)>=0)
			m[x-1][y-1]=1;
		if ((y+1)<=max)
			m[x-1][y+1]=1;
	}
	
	if((y-1)>=0)
		m[x][y-1]=1;
	if((y+1)<=max)
		m[x][y+1]=1;
	
	if((x+1)<=max){
		m[x+1][y]=1;
		if((y-1)>=0)
			m[x+1][y-1]=1;
		if((y+1)<=max)
			m[x+1][y+1]=1;
	}
	
	for (i=0;i<TAM;i++){
		printf("\n\n");
		for (j=0;j<TAM;j++)
			printf("%d\t",m[i][j]);
	}
	getch();
}
		
