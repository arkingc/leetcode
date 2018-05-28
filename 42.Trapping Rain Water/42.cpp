class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0,sz = height.size();
        int left_bar = 0,right_bar = sz - 1;
        int max_left = 0,max_right = 0;
        
        while(left_bar < right_bar){
            if(height[left_bar] < height[right_bar]){
                if(height[left_bar] < max_left) water += max_left - height[left_bar];
                else    max_left = height[left_bar];
                left_bar++;
            }
            else{
                if(height[right_bar] < max_right) water += max_right - height[right_bar];
                else    max_right = height[right_bar];
                right_bar--;
            }
        }
        
        return water;
    }
};