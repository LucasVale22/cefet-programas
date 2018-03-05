#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux,*maior,*menor,*ver;
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
void exluir_dado_lsec(){
     printf("Entre com o valor a ser excluido: ");
     scanf("%d",&dado);
     void f1(){
          if(lista->prox!=aux){
               lista=lista->prox;
               f1();
               }
          }
      void f2(){
           if((maior->prox!=lista)&&(maior->dado!=dado)){
                                                                    menor=maior;
                                                                    maior=maior->prox;
                                                                    f2();
                                                                    }
                         }
     if(lista==(struct ptr*)NULL)
          printf("Lista Vazia!");
     else{
          if(lista->prox==lista){
                                 if(lista->dado!=dado)
                                       printf("Não existe!");
                                 else{
                                      free(lista);
                                      lista=(struct ptr*)NULL;
                                      printf("O %d foi excluido.",dado);
                                      }
                                 }  
          else{
               if(lista->dado==dado){
                                     aux=lista;
                                     f1();
                                     lista->prox=aux->prox;
                                     aux->prox=(struct ptr*)NULL;
                                     free(aux);
                                     aux=(struct ptr*)NULL;
                                     lista=lista->prox;
                                     printf("O %d foi excluido.",dado);
                                     }
               else{
                    maior=lista;
                    f2();
                    if(dado!=maior->dado)
                         printf("Não existe!");
                    else{
                         menor->prox=maior->prox;
                         maior->prox=(struct ptr*)NULL;
                         free(maior);
                         maior=(struct ptr*)NULL;
                         menor=maior;
                         printf("O %d foi excluido.",dado);
                         }
                    }
               }
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
    exluir_dado_lsec();
    if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
    getch();
}                                          
