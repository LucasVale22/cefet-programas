#include <stdio.h>
struct ptr{
       char dado[10];
       struct ptr *prox;
       };
struct ptr *expressao,*p1,*p2,*p3;
void cria_ordem();
void empilha(char valor[10],struct ptr *p);
void desempilha(char valor[10],struct ptr *p);
void avalia();
void apaga();
main(){
       cria_ordem();
       p1=(struct ptr*)NULL;
       p2=p1;
       p3=p2;
       avalia();
       getch();
}
void avalia(){
     struct ptr *aux;
     char operador[2],valor[10];
     int resp;
     void mostra(){
          if(aux!=(struct ptr*)NULL){
                          printf("%s",aux->dado);
                          aux=aux->prox;
                          desempilha(aux->dado,p3);
                          mostra();
          }
     }
     void repete2(){
          if(aux!=(struct ptr*)NULL){
                             resp=atoi(aux->dado);
                             if(resp!=0){
                                        empilha(aux->dado,p1);
                                        }
                             else{
                                  if((strcmp(aux->dado,"*")==0)||(strcmp(aux->dado,"+")==0))
                                             empilha(aux->dado,p2);
                                  if(strcmp(aux->dado,")")==0){
                                                               desempilha(operador,p2);
                                                               empilha(operador,p1);
                                                               }
                                  }
                             aux=aux->prox;
                             repete2();
          }
     }
     void re_empilha(){
               if(p1!=(struct ptr*)NULL){
                               desempilha(valor,p1);
                               empilha(valor,p3);
                               re_empilha();
               }
          }
     aux=expressao;          
     if(aux!=(struct ptr*)NULL){
          repete2();
          re_empilha();
          aux=p3;
          mostra();
          }
}
void cria_ordem(){
     struct ptr *aux;
     char valor[10];
     void repete(){
          if(strcmp(valor,".")!=0){
                        aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                        aux=aux->prox;
                        strcpy(aux->dado,valor);
                        scanf("%s",&valor);
                        repete();
          }            
     }
     expressao=(struct ptr*)NULL;
     printf("Entre com a expressão. O (.) indica o término.\n");
     scanf("%s",&valor);
     if(strcmp(valor,".")!=0){
                   expressao=(struct ptr*)malloc(sizeof(struct ptr));
                   strcpy(expressao->dado,valor);
                   aux=expressao;
                   scanf("%s",&valor);
                   repete();
                   aux->prox=(struct ptr*)NULL;
                   aux=aux->prox;
                   }
     else
         printf("Pilha vazia!");
}
void empilha(char valor[10],struct ptr *p){
          struct ptr *aux;
          aux=(struct ptr*)malloc(sizeof(struct ptr));
          strcpy(aux->dado,valor);
          aux->prox=p;
          p=aux;
          aux=(struct ptr*)NULL;
}
void desempilha(char valor[10],struct ptr *p){
                     struct ptr *aux;
                     if(p!=(struct ptr*)NULL){
                                   aux=p;
                                   p=p->prox;
                                   aux->prox=(struct ptr*)NULL;
                                   valor=aux->dado;
                                   free(aux);
                                   aux=(struct ptr*)NULL;
                     }                      
}

                
                 
                   
     
       
