class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        int flag = 0;
        int islittle = 0;
        for (size_t i = 0; i < word.size(); i++)
		{
			if(i == 0){
				if(isupper(word[i])) flag = 1;//首字母是大写
				continue;
			}
			if(i == 1){
                if(islower(word[i])) islittle = 1;
                continue;
            }
            if((islittle and islower(word[i])) or (islittle == 0 and isupper(word[i])))continue;
            else return false;
		}
        if(flag == 0 and islittle == 0) return false;
        return true;
    }
};
