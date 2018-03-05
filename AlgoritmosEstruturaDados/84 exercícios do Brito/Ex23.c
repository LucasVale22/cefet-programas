#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
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
void cria_ordem_lded(){
     int dado;
     lista_vazia();
     printf("Entre com valor: ");
     scanf("%d",&dado);
     if(dado>=0){ 
             lista->ult=(struct ptr*)malloc(sizeof(struct ptr));    
             lista->ult->dado=dado;
             lista->prim=lista->ult;
             lista->prim->prox=(struct ptr*)NULL;
             printf("Entre com valor: ");
             scanf("%d",&dado);
             while(dado>=0){
                            lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                            lista->ult->prox->dado=dado;
                            lista->ult->prox->ant=lista->ult;
                            lista->ult=lista->ult->prox;
                            printf("Entre com valor: ");
                            scanf("%d",&dado);
                                     }
             lista->ult->prox=(struct ptr*)NULL;
          }
          else
              printf("Lista Vazia!");
              } 
void excluir_dado_lded(int dado){
     if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL))
                              printf("Lista Vazia!");
     else{
          if(lista->prim->prox==(struct ptr*)NULL){
                if(lista->prim->dado==dado){
                                            lista->ult=lista->ult->prox;
                                            free(lista->prim);
                                            lista->prim=lista->ult;
                                              }
                else
                     printf("Nao Existe!");
                     }
          else{
               if(lista->prim->dado==dado){
                      lista->prim=lista->prim->prox;
                      lista->prim->ant->prox=(struct ptr*)NULL;
                      free(lista->prim->ant);
                      lista->prim->ant=(struct ptr*)NULL;
                      }
               else{
                    if(lista->ult->dado==dado){
                      lista->ult=lista->ult->ant;
                      lista->ult->prox->ant=(struct ptr*)NULL;
                      free(lista->ult->prox);
                      lista->ult->prox=(struct ptr*)NULL;
                      }
                    else{
                           lista->ult=lista->prim;
                           while((lista->ult->prox!=(struct ptr*)NULL)&&(lista->ult->dado!=dado))
                                                           lista->ult=lista->ult->prox;
                           if(lista->ult->dado!=dado)
                                                     printf("Nao Existe!");
                           else{
                                lista->ult->prox->ant=lista->ult->ant;
                                lista->ult->ant->prox=lista->ult->prox;
                                lista->ult->ant=(struct ptr*)NULL;
                                lista->ult->prox=(struct ptr*)NULL;
                                free(lista->ult);
                                lista->ult=lista->prim;
                                while(lista->ult->prox!=(struct ptr*)NULL)
                                                                lista->ult=lista->ult->prox; 
                                }   
                           }
                    }
               } 
          }           
}
main(){
      int dado;
      cria_ordem_lded();
      printf("Entre com valor a ser excluido: ");
      scanf("%d",&dado);
      excluir_dado_lded(dado);
      printf("Fim da Exclusao!");
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
                              }
      getch();
      } 
