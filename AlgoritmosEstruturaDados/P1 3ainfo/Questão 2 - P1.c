int decbin(int a,int i){
    int aux;
    if(a==0)
            return 0;
    else
        aux = (a%2)*pow(10,i-1) + decbin(div(a,2),i+1); //eis o trecho inserido...
    return aux;
}
main(){
       int a;
       printf("Entre com um numero decimal: ");
       scanf("%d",&a);
       printf("O numero decimal %d eh equivalente ao numero %d binario",a,decbin(a,1));
       getch();
       }
            
