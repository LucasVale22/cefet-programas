struct regjog{
       char nome[50];
       int id;
       float alt,peso;
       };
struct regjog jog[4][12];
int qtde[4],i,tot=0,l,meid,cont1=0;

float totalt[4],totpeso=0,mapeso,altp;
main(){
       for(i=0;i<4;i++)
           totalt[i]=0;            
       for(i=0;i<4;i++){
            printf("Entre com a quantidade de jogadores da equipe%d: ",i+1);
            scanf("%d",&qtde[i]);
            while((qtde[i]<8)&&(qtde[i]>12)){
                printf("A equipe deve conter entre 8 e 12 jogadores. Ebtre com a quantidade correta: ");
                scanf("%d",&qtde[i]);
                }
       tot+=qtde[i];
       for(l=0;l<qtde[i];l++){
            printf("Nome: ");
            scanf("%s",&jog[i][l].nome);
            printf("Altura: ");
            scanf("%f",&jog[i][l].alt);
            printf("Peso: ");
            scanf("%f",&jog[i][l].peso);
            printf("Idade: ");
            scanf("%d",&jog[i][l].id);
            totalt[i]+=jog[i][l].alt;
            totpeso+=jog[i][l].peso;
            if((i==0)&&(l==0)){
                mapeso=jog[i][l].peso;
                meid=jog[i][l].id;
                }
            else{
                 if(jog[i][l].peso>mapeso){
                     mapeso=jog[i][l].peso;
                     
                     altp=jog[i][l].alt;
                     }
                 if(jog[i][l].id<meid)
                     meid=jog[i][l].id;
                     }
            }        
       printf("Total de jogadores de cada equipe:\n");
       for(i=0;i<4;i++){
                           printf("Equipe %d: %d",i+1,qtde[i]);
       }
       getch();
       }
       }
