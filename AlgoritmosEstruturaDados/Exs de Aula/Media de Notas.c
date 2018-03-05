float media(float a, float b,float c){
      float m;
      m=(a+b+c)/3;
      return(m);
      }
main(){
       float a,b,c,med;
       printf("Entre com tres notas: ");
       scanf("%f%f%f",&a,&b,&c);
       med=media(a,b,c);
       printf("A media sera: %.2f",med);
       getch();
       }
             
