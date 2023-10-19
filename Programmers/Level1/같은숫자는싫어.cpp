// stack, queue문제라고 안했으면 몰랐을 것 같은 문제
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    stack<int> stk;
    for(int i : arr){
        if(stk.size() && stk.top() == i) continue;
        else stk.push(i);
    }
    while(stk.size()){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end()); // ans를 뒤집는 과정이 필요함
    return ans;
}