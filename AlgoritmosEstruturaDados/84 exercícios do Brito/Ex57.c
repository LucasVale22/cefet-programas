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
void cria_ordem_lded(){
     if(dado>=0){
                 lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->ult->prox->dado=dado;
                 lista->ult->prox->ant=lista->ult;
                 lista->ult=lista->ult->prox;
                 printf("Entre com valor: ");
                 scanf("%d",&dado);
                 cria_ordem_lded();
                 }
      else      
                lista->ult->prox=(struct ptr *)NULL;
      } 
void inserir_ordenado_lded(){
     void f1(){
          if(lista->ult->dado<dado){
                                    lista->prim=lista->ult;
                                    lista->ult=lista->ult->prox;
                                    f1();
                                                }
          }
     void f2(){
          if(lista->ult->prox!=(struct ptr*)NULL){
                                       lista->ult=lista->ult->prox;
                                       f2();
                                       }
          if(lista->prim->ant!=(struct ptr*)NULL){
                                       lista->prim=lista->prim->ant;
                                       f2();
                                       }
          }
     if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL)){
                              lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                              lista->ult=lista->prim;
                              lista->prim->ant=(struct ptr*)NULL;
                              lista->prim->prox=lista->prim->ant;
                              lista->prim->dado=dado;
                              }
     else{
          if(lista->prim->dado>dado){
                                     lista->prim->ant=(struct ptr*)malloc(sizeof(struct ptr));  
                                     lista->prim->ant->prox=lista->prim;
                                     lista->prim=lista->prim->ant;
                                     lista->prim->dado=dado;
                                     lista->prim->ant=(struct ptr*)NULL;
                                     }
          else{
               if(lista->ult->dado<dado){
                                     lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));  
                                     lista->ult->prox->ant=lista->ult;
                                     lista->ult=lista->ult->prox;
                                     lista->ult->dado=dado;
                                     lista->ult->prox=(struct ptr*)NULL;
                                     }
               else{
                    lista->ult=lista->prim->prox;
                    f1();
                    lista->prim->prox=(struct ptr*)malloc(sizeof(struct ptr));
                    lista->prim->dado=dado;  
                    lista->ult->ant=lista->prim->prox;
                    lista->prim->prox->ant=lista->prim;
                    lista->ult->ant->prox=lista->ult;
                    f2();
                    }
               }
          }
     }     
main(){
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
             cria_ordem_lded();
             }
     else
         printf("Lista Vazia!");
     printf("Fim da Lista!");
     printf("Entre com valor a ser inserido: ");
     scanf("%d",&dado);
     inserir_ordenado_lded();
     printf("Fim da Nova Lista!");
     if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
     getch();
      }
