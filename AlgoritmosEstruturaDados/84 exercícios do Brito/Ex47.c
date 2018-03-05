#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
       };
struct ptr *lista,*aux,*ver;
int dado;
void mostra(){
     if(ver->prox!=lista){
                          printf("\t%d",ver->dado);
                          ver=ver->prox;
                          mostra();
                          }
     else
         printf("\t%d",ver->dado);
         }
void cria_ordem_ldec(){
     if(dado>=0){
                    aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                    aux->prox->ant=aux;
                    aux=aux->prox;
                    aux->dado=dado;
                    printf("Entre com o valor: ");
                    scanf("%d",&dado);
                    cria_ordem_ldec();
                    }
     else{
          aux->prox=lista;
          lista->ant=aux;
          aux=(struct ptr*)NULL;
          printf("Fim da Lista!");
          }
}
void exluir_dado_ldec(){
     void f1(){
          if(lista->prox!=aux){
                                         lista=lista->prox;
                                         f1();
                                         }
                                     }
     void f2(){
                    if((aux->prox!=lista)&&(aux->dado!=dado)){
                          aux=aux->prox;
                          f2();
                          }
                    }
     printf("Entre com o valor a ser excluido: ");
     scanf("%d",&dado);
     if(lista==(struct ptr*)NULL)
          printf("Lista Vazia!");
     else{
          if(lista->prox==lista){
                                 if(lista->dado!=dado)
                                       printf("Não existe!");
                                 else{
                                      free(lista);
                                      lista=(struct ptr*)NULL;
                                      printf("O %d foi excluido.",dado);
                                      }
                                 }  
          else{
               if(lista->dado==dado){
                                     aux=lista;
                                     f1();
                                     lista->prox=aux->prox;
                                     lista->prox->ant=lista;
                                     aux->prox=(struct ptr*)NULL;
                                     aux->ant=aux->prox;
                                     free(aux);
                                     aux=(struct ptr*)NULL;
                                     lista=lista->prox;
                                     printf("O %d foi excluido.",dado);
                                     }
               else{
                    aux=lista;
                    f2();
                    if(dado!=aux->dado)
                         printf("Não existe!");
                    else{
                         if(aux->prox==lista){
                                              aux->ant->prox=lista;
                                              lista->ant=aux->ant;
                                              aux->prox=(struct ptr*)NULL;
                                              aux->ant=aux->prox;
                                              free(aux);
                                              printf("O %d foi excluido.",dado);
                                              }
                         else{
                              aux->ant->prox=aux->prox;
                              aux->prox->ant=aux->ant;
                              aux->ant=(struct ptr*)NULL;
                              aux->prox=aux->ant;
                              free(aux);
                              aux=(struct ptr*)NULL;
                              printf("O %d foi excluido.",dado);
                              }
                         }
                    }
               }
          }   
}  
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_ldec();
                 }
       else
          printf("Lista Vazia!");
       exluir_dado_ldec();
       if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
       getch();
       }
