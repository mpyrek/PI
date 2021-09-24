#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    long long int n=0;
    scanf("%lli",&n);

    int len=1;
    long long int dzielnik=1;
    long long int tmp=n;

    while(tmp/10!=0){
        tmp=tmp/10;
        len++;
        dzielnik=dzielnik*10+1;
    }
    long long int liczba=0;

    while(n!=0){
        if(n/dzielnik>=0 && n/dzielnik<10){
            liczba+=(n/dzielnik)*pow(10,len-1);
            len--;
            n=n%dzielnik;
            dzielnik/=10;
        }
        else if((n/dzielnik)>=10){
            liczba=-1;
            n=0;
        }
    }
    if(liczba!=-1){
        printf("%lli",liczba);
    }
    else{
        printf("%d",-1);
    }
}
