#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **F(int **T, int n){
    int p=0;
    int sum=n*n;
    int i=0;
    int j=0;
    int sum2=1;

    while(sum2<=sum){
        while(i<n-p && sum2<=sum){
            T[i][j]=sum2;
            sum2++;
            i++;
        }
        i--;
        j++;

        while(j<n-p && sum2<=sum){
            T[i][j]=sum2;
            sum2++;
            j++;
        }
        j--;
        i--;

        while(i>=p && sum2<=sum){
            T[i][j]=sum2;
            sum2++;
            i--;
        }
        i++;
        j--;

        p++;

        while(j>=p && sum2<=sum){
            T[i][j]=sum2;
            sum2++;
            j--;
        }

        j++;
        i++;
    }
    int l=0;
    int z=sum-10;
    z=sqrt(z);

    while(sum2!=0){
        sum2=sum2/10;
        l++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t=T[j][i];
            int l2=0;
            while(t!=0){
                t=t/10;
                l2++;
            }
            for(int k=0;k<(l-l2);k++){
                printf(" ");
            }
            printf(" %d",T[j][i]);
        }
        printf("\n");
    }
    return T;
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


    F(T,n);
    for(int i=0;i<n;i++){
        free(T[i]);
    }
    free(T);
}
