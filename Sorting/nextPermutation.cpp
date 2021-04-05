class Solution {
public:
    void nextPermutation(vector<int>& nums) {

      int culprit=-1;
      int n=nums.size();
      for(int i=n-1;i>=1;i--)
      {
        if(nums[i]>nums[i-1])
        {
          culprit=i-1;
          break;
        }
      }
      //checking for corner case
     if(culprit==-1)
     {
       reverse(nums.begin(),nums.end());
       return;
     }
     int just_max= INT_MAX;  // to find the ele just greater than the culprit
     int index=-1;
     for(int i=n-1;i>culprit;i--)
     {
       if(nums[culprit]<nums[i])
       {
         if(just_max>nums[i])
         {
           just_max=nums[i];
           index=i;
         }
       }
     }
     swap(nums[culprit],nums[index]);
     //reverse the chunk to get the minimal possible next permuatation
    // as the chunk will be in descending increasing order so reversing will do fine.
     reverse(nums.begin()+culprit+1,nums.end());
    }
};
