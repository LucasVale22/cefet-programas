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
void cria_ordem_lsec(){
                 if(dado>=0){
                                aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                aux=aux->prox;
                                aux->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                cria_ordem_lsec();
                                }
                 else{
                 aux->prox=lista;
                 aux=(struct ptr*)NULL;
                 printf("Fim da Lista!");
                 }  
}
main(){
     lista=(struct ptr*)NULL;
     aux=lista;
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_lsec();
                 }
     else
          printf("Lista Vazia!");
     if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
     getch();
       }
     
