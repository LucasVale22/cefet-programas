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
                lista->ult->prox=(struct ptr*)NULL;
      } 
void excluir_dado_lded(){
     void f1(){
          if((lista->ult->prox!=(struct ptr*)NULL)&&(lista->ult->dado!=dado)){
                                                           lista->ult=lista->ult->prox;
                                                           f1();
                                                           }
          }
     void f2(){
          if(lista->ult->prox!=(struct ptr*)NULL){
                                       lista->ult=lista->ult->prox;
                                       f2();
                                       }
          }
     if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL))
                              printf("Lista Vazia!");
     else{
          if(lista->prim->prox==(struct ptr*)NULL){
                if(lista->prim->dado==dado){
                                            lista->ult=lista->ult->prox;
                                            free(lista->prim);
                                              }
                else
                     printf("Nao Existe!");
                     }
          else{
               if(lista->prim->dado==dado){
                      lista->prim=lista->prim->prox;
                      lista->prim->ant->prox=(struct ptr*)NULL;
                      free(lista->prim->ant);
                      lista->prim->ant=(struct ptr*)NULL;
                      }
               else{
                    if(lista->ult->dado==dado){
                      lista->ult=lista->ult->ant;
                      lista->ult->prox->ant=(struct ptr*)NULL;
                      free(lista->ult->prox);
                      lista->ult->prox=(struct ptr*)NULL;
                      }
                    else{
                           lista->ult=lista->prim;
                           f1();
                           if(lista->ult->dado!=dado)
                                                     printf("Nao Existe!");
                           else{
                                lista->ult->prox->ant=lista->ult->ant;
                                lista->ult->ant->prox=lista->ult->prox;
                                lista->ult->ant=(struct ptr*)NULL;
                                lista->ult->prox=(struct ptr*)NULL;
                                free(lista->ult);
                                lista->ult=lista->prim;
                                f2(); 
                                }   
                           }
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
     printf("Entre com valor a ser excluido: ");
     scanf("%d",&dado);
     excluir_dado_lded();
     printf("Fim da Exclusao!");
     if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
     getch();
      }
