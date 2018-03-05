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
void cria_inv_lsec(){
     int dado;
     struct ptr *aux1,*aux2;
     printf("Entre com o dado: ");
     scanf("%d",&dado);
     lista=(struct ptr*)NULL;
     if(dado>=0){
                lista=(struct ptr*)malloc(sizeof(struct ptr));
                lista->dado=dado;
                lista->prox=lista;
                aux2=lista;
                printf("Entre com o dado: ");
                scanf("%d",&dado);
                while(dado>=0){
                               aux1=(struct ptr*)malloc(sizeof(struct ptr));
                               aux1->dado=dado;
                               aux1->prox=lista;
                               aux2->prox=aux1;
                               lista=aux1;
                               printf("Entre com o dado: ");
                               scanf("%d",&dado);
                               }
                aux2=lista;
                aux1=(struct ptr*)NULL;
                aux2=aux1;
                printf("\nFim da lista!\n");
                }
     else
         printf("\nLista Vazia!");
}
main(){
      cria_inv_lsec();
      if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
      getch();
      } 
  
     
