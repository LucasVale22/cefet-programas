#define TM1 11
#define TM2 4
main(){
       int n[TM1][TM2],i,j;
       for(i=0;i<TM1;i++){
           printf("Numero %d:\n",i+1);
           n[i][0]=i;
           for(j=1;j<TM2;j++){
                  printf("Nota %d: ",i+1);
                  scanf("%d",&n[i][j]);
                  }
                  }
       for(i=0;i<TM1;i++){
            for(j=0;j<TM2;j++){
                  printf("%d\t",n[i][j]);
                  }
                  }
                  getch();
                  }                                                            
