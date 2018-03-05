main(){
       int mat,totaprov=0,totreprov=0,total;
       float n1,n2,n3,media;
       do{
          printf("Entre com a matricula de um aluno: ");
          scanf("%d",&mat);
          printf("Insira suas tres notas:\n");
          printf("Nota 1: ");
          scanf("%f",&n1);
          printf("Nota 2: ");
          scanf("%f",&n2);
          printf("Nota 3: "); 
          scanf("%f",&n3);
          media=(n1*2+n1*3+n3*4)/9;
          if(media>=5){
              printf("\nMatricula: %d",mat);
              printf("\nMedia final: %.2f",media);
              printf("\nAPROVADO! :D\n");
              totaprov++;
              }
          else{
              printf("\nMatricula: %d",mat);
              printf("\nMedia final: %.2f",media);
              printf("\nREPROVADO! :(\n");
              totreprov++;
              }
          }while(mat<9999);
           total=totaprov+totreprov;
           printf("\n\tTotal de alunos aprovados: %d",totaprov);
           printf("\n\tTotal de alunos reprovados: %d",totreprov);
           printf("\n\tTotal de alunos: %d",total);
           getch();
           }       
                   
