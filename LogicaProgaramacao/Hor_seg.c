main(){
       int h,m,s,ht;
       printf("Informe as horas,os minutos e os segundos (entre espa�os): ");
       scanf("%d%d%d",&h,&m,&s);
       ht=s+60*m+3600*h;
       printf("O hor�rio total em segundos sera de %d s",ht);
       getch();
       }
