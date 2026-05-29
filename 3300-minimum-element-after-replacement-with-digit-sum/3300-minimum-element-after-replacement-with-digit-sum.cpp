class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int minElement = INT_MAX;
        for(int i=0;i<n;i++){
            int temp = nums[i];
            int sum = 0;
            while(temp){
                sum += temp%10;
                temp = temp/10;
            }
            nums[i] = sum;
            minElement = min(minElement,nums[i]);
        }
        return minElement;
    }
};