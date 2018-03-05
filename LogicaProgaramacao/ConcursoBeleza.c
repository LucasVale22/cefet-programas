main(){
 float alt, maior1, maior2; 
 char nome[100];
 maior1=0; 
 maior2=0; 
 printf("Entre com o nome: ");
 scanf("%s",&nome);
 printf("Entre com a altura: ");
 scanf("%f",&alt);
 while(nome!="vazio"){
    printf("%s %.2f\n",nome,alt); 
    if(alt>maior1){
       maior2=maior1; 
       maior1=alt;  
       }
    
      else{
        maior2=alt;
        

              }
  printf("Entre com o nome: ");
  scanf("%s",&nome); 
}
 printf("As duas maoires slturas sao: ",maior1,maior2);
 getch();
}

