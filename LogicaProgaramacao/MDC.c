main(){
       int a,b;
       printf("Entre com dois numeros: ");
       scanf("%d%d",&a,&b);
       while((a==0)||(b==0)){
       printf("O zero posui indeterminados divisores");
       printf("\nEntre com dois numeros: ");
       scanf("%d%d",&a,&b);
       }
                          
       while(a!=b){
                   if(a>b)
                     a=a-b;
                     else
                     b=b-a;
                     }
                     printf("o MDC dos dois numeros eh: %d",a);
                     getch();
                     }
                     
