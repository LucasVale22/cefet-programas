#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
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
void cria_ordem_ldec(){
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
                                aux->prox->ant=aux;
                                aux=aux->prox;
                                aux->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                }
                 aux->prox=lista;
                 lista->ant=aux;
                 aux=(struct ptr*)NULL;
                 printf("\nFim da Lista\n!");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("\nLista Vazia!");
          }
}
main(){
       cria_ordem_ldec();
       if(lista!=(struct ptr*)NULL){
                         ver=lista;
                         mostra();
       }
       getch();
       }
