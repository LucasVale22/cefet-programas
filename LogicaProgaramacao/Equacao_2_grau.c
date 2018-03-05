main(){
      float a,b,c,delta,x1,x2,i;
      printf("Entre com os coeficientes de uma equacao do segundo grau:\n ");
      scanf("%f%f%f",&a,&b,&c);
      delta=b*b-4*a*c;
      if(delta<0){
                  printf("Raizes imaginarias");
                  }
                  else{
                       if(delta==0){
                                   x1=(-b)/(2*a);
                                   printf("Raiz uica:%.2f",x1);
                                   }
                                   else{
                                        x1=(-b+sqrt(delta))/2*a;
                                        x2=(-b-sqrt(delta))/2*a;
                                        printf("Raizes distintas: %.2f e %.2f",x1,x2);
                                        }
                                        }
                                        
                                        
                                        getch();
                                        }
       
