#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{

    char numSign;
    scanf("%c",&numSign);
    char nums[10100];
    char preNum[10100];
    scanf("%s",nums);
    int len=strlen(nums);
    int eIndex=-1;
    int preNumCount=0;
    for(int i=0; i<len; i++)
    {
        if(nums[i]=='E')
        {
            eIndex=i;
            break;
        }
        if(nums[i]!='.')
        {
            preNum[preNumCount++]=nums[i];
        }
    }
    char expSign=nums[eIndex+1];
    char *exps;
    exps=new char[len-eIndex];
    int expsCount=0;
    bool isStart=false;
    for(int i=eIndex+2; i<len; i++)
    {
        if(nums[i]=='0'&&!isStart)
        {
            continue;
        }
        else
        {
            isStart=true;
            exps[expsCount++]=nums[i];
        }
    }
    int expNum;
    sscanf(exps,"%d",&expNum);

    if(expNum==0)
    {
        for(int i=1; i<eIndex; i++)
        {
            printf("%c",nums[i]);
        }
        return 0;
    }

    if(numSign=='-')
    {
        printf("%c",numSign);
    }

    if(expSign=='-')
    {

        printf("0.");
        for(int i=0; i<expNum-1; i++)
        {
            printf("0");
        }
//        //这里有一个坑，下面这句不行
//        printf("%s",preNum);
        //下面这个可以
        printf("%c",nums[0]);
        for(int i=2; i<eIndex; i++)
        {
            printf("%c",nums[i]);
        }
    }

    if(expSign=='+')
    {
        int preNumLen=strlen(preNum);
        if(preNumLen-1>expNum)
        {
            for(int i=0; i<=expNum; i++)
            {
                printf("%c",preNum[i]);
            }
            printf(".");
            for(int i=expNum+1; i<preNumLen; i++)
            {
                printf("%c",preNum[i]);
            }
        }
        else
        {
            printf("%s",preNum);
            int zeroLen=expNum-strlen(preNum);
            for(int i=0; i<=zeroLen; i++)
            {
                printf("0");
            }
        }
    }

    return 0;
}
