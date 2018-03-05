main(){
       char sexo;
       int n,qtdeh=0,qtdem=0,i;
       float alth=0,altm=0,maioralt,menoralt,alt,m,mm,mh;
       printf("Entre com um numero de pessoas: ");
       scanf("%d",&n);
       for(i=1;i<=n;i++){
            printf("\nEntre com um sexo(F ou M): ");
            scanf("%s",&sexo);
            printf("Entre com uma altura: ");
            scanf("%f",&alt);  
            if(sexo=='F'){
              alth=alth+alt;
              qtdeh++;
              }
            else{
              altm=altm+alt;
              qtdem++;
              }
            if(i==1){
                     maioralt=alt;
                     menoralt=alt;
                     }
            else{
                 maioralt=(alt>maioralt)?alt:maioralt;
                 menoralt=(alt<menoralt)?alt:menoralt;
                 }
                 }
       if(n==0){
            m=0;
            maioralt=0;
            menoralt=0;
            }
       else                   
            m=(alth+altm)/n;
       if(qtdeh==0)
            mh=0;
       else          
            mh=(alth/qtdeh);
       if(qtdem==0)
            mm=0;
       else     
       mm=(altm/qtdem);
       printf("\nA media da altura do grupo eh: %.2f\n\n",m);
       printf("A media da altura dos homens eh: %.2f\n\n",mh);
       printf("A media da altura das mulheres eh: %.2f\n\n",mm);
       printf("A maior altura do grupo eh: %.2f\n\n",maioralt);
       printf("A menor alturado grupo eh: %.2f\n\n",menoralt);   
       getch();
       }                                 
                     
                                             
                                  
