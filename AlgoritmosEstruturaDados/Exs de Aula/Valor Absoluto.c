float absoluto(float num){
      if(num<0)
        num=-num;
      return(num);
      }
main(){
       float num;
       printf("Entre com um numero qualquer: ");
       scanf("%f",&num);
       num=absoluto(num);
       printf("Valor absoluto eh: %.0f",num);
       getch();
       }
                   
