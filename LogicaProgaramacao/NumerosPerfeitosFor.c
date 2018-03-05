main(){
       int n,i,s=0;
       printf("Entre com um numero: ");
       scanf("%d",&n);
       if(n<=0){
          printf("%d nao eh um numero perfeito.",n);
          }
       else{
          for(i=1;i<n;i++){
             if((n%i)==0)
                  s=s+i;
                  }
          if(s==n)
                printf("%d eh um numero perfeito.",n);
          else
             printf("%d nao eh um numero perfeito.",n);
             }    
             getch();
             }                           
                          
