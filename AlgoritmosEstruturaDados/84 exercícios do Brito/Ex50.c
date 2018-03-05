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
void cria_ordem_lsed(){
     if(dado>=0){
                            lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));    
                            lista->ult=lista->ult->prox;
                            lista->ult->dado=dado;
                            printf("Entre com o valor: ");
                            scanf("%d",&dado);
                            cria_ordem_lsed();
                            }
     else{
          lista->ult->prox=(struct ptr*)NULL;
          printf("Fim da Lista!");
          }
}
main(){
      lista_vazia();
      printf("Entre com o valor: ");
      scanf("%d",&dado);
      if(dado>=0){
                 lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->prim->dado=dado;
                 lista->ult=lista->prim;           
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_lsed();
                 }
      else
          printf("Lista Vazia!");
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
      getch();
      } 
         
