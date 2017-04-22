#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        bool flag = true;
        long long res = a + b;
        if(a<0&&b<0&&res>0){
            flag=false;
        }else if(a>0&&b>0&&res<0){
            flag=true;
        }else if(a+b>c){
            flag=true;
        }else{
            flag=false;
        }
        if(flag){
            printf("Case #%d: true\n",i+1);
        }else{
            printf("Case #%d: false\n",i+1);
        }
    }


    return 0;
}

