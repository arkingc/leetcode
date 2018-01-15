#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
	int l = 0;
	int r = heightSize - 1;
	int area = 0;

	while(l < r){
		area = max(area,(r - l) * min(height[l],height[r]));

		if(height[l] < height[r]){		  
			int old_value = height[l];
			while(++l < r && height[l] <= old_value){}
		}
		else{
			int old_value = height[r];
			while(--r > l && height[r] <= old_value){}
		}
	}

	return area;
}

int main(){
	int a[] = {1,8,6,2,5,4,8,3,7};

	printf("%d\n",maxArea(a,9));

	return 0;
}
