#include <stdio.h>
main(){
	#define TAM 3
	int matriz[TAM][TAM], DP[TAM], DS[TAM];
	int i,j;
	
	for(i=0;i<TAM;i++)
		for (j=0;j<TAM;j++){
			printf("Entre com o valor da matriz[%d][%d]: ",i,j);
			scanf("%d",&matriz[i][j]);
			printf("\n");
		}
	
	for (i=0;i<TAM;i++)
		DP[i]=matriz[i][i];
	
	j=TAM-1;
	for (i=0;i<TAM;i++){
		DS[i]=matriz[i][j];
		j--;
	}
	
	printf("\nDiagonal Principal: %d",DP[0]); //coloquei esse printf aqui só pra ficar tudo certo com a vírgula, se eu deixasse só o for ia ficar uma vírgula no final da impressão, com esse comando aki não fica essa vírgula. Se não entedeu, faça o seguinte: delete essa linha e no for abaixo coloque i=0 e veja o que acontece! :)
	for (i=1; i<TAM; i++)
		printf(", %d",DP[i]);
	
	printf("\n\nDiagonal Secundaria: %d", DS[0]);
	for (i=1; i<TAM; i++)
		printf(", %d",DS[i]);
	
	getch();
}
