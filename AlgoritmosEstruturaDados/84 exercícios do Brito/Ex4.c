#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*ver;
void mostra(){
     if(ver->prox!=lista){
                          printf("\t%d",ver->dado);
                          ver=ver->prox;
                          mostra();
                          }
     else
         printf("\t%d",ver->dado);
         }
void insere_ordenado_lsec(int dado){
     struct ptr *aux,*maior,*menor;
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
                                    while(aux->prox!=lista->prox)
                                       aux=aux->prox;                          
                                    aux->prox=lista;
                                    aux= aux=(struct ptr*)NULL;
                                    }
          else{
               maior=lista;
               while((maior->dado<dado)&&(maior->prox!=lista)){
                                                               menor=maior;
                                                               maior=maior->prox;
                                                               }
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
     int dado;
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     lista=(struct ptr*)NULL;
     while(dado>=0){
              insere_ordenado_lsec(dado);
              printf("Entre com o valor: ");
               scanf("%d",&dado);
               }
              }
main(){
     cria_cresc_lsec();
     ver=lista;
       mostra();
     printf("\nFim da Lista!");
     getch();
     }        
