class Solution {
public:
  string addStrings(string num1, string num2) {
    stack<char> st;
		string res;
		auto a = num1.size();
		auto b = num2.size();
		int val1=0,val2=0,sum=0;
		while(a or b)
		{
			if(a){
				val1 = num1[a-1] - '0';
                a--;
			}
			else{
				val1 = 0;
			}

			if(b){
				val2 = num2[b-1] - '0';
                b--;
			}
			else{
				val2 = 0;
			}
			sum += val1 + val2 ;
			st.push('0'+ sum%10);
			sum = sum / 10;
		}
		if(sum) st.push('1');
		while(!st.empty()){
			res += st.top();
			st.pop();
		}
		return res;
    }
};
