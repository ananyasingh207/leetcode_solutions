class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxArea = -1;
        while(left<right){
            int w = right-left;
            int h = min(height[left],height[right]);
            int area = w*h;
            maxArea = max(area,maxArea);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};