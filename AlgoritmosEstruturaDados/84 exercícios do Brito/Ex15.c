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
void cria_ordem_lsed(){//usado para verificar o funcionamento de inserir_ordenado_lsed()...
     int dado;
     lista_vazia();
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->prim->dado=dado;
                 lista->ult=lista->prim;           
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 while(dado>=0){
                            lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));    
                            lista->ult=lista->ult->prox;
                            lista->ult->dado=dado;
                            printf("Entre com o valor: ");
                            scanf("%d",&dado);
                            }
                lista->ult->prox=(struct ptr*)NULL; 
                }
     else
         printf("Lista Vazia!");
}
void inserir_ordenado_lsed(int dado){
      struct ptr *aux;
      if((lista->ult==(struct ptr*)NULL)&&(lista->prim==(struct ptr*)NULL)){
                             lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                             lista->prim->dado=dado;
                             lista->ult=lista->prim;
                             lista->ult->prox=(struct ptr*)NULL;
                             }
      else{
           if(lista->prim->dado>dado){
                                      lista->ult=(struct ptr*)malloc(sizeof(struct ptr));
                                      lista->ult->dado=dado;
                                      lista->ult->prox=lista->prim;
                                      lista->prim=lista->ult;
                                      while(lista->ult->prox!=(struct ptr*)NULL)
                                            lista->ult=lista->ult->prox;
                                      }
           else{
                if(lista->ult->dado<dado){
                                          lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                          lista->ult=lista->ult->prox;
                                          lista->ult->dado=dado;
                                          lista->ult->prox=(struct ptr*)NULL;
                                          }
                else{
                lista->ult=lista->prim;
                while((lista->ult->prox->dado<dado))
                     lista->ult=lista->ult->prox;     
                aux=(struct ptr*)malloc(sizeof(struct ptr));
                aux->dado=dado;
                aux->prox=lista->ult->prox;
                lista->ult->prox=aux;
                aux=(struct ptr*)NULL;
                while(lista->ult->prox!=(struct ptr*)NULL)
                     lista->ult=lista->ult->prox;
                }
           }
      }
}
main(){
       int dado;
       cria_ordem_lsed();
       printf("Entre com o valor a ser inserido: ");
       scanf("%d",&dado);
       inserir_ordenado_lsed(dado);
       printf("Fim da Nova Lista!");
       ver=lista->prim;
       mostra();
       getch();
       }
