#define TM 5
main(){
       int e[TM],i,j,cont1=0,cont2=0,maior,menor,v[TM];
       printf("Preencha o vetor com 5 elementos: ");
       printf("\n");
       for(i=0;i<TM;i++){
             printf("Elemento[%d]: ",i);
             scanf("%d",&e[i]);
             for(j=0;j<=i;j++){
                  if((i!=j)&&(e[i]>e[j]))
                       cont1++;
                  if((i!=j)&&(e[i]<e[j]))
                       cont2++;
                              }
                         }
       if(cont1==(2*TM))
          printf("O vetor encontra-se em ordem crescente.");
       if(cont2==(2*TM))
          printf("O vetor encontra-se em ordem decrescente.");
       if((cont1!=(2*TM))&&(cont2!=(2*TM))){  
          maior=e[0];
          menor=e[0];
          for(i=1;i<TM;i++){
             for(j=0;j<=i;j++){
                 if(e[j]>maior)
                    maior=e[j];
                    v[i+1]=maior;
                 if(e[j]<maior)
                    menor=e[j];
                    v[3-i]=menor;
                              }
                          }
       printf("O vetor encontra-se desordenado.");
       printf("Aqui esta ele em ordem crecsente: ");
       for(i=0;i<TM;i++)
            printf("%d ",v[i]);
       printf("Aqui esta ele em ordem decrescente: ");
       for(i=(TM-1);i>=0;i--)
            printf("%d ",v[i]);
            }                 
          getch();
          }   
           
                              
                                                            
       
