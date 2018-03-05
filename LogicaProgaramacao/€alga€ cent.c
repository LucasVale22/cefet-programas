main(){
       int n,c;
    
       printf("Insira um numero inteiro: ");
          while(n>0){
        printf("Insira um numero inteiro: ");
       scanf("%d",&n);
       c=div(n,100);
       if((c%2)==0)
       printf("O algarismo das centenas eh par.");
       else
       printf("O algarismos das centenas eh impar.");
      
          }
       system("pause");
       }
       
