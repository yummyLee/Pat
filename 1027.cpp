#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{

    int num[3];
    scanf("%d%d%d",&num[0],&num[1],&num[2]);
    int base=13;
    stack<int> s;

    char res[8];
    res[0]='#';
    int charCount=1;
    for(int i=0; i<3; i++)
    {
        int number=num[i];

        if(number==0){
            res[charCount++]='0';
            res[charCount++]='0';
        }

        while(number!=0)
        {
            int temp=number/base;
            int a=number-temp*base;
            s.push(a);
//            printf("%d\n",a);
            number=temp;
        }
        if(s.size()==1){
            res[charCount++]='0';
        }
        while(!s.empty()){
            int temp=s.top();
//            printf("%d %d\n",temp,charCount);
            s.pop();
            if(temp<10){
//                printf("%d %c\n",temp,temp+'0');
                res[charCount++]=temp+'0';
            }else{
//                printf("%d %c\n",temp,('0'-('0'-'A'))+(temp-10));
                res[charCount++]=('0'-('0'-'A'))+(temp-10);
            }
        }

    }

    printf("%s",res);

    return 0;
}

