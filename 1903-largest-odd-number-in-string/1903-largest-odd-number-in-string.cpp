class Solution {
public:
    string largestOddNumber(string nums) {
        int n=nums.length();
        int i=n-1;
        while(i>=0){
            if(stoi(nums.substr(i,1))%2!=0) break;
            i--;
        }
        if(i<0) return "";
        return nums.substr(0,i+1);
    }
};