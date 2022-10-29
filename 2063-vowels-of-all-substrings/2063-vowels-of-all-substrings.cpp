class Solution {
public:
    bool is_vowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    long long countVowels(string word) {
        long long n = word.length();
        long long res= 0;
        for(long long i=0;i<n;i++)
        {
            if(is_vowel(word[i]))
            {
                res += (i+1)*(n-i);
            }
        }
        return res;
    }
};