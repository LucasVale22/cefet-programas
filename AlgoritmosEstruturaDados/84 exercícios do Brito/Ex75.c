#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox;
       };
struct ptr *lista,*aux,*maior,*menor,*ver;
int dado;
void mostra(){
     if(ver!=(struct ptr*)NULL){
                     printf("\t%d",ver->dado);
                     ver=ver->prox;
                     mostra();
                     }
     }
void cria_ordem_lse(){
     if(dado>=0){
               aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
               aux=aux->prox;
               aux->dado=dado;
               aux->prox=(struct ptr*)NULL;
               printf("Entre com o valor: ");
               scanf("%d",&dado);
               cria_ordem_lse();
               }
     else{
         aux=(struct ptr*)NULL;
         printf("\nFim da Lista!\n");
         }
         }
void inserir_ordenado_lse(){
     void f1(){
          if((maior->prox!=(struct ptr*)NULL)&&(maior->dado<dado)){
                                   menor=maior;
                                   maior=maior->prox;
                                   f1();
                                   }
          }
          aux=(struct ptr*)malloc(sizeof(struct ptr));
          aux->dado=dado;
          aux->prox=(struct ptr*)NULL;
          if(lista==(struct ptr*)NULL){
                            lista=aux;
                            aux=aux->prox;
                            }
          else{
               if(lista->dado>dado){
                                    aux->prox=lista;
                                    lista=aux;
                                    aux=(struct ptr*)NULL;
                                    }
               else{
                    maior=lista;
                    f1();
                    if(maior->dado<dado){
                                         maior->prox=aux;
                                         aux=(struct ptr*)NULL;
                                         menor=aux;
                                         maior=aux;
                                         }
                    else{
                         menor->prox=aux;
                         aux->prox=maior;
                         aux=(struct ptr*)NULL;
                         menor=aux;
                         maior=aux;
                         }
                    }
               }
}
main(){
       aux=(struct ptr*)NULL;
       printf("Entre com o valor: ");
       scanf("%d",&dado);
       if(dado>=0){
                   lista=(struct ptr*)malloc(sizeof(struct ptr));
                   lista->dado=dado;
                   lista->prox=(struct ptr*)NULL;
                   aux=lista;
                   printf("Entre com o valor: ");
                   scanf("%d",&dado);
                   cria_ordem_lse();
                   }
       else{
            lista=(struct ptr*)NULL;
            printf("Lista Vazia!");
            }
       printf("Entre com o valor a ser inserido: ");
       scanf("%d",&dado);
       inserir_ordenado_lse();
       printf("\nFim da Nova Lista!\n");
       ver=lista;
       mostra();
       getch();
       }
       
                         
                            
