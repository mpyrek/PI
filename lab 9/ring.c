#include <stdio.h>
#include <stdlib.h>


int is_prime(int a){
    if(a==2 ||a==3) return 1;
    if(a%2==0) return 0;

    for(int i=3;i*i<a;i+=2){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    char s[50];
    scanf("%s",s);

    int len=0;
    for (len = 0; s[len] != '\0'; len++);

    char a=s[0];
    int *T;
    T=(int*)malloc(sizeof(int)*len);
    int idx=1;
    T[0]=0;
    char *R;
    R=(char*)malloc(sizeof(char)*len);

    for(int i=1;i<len;i++){
        if(a>s[i]){
            idx=0;
            T[0]=i;
            a=s[i];
            idx++;
        }
        else if (a==s[i]){
            T[idx]=i;
            idx++;
        }
    }

    for(int i=0;i<len;i++){
        R[i]='z';
    }



    for(int i=0;i<idx;i++){
        for(int j=2;j<len;j++){
            int flag=1;
            if(is_prime(j)){
                for(int p=0;p<len;p++){
                    if(flag!=0){
                        if(flag==1){
                            if(R[p]>s[(T[i]+j*p)%(len)]){
                                R[p]=s[(T[i]+j*p)%(len)];
                                flag=2;
                                }
                            else if (R[p]<s[(T[i]+j*p)%(len)]){
                                flag=0;
                            }
                        }
                        else if(flag==2){
                            R[p]=s[(T[i]+j*p)%(len)];
                        }
                    }
                }
            }
        }
    }


    for(int i=0;i<len;i++){
        printf("%c",R[i]);
    }
    free(R);
    free(T);

}
