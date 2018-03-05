main(){
       int qtdeh=0,qtdem=0,total=0,id,sex;
       float media;
       while(id!=0){
       printf("Entre com a idade: ");
       scanf("%d",&id);
       printf("Entre com o sexo (0-masculino 1-feminino: ");
       scanf("%d",&sex);
       if(sex==0)
         qtdeh++; 
       if((id>30)&&(id<45)&&(sex==1))
         total+=id;
         qtdem++;
       }
       media=total/qtdem;
       if(qtdem==0)
         printf("A media das idades de mulheres entre 30-45 anos eh 0.");
       else
         printf("A media das idades de mulheres entre 30-45 anos eh %.1f.",media);
       if(qtdeh==0)
         printf("Total de homens: 0");
       else
         printf("Total de homens: %d",qtdeh);    
         getch();
         }  
       
      
       
       
       
