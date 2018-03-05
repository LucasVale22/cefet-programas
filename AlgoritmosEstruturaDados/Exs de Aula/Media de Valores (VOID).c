void media(float a,float b){
    float m;
    m=(a+b)/2;
    printf("A media sera: %.2f",m);
}
main(){
    float a,b;
    printf("Entre com dois valores: ");
    scanf("%f%f",&a,&b);
    media(a,b);
    getch();
}
