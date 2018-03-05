#define TAM 100
main(){
       int m[TAM][TAM],i,j,aux=1;
       for(i=0;j<TAM;i++){
                          for(j=0;j<TAM;j++){
                                             m[i][j]=aux;
                                             aux++;
                                             printf("%d \t",m[i][j]);
                                             }
                          
                          printf("\n");
                          }
                          getch();
}                           
