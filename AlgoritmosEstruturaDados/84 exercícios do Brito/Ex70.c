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
inserir_ordenado_ldecd(){
                         void f1(){
                              if(lista->prim->prox->dado<dado){
                                                lista->prim=lista->prim->prox;
                                                f1();
                                                }
                              }
                         if((lista->prim==(struct ptr*)NULL)&&(lista->ult==(struct ptr*)NULL)){
                                                  lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                                                  lista->ult=lista->prim;
                                                  lista->prim->dado=dado;
                                                  lista->prim->ant=lista->prim;
                                                  lista->ult->prox=lista->ult;
                                                  }
                         else{
                              if(lista->prim->dado>dado){
                                                         lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                                                         lista->prim->dado=dado;
                                                         lista->prim->prox=lista->ult->prox;
                                                         lista->prim->prox->ant=lista->prim;
                                                         lista->ult->prox=lista->prim;
                                                         lista->prim->ant=lista->ult;
                                                         }
                              else{
                                   if(lista->ult->dado<dado){
                                                             lista->ult=(struct ptr*)malloc(sizeof(struct ptr));
                                                             lista->ult->dado=dado;
                                                             lista->ult->ant=lista->prim->ant;
                                                             lista->ult->ant->prox=lista->ult;
                                                             lista->prim->ant=lista->ult;
                                                             lista->ult->prox=lista->prim;
                                                             }
                                   else{
                                        f1();
                                        lista->ult->prox->ant=lista->prim->prox;
                                        lista->prim->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                        lista->prim->prox->ant=lista->prim;
                                        lista->prim=lista->prim->prox;
                                        lista->prim->dado=dado;
                                        lista->prim->prox=lista->ult->prox->ant;
                                        lista->prim->prox->ant=lista->prim;
                                        lista->prim=lista->ult->prox;
                                        lista->ult->prox->ant=lista->ult;
                                        }
                                   } 
                              }                   
}
cria_cresc_ldecd(){
                   if(dado>=0){
                                  inserir_ordenado_ldecd();
                                  printf("Entre com o valor: ");
                                  scanf("%d",&dado);
                                  cria_cresc_ldecd(); 
                                  } 
            }
main(){
      printf("Entre com o valor: ");
      scanf("%d",&dado);
      lista_vazia();
      cria_cresc_ldecd();
      printf("\nFim da Lista!"); 
      if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }
      getch();
      }
