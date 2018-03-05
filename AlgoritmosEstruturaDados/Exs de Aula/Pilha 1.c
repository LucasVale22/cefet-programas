#include <stdio.h>
struct ptr{
       char dado[10];
       struct ptr *prox;
       };
struct ptr *expressao,*p1,*p2;
void cria_ordem();
void empilha(char valor[10],struct ptr *aux);
void desempilha(char valor[10],struct ptr *aux);
void avalia();
void apaga();
main(){
       cria_ordem();
       p1=(struct ptr*)NULL;
       p2=p1;
       avalia();
       getch();
}
void avalia(){
     void repete2(){
          if(aux!=(struct ptr*)NULL){
                             resp=atoi(aux->dado);
                             if(resp!=0)
                                        empilha(aux->dado,p1);
                             else{
                                  if((strcmp(aux->dado,'*')==0)||(strcmp(aux->dado,'+')==0)
                                             empilha(aux->dado,p2);
                                  if(strcmp(aux->dado,')')==0){
                                                               desempilha(a,p1);
                                                               desempilha(operador,p1);
                                                               a1=atoi(a);
                                                               b1=atoi(b);
                                                               if(strcmp(operador,'+')==0)
                                                                                          valor=a1+b1;
                                                               else
                                                                   valor=a1*b1;
                                                               itoa(valor,cadeia,10);
                                                               empilha(cadeia,p1);
                                                               }
                                  }
                             aux=aux->prox;
                             repete2();
          }
          }
     struct ptr *aux;
     char a[10],b[10],operador[2],cadeia[10];
     int a1,b1,valor,resp;
     aux=expressao;          
     if(aux!=(struct ptr*)NULL){
          repete2();
          printf("Resposta = %s",cadeia);
          free(p1);
          p1=(struct ptr)NULL;
          }
}
void cria_ordem(){
     void repete(){
          if(dado!='.'){
                        aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                        aux=aux->prox;
                        aux->dado=dado;
                        repete();
          }            
     }
     struct ptr *aux;
     char dado[10];
     expressao=(struct ptr*)NULL;
     printf("Entre com a expressão. O (.) indica o término.");
     scanf("%s",&dado);
     if(dado!='.'){
                   expressao=(struct ptr*)malloc(sizeof(struct ptr));
                   expressao->dado=dado;
                   printf("Proximo...\n");
                   scanf("%s",&dado);
                   aux=expressao;
                   repete();
                   aux->prox=(struct ptr*)NULL;
                   aux=aux->prox;
                   }
     else
         printf("Pilha vazia!");
}
void empilha(char valor[10],struct ptr *aux){
   
     }
                   
                   
     
       
