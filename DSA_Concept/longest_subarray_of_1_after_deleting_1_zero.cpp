class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Sliding Window 
        // int zero=0;
        // int i=0,j=0,res=0;
        // while(j<nums.size()){
        //     if(nums[j]==0)
        //         zero++;
        //     if(zero>1){
        //         while(nums[i++]!=0);
        //         zero--;
        //     }
        //     res=max(res,j-i);                
        //     j++;
        // }
        // return res;

        // DP
        int n=nums.size(),mx=0;
        int left[n];memset(left,0,sizeof(left));
        int right[n];memset(right,0,sizeof(right));
        for(int i=1;i<n;i++){
            if(nums[i-1]==1)
            left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]==1)
            right[i]=right[i+1]+1;
        }
        for(int i=0;i<n;i++){
     
            mx=max(mx,left[i]+right[i]);
        }
        return mx;
    }
};


// Understand the solution and approach: