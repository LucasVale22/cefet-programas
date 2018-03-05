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
void cria_inv_lded(){
          int dado;
          lista_vazia();
          printf("Entre com valor: ");
          scanf("%d",&dado);
          if(dado>=0){
                      lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                      lista->prim->dado=dado;
                      lista->ult=lista->prim;
                      lista->ult->prox=(struct ptr*)NULL;
                      printf("Entre com valor: ");
                      scanf("%d",&dado);
                      while(dado>=0){
                                     lista->prim->ant=(struct ptr*)malloc(sizeof(struct ptr));
                                     lista->prim->ant->dado=dado;
                                     lista->prim->ant->prox=lista->prim;
                                     lista->prim=lista->prim->ant;
                                     printf("Entre com valor: ");
                                     scanf("%d",&dado);
                      }
                      lista->prim->ant=(struct ptr*)NULL;
          }
          else
              printf("Lista Vazia!");
              }
main(){
      cria_inv_lded();
      printf("\nFim da Lista!\n");
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
       }
      getch();
      } 
          
                        
