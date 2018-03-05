main(){
       float n1,n2;
       char op;
       printf("      *************\n      *CALCULADORA*\n      *************\n      + para somar\n      -para subtrair\n      *para multiplicar\n      / para dividir\n\n");
       printf("Digite a opcao de operacao: ");
       scanf("%c",&op);
       printf("numero: ");
       scanf("%f",&n1);
       printf("numero: ");
       scanf("%f",&n2);
       switch(op){
                  case('+'): printf("Soma=%.0f",n1+n2);
                  break;
                  case('-'): printf("Subtracao=%.0f",n1-n2);
                  break;
                  case('*'): printf("Multiplicacao=%.0f",n1*n2);
                  break;
                  case('/'):if(n2==0)
                  printf("Erro!Divisao por zero!");
                  else
                  printf("Divisao=%.2f",n1/n2);
                  break;
                  default: printf("Opcao incorreta!");
                  break;
                  }
                  getch();
                  }
                  
       
