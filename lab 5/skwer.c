#include <stdio.h>
#include <stdlib.h>

void F(int **T,int **W,int **S1,int n,int sum){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=T[i][j];
            S1[i][j]=sum;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            T[j][i]=T[j-1][i]+T[j][i];
        }
    }

    int idx=0;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k=2;
            while(j+k<n && i+k<n){
                int suma=0;
                if(j==0){
                    suma+=S1[i][j+k];
                    suma+=S1[i+k][j+k];
                    suma+=T[i+k-1][j]-T[i][j];
                    suma+=T[i+k-1][j+k]-T[i][j+k];
                }

                else{
                    suma+=S1[i][j+k]-S1[i][j-1];
                    suma+=S1[i+k][j+k]-S1[i+k][j-1];
                    suma+=T[i+k-1][j]-T[i][j];
                    suma+=T[i+k-1][j+k]-T[i][j+k];
                }

                if(suma==sum){
                    W[idx][0]=(i+k/2);
                    W[idx][1]=(j+k/2);
                    count++;
                    idx++;
                }
                k+=2;

            }
        }
    }

    printf("%d \n",count);
    for(int i =0;i<idx;i++){
        for(int j=0;j<2;j++){
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }

}


int main()
{
    int n=0;
    scanf("%d",&n);
    int sum=0;
    scanf("%d",&sum);

    int **W;
    W=(int**)malloc(n*n*sizeof(int*));

    for(int i=0;i<n*n;i++){
        W[i]=(int*)malloc(2*sizeof(int));
    }

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

    int **S1;
    S1=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        S1[i]=(int*)malloc(n*sizeof(int));
    }

    F(T,W,S1,n,sum);

    for(int i=0;i<n;i++){
        free(T[i]);
        free(S1[i]);
    }

    for(int i=0;i<2;i++){
        free(W[i]);
    }

    free(S1);
    free(T);
    free(W);
    return 0;
}
