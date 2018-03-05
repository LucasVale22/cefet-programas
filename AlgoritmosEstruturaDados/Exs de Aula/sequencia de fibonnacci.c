int n;
int fib(int n);
main(){
       printf("Entre com o limite de termos que deseja na sequência de fibonnacci: ");
       scanf("%d",&n);
       if((n==1)||(n==2))
       printf("1");
       else
       prinf("%d",fib(n));
       
       getch();
       }
int fib(int n){
           if((n==0)||(n==1))
              return(n);
           else
              return(fib(n-2)+fib(n-1));
       }

       
             
              
