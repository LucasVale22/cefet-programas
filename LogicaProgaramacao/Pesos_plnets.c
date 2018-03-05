main(){
       float pt;
       int n;
       printf("Entre com o modulo de um peso na Terra:\n");
       scanf("%f",&pt);
       printf("escolha o numero de um planeta:\n1-mercurio\n2-venus\n3-marte\n4-jupiter\n5-saturno\n6-urano\n");
       scanf("%d",&n);
       switch(n){
                 case(1): printf("Valor do peso no planeta mercurio:%.2f",pt*0.37);
                 break;
                 case(2): printf("Valor do peso no planeta venus:%.2f",pt*0.88);
                 break;
                 case(3): printf("Valor do peso no planeta marte:%.2f",pt*0.38);
                 break;
                 case(4): printf("Valor do peso no planeta jupiter:%.2f",pt*2.64);
                 break;
                 case(5): printf("Valor do peso no planeta saturno:%.2f",pt*1.15);
                 break;
                 case(6): printf("Valor do peso no planeta urano:%.2f",pt*1.17);
                 break;
                 default: printf("Opcao invalida ^_^!");
                 break;
                 }
                 getch();
                 }
                                            
                       
