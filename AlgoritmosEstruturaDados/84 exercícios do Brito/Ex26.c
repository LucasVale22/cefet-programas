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
void cria_ordem_lsecd(){
     int dado;
     lista_vazia();
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->prim->dado=dado;
                 lista->ult=lista->prim;     
                 lista->ult->prox=lista->prim;      
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 while(dado>=0){
                            lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));    
                            lista->ult=lista->ult->prox;
                            lista->ult->dado=dado;
                            lista->ult->prox=lista->prim; 
                            printf("Entre com o valor: ");
                            scanf("%d",&dado);
                            }
                 
                }
     else
         printf("Lista Vazia!");
}
main(){
      cria_ordem_lsecd();
      printf("Fim da Lista!");
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
                              }
      getch();
      } 
