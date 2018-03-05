#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *ant,*prox;
       };
struct ptr *lista,*aux;
int dado;
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
void excluir_tudo_lde(){
     if(lista->prox!=(struct ptr*)NULL){
                       lista=aux->prox;
                       aux->prox=(struct ptr*)NULL;
                       lista->ant=aux->prox;
                       free(aux);
                       aux=lista;
                       excluir_tudo_lde();
                       }
     else{
          aux=lista->prox;
          free(lista);
          lista=aux;
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
       if(lista!=(struct ptr*)NULL){
                         aux=lista;
                         excluir_tudo_lde();
                         printf("\nA Lista foi Excluida.\n");
                         }
       getch();
}
