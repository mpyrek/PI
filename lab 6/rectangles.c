#include <stdio.h>
#include <stdlib.h>

int X(int **T,int **W,int k){
    int suma=0;

    for(int i=0;i<k;i++){
        for(int x=W[i][0]+100;x<W[i][2]+100;x++){
            for(int y=W[i][1]+100;y<W[i][3]+100;y++){
                if(T[x][y]==0){
                    suma++;
                    T[x][y]=1;
                }
                else{
                    suma--;
                    T[x][y]=0;
                }
            }
        }
    }
    printf("%d ",suma);
}

int main()
{

    int k=0;
    scanf("%d",&k);

    int **T;
    T=(int**)malloc(202*sizeof(int*));

    for(int i=0;i<202;i++){
        T[i]=(int*)malloc(202*sizeof(int));
    }

    int **W;
    W=(int**)malloc(k*sizeof(int*));

    for(int i=0;i<k;i++){
        W[i]=(int*)malloc(4*sizeof(int));
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&W[i][j]);
        }
    }
    for(int i=0;i<202;i++){
        for(int j=0;j<202;j++){
            T[i][j]=0;
        }
    }

    X(T,W,k);

    for(int i=0;i<202;i++){
        free(T[i]);
    }
    free(T);
    for(int i=0;i<k;i++){
        free(W[i]);
    }
    free(W);


}















