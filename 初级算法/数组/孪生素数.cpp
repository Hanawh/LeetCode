#include<iostream>
#include<cmath>
using namespace std;
const int IMAX=1e6;
int PrimMap[IMAX];

int isPrim(int num){
    if(num<=1) return 0;
    for(int i=2; i<=int(sqrt(double(num))); ++i)
    {
        if (num%i == 0) return 0;
    }
    return 1;
}

int main()
{
    int num;
    for(int i=1; i<=IMAX; i=i+2)
        PrimMap[i] = isPrim(i); //跳过偶数
    
    while (cin>>num)
    {
        int count=0;
        if(num<=1) return 0;
        for(int i=2; i<=num; ++i)
        {
            if(PrimMap[i] == 1)
            {
                if(i+2<=num && PrimMap[i+2]==1)
                count++;
            }
        };
        cout<<count<<endl;
    }

    return 0;
}
