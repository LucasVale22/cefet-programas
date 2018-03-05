#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *ant,*prox;
       };
struct ptr *lista,*aux,*ver;
int dado;
void mostra(){
     if(ver!=(struct ptr*)NULL){
                     printf("\t%d",ver->dado);
                     ver=ver->prox;
                     mostra();
                     }
     }
void cria_ordem_lde(){
      if(dado>=0){
                  aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                  aux->prox->ant=aux;
                  aux=aux->prox;
                  aux->prox=(struct ptr*)NULL;
                  aux->dado=dado;
                  printf("Entre com um valor: ");
                  scanf("%d",&dado);
                  cria_ordem_lde();
     }
     else{
          aux=(struct ptr*)NULL;
          printf("\nFim da Lista!\n");
          }
}
main(){
       printf("Entre com um valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       aux=lista;
       if(dado>=0){
                   lista=(struct ptr*)malloc(sizeof(struct ptr));
                   lista->dado=dado;
                   lista->ant=(struct ptr*)NULL;
                   lista->prox=lista->ant;
                   aux=lista;
                   printf("Entre com um valor: ");
                   scanf("%d",&dado);
                   cria_ordem_lde();
                   }
       else
            printf("Lista Vazia!");
       ver=lista;
       mostra();
       getch();
}
