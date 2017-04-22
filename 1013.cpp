#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool isVisited[1000] = { false };
int graph[1010][1010];

void dfs(int root, int max, int checked){
	//printf("now--%d\n", root);
	for (int i = 1; i <= max; i++){
		if (i != root&&i != checked && graph[root][i] == 1 && !isVisited[i]){
			isVisited[i] = true;
			dfs(i, max,checked);
		}
	}
	return;
}



int main(){


	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int maxCityNumber = n;
	for (int i = 0; i < m; i++){
		int temp, temp2;

		scanf("%d%d", &temp, &temp2);
		graph[temp][temp2] = 1;
		graph[temp2][temp] = 1;
		temp = max(temp, temp2);
		//maxCityNumber = max(maxCityNumber, temp);
	}

	//for (int i = 1; i <= maxCityNumber; i++){
	//	for (int ii = 1; ii <= maxCityNumber; ii++){
	//		printf("%d ", graph[i][ii]);
	//	}
	//	printf("\n");
	//}

	for (int j = 0; j < k; j++){
		int checked;
		scanf("%d", &checked);
		//for (int i = 1; i <= maxCityNumber; i++){
		//	graph[i][checked] = 0;
		//	graph[checked][i] = 0;
		//}

		//for (int i = 1; i <= maxCityNumber; i++){
		//	for (int ii = 1; ii <= maxCityNumber; ii++){
		//		printf("%d ", graph[i][ii]);
		//	}
		//	printf("\n");
		//}

		for (int i = 1; i <= maxCityNumber; i++){
			isVisited[i] = false;
		}

		//printf("----index=%d----\n", j + 1);
		int UCCount = 0;
		for (int i = 1; i <= maxCityNumber; i++){
			if (!isVisited[i] && i != checked){
				UCCount++;
				isVisited[i] = true;
				//printf("uccount=%d\n", UCCount);
				dfs(i, maxCityNumber, checked);
			}
		}

		//for (int i = 1; i < maxCityNumber; i++){
		//	graph[i][checked] = 1;
		//	graph[checked][i] = 1;
		//}
		if (UCCount > 0){
			printf("%d\n", UCCount - 1);
		}
		else{
			printf("%d\n", 0);
		}
	}




	system("pause");
	return 0;
}