class Solution {
public:
    int majorityElement(vector<int>& a) {
        int size = a.size();
        int count=1,ele = a[0];
        for(int i=1;i<size;i++)
        {
            if(ele == a[i])
            {
                count++;
            }
            else if(ele!=a[i])
            {
                count--;
                if(count == 0)
                {
                    count=1;
                    ele = a[i];
                }
            }
        }
        count =0;
        for(int i=0;i<size;i++)
        {
           if(a[i]==ele) count++;
        }
        if(count> size/2)
            return ele;
        return -1;
    }
};