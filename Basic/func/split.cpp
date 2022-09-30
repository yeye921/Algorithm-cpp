#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){
    vector <string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter) != string::npos){
	token = input.substr(0, pos);
        ret.push_back(token);
	input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input); // 마지막 남은 것은 그냥넣음
    return ret;
}

vector<string> split_debug(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos){
	long long pos = input.find(delimiter);
	cout << "POS : " << pos << '\n';
	if(pos == string:npos)break;
	token = input.substr(0, pos);
	ret.push_back(token);
	input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    retrun 0;
}

int main(){
    string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!";
    string d = " ";
    vector<string> a = split(s, d);
    string s2 = "aaaa bbb cccc ee ddddd!";
    vector<string> c = split_debug(s2, d);
    for(string b : a) cout << b << "\n";
}
