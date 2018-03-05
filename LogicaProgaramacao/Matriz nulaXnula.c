#define TM 2
main(){
       int a[TM][TM],i,j,sc=0,sl=0,contl=0,contc=0;
            for(i=0;i<TM;i++){
                                for(j=0;j<TM;j++){
                                         printf("Elemento[%d][%d]: ",i,j);
                                         scanf("%d",&a[i][j]);
                                         sl+=abs(a[i][j]);
                                         sc+=abs(a[j][i]);
                                         }
                                         }
                                         for(i=0;i<TM;i++){
                                                           if(sl==0)
                                                           contl++;
                                                           if(sc==0)
                                                           contc++;
                                                           }
                                                           printf("Possui %d linhas nulas e %d colunas nulas!",contl,contc);
                                                           getch();
                                                           }                    
