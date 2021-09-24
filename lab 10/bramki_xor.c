#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);

    int **T;
    T=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=1;i<m+1;i++){
        T[i]=(int*)malloc(sizeof(int)*2);
    }
    for(int i=1;i<m+1;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&T[i][j]);
        }
    }

    char liczba[100];
    char liczba2[100];

    scanf("%s",&liczba);
    scanf("%s",&liczba2);

    int suma=0;
    int **bit;
    int *exit;
    bit=(int**)malloc(sizeof(int*)*(m+1));
    exit=(int*)malloc(sizeof(int)*(m+1));
    for(int i=1;i<m+1;i++){
        exit[i]=-2;
    }
    for(int i=1;i<m+1;i++){
        bit[i]=(int*)malloc(sizeof(int)*2);
    }

    int flag=1;
    int i=0;
    int flag2=0;

    while(flag2==0){
        for(int i=1;i<m+1;i++){
            bit[i][0]=-1;
            bit[i][1]=-1;
            exit[i]=-2;
        }
        flag=1;
        while(flag==1){
            flag=0;
            for(int i=1;i<m+1;i++){
                if(exit[i]<0){
                    flag=1;
                    if(bit[i][0]==-1 && T[i][0]<0){
                        bit[i][0]=liczba[abs(T[i][0])-1]-48;
                        exit[i]++;
                    }
                    else if(bit[i][0]==-1 && T[i][0]>0 && exit[T[i][0]]>=0){
                        bit[i][0]=exit[T[i][0]];
                        exit[i]++;
                    }

                    if(bit[i][1]==-1 && T[i][1]<0 && exit[i]<0){
                        bit[i][1]=liczba[-T[i][1]-1]-48;
                        exit[i]++;
                    }
                    else if(bit[i][1]==-1 && T[i][1]>0 && exit[T[i][1]]>=0){
                        bit[i][1]=exit[T[i][1]];
                        exit[i]++;
                    }
                    if(exit[i]==0){
                        exit[i]=bit[i][0]^bit[i][1];
                        if(i==k){
                            flag=1;
                            break;
                        }
                    }
                }
            }
        }
        if(exit[k]==1){
            printf("%s \n",liczba);
        }
        suma+=exit[k];
        flag2=1;
        for(int i=0;i<n;i++){
            if(liczba[i]!=liczba2[i]){
                flag2=0;
            }
        }
        if(flag2==1) break;
        int p=n-1;
        while(p>=0 && liczba[p]=='1'){
            liczba[p]='0';
            p--;
        }
        if(p>=0) liczba[p]='1';
    }
    printf("%d",suma);

    for(int i=1;i<m+1;i++){
        free(T[i]);
        free(bit[i]);
    }
    free(bit);
    free(T);
    free(exit);
}


