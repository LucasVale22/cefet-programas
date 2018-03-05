main(){
       char nome[10];
       float n1,n2,m;
       printf("Informe o seu nome; ");
       scanf("%s",&nome);
       printf("Digite a nota do seu teste: ");
       scanf("%f",&n1);
       printf("Digite a nota da sua prova: ");
       scanf("%f",&n2);
       m=(n1+n2)/2;
       printf("%s, sua media sera %.1f.",nome,m);
       getch();
       }
