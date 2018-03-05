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
void excluir_dado_lde(){
     void f1(){
          if((aux->dado!=dado)&&(aux->prox!=(struct ptr*)NULL)){
                                                   aux=aux->prox;
                                                   f1();
                                                   }
          }
     if(lista==(struct ptr*)NULL)
          printf("LIsta Vazia!");
     else{
          if(lista->prox==(struct ptr*)NULL){
                                  if(lista->dado!=dado)
                                                       printf("Não Existe!");
                                  else{
                                       free(lista);
                                       lista=(struct ptr*)NULL;
                                       }
          }
          else{
               if(lista->dado==dado){
                                     lista=lista->prox;
                                     lista->ant->prox=(struct ptr*)NULL;
                                     free(lista->ant);
                                     lista->ant=(struct ptr*)NULL;
                                     }
               else{
                    aux=lista;
                    f1();
                    if(aux->dado!=dado)
                                       printf("Não Existe!");
                    else{
                         if(aux->prox==(struct ptr*)NULL){
                                               aux->ant->prox=(struct ptr*)NULL;
                                               aux->ant=(struct ptr*)NULL;
                                               free(aux);
                                               aux=(struct ptr*)NULL;
                                               }
                         else{
                              aux->ant->prox=aux->prox;
                              aux->prox->ant=aux->ant;
                              aux->ant=(struct ptr*)NULL;
                              aux->prox=aux->ant;
                              free(aux);
                              aux=(struct ptr*)NULL;
                              }
                         }
                    }
               }
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
       printf("Entre com um valor a ser excluido: ");
       scanf("%d",&dado);   
       excluir_dado_lde();
       printf("\nFim da Exclusao!\n");
       ver=lista;
       mostra();
       getch();
       }

