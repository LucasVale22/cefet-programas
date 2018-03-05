#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *ant,*prox;
       };
struct ptr *lista,*aux,*maior,*ver;
int dado;
void mostra(){
     if(ver!=(struct ptr*)NULL){
                     printf("\t%d",ver->dado);
                     ver=ver->prox;
                     mostra();
                     }
     }
void inserir_ordenado_lde(){
     void f1(){
          if((maior->dado<dado)&&(maior->prox!=(struct ptr*)NULL)){
                                                       maior=maior->prox;
                                                       f1();
                                                       }
          }
     aux=(struct ptr*)malloc(sizeof(struct ptr));
     aux->ant=(struct ptr*)NULL;
     aux->prox=aux->ant;
     aux->dado=dado;
     if(lista==(struct ptr*)NULL){
                       lista=aux;
                       aux=(struct ptr*)NULL;
                       }
     else{
          if(aux->dado<lista->dado){
                                    lista->ant=aux;
                                    aux->prox=lista;
                                    lista=aux;
                                    aux=(struct ptr*)NULL;
                                    }
          else{
               maior=lista;
               f1();
               if(maior->dado>dado){
                                    maior->ant->prox=aux;
                                    aux->prox=maior;
                                    aux->ant=maior->ant;
                                    maior->ant=aux;
                                    aux=(struct ptr*)NULL;
                                    }
               else{
                     maior->prox=aux;
                     aux->ant=maior;
                     aux=(struct ptr*)NULL;
                     maior=aux;
                    }
               }
          }
}
void cria_cresc_lde(){
     if(dado>=0){
              inserir_ordenado_lde();
              printf("Entre com um valor: ");
              scanf("%d",&dado);   
              cria_cresc_lde();
              }
     }
main(){
       lista=(struct ptr*)NULL;
       printf("Entre com um valor: ");
       scanf("%d",&dado);
       cria_cresc_lde();
       printf("\nFim da Lista!\n");
       ver=lista;
       mostra();
       getch();
       }
