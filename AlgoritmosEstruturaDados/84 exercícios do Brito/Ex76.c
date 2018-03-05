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
void cria_cresc_lse(){
     if(dado>=0){
                 inserir_ordenado_lse();
                 printf("Entre com o valor: ");
                 scanf("%d",&dado); 
                 cria_cresc_lse();
     }
     else
        printf("\nFim da Lista!\n"); 
}
main(){
      aux=(struct ptr*)NULL;
      printf("Entre com o valor: ");
      scanf("%d",&dado); 
      cria_cresc_lse();
      ver=lista;
       mostra();
      getch();
      }
      
