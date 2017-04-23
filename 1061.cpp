#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{

    char f1[61],f2[61],s1[61],s2[61];
    scanf("%s%s%s%s",f1,f2,s1,s2);
    int len1=strlen(f1)<strlen(f2)?strlen(f1):strlen(f2);
    int len2=strlen(s1)<strlen(s2)?strlen(s1):strlen(s2);
    bool isDay=true;
    int day,hour,minute;
    for(int i=0; i<len1; i++)
    {
        if(isDay&&f1[i]>='A'&&f1[i]<='G'&&f1[i]==f2[i])
        {
            day=f1[i]-'A'+1;
//            printf("day=%d\n",day);
            isDay=false;
        }
        else if(!isDay&&f1[i]>='A'&&f1[i]<='N'&&f1[i]==f2[i])
        {
            hour=f1[i]-'A'+10;
//            printf("hour=%c\n",f1[i]);
            break;
        }else if(!isDay&&isdigit(f1[i])&&f1[i]==f2[i]){
            hour=f1[i]-'0';
//            printf("hour=%c\n",f1[i]);
            break;
        }
    }
    for(int i=0; i<len2; i++)
    {
        if(isalpha(s1[i])&&s1[i]==s2[i])
        {
            minute=i;
            break;
        }
    }
    switch(day)
    {
    case 1:
        printf("MON ");
        break;
    case 2:
        printf("TUE ");
        break;
    case 3:
        printf("WED ");
        break;
    case 4:
        printf("THU ");
        break;
    case 5:
        printf("FRI ");
        break;
    case 6:
        printf("SAT ");
        break;
    case 7:
        printf("SUN ");
        break;
    default:
        printf("NON ");
        break;
    }
    printf("%02d:%02d\n",hour,minute);

    return 0;
}
