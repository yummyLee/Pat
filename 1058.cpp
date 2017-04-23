#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){

    int h1,m1,l1,h2,m2,l2,h3,m3,l3;
    char c;
    scanf("%d%c%d%c%d%d%c%d%c%d",&h1,&c,&m1,&c,&l1,&h2,&c,&m2,&c,&l2);
//    printf("%d %d %d %d %d %d\n",h1,m1,l1,h2,m2,l2);
    l3=l2+l1;
    int carry=0;
    if(l3>=29){
        carry=1;
        l3-=29;
    }
    m3=m2+m1+carry;
    carry=0;
    if(m3>=17){
        carry=1;
        m3-=17;
    }
    h3=h1+h2+carry;
    printf("%d.%d.%d\n",h3,m3,l3);

    return 0;
}
