#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int zamiana_na_system_dziesiatkowy(int n,int b){
    int liczba=0;
    int w=0;
    if (b<8){
        while(n>0){
            liczba+=n%10*pow(b,w);
            n=n/10;
            w+=1;
        }
    }


    return liczba;
}

int check_all_lower_then_b(int a,int b){
    while(a>0){
        int x=a%10;
        if(x>=b){
            return -1;
        }
        a=a/10;
    }
    return 1;
}


void generate_all_possible_digits(int T[],int b,int m){
    int idx=pow(10,m-1);
    int j=0;

    for(int i=idx;i<pow(10,m);i++){
        if((check_all_lower_then_b(i,b))==1){
            T[j]=i;
            j+=1;
        }
    }
}

int is_narcissistic(int n,int b){
    int count=0;
    int a=n;

    while(a>0){
        count+=pow(a%10,b);
        a=a/10;
    }
    if(count==zamiana_na_system_dziesiatkowy(n,b)) return 1;
    else return -1;
}


int main()
{

    int a,b,m;

    scanf("%d",&m);
    scanf("%d",&b);

    int size=pow(b,m)-pow(b,m-1);
    int *T;

    T=(int*)malloc(size * sizeof(int));

    generate_all_possible_digits(T,b,m);

    int flag=-1;

    for(int i=0;i<size;i++){
        if(is_narcissistic(T[i],b)==1){
            printf("%d \n",T[i]);
            flag=1;
        }
    }

    if flag==-1: printf("NO");


    free(T);
    T=NULL;
}
