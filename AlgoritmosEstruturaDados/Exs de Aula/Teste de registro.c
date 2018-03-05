struct regpessoa{
       char nome[50];
       int idade;
       
       };
struct regpessoa info;

main(){
       printf("Entre com o nome da pessoa: ");
       scanf("%s",&info.nome);
       printf("\nEntre com a idade: ");
       scanf("%d",&info.idade);  
       printf("%s %d",info.nome,info.idade);
       getch();
       }
