#include <stdio.h>
#include <stdlib.h>

int *merge(int *A,int *B,int n,int size){
    int a=0;
    int b=0;

    int sum=size+n;
    int *T;
    T=(int*)malloc(sum*sizeof(int*));
    int idx=0;

    while(a<size && b<n){
        if(A[a]<=B[b]){
            T[idx]=A[a];
            a++;
        }
        else{
            T[idx]=B[b];
            b++;
        }
        idx++;
    }

    while(a<size){
        T[idx]=A[a];
        a++;
        idx++;
    }
    while(b<n){
        T[idx]=B[b];
        b++;
        idx++;
    }

    return T;
}


int main()
{
    int n=0;
    scanf("%d",&n);

    int *T;

    T=(int*)malloc( n*n * sizeof(int*));

    int **arr;
    arr  = (int**)malloc(n*n * sizeof(int*));

    for(int i=0;i<n;i++){
        arr[i]=(int*)malloc(n * sizeof(int));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    T=merge(arr[0],arr[1],n,n);

    for(int i=2;i<n;i++){
            T=merge(T,arr[i],n,n*i);
    }

    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    free(arr);

    int idx=0;
    int item=1;
    printf("%d ",T[0]);

    while(item<n*n){
        if(T[idx]!=T[item]){
            printf("%d ",T[item]);
            idx++;
            item++;
        }
        else{
            while(T[idx]==T[item]){
                idx++;

            }
            idx=item;
            item=item+1;
        }
    }

    free(T);

    return 0;
}
