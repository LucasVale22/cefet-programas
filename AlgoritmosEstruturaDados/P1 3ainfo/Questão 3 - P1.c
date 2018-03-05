#include <stdio.h>
struct ptr{
       char nome[20];
       int cpf,tel;
       struct ptr *prox;
       };
struct ptr *lista[26];
void menu();
void insercao();
void exclusao();
void consulta();
void fim();
main(){
       int k;
       printf("**Agenda**\n");
       printf("Digite (1) para inserir um registro.\n");
       printf("Digite (2) para excluir um registro existente.\n");
       printf("Digite (3) para consultar um telefone.\n");
       printf("Digite (4) para finalizar a tarefa.\n");
       for(k=0;k<26;k++)
             lista[k]=(struct ptr*)NULL;
       menu();
       getch();
       }
void menu(){
     int op;
     printf("Entre com a opcao desejada: ");
     scanf("%d",&op);
     switch(op){
                case(1): insercao();
                         menu();
                         break;
                case(2): exclusao();
                         menu();
                         break;
                case(3): consulta();
                         menu();
                         break;
                case(4): fim();
                         break;
                default: printf("Entre com uma opcao valida: ");
                         menu();
                         break;
                         }
}
void insercao(){
     struct ptr *maior,*menor,*aux;
     int k=0;
     char letra;
     aux=(struct ptr*)malloc(sizeof(struct ptr));
     printf("Entre com um nome: ");
     scanf("%s",&aux->nome);
     printf("Entre com o cpf: ");
     scanf("%d",&aux->cpf);
     printf("Entre com o telefone: ");
     scanf("%d",&aux->tel);
     aux->prox=(struct ptr *)NULL;
     for(letra='A';letra<aux->nome[0];letra++)
                                  k++;
     if(lista[k]==(struct ptr*)NULL){
                       lista[k]=aux;
                       aux=(struct ptr *)NULL;
                       }
     else{
          if(strcmp(aux->nome,lista[k]->nome)<0){
                                                 aux->prox=lista[k];
                                                 lista[k]=aux;
                                                 aux=(struct ptr *)NULL;
                                                 }
          else{
               maior=lista[k];
               while((maior->prox!=(struct ptr*)NULL)&&(strcmp(maior->nome,aux->nome)<0)){
                     menor=maior;
                     maior=maior->prox;
                     }                
               if(maior->prox==(struct ptr*)NULL){
                                       maior->prox=aux;
                                       aux=(struct ptr*)NULL;
                                       maior=aux;
                                       menor=aux;
                                       }
               else{
                    aux->prox=maior;
                    menor->prox=aux;
                    aux=(struct ptr*)NULL;
                    maior=aux;
                    menor=aux;
                    }
               }
          }
}
void exclusao(){
     struct ptr *maior,*menor,*aux;
     int k=0;
     char nome[20],letra;
     printf("Entre com o nome do registro a ser excluido: ");
     scanf("%s",&nome);
     for(letra='A';letra<nome[0];letra++)
                                  k++;
     aux=lista[k];
     if(aux==(struct ptr*)NULL)
                     printf("Não há registros na agenda!");
     else{
          if(aux->prox==(struct ptr*)NULL){
                                if(aux->nome!=nome)
                                                   printf("Este registro nao existe!");
                                else{
                                     lista[k]=(struct ptr*)NULL;
                                     free(aux);
                                     }
          }
          else{
               if(aux->nome==nome){
                                   lista[k]=aux->prox;
                                   aux->prox=(struct ptr*)NULL;
                                   free(aux);
                                   aux=(struct ptr*)NULL;
                                   }
               else{
                    maior=lista[k];
                    while((maior->nome!=nome)&&(maior->prox!=(struct ptr*)NULL)){
                                                                 menor=maior;
                                                                 maior=maior->prox;
                                                                 }
                    if(maior->nome!=nome)
                                         printf("Este registro nao existe!");
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
void consulta(){
    struct ptr *aux;
    int cpf,k=0;
    printf("Entre com um cpf: ");
    scanf("%d",&cpf);
    aux=lista[k];
    while((k<26)&&(aux->cpf!=cpf)){
                      while((aux!=(struct ptr*)NULL)&&(aux->cpf!=cpf))
                                          aux=aux->prox;
                      k++;
                      aux=lista[k];
    }
    if(aux->cpf!=cpf)
                     printf("Nao existe um registro com este cpf!");
    else
        printf("Este eh o telefone correspondente: %d",aux->tel);                                        
}
void fim(){
     struct ptr *aux;
     char rp;
     int k=0;
     printf("Se deseja sair da agenda, digite (S), caso contrario, digite (N).");
     scanf("%c",&rp);
     if(rp=='S'){
                 while(k<26){
                             aux=lista[k];
                             while(aux!=(struct ptr*)NULL){
                                                lista[k]=aux->prox;
                                                aux->prox=(struct ptr*)NULL;
                                                free(aux);
                                                aux=lista[k];
                                                }
                             k++;
                 }
     }
     else{
          if(rp=='N')
                     menu();
          else
               fim();
          }
}
                    
                    
                                                                 
                    
     
     
                                               
                         
       
       
