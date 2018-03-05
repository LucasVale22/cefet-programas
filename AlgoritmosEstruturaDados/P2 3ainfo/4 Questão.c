#include <stdio.h>
struct ptr{
       int num;
       struct ptr *prox;
};
struct ptr *p1,*p2,*paux,*auxg;
void empilha(int valor,struct ptr *p){
     struct ptr *aux;
     aux=(struct ptr*)malloc(sizeof(struct ptr));
     aux->num=valor;
     aux->prox=p;
     p=aux;
     aux=(struct ptr*)NULL;
}
void desempilha(int *valor,struct ptr *p){
     struct ptr *aux;
                   aux=p;
                   p=p->prox;
                   aux->prox=(struct ptr*)NULL;
                   *valor=aux->num;
                   auxg=p;
                   free(aux);
                   aux=(struct ptr*)NULL;        
}   
main(){
       int num,valor;
       p1=(struct ptr*)NULL;
       p2=p1;
       paux=p2;
       printf("Entre com um numero: ");
       scanf("%d",&num);
       if(num>=0){
                  while(num>=0){
                                empilha(num,p1);
                                printf("Entre com um numero: ");
                                scanf("%d",&num);
                  }
                  auxg=p1;
                  while(auxg!=(struct ptr*)NULL){
                                     valor=auxg->num;
                                     desempilha(&valor,p1);
                                     if((valor%2)!=0)
                                                     empilha(valor,p2);
                                     else
                                          empilha(valor,paux);
                  }
                  desempilha(&valor,paux);
                  empilha(valor,p1);                                         
       }
       else
           printf("Criastes uma pilha vazia!");
       getch();
}
