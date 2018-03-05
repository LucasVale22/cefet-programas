main(){
       int n,r3,r7;
       printf("Entre com um numero inteiro qualquer: ");
       scanf("%d",&n);
       r3=n%3;
       r7=n%7;
       if((r3==0)&&(r7==0))
       printf("%d eh divisivel por 3 e 7",n);
       else
       printf("%d nao eh divisivel por 3 e 7",n);
       getch();
       }
