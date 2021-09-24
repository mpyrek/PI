#include <stdio.h>
#include <stdlib.h>

int fibbonaci(int n){
    int a=0;
    int b=1;
    int c=a+b;
    while(c<=n){
        if(a*b==n){
            return 1;
        }
        c=a+b;
        a=b;
        b=c;
    }
    return -1;
}
int main(){
    int a=0;
    scanf("%d",&a);

    if(fibbonaci(a)==1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}

