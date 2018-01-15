#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>	//不然bool类型会报错

bool isPalindrome(int x);

int main(){
	printf("%d\n",isPalindrome(12321));

	return 0;
}

bool isPalindrome(int x){
	int newResult = 0;
	int palindrome = 0;
	int y = x;

	while(x){
		newResult = palindrome * 10 + x % 10;
		if(newResult / 10 != palindrome )	return false;
		palindrome = newResult;
		x /= 10;
	}

	return palindrome == y ? true : false;
}
