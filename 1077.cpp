#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char **charss;

int main(){

    int n;
    int maxSuffix=257;
    scanf("%d",&n);
    charss=new char*[n];
    charss[0]=new char[257];
    getchar();
    gets(charss[0]);
//    printf("%s\n",charss[0]);
    int preLen=strlen(charss[0]);
    for(int i=1;i<n;i++){
        charss[i]=new char[257];
        gets(charss[i]);
//        printf("%s\n",charss[i]);
        int curLen=strlen(charss[i]);
        int minLen=curLen<preLen?curLen:preLen;
        int curMax=0;
        for(int j=0;j<minLen;j++){
            if(charss[i][curLen-1-j]==charss[i-1][preLen-1-j]){
                curMax++;
            }else{
                break;
            }
        }
        preLen=curLen;
        maxSuffix=min(curMax,maxSuffix);
    }


    for(int i=preLen-maxSuffix;i<preLen;i++){
        printf("%c",charss[n-1][i]);
    }


    if(maxSuffix==0){
        printf("nai\n");
    }else{
        printf("\n");
    }

    return 0;
}
