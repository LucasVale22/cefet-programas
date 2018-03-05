#include <stdio.h>
struct ptr{
       struct ptr *esq,*dir;
       char dado;
       };
struct ptr *inicio;
void constroi(struct ptr *a);
main(){
       constroi(inicio);
       printf("Fim da Arvore!");
       getch();
       }
void constroi(struct ptr *a){
     char dado;
     printf("Entre com um valor: ");
     scanf("%c",&dado);
     if(dado!='.'){
                   a=(struct ptr*)malloc(sizeof(struct ptr));
                   a->dado=dado;
                   constroi(a->esq);
                   constroi(a->dir);
     }
     else
         a=(struct ptr*)NULL;
}
