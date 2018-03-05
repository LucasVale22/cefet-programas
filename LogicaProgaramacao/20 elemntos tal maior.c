main(){
       #define TM 5
       int vet1[TM],vet2[TM],i,j=0;
       for(i=0;i<TM;i++){
            printf("Entre com o elemento%d: ",1+i);
            scanf("%d",&vet1[i]);
            if((vet1[i]%3)==0){
               vet2[j]=vet1[i];
               j++; 
               }            
               }
        for(i=0;i<j;i++){
            printf("%d\t",vet2[i]);                
            }
        getch();
        }     
