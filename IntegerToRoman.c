#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define LENGTH 4

char* intToRoman(int num){
	int index[LENGTH];
	int i;
	char *result = (char*)malloc(sizeof(char) * 16);
	char* c[4][10]={
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
		{"","M","MM","MMM"}  
	};

	memset(result,'\0',16);

	i = 0;
	while(num){
		index[i++] = num % 10;
		num /= 10;
	}

	i--;
	while(i >= 0){
		strcat(result,c[i][index[i]]);
		i--;
	}

	return result;
}

int main(){
	//printf("%s\n",intToRoman(1));
	char *str = (char*)malloc(16);
	int *a = (int*)malloc(16 * sizeof(int));
	for(int i = 0;i < 16;i++){
		printf("%d %d\n",i,str[i] == '\0');
		printf("%d: a:%d\n",i,a[i]);
		printf("%d: str:%c\n",i,str[i]);
	}
	return 0;
}
