main(){
       int ht,h,m,s;
       printf("Informe o hor�rio total em segundos: ");
       scanf("%d",&ht);
       h=ht/3600;
       m=(ht%3600)/60;
       s=(ht%3600)%60;
       printf("O hor�rio sera de %d hora(s), %d min(s) e %d seg(S)",h,m,s);
       getch();
       }
