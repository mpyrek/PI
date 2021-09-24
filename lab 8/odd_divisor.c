#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    unsigned long long int suma=0;
    int s;

    for(int i=1;i<=n;i+=2){
        s=i;
        while(s<=n){
            suma += i;
            s =s*2;
        }
    }
    printf("%llu",suma);

}
