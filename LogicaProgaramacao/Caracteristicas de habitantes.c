main(){
       int qtde_exclusiva=0,qtde=0,id,maior,sexo,cor_olho,cor_cabelo;
       float porc;
       while(id>0){
                    printf("Entre com a idade: ");
                    scanf("%d",&id);
                    printf("Insira o sexo (f=1 ou m=2): ");
                    scanf("%d",&sexo);
                    printf("Insira a cor dos olhos (a=1,v=2 ou c=3): ");
                    scanf("%d",&cor_olho);
                    printf("Insira a cor dos cabelos (l=1,c=2 ou p=3): ");
                    scanf("%d",&cor_cabelo);
                    if((sexo==1)&&(id>18)&&(id<=35)&&(cor_olho==2)&&(cor_cabelo==1)){
                          qtde_exclusiva++;
                          }                                                                 
                    qtde++;
                    }
        if(qtde==1){
               maior=id;
               }
        else{
             if(id>maior)
               maior=id;
               }
        porc=(100*qtde_exclusiva)/qtde;
        printf("A maior idade dos habitantes eh: %d\n",maior);
        printf("A porcentagem a porcentagem de indivíduos do sexo feminino cuja idade está entre 18 e 35 anos inclusive e que tenham olhos verdes e cabelos louros eh: %.1f",porc);
        getch();
        }                                  
                    
