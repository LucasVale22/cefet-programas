#define TM 2
main(){
       int a[TM][TM],i,j,maior;
       for(i=0;i<TM;i++){
            for(j=0;j<TM;j++){
                   printf("Elemento[%d][%d]: ",i,j);
                   scanf("%d",&a[i][j]);
                   if((i==0)&&(j==0))
                       maior=a[i][j];
                   if(a[i][j]>maior)
                       maior=a[i][j];
                   }
                   }
       for(i=0;i<TM;i++){
          printf("\n");
          for(j=0;j<TM;j++){
                printf("%d\t",a[i][j]*maior);
                }
                }
                getch();
                }                                       
                                           
