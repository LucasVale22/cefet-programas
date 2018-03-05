#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
       };
struct desc{
       int quant;
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
     lista->quant=0;
     }
void cria_ordem_ldecd(){
                 if(dado>=0){
                                lista->ult->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                lista->ult->prox->ant=lista->ult;
                                lista->ult=lista->ult->prox;
                                lista->ult->dado=dado;
                                lista->quant++;
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
void excluir_dado_ldecd(){
     int lim;
     void f1(){
           if((lista->quant<2*lim)&&(lista->prim->dado!=dado)){//a primeira condição evita uma procura infinita, já que nunca encontraria o elemento na lista circular
                    lista->prim=lista->prim->prox;
                    lista->quant++;
                    f1();
                    }
          }
     if(lista->quant==0)
           printf("Lista Vazia!");
     else{
          if(lista->prim==lista->ult){
                                      if(lista->prim->dado!=dado)
                                           printf("Nao Existe!");
                                      else{
                                           lista->prim->ant=(struct ptr*)NULL;
                                           lista->ult->prox=lista->prim->ant;
                                           lista->ult=lista->ult->prox;
                                           free(lista->prim);
                                           lista->prim=lista->ult;
                                           }
                                      }
          else{
               lim=lista->quant;
               f1();
               if(lista->prim->dado!=dado)
                   printf("Não Existe!");
               else{           
                         lista->prim->ant->prox=lista->prim->prox;
                         lista->prim->prox->ant=lista->prim->ant;
                         if(lista->prim->dado==lista->ult->dado){
                                    lista->prim=lista->prim->ant;
                                    lista->ult->ant=(struct ptr*)NULL;
                                    lista->ult->prox=lista->ult->ant;
                                    free(lista->ult);
                                    lista->ult=lista->prim;
                                    lista->prim=lista->ult->prox;
                                    }
                         else{
                         lista->prim->ant=(struct ptr*)NULL;
                         lista->prim->prox=lista->prim->ant;
                         free(lista->prim);
                         lista->prim=lista->ult->prox;
                             }
                             }
             }    
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
                 lista->quant++;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_ldecd();
       }
       else
           printf("Lista Vazia!"); 
      printf("Entre com o valor a ser excluido: ");
      scanf("%d",&dado);
      excluir_dado_ldecd();
      printf("Fim da Exclusao!\n"); 
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
      getch();
      }
         
