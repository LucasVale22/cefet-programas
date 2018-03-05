#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
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
void cria_ordem_lse(){
     if(dado>=0){
               aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
               aux=aux->prox;
               aux->dado=dado;
               aux->prox=(struct ptr*)NULL;
               printf("Entre com o valor: ");
               scanf("%d",&dado);
               cria_ordem_lse();
               }
     else{
         aux=(struct ptr*)NULL;
         printf("\nFim da Lista!\n");
         }
         }
main(){
       aux=(struct ptr*)NULL;
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       if(dado>=0){
                   lista=(struct ptr*)malloc(sizeof(struct ptr));
                   lista->dado=dado;
                   lista->prox=(struct ptr*)NULL;
                   aux=lista;
                   printf("Entre com o valor: ");
                   scanf("%d",&dado);
                   cria_ordem_lse();
                   }
       else{
            lista=(struct ptr*)NULL;
            printf("Lista Vazia!");
            }
       ver=lista;
       mostra();
       getch();
       }
       
