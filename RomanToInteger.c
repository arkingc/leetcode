#include <stdio.h>
#include <stdlib.h>

int romanToInt(char* s){
	int map[128];
	int prev;
	int rs = 0;

	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	prev = map[*s];
	while(*s != '\0'){
		if(map[*s] > prev)
		  rs += map[*s] - 2 * prev;
		else
		  rs += map[*s];
		prev = map[*s];
		s++;
	}

	return rs;
}

int main(){
	printf("%d\n",romanToInt("XCVIII"));
	return 0;
}
