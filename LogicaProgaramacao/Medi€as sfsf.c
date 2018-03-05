main(){
       char nome[100];
       float m,n1,n2;
       printf("Entre com o nome de um aluno: ");
       scanf("%s",&nome);
       printf("Entre com duas notas: ");
       scanf("%f%f",&n1,&n2);
       m=(n1+n2)/2;
       if(m>=8){
                printf("%s esta aprovado com media %.2f.",nome,m);
                }
                else{
                     if(m<5){
                             printf("%s esta reprovado com media %.2f.",nome,m);
                             }
                             else{
                                  printf("%s realizara a prova final.",nome);
                                  }
                                  }
                                  getch();
                                  }
                             
       
