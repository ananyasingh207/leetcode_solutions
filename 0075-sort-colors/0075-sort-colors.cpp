class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int end = nums.size()-1;
        int start = 0;
        int mid = 0;
        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[mid],nums[start]);
                start++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[end]);
                end--;
            }
        }
    }
};
