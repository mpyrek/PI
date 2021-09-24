#include <stdio.h>
#include <stdlib.h>

int my_compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}


int count_pair(int *T,int k,int n){
    int count=0;
    int j=0;
    while(j<n){
        int ok=0;
        int left=j-1;
        int right=j+1;

        if(left>=0 && T[left ]>= T[j]-k){
            ok=1;
        }
        while(right<n && T[right]==T[j]){
            right++;
        }
        if(right<n && T[right]<=T[j]+k){
            ok=1;
        }
        if(ok==1){
            count+=right-j;
        }
        j=right;
    }
    printf("%d",count);
}


int main()
{
    int N,K;
    scanf("%d",&N);
    scanf("%d",&K);

    int *T;
    T=(int*)malloc(N*sizeof(T));

    for(int i=0;i<N;i++){
        scanf("%d",&T[i]);
    }

    qsort(T,N,sizeof(int),my_compare);
    if(K!=0){
        count_pair(T,K,N);
    }
    else{
        printf("%d",0);
    }
}
