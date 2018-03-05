#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
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
void excluir_tudo_lded(){
     while(lista->prim->prox!=(struct ptr*)NULL){
                                      lista->prim=lista->prim->prox;
                                      lista->prim->ant->prox=(struct ptr*)NULL;
                                      free(lista->prim->ant);
                                      lista->prim->ant=(struct ptr*)NULL;
                                      }
     lista->prim=lista->prim->ant;
     free(lista->ult);
     lista->ult=lista->prim;
     }
     
     
main(){
      cria_ordem_lded();
      if(lista->prim!=(struct ptr*)NULL){
      excluir_tudo_lded();
      printf("A Lista foi Excluida!");
      }  
      getch();
      } 
