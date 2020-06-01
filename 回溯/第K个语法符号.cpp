class Solution {
public:
    int kthGrammar(int N, int K) { 
    //父节点 = (K+1)/2
    // 父节点*2+1 始终与父节点保持一致
    // 父节点*2 与父节点相反

        //先考虑递归的边界
        if(N == 1) return 0;
        int father = (K+1)/2;
        int res = kthGrammar(N-1, father); //返回父节点的值
        if(K == father * 2) return 1-res;
        else return res;
    }
};
