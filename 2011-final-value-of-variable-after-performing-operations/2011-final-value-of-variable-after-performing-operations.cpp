class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int res =0;
        for(int i=0;i<op.size();i++)
        {
            if(op[i]=="--X") res-=1;
            else if(op[i]=="X--") res-=1;
            else if(op[i]=="X++") res+=1;
            else if(op[i]=="++X") res+=1;
        }
        return res;
    }
};