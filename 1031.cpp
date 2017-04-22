#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;


int main(){

    char chars[81];
    scanf("%s",chars);
    queue<int> s;
    int len=strlen(chars);
    int n13=(len-1)/3;
    int spaceCount=len-2*n13-2;
    for(int i=0;i<n13;i++){
        printf("%c",chars[i]);
        for(int j=0;j<spaceCount;j++){
            printf(" ");
        }
        printf("%c\n",chars[len-1-i]);
    }
    for(int i=n13;i<len-n13;i++){
        printf("%c",chars[i]);
    }
    printf("\n");

    return 0;
}
