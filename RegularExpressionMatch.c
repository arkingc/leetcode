#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool solution(char *s,char *p);

int main(){
	printf("%d\n",solution("abc","c*a*b*c**"));
	return 0;
}

bool solution(char *s,char *p){
	int length_1 = 0;
	int length_2 = 0;
	bool **dp;
	
	for(int i = 0;;i++){
		if(s[i] == '\0')
		  break;
		length_1++;
	}

	for(int j = 0;;j++){
		if(p[j] == '\0')
		  break;
		length_2++;
	}

	dp = (bool **)malloc((length_1 + 1) * sizeof(bool *));
	for(int i = 0;i <= length_1;i++)
		dp[i] = (bool *)malloc((length_2 + 1) * sizeof(bool));
	
	dp[0][0] = true;

	for(int i = 1;i <= length_1;i++){
		dp[i][0] = false;
	}

	for(int j = 1;j <= length_2;j++){
		//d[0][j] = false,因此d[0][奇数] = false;
		dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j-2];
	}

	for(int j = 1;j <= length_2;j++){
		for(int i = 1;i <= length_1;i++){
			if(p[j - 1] == '*')
				dp[i][j] = j > 1 && (dp[i][j - 2] || (p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j]);
			else
				dp[i][j] = (p[j - 1] == s[i - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
		}
	}

	return dp[length_1][length_2];
}
