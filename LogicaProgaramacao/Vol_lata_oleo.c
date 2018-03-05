main(){
       #define PI 3.1415
       float r,h,v;
       printf("Entre com um raio de uma lata de oleo: ");
       scanf("%f",&r);
       printf("Entre com a altuta dessa lata: ");
       scanf("%f",&h);
       v=PI*pow(r,2)*h;
       printf("O volume dessa lata sera de %.2f cm3",v);
       getch();
       }
