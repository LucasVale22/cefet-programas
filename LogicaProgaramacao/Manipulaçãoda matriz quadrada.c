#define TM 5
main(){
       int mat[TM][TM],i,j,sl3e5=0,pc4=1,sdp=0,sds=0;
       for(i=0;i<TM;i++){
            for(j=0;j<TM;j++){
                      printf("Elemento[%d][%d]: ",i,j);
                      scanf("%d",&mat[i][j]);        
                      if((i==2)||(i==4))
                         sl3e5+=mat[i][j];
                      if(j==3)
                         pc4*=mat[i][j];
                      if(i==j)
                         sdp+=mat[i][j];
                      if((i+j)==(TM-1))
                         sds+=mat[i][j];
                         }
            }
        printf("\n");
        for(i=0;i<TM;i++){
            for(j=0;j<TM;j++){
                printf("%d  ",mat[i][j]);
                }
                printf("\n");
                }              
            
        printf("\nSoma dos elemntos da terceira linha com os da quinta linha: %d",sl3e5);
        printf("\nProduto dos elementos da quarta coluna: %d",pc4);
        printf("\nSoma dos elementos da diagonal principal: %d",sdp);
        printf("\nSoma dos elemntos da diagonal secundaria: %d",sds);
        getch();
        }    
                                          
