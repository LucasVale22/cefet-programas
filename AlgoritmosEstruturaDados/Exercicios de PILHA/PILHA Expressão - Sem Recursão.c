#include <stdio.h>
struct ptr{
       char dado[10];
       struct ptr *prox;
       };
struct ptr *expressao,*p1,*p2;
void cria_ordem();
void empilha(char valor[10],struct ptr *p);
void desempilha(char valor[10],struct ptr *p);
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
     struct ptr *aux;
     char a[10],b[10],operador[2],cadeia[10];
     int a1,b1,valor,resp;
     aux=expressao;          
     if(aux!=(struct ptr*)NULL){
          while(strcmp(aux->dado,".")!=0){
                                          resp=atoi(aux->dado);
                                          if(resp!=0)
                                                     empilha(aux->dado,p1);
                                        else{
                                             if((strcmp(aux->dado,"*")==0)||(strcmp(aux->dado,"+")==0))
                                             empilha(aux->dado,p2);
                                             if(strcmp(aux->dado,")")==0){
                                                               desempilha(a,p1);
                                                               desempilha(b,p1);
                                                               printf(
                                                               desempilha(operador,p2);
                                                               a1=atoi(a);
                                                               b1=atoi(b);
                                                               if(strcmp(operador,"+")==0)
                                                                                          valor=a1+b1;
                                                               else
                                                                   valor=a1*b1;
                                                               itoa(valor,cadeia,10);
                                                               empilha(cadeia,p1);
                                             }
                                        }
                                        aux=aux->prox;
          }    
          printf("Resposta = %s",cadeia);
          free(p1);
          p1=(struct ptr*)NULL;
          }
}
void cria_ordem(){
     struct ptr *aux;
     char valor[10];
     expressao=(struct ptr*)NULL;
     printf("Entre com a expressão linha a linha. O (.) indica o término.\n");
     scanf("%s",&valor);    
     if(strcmp(valor,".")!=0){
                   expressao=(struct ptr*)malloc(sizeof(struct ptr));
                   strcpy(expressao->dado,valor);
                   scanf("%s",&valor);
                   aux=expressao;
                   while(strcmp(valor,".")!=0){
                                               aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
                                               aux=aux->prox;
                                               strcpy(aux->dado,valor);
                                               scanf("%s",&valor);
                   }            
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
          aux=(struct ptr*)malloc(sizeof(struct ptr));
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

                
                 
                   
     
       
