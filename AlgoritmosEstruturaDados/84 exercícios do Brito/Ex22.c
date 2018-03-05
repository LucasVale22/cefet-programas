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
void cria_cresc_lded(){
     int dado;
     void inserir_ordenado_lded(int dado){
     if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL)){
                              lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                              lista->prim->dado=dado;
                              lista->ult=lista->prim;
                              lista->prim->ant=(struct ptr*)NULL;
                              lista->prim->prox=lista->prim->ant;
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
                    while(lista->ult->dado<dado){
                                                lista->prim=lista->ult;
                                                lista->ult=lista->ult->prox;
                                                }
                    lista->prim->prox=(struct ptr*)malloc(sizeof(struct ptr));
                    lista->prim->prox->dado=dado;  
                    lista->ult->ant=lista->prim->prox;
                    lista->prim->prox->ant=lista->prim;
                    lista->ult->ant->prox=lista->ult;
                    while(lista->ult->prox!=(struct ptr*)NULL)
                                                    lista->ult=lista->ult->prox;
                    while(lista->prim->ant!=(struct ptr*)NULL)
                                                    lista->prim=lista->prim->ant;
                    }
               }
          }
     }
     lista_vazia();
     printf("Entre com valor a ser inserido: ");
     scanf("%d",&dado); 
     while(dado>=0){
                   inserir_ordenado_lded(dado);
                   printf("Entre com valor a ser inserido: ");
                   scanf("%d",&dado);
                   }
}
main(){
       cria_cresc_lded();
       printf("Fim da Nova Lista!");
       ver=lista->prim;
       mostra();
       getch();
      } 
