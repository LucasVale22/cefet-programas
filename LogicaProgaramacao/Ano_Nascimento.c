main(){
       int id,ano2,ano1;
       if (id<1){
       printf("Dados incorretos. Pressione uma tecla para sair.");
       }
       else{
            if (id>0){
       printf("Entre com sua idade atual ou que sera completada este ano: ");
       scanf("%d",&id);
       printf("Informe o ano atual: ");
       scanf("%d",&ano2);
       ano1=ano2-id;
       printf("Seu ano de nascimento foi em %d.",ano1);
       }
       }
       getch();
       }
