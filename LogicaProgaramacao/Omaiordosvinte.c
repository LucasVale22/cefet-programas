#define TM 10

main(){
       int vet[TM],maior,i;
       for(i=0;i<TM;i++){
                         printf("Digite o %d numero: ",i+1);
                         scanf("%d",&vet[i]);
                         if(i==0)
                            maior=vet[i];
                         if(vet[i]>maior)
                            maior=vet[i];
                            }
                            printf("O maior numero eh %d.",maior);
                            getch();
                            }  
