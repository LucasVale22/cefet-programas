main(){
       int n,ced,moed,r;
       printf("Informe um numero inteiro em reais: ");
       scanf("%d",&n);
       r=n%2;
       if((r==0)&&(n>4))
       {
               ced=div(n,2)-1;
               moed=2;
               }
               else{
                    ced=div(n,2);
                    moed=r;
                    }
       printf("O numero pode ser representado por %d nota(s) de R$2,00 , no maximo, e %d moeda(s) de R$1,00 , no minimo.",ced,moed);
       getch();
       }
       
