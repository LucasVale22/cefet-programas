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
void cria_ordem_lsec(){
     int dado;
     struct ptr *aux;
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 while(dado>=0){
                                aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                aux=aux->prox;
                                aux->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                }
                 aux->prox=lista;
                 aux=(struct ptr*)NULL;
                 printf("Fim da Lista!");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("Lista Vazia!");
          }
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
                                    aux=(struct ptr*)NULL;
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
main(){
       int dado;
       cria_ordem_lsec();
       printf("Entre com o valor a ser inserido na ordem: ");
       scanf("%d",&dado);
       insere_ordenado_lsec(dado);
       printf("\nFim da Nova Lista!");
       ver=lista;
       mostra();
       getch();
       }
