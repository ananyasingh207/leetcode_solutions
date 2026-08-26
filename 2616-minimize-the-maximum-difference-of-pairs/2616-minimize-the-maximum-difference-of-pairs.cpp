class Solution {
public:
    bool canMakePairs(vector<int>& nums, int n, int p, int maxDiff){
        int pairs = 0;
        int i = 1;
        while(i<n){
            if(nums[i]-nums[i-1]<=maxDiff){
                pairs++;
                i+=2;
                if(pairs>=p) return true;
            }
            else{
                i++;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums[n-1]-nums[0];
        while(low<high){
            int mid = low + (high-low)/2;
            if(canMakePairs(nums,n,p,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};