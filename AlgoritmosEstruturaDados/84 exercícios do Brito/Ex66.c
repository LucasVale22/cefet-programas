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
void lista_vazia(){
     lista=(struct desc*)malloc(sizeof(struct desc));
     lista->prim=(struct ptr*)NULL;
     lista->ult=lista->prim;
     }  
void cria_inv_lsecd(){
                  if(dado>=0){
                                lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                lista->ult->prox->dado=dado;
                                lista->ult->prox->prox=lista->prim;
                                lista->prim=lista->ult->prox;
                                printf("Entre com valor: ");
                                scanf("%d",&dado);
                                cria_inv_lsecd();
                                }
                 else
                     printf("\nFim da Lista!");
}
void exluir_tudo_lsecd(){
              if(lista->prim!=lista->ult){
                                         lista->ult->prox=lista->prim->prox;
                                         lista->prim->prox=(struct ptr*)NULL;
                                         free(lista->prim);
                                         lista->prim=lista->ult->prox;
                                         exluir_tudo_lsecd();
                                         }
              else{
                  lista->ult->prox=(struct ptr*)NULL;
                  lista->ult=lista->ult->prox;
                  free(lista->prim);
                  }
              }
main(){
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
                cria_inv_lsecd();
                }
     else
          printf("Lista Vazia!");
     if(lista->prim!=(struct ptr*)NULL){
                             exluir_tudo_lsecd();
                             printf("\nA lista foi excluida!");
                             }
     getch();
       }  
