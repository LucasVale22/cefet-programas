main(){
       char rad[20],term[2];
       int i;
       printf("Entre com um verbo regular no infinitivo pessoal: ");
       scanf("%c%c",&rad,&term);
       while(term!='r'){
       rad[i]=rad;
       term[i]=term;
       i++
       scanf("%c%c",&rad,&term);
       if((term!="ar")||(term!="er")||(term!="ir")){
                          printf("Esta incorreto.");
       }
       }
       
       printf("Na rimeira pessoal do singular: %so ",rad);
       getch();
       }
           
       
