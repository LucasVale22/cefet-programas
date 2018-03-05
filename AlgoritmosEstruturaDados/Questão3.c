//Questão 3 da P1
#include <stdio.h>

struct ptr{
       int cpf, tel;
       char nome[50];
       struct ptr *prox;
       };struct ptr *inicio[26];

void menu();
void apaga(struct ptr lista);
void inserir();
void excluir();
void pesquisar();
void fim();

main(){
       printf("Esta eh sua agenda telefonica. Entre com as opcoes:\n\n(1) para inserir um registro na lista;\n(2) para excluir um registro da lista;\n(3) para pesquisar um telefone e\n(4) para sair.");
       menu();
       system("pause");
       }

void menu(){
     int op;
     do{
        printf("\n\nDigite sua opcao: ");
        scanf("%d",&op);
        if((op>4)&&(op<1))
                          printf("OPCAO INVALIDA");
        }while((op>4)&&(op<1));
     if(op==1){
               inserir();
               menu();
               }
     else{
          if(op==2){
                    excluir();
                    menu();
                    }
          else{
               if(op==3){
                         pesquisar();
                         menu();
                         }
               else
                   fim();
               }
          }
     }

void pesquisar(){
     int cpf,tel,i=0;
     struct ptr *maior;
     printf("Entre com o CPF: ");
     scanf("%d",&cpf);
     while((i<26)&&(tel!=maior->tel)){
                       if(inicio[i]!=(struct ptr *)NULL){
                                             maior=inicio[i];
                                             while((cpf!=maior->cpf)&&(maior->prox!=(struct ptr *)NULL))
                                                                                            maior=maior->prox;
                                             if(cpf==maior->cpf)
                                                                tel=maior->tel;
                                             }
                       i++;
                       }
     maior=(struct ptr *)NULL;
     printf("O telefone buscado eh %d",tel);
     }                                           


void inserir(){
     struct ptr *aux,*maior,*menor; char l; int i=0;
     aux=(struct ptr *)malloc(sizeof(struct ptr));
     printf("Entre com o nome: ");
     scanf("%s",&aux->nome);
     printf("Entre com o CPF: ");
     scanf("%d",&aux->cpf);
     printf("Entre com o telefone: ");
     scanf("%d",&aux->tel);
     aux->prox=(struct ptr *)NULL;
     for(l='A';l<aux->nome[0];l++)
                                  i++;
     if(inicio[i]==(struct ptr *)NULL){
                           inicio[i]=aux;
                           free(aux);
                           aux=(struct ptr *)NULL;
                           }
     else{
          if(strcmp(aux->nome,inicio[i]->nome)<0){
                                                   aux->prox=inicio[i];
                                                   inicio[i]=aux;
                                                   aux=(struct ptr *)NULL;
                                                   }
          else{
               maior=inicio[i];
               while((maior->prox!=(struct ptr *)NULL)&&(strcmp(aux->nome,maior->nome)>0)){
                                           menor=maior;
                                           maior=maior->prox;
                                           }
               if(strcmp(aux->nome,maior->nome)>0){
                                                  maior->prox=aux;
                                                  aux=(struct ptr *)NULL;
                                                  menor=aux;
                                                  maior=aux;
                                                  }
               else{
                    menor->prox=aux;
                    aux->prox=maior;
                    aux=(struct ptr *)NULL;
                    menor=aux;
                    maior=aux;
                    }
               }
          }
     }
     
void excluir(){
     char nome[50], l; int i=0;
     struct ptr *maior,*menor,*aux;
     printf("entre com o nome do resgistro a ser ecluído: ");
     scanf("%s",&nome);
     for(l='A';l<nome[0];l++)
                             i++;
     if(inicio[i]==(struct ptr *)NULL)
                           printf("Lista vazia!");
     else{
          if(inicio[i]->prox==(struct ptr *)NULL){
                                      if(inicio[i]->nome==nome){
                                                          free(inicio[i]);
                                                          inicio[i]=inicio[i]=(struct ptr *)NULL;
                                                          }
                                      else
                                          if(inicio[i]->nome==nome){
                                                                    aux=inicio[i];
                                                                    inicio[i]=inicio[i]->prox;
                                                                    aux->prox=(struct ptr *)NULL;
                                                                    free(aux);
                                                                    aux=(struct prt *)NULL;
                                                                    }
                                          else{
                                               maior==inicio[i];
                                               while((maior->prox!=(struct prt *)NULL)&&(maior->nome!=nome)){
                                                                           menor=maior;
                                                                           maior=maior->prox;
                                                                           }
                                               if(nome!=maior->nome)
                                                                    printf("Elemento nao existe!");
                                               else{
                                                    maior->prox=maior->prox;
                                                    maior->prox=(struct ptr *)NULL;
                                                    free(maior);
                                                    maior=(struct ptr *)NULL;
                                                    menor=maior;
                                                    }
                                               }
                                          }
                                      }
          }
          
void fim(){
     int i; char resp;
     struct ptr *aux;
     printf("Tem certeza de que deseja sair?");
     scanf("%s",&resp);
     if(resp=="SIM")
                    for(i=0;i<26;i++){
                                      aux=inicio[i];
                                      while(inicio[i]!=(struct ptr *)NULL){
                                                               inicio[i]=inicio[i]->prox;
                                                               aux->prox=(struct ptr *)NULL;
                                                               free(aux);
                                                               aux=inicio[i];
                                                               }
                                      }
     else{
          if(resp="NAO")
                        menu();
          else{
               printf("Resposta Invalida. Digite SIM ou NAO.");
               fim();
               }
          }
     }
