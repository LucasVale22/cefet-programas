main(){
       char bin[4]; int i,cont=0;
       printf("Entre com um numero binário de quatro digitos: ");
       for(i=0;i<4;i++){
                        scanf("%c",&bin[i]);
                        if(bin[i]=='0')
                                     cont++;
       }
       printf("Este numero contem %d zeros!",cont);
       getch();
}
                                      
