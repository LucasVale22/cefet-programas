#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux,*ver;
int dado;
void mostra(){
     if(ver->prox!=lista){
                          printf("\t%d",ver->dado);
                          ver=ver->prox;
                          mostra();
                          }
     else
         printf("\t%d",ver->dado);
         }
void insere_ordenado_lsec(){
     struct ptr *maior,*menor;
     void f1(){
          if(aux->prox!=lista->prox){
                aux=aux->prox;
                f1();
                }  
          }
     void f2(){
          if((maior->dado<dado)&&(maior->prox!=lista)){
                    menor=maior;
                    maior=maior->prox;
                    f2();
                    }
               }
     aux=(struct ptr*)malloc(sizeof(struct ptr));
     aux->dado=dado;
     if(lista==(struct ptr*)NULL){
                       lista=aux;
                       aux=(struct ptr*)NULL;
                       lista->prox=lista;
                       }
     else{
          if(aux->dado<lista->dado){
                                    aux->prox=lista;
                                    lista=aux;
                                    aux=aux->prox;
                                    f1();
                                    aux->prox=lista;
                                    aux=(struct ptr*)NULL;
                                    }
          else{
               maior=lista;
               f2();
               if(maior->dado<dado){
                                    maior->prox=aux;
                                    aux->prox=lista;
                                    aux=(struct ptr*)NULL;
                                    menor=aux;
                                    maior=aux;
                                    }
               else{
                    menor->prox=aux;
                    aux->prox=maior;
                    aux=(struct ptr*)NULL;
                    menor=aux;
                    maior=aux;
                    }
               }
          }
}
void cria_cresc_lsec(){
     if(dado>=0){
              insere_ordenado_lsec();
              printf("Entre com o valor: ");
              scanf("%d",&dado);
              cria_cresc_lsec();
               }
              }
main(){
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     lista=(struct ptr*)NULL;
     cria_cresc_lsec();
     printf("\nFim da Lista!");
     if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
     getch();
     }     
