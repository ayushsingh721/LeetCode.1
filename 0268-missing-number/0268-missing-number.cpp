class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n){
            int CurrentIndex = nums[i];

            if(nums[i] < n && nums[i] != nums[CurrentIndex]){
                swap(nums[i], nums[CurrentIndex]);
            }
            else{
                i++;
            }
        }
        for(int i =0; i<n;i++){
            if(nums[i] != i){
                return i;
            }
        }
        return n;

    }
};