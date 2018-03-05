#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
       };
struct ptr *lista,*ver;
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
                 printf("Fim da Lista!\n");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("Lista Vazia!");
          }
}
void excluir_tudo_ldec(){
     struct ptr *aux;
     aux=lista->ant;
     while(aux!=lista){
                          aux->prox=(struct ptr*)NULL;
                          aux->ant->prox=lista;
                          lista->ant=aux->ant;
                          aux->ant=aux->prox;
                          free(aux);
                          aux=lista->ant;
                          }
     lista=(struct ptr*)NULL;
     aux->ant=lista;
     aux->prox=lista;
     free(aux);
     aux=lista;
}
main(){
       cria_ordem_ldec();
       excluir_tudo_ldec();
       printf("A lista foi excluida!");
       getch();
       }       
