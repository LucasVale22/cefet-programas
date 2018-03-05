void tabuada(int num){
     int i;
     for(i=1;i<=10;i++)
          printf("%d x %d = %d\n",i,num,i*num);
          }

main(){
       int num;
       printf("Entre com um numero inteiro: ");
       scanf("%d",&num);
       tabuada(num);
       getch();
       }
                 
                        
