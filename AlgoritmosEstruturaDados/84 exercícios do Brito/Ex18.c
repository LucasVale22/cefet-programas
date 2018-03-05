#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct desc{
       struct ptr *prim,*ult;
       };
struct desc *lista;
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
void exluir_tudo_lsed(){
              lista->ult=lista->prim;
              while(lista->prim!=(struct ptr*)NULL){
                                         lista->prim=lista->prim->prox;
                                         lista->ult->prox=(struct ptr*)NULL;
                                         free(lista->ult);
                                         lista->ult=lista->prim;
                                         }
              }
main(){
       cria_inv_lsed();
       exluir_tudo_lsed();
       printf("\nA lista foi excluida!");
       getch();
       }     
