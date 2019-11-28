/*Input:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        string init = "0000";
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        if(deadset.count(init)) return -1;
        q.push(init);
        bool visited[10000]; //利用数组存储标记
        memset(visited, 0, sizeof(visited));//标记是否被访问过
        visited[0] = true;
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int i = 0; i < size; ++i){
                string cur = q.front();
                //扩展符合条件的新节点
                for(int j = 0; j < 4; ++j){
                    string temp = cur;
                    temp[j] = '0' + ((temp[j]-'0')-1+10)%10;
                    if(temp == target) return step;
                    if(!deadset.count(temp) && visited[strToNumber(temp)] == false){
                        q.push(temp);
                        visited[strToNumber(temp)] = true;
                    }
                    temp[j] = '0' + ((temp[j]-'0')+2)%10;
                    if(temp == target) return step;
                    if(!deadset.count(temp) && visited[strToNumber(temp)] == false){
                        q.push(temp);
                        visited[strToNumber(temp)] = true;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }

    int strToNumber(string a)
    {
        int qian = a[0];
        int bai = a[1];
        int shi = a[2];
        int ge = a[3];
        int res = (qian - '0') * 1000 + (bai - '0') * 100 + (shi - '0') * 10 + (ge - '0');
        return res;
    }
};

int main(){
    string str[] = {"0201","0101","0102","1212","2002"};
    vector<string> s(str,str+sizeof(str)/sizeof(str[0]));
    cout << Solution().openLock(s, "0202");
}
