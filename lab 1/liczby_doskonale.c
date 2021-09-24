#include <stdio.h>
#include <stdlib.h>

int czy_doskonala(int n){
    if(n==1){
        return -1;
    }
    int tmp_n=n;
    tmp_n-=1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                    if(i!=n/i){
                        tmp_n-=(i+n/i);
                    }
                    else{
                        tmp_n-=i;
                    }
            }
            if(tmp_n<0){
                return -1;
            }
        }
    if(tmp_n!=0){
        return -1;
    }
    return 1;
}

int main(){
    int a=0;
    int b=0;
    scanf("%d",&a);
    scanf("%d",&b);

    int count=0;
    for(int i=a;i<=b;i++){
        if(czy_doskonala(i)==1){
            count++;
        }
    }
    printf("%d \n",count);

    for(int i=a;i<=b;i++){
        if(czy_doskonala(i)==1){
            printf("%d ",i);
        }
    }
    return 0;
}

