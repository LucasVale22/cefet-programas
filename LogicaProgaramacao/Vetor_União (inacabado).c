#include<conio.h> //Inclui essa biblioteca, pois quando houver execução, possa aparecer o caraceter especial do conjunto vazio
#define TM 101
main(){
       int a[TM],b[TM],c[2*TM-2],i,j,lim=0;
       printf("Entre com a quantidade de elementos do vetor a: ");
       scanf("%d",&a[0]);
       while(a[0]>100){
              printf("Entre com uma quantidade que seja menor ou igual a 100: ");
              scanf("%d",&a[0]);
              }         
       printf("Entre com a quantidade de elementos do vetor b: ");
       scanf("%d",&b[0]);
       while(b[0]>100){
            printf("Entre com uma quantidade que seja menor ou igual a 100: ");
            scanf("%d",&b[0]);  
            }         
       printf("\n");
       for(i=1;i<=a[0];i++){
          printf("Elemento a[%d]: ",i);
          scanf("%d",&a[i]);
          for(j=1;j<=i;j++){
                  while((a[j]==a[i])&&(j!=i)){
                      printf("Ja existe no vetor a! Entre com outro diferente : ");
                      scanf("%d",&a[i]);
                                              }
                           }
          c[lim]=a[i];
          lim++;                 
                           }
       printf("\n");                    
       for(i=1;i<=b[0];i++){
          printf("Elemento b[%d]: ",i);
          scanf("%d",&b[i]);
          for(j=1;j<=i;j++){
                  while((b[j]==b[i])&&(j!=i)){
                      printf("Ja existe no vetor b! Entre com outro diferente: ");
                      scanf("%d",&b[i]);
                                             }
                           } 
                           }
       for(i=1;i<=b[0];i++){
             for(j=1;j<=a[0];j++){
                     if(b[j]!=a[i]){
                      c[lim]=b[i];
                      lim++;
                              } 
                                  }
                            }
       printf("\n");
       printf("\nEste eh o vetor c, que representa a uniao dos vetores a e b:\n\n");
       if(lim!=0){
       for(i=0;i<lim;i++){
           printf("%d ",c[i]);
           }
           }
       else
          printf("Conjunto vazio ^^!: %c",157);
       getch();
       }                                                                             
