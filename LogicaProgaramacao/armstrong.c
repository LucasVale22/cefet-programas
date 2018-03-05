//Esta sera a função que ocupara o lugar do pow
int pow2(int n,int e){
    if(e==1){
             return(n);
             }
    else{
         return(n*pow(n,e-1));
         }
                     }
//Esta ira dividir o numero em algarismos para contar quantos algarismos são, esse numero sera expresso por e.
int nalgarismos(int n,int e){
    if(n/(pow2(10,e))==0){
                        return(e);
                        }
    else{
         return(nalgarismos(n,e+1));
         }
                           }
//Esta ira redividir o numero e agora ira elevalo ao numero de algarismos e soma-lo com os outros.
int algarismos(int n,int e,int e2){
    if((e2==1) || (e2!=e)){
               return(pow2((n-((n/10)*10)),e)+algarismos(n,e,e2+1));
                           }
    else{
         if(e2==e){
                  return(pow2((n-n%pow2(10,e-1))/pow2(10,e-1),e));
                  }
         else{
              return(pow2((n-(pow2(10,e2-1)))-((n/pow2(10,e2))*pow2(10,e2))/pow2(10,e2-1),e)+algarismos(n,e,e2+1));
              }
         }
                                 }
//OBS: E=numero de algarismos. E2= Numero do algarismo que esta sendo trabalhado no loop da recursão
         main(){
                int n;
                printf("Entre com um numero");
                scanf("%d",&n);
                int e=(nalgarismos(n,1));
                if(n==algarismos(n,e,1)){
                                        printf("Este e um numero de amstrong");
                                        }
                else{
                     printf("Este não e um numero de amstrong");
                     }
                getch();
                }
