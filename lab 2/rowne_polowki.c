#include <stdio.h>
#include <stdlib.h>

int equal_halves(int T[],int size){
    int sum1=0;
    int sum2=0;
    int idx=size/2;

    for(int i=0;i<=size/2-1;i++){
        sum1+=T[i];
    }

    for(int i=(size/2)+1;i<size;i++){
        sum2+=T[i];
    }

    if(sum1==sum2) return idx;

    while(idx!=0 && idx!=size-1){
        if(sum1!=sum2){
            if(sum1<sum2){
                sum1+=T[idx];
                idx+=1;
                sum2-=T[idx];
            }
            else{
                sum2+=T[idx];
                idx-=1;
                sum1-=T[idx];
            }
        }
        else{
            return idx;
        }
    }
}



int main()
{
    int n;
    scanf("%d",&n);


    int *T;
    T=(int*)malloc(n * sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",&T[i]);
    }

    int k=equal_halves(T,n);

    printf("%d \n",k);

    free(T);
    T=NULL;
}
