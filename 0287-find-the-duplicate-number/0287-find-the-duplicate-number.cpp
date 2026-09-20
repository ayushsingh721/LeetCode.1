class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n){
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i], nums[correctIndex]);
            }
            else{
                if(i != correctIndex){
                    return nums[i];
                }
                i++;
            }
        }
        return -1;
        
    }
};