void imprime1(int z,int *x,int y){
     z*=z;
     *x+=y+z;
     y=*x+z;
     printf("y=%d x=%d z=%d",y,*x,z);
}
void imprime2(int *y,int z,int x){
     *y+=x;
     z=x;
     x=z;
     printf("z=%d x=%d y=%d",z,x,*y);
}
main(){
       int x,y,z;
       x=1;y=3;z=2;
       imprime1(x,&y,z);
       printf("x=%d y=%d z=%d",x,y,z);
       imprime2(&x,y,z);
       printf("x=%d y=%d z=%d",x,y,z);
       getch();
}     
