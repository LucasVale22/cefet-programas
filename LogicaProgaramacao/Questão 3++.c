main() {
    int matriz[10][10];
    int i;
    int j;
    int x;
    int y;
    for (i=0 ; i<10 ; i++)
        for (j=0 ; j<10 ; j++) 
            matriz[i][j] = 0;   
    
    
    printf("\nEntre com x e y: \n");
    scanf("%d%d",&x,&y);
    
    for(i=x-1 ; i<=x+1 ; i++)
        for (j=y-1 ; j<=y+1 ; j++)
            if (((i!=x)||(j!=y))&&((i>=0)&&(j>=0)&&(i<10)&&(j<10)))
                matriz[i][j] = 1;        
    

    for (i=0 ; i<10 ; i++){
        printf("\n\n");
        for (j=0 ; j<10 ; j++){
            printf(" %d",matriz[i][j]);
        }
    }
    getch();         

}

