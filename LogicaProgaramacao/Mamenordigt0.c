main(){
       int n,ma,me,aux=0;
       
       while(n!=0){
                   printf("Entre com um numero: ");
       scanf("%d",&n);
                   if(aux==0){
                              ma=n;
                              me=n;
                            aux++;
                              }
                              else{
                                   ma=(n>ma)?n:ma;
                                   me=(n<me)?n:me;
                                   }
                                   printf("\nEntre com um numero: ");
                                   scanf("%d",n&n);
                             
                   }
                   printf("Maior: %d e Menor: %d",ma,me);
                   getch();
                   }
