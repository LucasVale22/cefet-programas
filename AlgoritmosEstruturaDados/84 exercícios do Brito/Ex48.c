#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
       };
struct ptr *lista,*aux;;
int dado;
void cria_ordem_ldec(){
     if(dado>=0){
                    aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                    aux->prox->ant=aux;
                    aux=aux->prox;
                    aux->dado=dado;
                    printf("Entre com o valor: ");
                    scanf("%d",&dado);
                    cria_ordem_ldec();
                    }
     else{
          aux->prox=lista;
          lista->ant=aux;
          aux=(struct ptr*)NULL;
          printf("Fim da Lista!");
          }
}
void excluir_tudo_ldec(){
     if(lista->ant!=lista->prox){
                          aux->prox=(struct ptr*)NULL;
                          aux->ant->prox=lista;
                          lista->ant=aux->ant;
                          aux->ant=aux->prox;
                          free(aux);
                          aux=lista->ant;
                          excluir_tudo_ldec();
                          }
     else{
     lista=(struct ptr*)NULL;
     aux->ant=lista;
     aux->prox=lista;
     free(aux);
     aux=lista;
     }
}
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_ldec();
                 }
       else
          printf("Lista Vazia!");
       aux=lista->ant;
       if(lista!=(struct ptr*)NULL){
                         excluir_tudo_ldec();
                         printf("Fim da Exclusao!");
                         }
       getch();
       }
