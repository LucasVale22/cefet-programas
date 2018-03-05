#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux,*maior,*menor;
int dado;
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
void excluir_tudo_lsec(){
     void f1(){
          if(aux->prox!=lista){
              aux=aux->prox;
              f1();
              }
          else{
               aux->prox=(struct ptr*)NULL;
               aux=lista;
               }
          }
     void f2(){
          if(aux->prox!=(struct ptr*)NULL){
                          lista=lista->prox;
                          aux->prox=(struct ptr*)NULL;
                          free(aux);
                          aux=lista;
                          }
          else{
               lista=aux->prox;
               free(aux);
               aux=lista;
          }
     }
     aux=lista;
     f1();
     f2();  
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
                       excluir_tudo_lsec();
                       printf("A Lista foi Excluida!");
                       }
     getch();
    }   
