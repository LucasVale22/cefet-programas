main(){
       int n,ma,me,i=1;
       while(i<=10){
                     printf("Entre co m umnumero: ");
                     scanf("%d",&n);
                     if(i==1){
                                                  ma=n;
                                                  me=n;
                                                  }
                                                  else{
                                                       ma=(n>ma)?n:ma;
                                                       me=(n<me)?n:me;
                                                       }
                                                       i++;
                     }
                     printf("Omenor eh %d e o maior eh %d",me,ma);
                     getch();
                     }
