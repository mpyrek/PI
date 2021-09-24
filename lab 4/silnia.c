#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *T;
    T=(int*)malloc(500 * sizeof(int));

    int n;
    scanf("%d",&n);

    T[0]=1;
    int size=1;

    for(int i=2;i<=n;i++){
        int carry=0;
        int prod=0;
        for(int s=0;s<size;s++){
            prod=T[s]*i+carry;
            carry=prod/10;
            T[s]=prod%10;
        }
        while(carry!=0){
            T[size]=carry%10;
            carry=carry/10;
            size++;
        }
    }

    for(int i=size-1;i>=0;i--){
        printf("%d",T[i]);
    }


    free(T);
    return 0;
}
