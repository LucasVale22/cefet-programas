int prova(int *b,int a){
    int aux;
    if(*b==1)
             return 0;
    else{
         *b=a;
         aux=prova(b,a-1) + *b + a;
         a+=2;
         *b+=3;
         }
    return aux;
}
main(){
       int *a,*b,*c;
       printf("Entre com um valor: ");
       a=(int*)malloc(sizeof(int));
       scanf("%d",&*a);
       b=(int*)malloc(sizeof(int));
       *b=*a;
       c=(int*)malloc(sizeof(int));
       *c=prova(a,*b);
       printf("%d %d %d",*a,*b,*c);
       getch();
       }
     
