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
                 printf("Fim da Lista!\n");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("Lista Vazia!");
          }
}
main(){
       cria_ordem_lsec();
       ver=lista;
       mostra();
       getch();
       }
     
