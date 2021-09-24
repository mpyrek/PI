#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n;
    long int m;
    scanf("%d",&n);
    scanf("%li",&m);

    long int max_number=pow(2,n);
    long int tmp_number;
    long int bit;
    long int licz=0;
    int flag=0;

    for(long int i=1;i<max_number;i++){
        flag=0;
        if(i%m!=0){
            for(int j=0;j<n;j++){
                if(flag==0){
                    bit=(1<<j);
                    tmp_number=i^bit;

                    if(tmp_number!=0  && tmp_number%m==0){
                        licz++;
                        flag=1;
                    }
                }
            }
        }
    }

    printf("%li",licz);
}
