#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
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
void cria_ordem_ldec(){
     if(dado>=0){
                    aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                    aux->prox->ant=aux;
                    aux=aux->prox;
                    aux->dado=dado;
                    printf("Entre com o valor: ");
                    scanf("%d",&dado);
                    cria_ordem_ldec();
                    }
     else{
          aux->prox=lista;
          lista->ant=aux;
          aux=(struct ptr*)NULL;
          printf("Fim da Lista!");
          }
}
void insere_ordenado_ldec(int dado){
      void f2(){
           if((maior->dado<dado)&&(maior->prox!=lista)){
                                                        menor=maior;
                                                        maior=maior->prox;
                                                        f2();
           }
      }
     aux=(struct ptr*)malloc(sizeof(struct ptr));
     aux->dado=dado;
     if(lista==(struct ptr*)NULL){
                       lista=aux;
                       aux=(struct ptr*)NULL;
                       lista->prox=lista;
                       lista->ant=lista;
                       }
     else{
          if(aux->dado<lista->dado){
                                    aux->prox=lista;
                                    lista=aux;
                                    aux->ant=aux->prox->ant;
                                    aux->prox->ant=aux;
                                    aux->ant->prox=lista;
                                    aux= aux=(struct ptr*)NULL;
                                    }
          else{
               maior=lista;
               f2();
               if(maior->dado<dado){
                                    maior->prox=aux;
                                    aux->prox=lista;
                                    aux->ant=maior;
                                    lista->ant=aux;
                                    aux=(struct ptr*)NULL;
                                    menor=aux;
                                    maior=aux;
                                    }
               else{
                    menor->prox=aux;
                    aux->prox=maior;
                    aux->ant=menor;
                    maior->ant=aux;
                    aux=(struct ptr*)NULL;
                    menor=aux;
                    maior=aux;
                    }
               }
          }
}
main(){
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       lista=(struct ptr*)NULL;
       if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 cria_ordem_ldec();
                 }
       else
          printf("Lista Vazia!");
       printf("Entre com o valor a ser inserido: ");
       scanf("%d",&dado);
       insere_ordenado_ldec(dado);
       printf("Fim da Nova Lista!");
       if(lista!=(struct ptr*)NULL){
                        ver=lista;
                        mostra();
                        }
       getch();
       }
