struct TrieNode{
    TrieNode* next[2] = {nullptr};
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    int findMaximumXOR(vector<int>& nums) {
        //计算二进制的最大长度
        int maxnum = 0;
        for(auto &a : nums){
            if(a > maxnum) maxnum = a;
        }
        if(maxnum == 0) return 0;
        maxnum = floor(log2(maxnum)) + 1;
        //将所有数字构造前缀树
        for(auto a : nums){
            TrieNode *cur = root;
            for(int i = maxnum - 1; i >= 0; i--){ //右移i位
                int bit = a >> i & 1;
                if(cur->next[bit] == nullptr) {
                    cur->next[bit] = new TrieNode();
                }
                cur = cur->next[bit];
            }
        }

        //对于每个树找最大异或值
        int res = 0;
        for(auto a : nums){
            TrieNode *cur = root;
            int val = 0;
            for(int i = maxnum - 1; i >= 0; i--){
                int bit = a >> i & 1;
                if(cur->next[1-bit] == nullptr) cur = cur->next[bit];
                else{
                    cur = cur->next[1-bit];
                    val += (1 << i); 
                }
            }
            res = max(res, val);
        }
        return res;
    }
};
