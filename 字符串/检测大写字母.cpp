class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.empty())return true;

        for(int i = 1; word[i]; i++)
        {
            if(i!=1 && isupper(word[i]) != isupper(word[i-1]) )
                return false;
        }

        if(!isupper(word[0]) && isupper(word[1]))return false;
        return true;
    }
};
