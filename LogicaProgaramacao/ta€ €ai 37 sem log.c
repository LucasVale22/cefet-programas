main(){
       int n,r3,r7;
       printf("Entre com um numero inteiro: ");
       scanf("%d",&n);
       r3=n%3;
       r7=n%7;
       if(r3==0){
                 printf("%d eh divisivel por 3 e ",n);
                 }
                 else{
                      printf("%d nao eh divisivel por 3 e ",n);
                      }
                 if(r7==0){
                           printf(" eh divisivel por 7.");
                           }
                           else{
                                printf(" nao eh divisivel por 7.");
                                }
                           getch();
                           }
