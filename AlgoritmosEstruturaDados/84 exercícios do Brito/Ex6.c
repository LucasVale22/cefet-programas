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
                 printf("\nFim da Lista!\n");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("Lista Vazia!");
          }
}
void excluir_tudo_lsec(){
     struct ptr *aux;
     aux=lista;
     while(aux->prox!=lista)
                       aux=aux->prox;
     aux->prox=(struct ptr*)NULL;
     aux=lista;
     while(lista!=(struct ptr*)NULL){
                          lista=lista->prox;
                          aux->prox=(struct ptr*)NULL;
                          free(aux);
                          aux=lista;
                          }
}
main(){
       cria_ordem_lsec();
       excluir_tudo_lsec();
       printf("A lista foi Excluida!");
       getch();
       }                         
                       
     
