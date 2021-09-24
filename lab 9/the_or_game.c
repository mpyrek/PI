#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void count_of_the_same_position(int a,int *RES,int le){
    int x;

    for(int i=0;i<le;i++){
        x=a|(1<<i);

        if( x == a ){
            RES[le-i-1]=RES[le-i-1]+1;
        }
    }
}

int main()
{
    int n;
    int g;
    scanf("%d",&n);
    scanf("%d",&g);

    if(n==1){
        printf("%d",0);
    }
    else{
        int *T;
        T=(int*)malloc(sizeof(int)*n);

        for(int i=0;i<n;i++){
            scanf("%d",&T[i]);
        }
        int p=g;
        int le=0;

        while(p>0){
            p=p/2;
            le++;
        }

        int *RES;
        RES=(int*)malloc(sizeof(int)*le);

        for(int i=0;i<le;i++){
            RES[i]=0;
        }

        for(int i=0;i<n;i++){
            if((g|T[i]) == g){
                count_of_the_same_position(T[i],RES,le);
            }
        }

        int count=pow(10,6);
        for(int i=0;i<le;i++){
            if((g|(1<<i))==g){
                if(count>RES[le-i-1]){
                    count=RES[le-i-1];
                }
            }
        }

        if(count!=pow(10,6)){
            printf("%d",count);
        }
        else{
            printf("%d",0);
        }
        free(T);
        free(RES);
    }
}
