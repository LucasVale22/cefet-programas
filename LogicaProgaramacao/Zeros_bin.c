main(){
       int a1,a2,a3,a4,qtde,n;
       printf("Entre com um numero binario de quatro digitos: ");
       scanf("%d",&n);
       a1=div(n,1000);
       a2=div(n%1000,100);
       a3=div((n%1000)%100);
       a4=n%1000;
       qtde=0;
       if(a1==0){
                 qtde++;
                 }
                 if(a2==0){
                           qtde++;
                           }
                           if(a3==0){
                                     qtde++;
                                     }
                                     if(a4==0){
                                               qtde++;
                                               }
                                               printf("O numero possui %d zeros",qtde);
                                               system("pause");
                                               }
