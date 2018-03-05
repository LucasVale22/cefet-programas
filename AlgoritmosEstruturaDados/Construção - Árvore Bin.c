#include <stdio.h>
struct ptr{
       struct ptr *esq,*dir;
       char dado;
       };
struct ptr *inicio;
void constroi(struct ptr *a){
     char dado;
     printf("Entre com um valor: ");
     scanf("%c",&dado);
     if(dado!='.'){
                   a=(struct ptr*)malloc(sizeof(struct ptr));
                   a->dado=dado;
                   printf("Insere no esquerdo!");
                   constroi(a->esq);
                   printf("Insere no direito!");
                   constroi(a->dir);
     }
     else
         a=(struct ptr*)NULL;
}     
main(){
       constroi(inicio);
       printf("Fim da arvore!");
       getch();
}
