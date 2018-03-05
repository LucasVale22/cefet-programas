#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux1,*aux2,*ver;
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
void cria_inv_lsec(){      
                if(dado>=0){
                               aux1=(struct ptr*)malloc(sizeof(struct ptr));
                               aux1->dado=dado;
                               aux1->prox=lista;
                               aux2->prox=aux1;
                               lista=aux1;
                               printf("Entre com o dado: ");
                               scanf("%d",&dado);
                               cria_inv_lsec();
                               }
                else{
                aux1=(struct ptr*)NULL;
                aux2=aux1;
                printf("\nFim da lista!");
                }
}
main(){
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
                cria_inv_lsec();
                }
      else
         printf("\nLista Vazia!");
      if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
      getch();
      } 
  
     
