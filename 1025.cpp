#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


struct student{

	char id[15];
	int info[5];
	/*
		0---score;
		1---final_rank
		2---location
		3---lcoal_rank
		*/
};

bool cmp(student a, student b){
	if (a.info[0] > b.info[0]){
		return true;
	}
	else if (a.info[0] < b.info[0]){
		return false;
	}
	else{
		if (strcmp(a.id, b.id) < 0){
			return true;
		}
		else{
			return false;
		}
	}
}

bool cmp2(student a, student b){
	if (strcmp(a.id, b.id) < 1){
		return true;
	}
	else{
		return false;
	}
}


int main(){

	student **stu;
	int rankListNum;
	int sumOfStudent = 0;
	scanf("%d", &rankListNum);
	//直接开大的结构体会超时
	stu = new student*[rankListNum];
	int *rankListNumCount = new int[rankListNum];
	for (int i = 0; i < rankListNum; i++){
		int num;
		scanf("%d", &num);
		rankListNumCount[i] = num;
		stu[i] = new student[num];
		for (int j = 0; j < num; j++){
			//printf("%d\n", sumOfStudent + j);
			scanf("%s%d", stu[i][j].id, &stu[i][j].info[0]);
			stu[i][j].info[2] = i + 1;
		}
		sumOfStudent += num;
	}

	student *stu2 = new student[sumOfStudent];
	printf("%d\n",sumOfStudent);
	int count = 0;
	for (int i = 0; i < rankListNum; i++){

		sort(stu[i], stu[i] + rankListNumCount[i], cmp);
		int pre = 1;
		//int preIndex = 0;
		//int lastIndex = 0;
		stu[i][0].info[3] = 1;
		for (int j = 1; j < rankListNumCount[i]; j++){
			if (stu[i][j].info[0] == stu[i][j - 1].info[0]){
				stu[i][j].info[3] = pre;
				//lastIndex++;
			}
			else{
				stu[i][j].info[3] = j + 1;
				pre = j + 1;
				//sort(stu[i] + preIndex, stu[i] + lastIndex + 1, cmp2);
				//preIndex = lastIndex+1;
				//lastIndex = lastIndex + 2;
			}
		}

		for (int j = 0; j < rankListNumCount[i]; j++){
			//printf("%d\n", count++);
			strcpy(stu2[count].id, stu[i][j].id);
			stu2[count].info[0] = stu[i][j].info[0];
			stu2[count].info[2] = stu[i][j].info[2];
			stu2[count].info[3] = stu[i][j].info[3];
			count++;
			//printf("id=%s,score=%d\n", stu[i][j].id, stu[i][j].info[0]);
		}
	}
	sort(stu2, stu2 + sumOfStudent, cmp);
	int pre = 1;
	stu2[0].info[1] = 1;
	for (int j = 1; j < sumOfStudent; j++){
		if (stu2[j].info[0] == stu2[j - 1].info[0]){
			stu2[j].info[1] = pre;
		}
		else{
			stu2[j].info[1] = j + 1;
			pre = j + 1;
		}
	}


	for (int i = 0; i < sumOfStudent; i++){
		//printf("id=%s,score=%d,final_rank=%d,location=%d,local_rank=%d\n", stu2[i].id, stu2[i].info[0], stu2[i].info[1], stu2[i].info[2], stu2[i].info[3]);
		printf("%s %d %d %d\n", stu2[i].id, stu2[i].info[1], stu2[i].info[2], stu2[i].info[3]);

	}


	system("pause");
	return 0;
}