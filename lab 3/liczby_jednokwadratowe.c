#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n){
    if(n<2) return -1;
    if(n==2 || n==3) return 1;
    if(n%2==0) return -1;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return -1;
        }
    }
    return 1;
}

int jednokwadratowa(int n){
    int liczba=0;

    while(n!=1 && n!=4){
        liczba=0;
        while(n>0){
            int x=n%10;
            if(x!=0) liczba+=pow(x,2);
            n=n/10;
        }
        n=liczba;
    }
    if(n==1) return 1;
    else return -1;
}


int main()
{
    int L,U,K;
    scanf("%d",&L);
    scanf("%d",&U);
    scanf("%d",&K);

    int count=0;

    while(L<=U && count!=K){
        if(is_prime(L)==1 && jednokwadratowa(L)==1){
            count+=1;
        }
        if(count==K) break;
        L+=1;
    }
    if(count==K){
        printf("%d",L);
    }
    else{
        printf("%d",-1);
    }
}
