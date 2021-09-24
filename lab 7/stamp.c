#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    else return b;
}


int main()
{
    int n,s1,s2;
    scanf("%d",&n);
    scanf("%d",&s1);
    scanf("%d",&s2);

    int **T;
    int **B;
    T=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        T[i]=(int*)malloc(sizeof(int)*n);
    }

    B=(int**)malloc(s1*sizeof(int*));

    for(int i=0;i<s1;i++){
        B[i]=(int*)malloc(sizeof(int)*s2);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&T[i][j]);
        }
    }

    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            scanf("%d",&B[i][j]);
        }
    }

    int max_suma=0;
    for(int i=0;i<n-s1;i++){
        for(int j=0;j<n-s2;j++){
            int suma=0;
            for(int k=0;k<s1;k++){
                for(int z=0;z<s2;z++){
                    if(B[k][z]==1){
                        suma+=T[i+k][j+z];
                    }
                }
            }
            if(suma>max_suma){
                max_suma=suma;
            }
        }
    }
    printf("%d",max_suma);

    for(int i=0;i<n;i++){
        free(T[i]);
    }
    for(int i=0;i<s1;i++){
        free(B[i]);
    }
    free(T);
    free(B);
}
