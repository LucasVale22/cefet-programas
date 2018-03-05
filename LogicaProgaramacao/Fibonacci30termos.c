main(){
       int a,b,c,i;
       a=1;
       b=1;
       printf("\t<<<ESTES SAO OS PRIMEIROS 30 TERMOS DA SEQUENCIA DE FIBONACCI>>>\n\n");
       printf("%d\t%d\t",a,b);
       for(i=1;i<=28;i++){
          c=a+b;
          printf("%d\t",c);
          a=b;
          b=c;
          }
          printf("________________________________________________________________________________");
        getch();
        }   
