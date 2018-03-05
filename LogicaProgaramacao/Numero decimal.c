main(){
       int nb,a1,a2,a3,a4,dec;
       printf("Informe um numero binario de quatro digitos: ");
       scanf("%d",&nb);
       a1=div(nb,1000);
       a2=div(nb%1000,100);
       a3=div((nb%1000)%100,10);
       a4=nb%10;
       dec=a1*pow(2,3)+a2*pow(2,2)+a3*2+a4;
       printf("O numero decimal correspondente eh %d",dec);
       getch();
       }
