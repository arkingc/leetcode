#include <stdlib.h>
#include <stdio.h>

char* convert(char* s,int numRows);

int main(){	
	printf("%s\n",convert("abcd",2));

	return 0;
}
/**/
char * convert(char* s,int numRows){
	if(numRows <= 1)	return s;
	
	int length = 0;
	char* c = s;
	while(*c++ != '\0')	{length++;}

	char *ans = (char*)malloc(sizeof(char) * length + 1);
	ans[length] = '\0';
	
	int row_index = 1;
	int index1;
	int index2 = 0;
	while(row_index <= numRows){
		index1 = row_index; 
		int increment = 2 * (numRows - 1);
		int inc = 2 * (numRows - row_index);

		while(index1 <= length){
			ans[index2] = s[index1-1];			
	
			if(inc > 0)	index2++;

			index1 += inc;
			inc = increment - inc;
		}

		row_index++;
	}

	return ans;
}
