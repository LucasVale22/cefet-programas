#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
       };
struct ptr *lista,*ver;
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
     int dado;
     struct ptr *aux;
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 while(dado>=0){
                                aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                aux->prox->ant=aux;
                                aux=aux->prox;
                                aux->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                }
                 aux->prox=lista;
                 lista->ant=aux;
                 aux=(struct ptr*)NULL;
                 printf("Fim da Lista!\n");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("Lista Vazia!");
          }
}
void exluir_dado_ldec(){
     int dado;    
     struct ptr *aux;
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
                                     while(lista->prox!=aux)
                                         lista=lista->prox;
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
                    while((aux->prox!=lista)&&(aux->dado!=dado)){
                                                                    aux=aux->prox;
                                                                    }
                    if(dado!=aux->dado)
                         printf("Não existe!");
                    else{
                         if(aux->prox==lista){
                                              aux->ant->prox=lista;
                                              lista=aux->ant;
                                              aux->ant=(struct ptr*)NULL;
                                              aux->prox=aux->ant;
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
       cria_ordem_ldec();
       exluir_dado_ldec();
       if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();  
                        }                  
       getch();
       }
