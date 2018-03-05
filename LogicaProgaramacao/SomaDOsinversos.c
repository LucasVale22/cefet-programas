main(){
       printf("Este programa calcula o valor da soma S=1+1/2+1/3+...+1/n\n\n");
       int n,i;
       float s;
       do{
       s=0;            
       printf("\nEntre com um numero que representara um quantidade: ");
       scanf("%d",&n);
       for(i=1;i<=n;i++){
               s=(i*s+1)/i;  
               }
               printf("Eis que o valor desta soma: %.2f\n",s);
               }while(n!=0);
               printf("Erro!");    
               getch();
               }
