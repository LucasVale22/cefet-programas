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
void cria_ordem_lde(){
      if(dado>=0){
                  aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                  aux->prox->ant=aux;
                  aux=aux->prox;
                  aux->prox=(struct ptr*)NULL;
                  aux->dado=dado;
                  printf("Entre com um valor: ");
                  scanf("%d",&dado);
                  cria_ordem_lde();
     }
     else{
          aux=(struct ptr*)NULL;
          printf("\nFim da Lista!\n");
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
main(){
      printf("Entre com um valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       aux=lista;
       if(dado>=0){
                   lista=(struct ptr*)malloc(sizeof(struct ptr));
                   lista->dado=dado;
                   lista->ant=(struct ptr*)NULL;
                   lista->prox=lista->ant;
                   aux=lista;
                   printf("Entre com um valor: ");
                   scanf("%d",&dado);
                   cria_ordem_lde();
                   }
       else
            printf("Lista Vazia!");
       printf("Entre com um valor a ser inserido: ");
       scanf("%d",&dado);
       inserir_ordenado_lde();
       printf("\nFim da Nova Lista!\n");
       ver=lista;
       mostra();
       getch();
       }
