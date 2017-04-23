#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


//Ë®Ìâ
struct user
{

    char name[11];
    char pwd[11];
    bool isChanged=false;
};

user* users;

int main()
{

    int n;
    scanf("%d",&n);
    users=new user[n];
    int changeCount=0;

    for(int i=0; i<n; i++)
    {
        scanf("%s %s",users[i].name,users[i].pwd);
        int pLen=strlen(users[i].pwd);
        bool isChanged=false;
        for(int j=0; j<pLen; j++)
        {
            char c=users[i].pwd[j];
            if(c=='1')
            {
                users[i].pwd[j]='@';
                isChanged=true;
            }
            else if(c=='0')
            {
                users[i].pwd[j]='%';
                isChanged=true;
            }
            else if(c=='l')
            {
                users[i].pwd[j]='L';
                isChanged=true;
            }
            else if(c=='O')
            {
                users[i].pwd[j]='o';
                isChanged=true;
            }
        }
        if(isChanged)
        {
            users[i].isChanged=true;
            changeCount++;
        }
    }
    if(changeCount==0)
    {
        if(n==1)
        {
            printf("There is 1 account and no account is modified\n");
            return 0;
        }
        else
        {
            printf("There are %d accounts and no account is modified\n",n);
        }
        return 0;
    }
    printf("%d\n",changeCount);
    for(int i=0; i<n; i++)
    {
        if(users[i].isChanged)
        {
            printf("%s %s\n",users[i].name,users[i].pwd);
        }
    }


    return 0;
}
