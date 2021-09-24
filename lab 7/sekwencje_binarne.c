#include <stdio.h>
#include <stdlib.h>

int find_number_of_string(long int len_of_first,long int len_of_second,int tmp_n,long int n){
    if(tmp_n>len_of_first) return 2;
    if (tmp_n==n){
        return len_of_second;
    }
    return find_number_of_string(len_of_second,len_of_first+len_of_second,tmp_n+1,n);

}

int a=0;

int *generate_all_strings(int n,int *arr,int k){
    for(int i=0;i<n;i++){
        arr[i]=0;
    }


    int tmp_k=1;
    while(tmp_k!=k){
        int i=n-1;
        if(arr[i]==0){
            arr[i]=1;
        }
        else{
            while(arr[i]==1){
                arr[i]=0;
                i--;
            }
            arr[i]=1;
        }
        int flag=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]==1 && arr[i+1]==1) flag=0;
        }
        if(flag==1) tmp_k++;
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}

int main(){
    long int n,k;
    scanf("%li",&n);
    scanf("%li",&k);

    long int len_of_first=2;
    long int len_of_second=3;
    long int tmp_n=2;

    long int x=find_number_of_string(len_of_first,len_of_second,tmp_n,n);

    if(x<k){
        printf("%d",-1);
    }
    else{
        int* T;
        T=(int*)malloc(n*sizeof(int));
        generate_all_strings(n,T,k);
        free(T);
    }
}
