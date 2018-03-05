main(){
      char nome[50],venc;
      int num,qtde,class,pont_a=0,pont_b=0,qtde_tot,aux,club;
      float temp;
      qtde_tot=0;
      while((num!=9999)&&(qtde>0)){
          printf("Insira o numero da prova: ");
          scanf("%d",&num);
          printf("Insira a quantidade de nadadores dessa prova: ");
          scanf("%d",&qtde);
          qtde_tot+=qtde;
                                    }
      aux=0;
      while(aux<qtde_tot){                              
      printf("\nEntre com o nome de um nadador: ");
      scanf("%s",&nome);
      printf("Entre com a classificacao: ");
      scanf("%d",&class);
      printf("E agora, o seu tempo: ");
      scanf("%f",&temp);
      printf("Insira tambem o clube (a-1 ou b-2) dele: ");
      scanf("%d",&club);
      if(club==1){
              if(class==1)
                 pont_a+=9;
              if(class==2)
                 pont_a+=6;
              if(class==3)
                 pont_a+=3;
              if(class>3)
                 pont_a+=0;   
                 }
      if(club==2){
              if(class==1)
                 pont_b+=9;
              if(class==2)
                 pont_b+=6;
              if(class==3)
                 pont_b+=3;
              if(class>3)
                 pont_b+=0;    
                 }         
       aux++;
                            }
       if(pont_a>pont_b)
         venc='A';
       else
          venc='B';
       
       printf("O clube A conquistou %d pontos.\n",pont_a);
       printf("O clube B conquistou %d pontos.\n\n",pont_b); 
       printf("O vencedor eh o clube %c!",venc);              
                
                                          
                             
           
      
      
      
      getch();
      }
      
      
      
      
      
      
       
       
