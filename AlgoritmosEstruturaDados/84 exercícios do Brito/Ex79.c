#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *ant,*prox;
       };
struct ptr *lista,*aux,*ver;
int dado;
void mostra(){
     if(ver!=(struct ptr*)NULL){
                     printf("\t%d",ver->dado);
                     ver=ver->prox;
                     mostra();
                     }
     }
void cria_inv_lde(){
     if(dado>=0){
                 aux=(struct ptr*)malloc(sizeof(struct ptr));
                 aux->dado=dado;
                 aux->prox=lista;
                 aux->ant=(struct ptr*)NULL;
                 lista->ant=aux;
                 lista=aux;
                 printf("Entre com um valor: ");
                 scanf("%d",&dado);
                 cria_inv_lde();
                 }
     else{
          aux=(struct ptr*)NULL;
          printf("\nFim da Lista!\n");
          }
     }
main(){
       printf("Entre com um valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       if(dado>=0){
                   lista=(struct ptr*)malloc(sizeof(struct ptr));
                   lista->dado=dado;
                   lista->ant=(struct ptr*)NULL;
                   lista->prox=lista->ant;
                   printf("Entre com um valor: ");
                   scanf("%d",&dado);
                   cria_inv_lde();
                   }
       else
           printf("Lista Vazia!");
       ver=lista;
       mostra();
       getch();
       }

