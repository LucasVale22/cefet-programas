#define TM 5
main(){
       int  vet[TM],i,cont1=0,cont2=0,maior,menor;
       for(i=0;i<TM;i++){
              printf("Insira o elemento[%d]: ",i+1);
              scanf("%d",&vet[i]);
              if(i==0)
                maior=vet[i];
                menor=vet[i];
              if(vet[i]>maior)
                maior=vet[i];
                cont1++;
              if(vet[i]<menor)  
                menor=vet[i];
                cont2++;
                }
        if(cont1>cont2)
           printf("O vetor esta em ordem crescente.");
        else
          if(cont1<cont2)
              printf("O vetor esta em oredm decrescente.");
          else
             printf("Esta em ordem aleatpria.");
        getch();
        }                                  
