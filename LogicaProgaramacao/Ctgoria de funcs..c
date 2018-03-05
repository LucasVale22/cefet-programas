main(){
       float s,sr;
       char cg;
       printf("Entre com o salario de um funcionario: ");
       scanf("%f",&s);
       printf("Entre com a categoria deste funcionario(B,D,,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,X,W,Y,Z): ");
       scanf("%c",&cg);
       if((cg=='F')||(cg=='G')||(cg=='H')){
              sr=s+s*10/100;
              printf("Salario reajustado: R$%.2f",s);
                                   }
              else{
                   if((cg=='B')||(cg=='D')||(cg=='E')||(cg=='J')||(cg=='I')||(cg=='T')){
                         sr=s+s*15/100; 
                         printf("Salario reajustado: R$%.2f",s);
                                                                      }
                         else{
                              if((cg=='L')||(cg=='M')||(cg=='N')||(cg=='O')||(cg=='P')||(cg=='Q')||(cg=='S')){
                                       sr=s+s*25/100; 
                                       printf("Salario reajustado: R$%.2f",s); 
                                                                                       }
                                       else{
                                            if((cg=='K')||(cg=='R')){
                                                   sr=s+s*35/100; 
                                                   printf("Salario reajustado: R$%.2f",s); 
                                                                   }      
                                                   else{
                                                        if((cg=='U')||(cg=='V')||(cg=='X')||(cg=='Y')||(cg=='W')||(cg=='Z')){
                                                              sr=s+s*50/100; 
                                                              printf("Salario reajustado: R$%.2f",s);  
                                                                                         }     
                                                             
                                                                   }
                                                                   }
                                                                   }
                                                                   }
                                                                   getch();
                                                                   }                                                                                                                                                                                                       
                         
                                                                              
                                                                                               
