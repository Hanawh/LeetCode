class add{
public:
    //初始化一次 N加1
    add(){
        N++;
        sum += N;
    }

    static void reset(){
        N = 0;
        sum = 0;
    }
    static int N;
    static int sum;
};

int add::N = 0;
int add::sum = 0;

class Solution {
public:
    int sumNums(int n) {
        add::reset();
        add *t = new add[n];
        //delete []t;
        //t = nullptr;
        return add::sum;
    }
};
