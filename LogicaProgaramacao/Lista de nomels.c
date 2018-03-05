main(){
       #define TM 5
       char lista[TM],nome[TM];
       int i;
       for(i=0;i<TM;i++){
           printf("Entre com um nome%d ",i+1);
           scanf("%s",&nome);
           lista[i]=nome; 
           }      
              
       for(i=0;i<TM;i++)
            printf("%s\n",lista[i]);
       getch();
       }                                
