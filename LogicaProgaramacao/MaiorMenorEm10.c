main(){
       int i,n,ma,me;
       for(i=1;i<=10;i++){
                          printf("\nEntre com o %d numero: ",i);
                          scanf("%d",&n);
                                         if(i==1){
                                                  ma=n;
                                                  me=n;
                                                  }
                                                  else{
                                                       ma=(n>ma)?n:ma;
                                                       me=(n<me)?n:me;
                                                       }
                          }
                          printf("O maior dos numeros eh o %d e o menor eh o %d.",ma,me);
                          getch();
                          }
