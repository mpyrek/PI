#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int my_compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a >_b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

void find_min(int *A,int n, int k){
    while(k!=0 && n>0){

       if(A[0]!=0){
            A[0]=A[0]/2;

            k=k-1;

            if(A[0]<A[1]){
                int j=1;
                while( j<n && A[j-1]<A[j]){
                    int temp=A[j-1];
                    A[j-1]=A[j];
                    A[j]=temp;
                    j++;

                }
            }
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        count+=A[i];
    }
    printf("%d",count);

}

int main()
{
    int N,K;
    scanf("%d",&N);
    scanf("%d",&K);

    int *T;
    T=(int*)malloc(N*sizeof(int));

    for(int i=0;i<N;i++){
        scanf("%d",&T[i]);
    }
    qsort(T,N,sizeof(int),my_compare);
    find_min(T,N,K);

}
