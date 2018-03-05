#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
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
void cria_inv_lse(){
     if(dado>=0){
                 aux=(struct ptr*)malloc(sizeof(struct ptr));
                 aux->dado=dado;
                 aux->prox=lista;
                 lista=aux;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_inv_lse();
     }
     else{
         aux=(struct ptr*)NULL;
         printf("\nFim da Lista!\n");
         }
     }
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       if(dado>=0)
                  cria_inv_lse();
       else
           printf("Lista Vazia!");
       ver=lista;
       mostra();
       getch();
       }
