#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int change_to_r(char* a, char** z2,int *t2,char* z1,int *t1){
    int suma=0;
    int i=0;
    int l=strlen(a);

    while(i<l){
        int flag=-1;
        for(int j=0;j<6;j++){
            if(flag!=1){
                if(a[i]==z2[j][0] && a[i+1]==z2[j][1]){
                    suma+=t2[j];
                    i++;
                    flag=1;
                }
            }
        }
        if(flag!=1){
            for(int j=0;j<7;j++){
                if(a[i]==z1[j]){
                    suma+=t1[j];
                }
            }
        }
        i++;
    }
    return suma;

}

void change_to_a(int wynik,char* z1,char** z2, int* t1,int* t2){
    char z[24];
    int i=0;
    int j=0;
    int idx=0;

    while(wynik!=0){
        int i=0;
        int j=0;
        while(i<7 && wynik-t1[i]<0){
            i++;
        }

        while(j<6 && wynik-t2[j]<0){
            j++;
        }


        if(wynik-t2[j]<0 || t1[i]>t2[j]){
            while(i<7 && wynik-t1[i]>=0){
                z[idx]=z1[i];
                wynik-=t1[i];
                idx++;
            }
            i++;
        }
        else{
            z[idx]=z2[j][0];
            z[idx+1]=z2[j][1];
            wynik-=t2[j];
            i++;
            idx+=2;
        }
    }

    for(int i=0;i<idx;i++){
        printf("%c",z[i]);
    }
}

int main()
{
    char z1[]={'M','D','C','L','X','V','I'};
    char* z2[]={"CM","CD","XC","XL","IX","IV"};
    int t1[]={1000,500,100,50,10,5,1};
    int t2[]={900,400,90,40,9,4};

    char t[26];
    char g[26];
    int wt=0;
    int wg=0;

    scanf("%s",&t);
    scanf("%s",&g);
    wt=change_to_r(t,z2,t2,z1,t1);
    wg=change_to_r(g,z2,t2,z1,t1);
    char wynik[100];
    int liczba=wt+wg;
    change_to_a(liczba,z1,z2,t1,t2);


}
