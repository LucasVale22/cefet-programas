#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux;
int dado;
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
         printf("Fim da Lista!");
         }
     }
void excluir_tudo_lse(){
     if(lista!=(struct ptr*)NULL){
                       lista=lista->prox;
                       aux->prox=(struct ptr*)NULL;
                       free(aux);
                       aux=lista;
                       excluir_tudo_lse();
     }
     else
         printf("\nA lista foi excluida!");
         }
                          
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       if(dado>=0)
                  cria_inv_lse();
       else
           printf("Lista Vazia!");
       aux=lista;
       excluir_tudo_lse();
       getch();
       }
