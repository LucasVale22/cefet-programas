#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct desc{
       struct ptr *prim,*ult;
       };
struct desc *lista;
struct ptr *ver;
void mostra(){
     if(ver!=lista->ult){
                          printf("\t%d",ver->dado);
                          ver=ver->prox;
                          mostra();
                          }
     else
         printf("\t%d",ver->dado);
         }
void lista_vazia(){
     lista=(struct desc*)malloc(sizeof(struct desc));
     lista->prim=(struct ptr*)NULL;
     lista->ult=lista->prim;
     }  
void cria_inv_lsecd(){
     int dado;
     printf("Entre com valor: ");
     scanf("%d",&dado);
     lista_vazia();
     if(dado>=0){
                lista->ult=(struct ptr*)malloc(sizeof(struct ptr));
                lista->ult->dado=dado;   
                lista->ult->prox=lista->ult;
                lista->prim=lista->ult;
                printf("Entre com valor: ");
                scanf("%d",&dado);             
                while(dado>=0){
                                lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                lista->ult->prox->dado=dado;
                                lista->ult->prox->prox=lista->prim;
                                lista->prim=lista->ult->prox;
                                printf("Entre com valor: ");
                                scanf("%d",&dado);
                                }
                 printf("\nFim da Lista!");
                 }
     else
          printf("Lista Vazia!");
}
void excluir_dado_lsecd(int dado){
     struct ptr *aux;
     if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL))
                              printf("Lista Vazia!");
     else{
          if(lista->prim->prox==lista->prim){
                 if(lista->prim->dado!=dado)
                          printf("Não existe");
                 else{
                      lista->ult=(struct ptr*)NULL;
                      lista->prim->prox=lista->ult;
                      free(lista->prim);
                      lista->prim=lista->ult;
                      }
          }
          else{
               if(lista->prim->dado==dado){
                       lista->ult->prox=lista->prim->prox;
                       lista->prim->prox=(struct ptr*)NULL;
                       free(lista->prim);
                       lista->prim=lista->ult->prox;
                                               } 
               else{
                    aux=lista->ult->prox;
                    lista->ult->prox=aux->prox;
                    while((aux->prox->dado!=dado)){
                              aux=aux->prox;
                              lista->ult->prox=aux->prox;
                              }
                    if(lista->ult->prox->dado!=dado)
                              printf("Nao existe!");
                    else{
                         if(lista->ult->dado==dado){
                                                      lista->ult->prox=(struct ptr*)NULL;
                                                      aux->prox=lista->prim;
                                                      free(lista->ult->prox);
                                                      lista->ult=aux;
                                                      aux=(struct ptr*)NULL;
                                                      }
                         else{
                              aux->prox=lista->ult->prox->prox;
                              lista->ult->prox->prox=(struct ptr*)NULL;
                              free(lista->ult->prox);
                              lista->ult->prox=lista->prim;
                              aux=(struct ptr*)NULL;
                              }
                         }
                    }
               }
          }
}                                   
main(){
       int dado;
       cria_inv_lsecd();
       printf("Entre com valor a ser excluido: ");
       scanf("%d",&dado);
       excluir_dado_lsecd(dado);
       printf("\nFim da Exclusao!");
       if(lista->prim!=(struct ptr*)NULL){
                               ver=lista->prim;
                               mostra();
       }
       getch();
       }   
