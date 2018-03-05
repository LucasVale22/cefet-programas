#define TAM 4
main(){
       int vet[TAM],i,cont1=0,cont2=0,menor,maior;
       for(i=0;i<TAM;i++){
       vet[i]=0;
       }
       maior=vet[0];
       menor=vet[0];
       for(i=0;i<TAM;i++){
             printf("Preencha a célula [%d]: ",i);
             scanf("%d",&vet[i]);
             if(vet[i]>maior)
               cont1++;
             if(vet[i]<menor)
               cont2++; 
             }
             
        if(cont1==TAM)
           printf("Esta em ordem crescente.");
        if(cont2==TAM)
           printf("Esta em ordem decrescente.");
        if((cont1!=TAM)||(cont2!=TAM))    
           printf("Esta em ordem aleatoria.");
           getch();
           }                    
