#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

void baseConversionAndJudge(int num,int base)
{

    if(num==0)
    {
        printf("Yes\n");
        printf("0\n");
        return;
    }

    stack<int> s;
    int number=num;
    while(number!=0)
    {
        int temp=number/base;
        int a=number-temp*base;
        s.push(a);
        number=temp;
    }
//    char chars[100];
//    int charCount=0;
//    while(1)
//    {
//        sprintf(chars+charCount,"%d",s.top());
//        while(chars[charCount]!='\0')
//        {
//            charCount++;
//        }
//        s.pop();
//        if(!s.empty())
//        {
//            chars[charCount++]=' ';
//        }
//        else
//        {
//            break;
//        }
//    }
//    int len=strlen(chars);

    int len=s.size();
    int *ints=new int[len];
    int intCount=0;
    while(1){
        ints[intCount++]=s.top();
        s.pop();
        if(s.empty()){
            break;
        }
    }


    int left=0;
    int right=len-1;
    bool flag=true;
    while(left<right)
    {
        if(ints[left++]!=ints[right--])
        {
            flag=false;
        }
    }
    if(flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    for(int i=0;i<len;i++){
        printf("%d",ints[i]);
        if(i!=len-1){
            printf(" ");
        }
    }
    printf("\n");
}


int main()
{
    int num,base;
    scanf("%d%d",&num,&base);
    baseConversionAndJudge(num,base);
    return 0;
}
