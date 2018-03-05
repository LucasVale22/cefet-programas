#include <stdio.h>
struct ptr{
       int dado;
       struct ptr *prox,*ant;
       };
struct desc{
       struct ptr *prim,*ult;
       };
struct desc *lista;
void lista_vazia(){
     lista=(struct desc*)malloc(sizeof(struct desc));
     lista->prim=(struct ptr*)NULL;
     lista->ult=lista->prim;
     }
void cria_inv_ldecd(){
     int dado;
     lista_vazia();
     printf("Entre com o valor: ");
     scanf("%d",&dado);
     if(dado>=0){
                 lista->prim=(struct ptr*)malloc(sizeof(struct ptr));
                 lista->ult=lista->prim;
                 lista->prim->dado=dado;
                 printf("Entre com o valor: ");
                 scanf("%d",&dado);
                 while(dado>=0){
                                lista->prim->ant=(struct ptr*)malloc(sizeof(struct ptr));
                                lista->prim->ant->prox=lista->prim;
                                lista->prim=lista->prim->ant;
                                lista->prim->dado=dado;
                                printf("Entre com o valor: ");
                                scanf("%d",&dado);
                                }
                 lista->prim->ant=lista->ult;
                 lista->ult->prox=lista->prim;
                 }
     else
         printf("Lista Vazia!");
}
excluir_tudo_ldecd(){
                     while(lista->prim->ant!=lista->ult->prox){
                             lista->ult->prox=lista->prim->prox;
                             lista->ult->prox->ant=lista->ult;
                             lista->prim->ant=(struct ptr*)NULL;
                             lista->prim->prox=lista->prim->ant;
                             free(lista->prim);
                             lista->prim=lista->ult->prox;
                             }
                     lista->prim->ant=(struct ptr*)NULL;
                     lista->prim->prox=lista->prim->ant;
                     free(lista->ult);
                     lista->prim=(struct ptr*)NULL;
                     lista->ult=lista->prim;               
}
main(){
      cria_inv_ldecd();
      printf("Fim da Lista!\n"); 
      if(lista->prim!=(struct ptr*)NULL){
                              excluir_tudo_ldecd();
                              printf("A Lista foi Excluida!");
                              }
      getch();
      }
