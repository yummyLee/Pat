#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

char output(int wtl){
	switch (wtl){
	case 0:
		return 'W';
	case 1:
		return 'T';
	case 2:
		return 'L';
	default:
		return 'W';
	}
}

int main(){

	double games[3][5];
	for (int i = 0; i < 3; i++){
		double max = 0;
		double wtl = 0;
		for (int j = 0; j < 3; j++){
			cin >> games[i][j];
			if (games[i][j]>max){
				max = games[i][j];
				wtl = j;
			}
		}
		games[i][3] = max;
		games[i][4] = wtl;
	}

	for (int i = 0; i < 3; i++){
		cout << output(games[i][4]) << " ";
	}

	double res = (games[0][3] * games[1][3] * games[2][3] * 0.65 - 1) * 2;
	if (res >= 0.01){
		printf("%.2f\n", round(res));
	}
	else{
		//double zero = 0;
		printf("%0.2f\n", 0);
	}
	system("pause");
	return 0;
}