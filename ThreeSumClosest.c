#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
	int tp = *a;
	*a = *b;
	*b = tp;
}

/*you should be sure that l and r are valid*/
void mergeSort(int* nums,int head,int tail){
	if(head >= tail - 1)
	  return;

	int r = tail;
	int l = head;
	int m = (head + 1 + tail) / 2;//l or value between l and r

	//swap nums[m] and nums[tail]
	swap(nums + m,nums + tail);

	while(l < r){
		while(l < tail && nums[++l] < nums[tail]){}
		while(r > head + 1 && nums[--r] >= nums[tail]){}
		//swap nums[l] and nums[r]
		swap(nums + l,nums + r);
	}

	swap(nums + l,nums + r);

	swap(nums + tail,nums + l);

	mergeSort(nums,head,l - 1);
	mergeSort(nums,l,tail);
}

int threeSumClosest(int* nums, int numsSize, int target) {
	int res;
	int l,r,tp;

	if(numsSize < 3){
		return -1;
	}

	mergeSort(nums,-1,numsSize - 1);
	
	for(int i = 0;i < numsSize - 2;i++){
		l = i + 1;
		r = numsSize - 1;
		if(i == 0)
			res = nums[i] + nums[l] + nums[r];
		while(l < r){
			tp = nums[i] + nums[l] + nums[r];
			if(tp - target == 0){
				res = tp;
				break;
			}
			else if(tp - target > 0){
				if(tp - target < res - target || tp - target < target - res)
					res = tp;
				r--;
			}
			else{
				if(target - tp < res - target || target - tp < target - res)
				  res = tp;
				l++;
			}
		}
	}

	return res;
}

int main(){
	/*int array[] = {3,4,6,2,9,1,5,8,7,0};

	mergeSort(array,-1,9);

	for(int i = 0;i < 10;i++){
		printf("%d ",array[i]);
	}
	printf("\n");*/

	int nums[] = {1,1,1,0};

	printf("%d\n",threeSumClosest(nums,4,-100));

	return 0;
}
