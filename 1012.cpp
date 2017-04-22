#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

struct student{
    int id;
    int grade[6];
    student(){
        grade[4] = 1000000;
    }
    //后两个是最好的名次和symbol
};

int now;

bool cmp(student a, student b){
    return a.grade[now] > b.grade[now];
}

bool cmp2(student a, student b){
    return a.id < b.id;
}

int main(){

    int n, m;
    student stu[2001];

    map<int, int> rankMap;
    //int rank[10000][4] = { 0 };

    char symbol[4] = { 'A', 'C', 'M', 'E' };

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++){
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3;
    }

    for (int i = 0; i < 4; i++){
        now = i;
        sort(stu, stu + n, cmp);
        //rank[stu[0].id][i] = 1;
        //stu[0].grade[i] = 1;
        if (stu[0].grade[4]>1){
            stu[0].grade[4] = 1;
            stu[0].grade[5] = i;
        }
        int pre = 1;
        for (int j = 1; j < n; j++){
            if (stu[j].grade[now] == stu[j - 1].grade[now]){
                if (stu[j].grade[4]>pre){
                    stu[j].grade[4] = pre;
                    stu[j].grade[5] = i;
                    //printf("id=%d,best=%d,symbol=%d\n", stu[j].id, stu[j].grade[4], stu[j].grade[5]);
                }
            }
            else{
                if (stu[j].grade[4] > j + 1){
                    stu[j].grade[4] = j + 1;
                    stu[j].grade[5] = i;
                    //printf("id=%d,best=%d,skymbol=%d\n", stu[j].id, stu[j].grade[4], stu[j].grade[5]);
                }
                pre = j + 1;
            }
        }
    }

    int queryID;

    sort(stu, stu + n, cmp2);
    //for (int j = 0; j < n; j++){
    //	printf("sort==%d\n", stu[j].id);
    //}


    for (int j = 0; j < m; j++){

        scanf("%d", &queryID);

        int index = -1;
        int left = 0;
        int right = n - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            //printf("j=%d,id=%d\n", j,stu[mid].id);
            if (stu[mid].id == queryID){
                index = mid;

                break;
            }
            else if (queryID>stu[mid].id){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        //printf("index=%d\n", index);

        if (index < 0){
            printf("N/A\n");
            continue;
        }

        printf("%d %c\n", stu[index].grade[4], symbol[stu[index].grade[5]]);
    }
    //system("pause");
    return 0;
}