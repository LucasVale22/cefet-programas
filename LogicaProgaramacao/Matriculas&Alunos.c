main(){
       float not[5],med=0;
       int mat[5],i;
       for(i=0;i<5;i++){
             printf("Entre com a matricula[%d]:\n",i+1);
             scanf("%d",&mat[i]);
             printf("Entre com a nota[%d]:\n",i+1);
             scanf("%d",not[i]);
             med+=not[i];
             }
       med/=5;
       for(i=0;i<5;i++){
             if(not[i]>med)
                printf("Matricula : %d\n",mat[i]);
                }
       getch();
       }         
                                                              
             
