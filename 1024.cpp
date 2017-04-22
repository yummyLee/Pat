#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


bool isP(char nums[1000]){
	int len = strlen(nums);
	int left = 0;
	int right = len - 1;
	while (left <= right){
		if (nums[left] != nums[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}

void reverseChars(char nums[1000]){
	int len = strlen(nums);
	int left = 0;
	int right = len - 1;
	while (left <= right){
		char temp = nums[right];
		nums[right] = nums[left];
		nums[left] = temp;
		left++;
		right--;
	}
}

void plusChars(char n1[1000], char n2[1000]){
	int carry = 0;
	int len = strlen(n1);
	for (int i = 0; i < len; i++){
		int n = n1[i] - '0';
		int m = n2[i] - '0';
		n += (m + carry);
		if (n>9){
			n -= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		n1[i] = n + '0';
		//printf("i=%d,n=%d\n", i, n);
	}
	if (carry > 0){
		n1[len] = carry + '0';
		n1[len + 1] = '\0';
	}
}


int main(){

	char n[1000];
	int k;
	scanf("%s%d", &n, &k);
	int stepCount = 0;
	char rn[1000];

	for (int i = 0; i < k; i++){

		int len = strlen(n);
		for (int i = 0; i < len; i++){
			rn[i] = n[len - 1 - i];
		}

		if (isP(n)){
			break;
		}
		else{
			plusChars(n, rn);
		}
		//printf("n=%s\n", n);
		stepCount++;
		//printf("count=%d\n", stepCount);
	}

	reverseChars(n);

	printf("%s\n", n);
	printf("%d\n", stepCount);

	system("pause");
	return 0;
}