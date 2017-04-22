#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

struct student
{
    string name;
    char gender;
    string id;
    int grade;
};

int main()
{

    int n;
    student minMale,maxFemale;
    minMale.grade=101;
    maxFemale.grade=-1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {

        string curName;
        char curGender;
        string curID;
        int curGrade;
        cin>>curName>>curGender>>curID>>curGrade;
//        printf("%s %c %s %d\n",curName.c_str(),curGender,curID.c_str(),curGrade);
        if(curGender=='M')
        {

            if(curGrade<minMale.grade)
            {
                minMale.gender=curGender;
                minMale.grade=curGrade;
                minMale.id=curID;
                minMale.name=curName;
//                printf("%d %d\n",curGrade,minMale.grade);
            }
        }
        else
        {
            if(curGrade>maxFemale.grade)
            {
                maxFemale.gender=curGender;
                maxFemale.grade=curGrade;
                maxFemale.id=curID;
                maxFemale.name=curName;
            }
        }
    }
//    printf("%d %d\n",maxFemale.grade,minMale.grade);

    bool flag=true;
    if(maxFemale.grade==-1)
    {
        flag=false;
        printf("Absent\n");
    }else{
        printf("%s %s\n",maxFemale.name.c_str(),maxFemale.id.c_str());
    }
    if(minMale.grade==101)
    {
        flag=false;
        printf("Absent\n");
    }else{
        printf("%s %s\n",minMale.name.c_str(),minMale.id.c_str());
    }
    if(flag){
        int res=abs(minMale.grade-maxFemale.grade);
        printf("%d\n",res);
    }else{
        printf("NA\n");
    }


    return 0;
}
