class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int i=0;
        int res = 0;
        vector<int> v(5,0);
        for(int i=0;i<n;i++)
        {
            vector<int> v(5,0);
            for(int j=i;j<n;j++)
            {
                if(word[j]!='a' &&word[j]!='e' &&word[j]!='i' &&word[j]!='o' &&word[j]!='u') break;
                if(word[j] =='a') v[0]++;
                else if(word[j]=='e') v[1]++;
                else if(word[j]=='i') v[2]++;
                else if(word[j]=='o') v[3]++;
                else if(word[j]=='u') v[4]++;
                if(v[0]>0 && v[1]>0 && v[2]>0&& v[3]>0&& v[4]>0 ) res++;
            }
        }
        return res;
    }
};