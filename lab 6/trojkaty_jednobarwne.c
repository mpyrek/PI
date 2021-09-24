#include <stdio.h>
#include <stdlib.h>

int count(int *T,int n){
    for(int i=1;i<n+1;i++){
        T[i]=T[i]*(n-1-T[i]);
    }

    int suma=0;
    for(int i=1;i<n+1;i++){
     suma+=T[i];
    }

    suma=suma/2;

    int ilosc_wszystkich_trojkatow=n*(n-1)*(n-2)/6;
    int wynik=ilosc_wszystkich_trojkatow-suma;
    printf("%d ",wynik);
}



int main()
{
    int n=0;
    scanf("%d",&n);
    int m=0;
    scanf("%d",&m);

    int *T;
    T=(int*)malloc((n+1)*sizeof(int));

    for(int i=1;i<n+1;i++){
        T[i]=0;
    }

    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);

        T[x]+=1;
        T[y]+=1;
    }

    count(T,n);
    free(T);

}
