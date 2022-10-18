class Solution {
public:
    string count(string temp){
        int count =1;
        int n=temp.size();
        string ans ="";
        for(int i=0;i<n;i++)
        {
            if(temp[i]==temp[i+1]) count++;
            else{
                ans+= to_string(count);
                ans+=temp[i];
                count=1;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        string temp ="1";
        if(n==1) return temp;
        temp="11";
        n--;
        n--;
        while(n--)
        {
            temp = count(temp);
        }
        return temp;
    }
};