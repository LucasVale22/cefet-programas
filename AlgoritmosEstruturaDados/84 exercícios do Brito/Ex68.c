#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
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
void cria_ordem_ldecd(){
                 if(dado>=0){
                                lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                lista->ult->prox->ant=lista->ult;
                                lista->ult=lista->ult->prox;
                                lista->ult->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                cria_ordem_ldecd();
                                }
                 else{
                     lista->ult->prox=lista->prim;
                     lista->prim->ant=lista->ult;
                     printf("Fim da Lista!\n"); 
                 }
     
}
main(){
       lista_vazia();
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       if(dado>=0){
                 lista->ult=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->prim=lista->ult;
                 lista->ult->dado=dado;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_ldecd();
       }
       else
         printf("Lista Vazia!");
       if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
       getch();
      }
                 
