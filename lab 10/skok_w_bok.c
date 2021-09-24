#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n;
   scanf("%d",&n);
    int **T;
    T=(int**)malloc(sizeof(int*)*n);

    for(int i=0;i<n;i++){
        T[i]=(int*)malloc(sizeof(int)*2);
    }
    int max=0;
    int min=1000000000;
    for(int i=0;i<n;i++){
        scanf("%d",&T[i][0]);
        scanf("%d",&T[i][1]);
        if(T[i][0]>max){
            max=T[i][0];
        }
        if(T[i][0]<min){
            min=T[i][0];
        }
    }
    int *P;
    P=(int*)malloc(sizeof(int)*(max-min+200));

    for(int i=0;i<max-min+200;i++){
        P[i]=0;
    }

    for(int i=0;i<n;i++){
        P[T[i][0]+50]=T[i][1];
    }

    int end=min+50;
    int start=max-min+50;
    int i=end;

    while(i<=start){
        if(P[i]>=3){
            P[i-2]+=1;
            P[i+2]+=1;
            P[i]-=3;
            i=i-3;
            if(end>i+1) end=i+1;
            if(start<i+5) start=i+5;
        }
        i++;
    }
    start=start;

    while(start>=end){
        if(P[start]>0 && P[start+1]>0){
            P[start+2]+=1;
            P[start]-=1;
            P[start+1]-=1;
            start+=2;
        }
        else if(P[start]==2 && P[start-1]>0){
            start=start-1;
        }
        else if(P[start]==2 && P[start+1]==0){
            P[start-1]+=1;
            P[start-2]+=1;
            P[start]-=1;
            P[start-1]-=1;
            P[start]-=1;
            P[start+1]+=1;
            if(end>start-1) end=start-1;
            start++;
        }
        else if(P[start] == 3){
            P[start-2]+=1;
            P[start+2]+=1;
            P[start]-=3;
            start=start+2;
            if(end>start-2) end=start-2;
        }
        else{
            start--;
        }
   }
    for(int i=0;i<max-min+200;i++){
        if(P[i]!=0){
            printf("%d ",i-50-min);
        }
    }
    free(P);
    for(int i=0;i<n;i++){
        free(T[i]);
    }
    free(T);

}
