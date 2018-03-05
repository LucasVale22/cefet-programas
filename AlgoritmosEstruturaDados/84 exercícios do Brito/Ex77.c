#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux,*maior,*menor,*ver;
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
void excluir_dado_lse(){
      void f1(){
          if((maior->prox!=(struct ptr*)NULL)&&(maior->dado!=dado)){
                                   menor=maior;
                                   maior=maior->prox;
                                   f1();
                                   }
          }
          if(lista==(struct ptr*)NULL)
                            printf("Lista Vazia!");
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
                                          aux=lista;
                                          lista=lista->prox;
                                          aux->prox=(struct ptr*)NULL;
                                          free(aux);
                                          aux=(struct ptr*)NULL;
                                          }
                    else{
                         maior=lista;
                         f1();
                         if(dado!=maior->dado)
                                              printf("Não Existe!");
                         else{
                              menor->prox=maior->prox;
                              maior->prox=(struct ptr*)NULL;
                              free(maior);
                              maior=(struct ptr*)NULL;
                              menor=maior;
                              }
                         }                               
                    }
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
       printf("Entre com o valor a ser excluido: ");
        scanf("%d",&dado);
       excluir_dado_lse();
       printf("\nFim da Exclusao!\n");
       ver=lista;
       mostra();
       getch();
       }
                         
