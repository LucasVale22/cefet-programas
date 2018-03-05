main(){
       float p,v;
       printf("Entre com o valor do produto: ");
       scanf("%f",&p);
       if(p<20)
       v=p+p*45/100;
       else
       v=p+p*30/100;
       printf("O valor de venda do produto sera: R$%.2f",v);
       getch();
       }
