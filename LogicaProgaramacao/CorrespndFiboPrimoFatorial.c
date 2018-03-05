main(){
       int a,b,c,i,n,fat,j,l,cont;
       printf("Insira um numero: ");
       scanf("%d",&n);
       if(n>2){        
          a=1;
          b=1;
          for(i=1;i<=(n-2);i++){
                         c=a+b;
                         a=b;
                         b=c;
                               }
                         fat=1;
                         for(j=1;j<=c;j++){
                            fat=fat*j;
                                     }
                         for(l=1;l<=c;l++){
                                  if((c%l)==0){
                                  cont++;
                                           }
                                           }             
                         if(cont==2){
                              printf("O numero %d corresponde ao numero %d em Fibonacci.\n",n,c);
                              printf("%d!=%d",c,fat);
                                    }
                         else{
                              printf("O numero %d corresponde ao numero %d em Fibonacci.\n",n,c);
                             }
                   }
          else{
             printf("O numero %d corresponde ao numero 1 em Fibonacci.\n",n);
                }
                         getch();
                         }
