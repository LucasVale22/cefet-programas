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
void cria_ordem_lsec(){ //criei uma lista para verificar o funcionamento da função exluir_dado_lsec()... 
     int dado;
     struct ptr *aux;
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->dado=dado;
                 aux=lista;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 while(dado>=0){
                                aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                aux=aux->prox;
                                aux->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                }
                 aux->prox=lista;
                 aux=(struct ptr*)NULL;
                 printf("\nFim da Lista!\n");
                 }
     else{
          lista=(struct ptr*)NULL;
          aux=lista;
          printf("Lista Vazia!");
          }
}
void exluir_dado_lsec(){
     int dado;    
     struct ptr *aux,*maior,*menor;
     printf("Entre com o valor a ser excluido: ");
     scanf("%d",&dado);
     if(lista==(struct ptr*)NULL)
          printf("Lista Vazia!");
     else{
          if(lista->prox==lista){
                                 if(lista->dado!=dado)
                                       printf("Não existe!");
                                 else{
                                      free(lista);
                                      lista=(struct ptr*)NULL;
                                      }
                                 }  
          else{
               if(lista->dado==dado){
                                     aux=lista;
                                     while(lista->prox!=aux)
                                         lista=lista->prox;
                                     lista->prox=aux->prox;
                                     aux->prox=(struct ptr*)NULL;
                                     free(aux);
                                     aux=(struct ptr*)NULL;
                                     lista=lista->prox;
                                     }
               else{
                    maior=lista;
                    while((maior->prox!=lista)&&(maior->dado!=dado)){
                                                                    menor=maior;
                                                                    maior=maior->prox;
                                                                    }
                    if(dado!=maior->dado)
                         printf("Não existe!");
                    else{
                         menor->prox=maior->prox;
                         maior->prox=(struct ptr*)NULL;
                         free(maior);
                         maior=(struct ptr*)NULL;
                         menor=maior;
                         }
                    }
               }
          }   
}                                  
main(){
    cria_ordem_lsec();
    exluir_dado_lsec();
    if(lista!=(struct ptr*)NULL){
                      ver=lista;
                      mostra();
    }
        printf("\nFim da Exclusão!");
    getch();
}                                          
