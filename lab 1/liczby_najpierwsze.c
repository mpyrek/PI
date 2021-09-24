#include <stdio.h>
#include <stdlib.h>


int is_descending_sequence(int n){
    int o_b_last=0;
    int last=n%10;
    n=n/10;

    while(n>0){
        o_b_last=n%10;
        if(o_b_last>last){
            return -1;
        }
        n=n/10;
        last=o_b_last;
    }
    return 1;
}


int is_prime(int n){
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return -1;
        }
    }
    return 1;
}


int main(){
    int n=0;
    scanf("%d",&n);
    if(n>=2){
        printf("2 \n");
    }

    for(int i=3;i<=n;i+=2){
        if(is_prime(i)==1){
                if(is_descending_sequence(i)==1){
                    printf("%d \n",i);
                }
        }
    }
    return 0;
}
