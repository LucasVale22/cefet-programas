main(){
       int ht,h,m,s;
       printf("Informe o horário total em segundos: ");
       scanf("%d",&ht);
       h=ht/3600;
       m=(ht%3600)/60;
       s=(ht%3600)%60;
       printf("O horário sera de %d hora(s), %d min(s) e %d seg(S)",h,m,s);
       getch();
       }
