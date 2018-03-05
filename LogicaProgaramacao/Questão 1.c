#include <stdio.h>
main(){
	char frase[1000];
	int i,tam,cont,caso,j;
	
	printf("Entre com a frase: ");
	for (i=0;i<1000;i++){
		scanf("%c",&frase[i]);
		if (frase[i]=='.')
			break;
	}
	
	tam=i;
	for (i=0;i<tam;i++){
		cont=caso=0;
		for (j=0;j<tam;j++){
			if (frase[j]==frase[i]){
				if (j<i){ //fazendo um DEBUG (à mão), dá pra entender o porquê desse IF. Usem a palavra "esse" como sendo a frase.
					caso=1;
					break;
				}
				else
					cont++;
			}
		}
		if (caso==0)
			printf("\n\n%d vezes a letra %c",cont,frase[i]);
	}
	getch();
}

