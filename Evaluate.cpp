#include<bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<long> st;
    for(auto i:tokens){
        if(i == "*" || i ==  "/" || i == "-" || i == "+"){
            long val1 = st.top();
            st.pop();
            long val2 = st.top();
            st.pop();
            if(i == "+"){
                st.push(val1+val2);
            }else if(i == "-"){
                st.push(val1-val2);
            }else if(i == "*"){
                st.push(val1*val2);
            }else{
                st.push(val1/val2);
            }
        }else{
            int num = stoi(i);
            st.push(num);
        }
    }
    return st.top();
}

int main(){
    vector<string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = evalRPN(v);
    cout << ans << endl;
    return 0;
}