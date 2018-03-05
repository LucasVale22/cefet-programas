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
void cria_inv_lsed(){
     int dado;
     printf("Entre com valor: ");
     scanf("%d",&dado);
     lista_vazia();
     if(dado>=0){
                                while(dado>=0){
                                lista->ult=(struct ptr*)malloc(sizeof(struct ptr));
                                lista->ult->dado=dado;
                                lista->ult->prox=lista->prim;
                                lista->prim=lista->ult;
                                printf("Entre com valor: ");
                                scanf("%d",&dado);
                                }
                 while(lista->ult->prox!=(struct ptr*)NULL)
                                          lista->ult=lista->ult->prox;
                 printf("\nFim da Lista!\n");
                 }
     else
          printf("Lista Vazia!");
} 
void exluir_dado_lsed(int dado){
     struct ptr *aux;
     if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL))
                              printf("Lista Vazia!");
     else{
          if(lista->prim->prox==(struct ptr*)NULL){
                 if(lista->prim->dado!=dado)
                          printf("Não existe");
                 else{
                      lista->ult=(struct ptr*)NULL;
                      free(lista->prim);
                      lista->prim=lista->ult;
                      }
          }
          else{
               if(lista->prim->dado==dado){
                       lista->ult=lista->prim->prox;
                       lista->prim=(struct ptr*)NULL;
                       free(lista->prim);
                       lista->prim=lista->ult;
                       while(lista->ult->prox!=(struct ptr*)NULL)
                               lista->ult=lista->ult->prox;
                                               } 
               else{
                    lista->ult=lista->prim;
                    while((lista->ult->dado!=dado)&&(lista->ult->prox!=(struct ptr*)NULL))
                              lista->ult=lista->ult->prox;
                    if(lista->ult->dado!=dado)
                              printf("Nao existe!");
                    else{
                         if(lista->ult->prox==(struct ptr*)NULL){
                                                      lista->ult=lista->prim;
                                                      while(lista->ult->prox->dado!=dado)
                                                               lista->ult=lista->ult->prox;
                                                      free(lista->ult->prox);
                                                      lista->ult->prox=(struct ptr*)NULL;
                                                      }
                         else{
                              aux=lista->ult->prox;
                              lista->ult->prox=(struct ptr*)NULL;
                              lista->ult=lista->prim;
                              while(lista->ult->prox->dado!=dado)
                                       lista->ult=lista->ult->prox;   
                              free(lista->ult->prox);
                              lista->ult->prox=aux;
                              while(lista->ult->prox!=(struct ptr*)NULL)
                                       lista->ult=lista->ult->prox;  
                              aux=lista->ult->prox;
                              }
                         }
                    }
               }
          }
}                                      
main(){
       int dado;
       cria_inv_lsed();
       printf("Entre com valor a ser excluido: ");
       scanf("%d",&dado);
       exluir_dado_lsed(dado);
       printf("\nFim da Exclusao!");
       if(lista->prim!=(struct ptr*)NULL){
                         ver=lista->prim;
                         mostra();
                         }
       getch();
       }     
     
     



