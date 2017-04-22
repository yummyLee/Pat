/*
	特别注意要去掉系数为0.0的项
	四舍五入放到最后输出时再四舍五入
*/


#include<iostream>
#include<set>
#include<map>
using namespace std;

struct num{
	int exponent;
	int coefficient;
};

void output(map<int, double> res, map<int, double>::iterator i, int depth){
	if (depth == res.size()){
		return;
	}
	map<int, double>::iterator tmp = i;
	output(res, ++i, depth + 1);
	if (tmp->second >= 0.1 || tmp->second <= -0.1){
		cout << " " << tmp->first << " ";
		printf("%0.1f", tmp->second);
	}
}


int main(){

	int n1;
	int n2;
	int exp1[11];
	double coe1[11];
	int exp2[11];
	double coe2[11];
	map<int, double> res;
	cin >> n1;
	for (int i = 0; i < n1; i++){
		cin >> exp1[i] >> coe1[i];
	}
	cin >> n2;
	for (int i = 0; i < n2; i++){
		cin >> exp2[i] >> coe2[i];
		for (int j = 0; j < n1; j++){
			//int expTmp = exp1[j];
			//double coeTmp = coe1[j];
			int resExpTmp = exp2[i] + exp1[j];
			double resCoeTmp = coe2[i] * coe1[j];
			int resCoeIntTmp = (resCoeTmp + 0.05) * 10;
			resCoeTmp = resCoeIntTmp / 10.0;
			if (res.find(resExpTmp) != res.end()){
				double dd = res[resExpTmp] + resCoeTmp;
				//不等于0;
				if (dd >= 0.1){
					res[resExpTmp] = dd;
				}
			}
			else{
				res[resExpTmp] = resCoeTmp;
			}
		}
	}


	int size = 0;
	for (map<int, double>::iterator i = res.begin(); i != res.end(); i++){
		if (i->second >= 0.1 || i->second <= -0.1){
			size++;
		}
	}
	cout << size;
	output(res, res.begin(), 0);
	//for (map<int, double>::iterator i = res.begin(); i != res.end(); i++){
	//	cout << i->first <<" "<< i->second << " ";
	//}
	cout << endl;

	system("pause");
	return 0;
}