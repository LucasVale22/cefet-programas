main(){
       int a[101],b[101],c[101],i,j,l=1;
       printf("Cite a quantidade do vetor a: ");
       scanf("%d",&a[0]);
       printf("Cite a quantidade do vetor b: ");
       scanf("%d",&b[0]);
       for(i=1;i<=a[0];i++){
           printf("Entre com o elemnto%d do vetor a: ",i);
           scanf("%d",&a[i]);
           for(j=1;j<=b[0];j++){
                printf("Entre com o elemento%d do vetor b: ",j);
                scanf("%d",&b[j]);
                if(b[j]==a[i])
                     c[l]=b[j];
                     l++;
                     }
                     }
        printf("Este eh vetor c, que contem a interseccao dos vetores a e b:\n");
        for(i=1;i<c[0];i++)
             printf("%d",c[i]);
        getch();
        }
                                                                    
          
           
       
           
           
           
