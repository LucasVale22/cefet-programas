main(){
       int n,primo,cont,i,aux;
       printf("Entre com um numero: ");
       scanf("%d",&n);
       primo=1;
       cont=0;
       while(i!=n){
                     aux=0;
                     for(i=1;i<primo;i++){
                     if((primo%i)==0){
                     aux++;}
                     if(aux==2){
                     primo++;}
                     }
      }
      primo--;
      printf("O %d corresponde ao numero primo %d",n,primo);
      getch();
      }               
