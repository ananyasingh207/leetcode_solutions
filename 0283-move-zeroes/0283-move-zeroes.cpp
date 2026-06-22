class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            if(nums[i]!=0){
                if(i!=j){
                    swap(nums[i],nums[j]);
                }
                j++;
            }
            i++;
        }
    }
};