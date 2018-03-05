#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct desc{
       struct ptr *prim,*ult;
       };
struct desc *lista;
int dado;
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
     if(dado>=0){
                 lista->ult=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->ult->dado=dado;
                 lista->ult->prox=lista->prim;
                 lista->prim=lista->ult;
                 printf("Entre com valor: ");
                 scanf("%d",&dado);
                 cria_inv_lsed();
     }
     else{
          if(lista->ult->prox!=(struct ptr*)NULL){
                       lista->ult=lista->ult->prox;
                       cria_inv_lsed();
                       }
          else
              printf("\nFim da Lista!");
     }
     
}
main(){
      printf("Entre com valor: ");
      scanf("%d",&dado);
      lista_vazia();
      if(dado>=0)
          cria_inv_lsed();
      else
          printf("Lista Vazia!");
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
      getch();
      } 
