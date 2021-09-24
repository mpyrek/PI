#include <stdio.h>
#include <stdlib.h>

int licz(int **T,int **S,int **G,int n){
    for(int i=0;i<n;i++){
        if(T[0][i]==0){
            G[0][i]=1;
        }
        else{
            G[0][i]=0;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(T[i][j]==0){
                G[i][j]=1+G[i-1][j];
            }
            else{
                G[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k=j-1;
            S[i][j]=G[i][j];
            int minimum=G[i][j];
            int z=0;
            while(k>=0){
                if(minimum<=G[i][k]){
                    z=minimum*(j-k+1);
                }
                else{
                    minimum=G[i][k];
                    z=minimum*(j-k+1);
                }
                if(S[i][j]<z){
                    S[i][j]=z;
                }
                k--;
            }
        }
    }

    int z=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(z<S[i][j]){
                z=S[i][j];
            }
        }
    }
    printf("%d", z);
}


int main()
{
    int n=0;
    scanf("%d",&n);
    int **T;

    T=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        T[i]=(int*)malloc(n*sizeof(int));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&T[i][j]);
        }
    }

    int **G;

    G=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        G[i]=(int*)malloc(n*sizeof(int));
    }

    int **S;

    S=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        S[i]=(int*)malloc(n*sizeof(int));
    }

    licz(T,S,G,n);

    for(int i=0;i<n;i++){
        free(T[i]);
        free(S[i]);
        free(G[i]);
    }
    free(S);
    free(T);
    free(G);

}
