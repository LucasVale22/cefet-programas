main(){
       int n,cent,dez,uni,cent2,dez2,uni2,inv,n2,r,v; 
       printf("Informe o numero da sua conta,que deve possuir tres digitos: ");
       scanf("%d",&n);
       cent=div(n,100);
       dez=div(n%100,10);
       uni=n%10;
       inv=100*uni+10*dez+cent;
       n2=n+inv;
       cent2=div(n2,100);
       dez2=div(n2%100,10);
       uni2=n2%10;
       if (n2>999){
                   r=4+cent2*2+dez2*3+uni2*4;
                  }
       else{
            r=cent2*1+dez2*2+uni2*3;
            }
       v=r%10;
       printf("O digito verificador da sua conta eh %d",v);
       getch();
       }
