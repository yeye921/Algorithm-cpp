#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> happy = {"charmed", "cheerful", "satisfied"};
vector<string> angry = {"upset", "mad", "raging"};
vector<string> sad = {"dry", "ugly"};
vector<string> joy = {"cool", "delighted"};
vector<string> song = {"charmed dry cool cheerful"};

vector<string> split(string input, string del){
    long long pos = 0;
    string token = "";
    vector<string> ret;
    while((pos = input.find(del)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + del.length());
    }
    ret.push_back(input);
    return ret;
}
int main(){
    string str;
    vector<string> ans;

    while(1){ // 공백 또는 빈 문자열을 입력하면 종료
        getline(cin, str);
        if(str.empty()) break;

        // 공백을 기준으로 문자열 분리해서 배열에 담기
        vector<string> words = split(str, " ");

        // 배열에 담긴 word들을 탐색하면서 어떤 분류에 속하는지 ans에 담기 (시간복잡도: N^2)
        // 여기서 어떤 분류에 속하는지 계산하는게 제일 어려움
        // h, a, s, j 중 가장 큰 수 찾는 법 > 시간 없을 때는 하드코딩하는게 맞음
        int h, a, s, j;
        for(string word: words){
            if(find(happy.begin(), happy.end(), word) != happy.end()) h++;
            if(find(angry.begin(), angry.end(), word) != angry.end()) a++;
            if(find(sad.begin(), sad.end(), word) != sad.end()) s++;
            if(find(joy.begin(), joy.end(), word) != joy.end()) j++;
        }
        int max_n = h;
        if(a > max_n) max_n = a;
        if(s > max_n) max_n = s;
        if(j > max_n) max_n = j;

        if(max_n == h) ans.push_back("happy");
        else if(max_n == a) ans.push_back("angry");
        else if(max_n == s) ans.push_back("sad");
        else ans.push_back("joy");
    }
    for(string s : ans) cout << s << " ";
    return 0;
}