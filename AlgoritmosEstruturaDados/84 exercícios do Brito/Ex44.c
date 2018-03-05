#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
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
       if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
       getch();
       }
