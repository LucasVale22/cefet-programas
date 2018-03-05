main(){
       int i,n,cont=0;
       printf("Insira um numero: ");
       scanf("%d",&n);
       for(i=1;i<=n;i++){
                         if((n%i)==0)
                            cont++;
                         }
                         if(cont==2)
                            printf("%d eh primo.",n);
                         else
                            printf("%d nao eh primo.",n);
                         getch();
       }
