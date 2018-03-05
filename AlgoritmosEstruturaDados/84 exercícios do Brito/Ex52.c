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
void inserir_ordenado_lsed(){
      void f1(){
           if(lista->ult->prox!=(struct ptr*)NULL){
               lista->ult=lista->ult->prox;
               f1();
               }
           }
      void f2(){
           if((lista->ult->prox->dado<dado)){
               lista->ult=lista->ult->prox;
               f2();
               }
           }
           
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
                                      f1();
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
                f2();     
                aux=(struct ptr*)malloc(sizeof(struct ptr));
                aux->dado=dado;
                aux->prox=lista->ult->prox;
                lista->ult->prox=aux;
                aux=(struct ptr*)NULL;
                f1();
                }
           }
      }
}
void cria_cresc_lsed(){
     if(dado>=0){
            inserir_ordenado_lsed();
            printf("Entre com o valor: ");
            scanf("%d",&dado);
            cria_cresc_lsed(); 
            }
     else
         printf("Fim da Lista!");
}      
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista_vazia();
       if(dado>=0)
          cria_cresc_lsed();        
       else
         printf("Lista Vazia!"); 
       if(lista->prim!=(struct ptr*)NULL){
                              ver=lista->prim;
                              mostra();
      }    
       getch();
       }
