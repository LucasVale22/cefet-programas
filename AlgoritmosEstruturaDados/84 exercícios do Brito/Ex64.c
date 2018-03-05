#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct desc{
       struct ptr *prim,*ult;
       };
struct desc *lista;
struct ptr *aux,*ver;
int dado;
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
void inserir_ordenado_lsecd(){
      void f1(){
           if(lista->prim->prox->dado<dado){
                              lista->prim=lista->prim->prox;
                              f1();
                              }
           }
      if((lista->ult==(struct ptr*)NULL)&&(lista->prim==(struct ptr*)NULL)){
                             lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                             lista->prim->dado=dado;
                             lista->ult=lista->prim;
                             lista->ult->prox=lista->prim;
                             }
      else{
           if(lista->prim->dado>dado){
                                      lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                      lista->ult->prox->dado=dado;
                                      lista->ult->prox->prox=lista->prim;
                                      lista->prim=lista->ult->prox;
                                      }
           else{
                if(lista->ult->dado<dado){
                                          lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                          lista->ult->prox->dado=dado;
                                          lista->ult=lista->ult->prox;
                                          lista->ult->prox=lista->prim;
                                          }
                else{
                     aux=lista->prim;
                     f1();
                     aux=(struct ptr*)malloc(sizeof(struct ptr));
                     aux->dado=dado;
                     aux->prox=lista->prim->prox;
                     lista->prim->prox=aux;
                     aux=(struct ptr*)NULL;
                     lista->prim=lista->ult->prox;
                }
           }
      }
}
void cria_cresc_lsecd(){
     if(dado>=0){
            inserir_ordenado_lsecd();
            printf("Entre com o valor: ");
            scanf("%d",&dado);  
            cria_cresc_lsecd();
            }
     else
         printf("Lista Vazia!");
}      
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista_vazia();
       cria_cresc_lsecd();
       printf("Fim da Lista!");
       if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
       getch();
       }
