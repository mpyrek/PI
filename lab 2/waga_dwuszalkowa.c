#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool two_pan_scale(int *T,int idx,int do_odwazenia, int n){
    if (do_odwazenia==0){
        return true;
    }
    if(idx==n){
        return false;
    }

    return (two_pan_scale(T,idx+1,do_odwazenia-T[idx],n) || two_pan_scale(T,idx+1,do_odwazenia+T[idx],n) || two_pan_scale(T,idx+1,do_odwazenia,n));

}


int main(){
    int n,w;
    scanf("%d",&n);
    scanf("%d",&w);

    int *T;
    T=(int*)malloc(n*sizeof(int));

    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&T[i]);
        count+=T[i];
    }

    if(count < w){
        printf("NO");
    }
    else{
        if(count==w){
            printf("YES");
        }
        else{

            if(two_pan_scale(T,0,w,n)==true){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
    }
}



