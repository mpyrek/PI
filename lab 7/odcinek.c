#include <stdio.h>
#include <stdlib.h>


int max(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);

    int **T;
    T=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        T[i]=(int*)malloc(n*sizeof(int));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&T[i][j]);
        }
    }

    int max_val=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            int suma1=T[i][j];
            int suma2=T[i][j];
            int suma3=T[i][j];
            int suma4=T[i][j];
            int suma5=T[i][j];
            int suma6=T[i][j];
            int suma11=T[i][j];
            int suma22=T[i][j];

            for(int z=1; z<k; z++){
                //odcinek w dol od i,j
                suma1+=T[(i+z)%(n)][j];
                // odcinek w prawo od i,j
                suma2+=T[i][(j+z)%(n)];
                //odcinek w gore od i,j
                suma11+=T[(i+n-z)%(n)][j];
                //odcinek w lewo od i,j
                suma22+=T[i][(j+n-z)%(n)];
                // na skos w prawo i w dol
                suma3+=T[(i+z)%(n)][(j+z)%(n)];
                // na skos w lawo i w dol
                suma4+=T[(i+n-z)%(n)][(j+z)%(n)];
                // na skos w prawo i w gore
                suma5+=T[(i+z)%(n)][(j+n-z)%(n)];
                // na skos w lewo i gore
                suma6+=T[(i+n-z)%(n)][(j+n-z)%(n)];
            }

            max_val=max(max_val,suma1);
            max_val=max(max_val,suma2);
            max_val=max(max_val,suma3);
            max_val=max(max_val,suma4);
            max_val=max(max_val,suma5);
            max_val=max(max_val,suma6);
            max_val=max(max_val,suma11);
            max_val=max(max_val,suma22);
        }
    }
    printf("%d \n",max_val);

    for(int i=0;i<n;i++){
        free(T[i]);
    }
    free(T);
}
