main(){
       int n,perf,cont,i,aux;
       printf("Entre com um numero: ");
       scanf("%d",&n);
       perf=1;
       cont=0;
       while(cont!=n){
                     aux=0;
                     for(i=1;i<perf;i++)
                     if((perf%i)==0)
                     aux+=i;
                     if(aux==perf)
                     cont++;
                     perf++;
      }
      perf--;
      printf("O %d corresponde ao numero perfeito %d",n,perf);
      getch();
      }               
