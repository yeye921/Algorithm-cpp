#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimeter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimeter)) != string::npos){  // input에서 delimeter의 위치를 찾음
        token = input.substr(0, pos);  // input의 처음부터 delimeter위치 전까지 자른 문자열을 token으로 저장
        ret.push_back(token);          // ret에 token을 집어넣음
        input.erase(0, pos + delimeter.length()); // input에서 처음부터 delimeter까지 지움
    }
    ret.push_back(input); // 남은 문자열은 delimeter를 포함하지 않은 문자열이기 때문에 그냥 넣어줌
    return ret;           // ret = {처음~delimeter전까지 문자열, delimeter다음부터 끝까지 문자열}
}

vector<string> split_debug(string input, string delimeter){
    vector<string> ret; // 반환할 벡터
    long long pos = 0;  // 구분자 위치
    string token = "";  // 구분자 기준으로 자른 문자열
    while((pos = input.find(delimeter)) != string::npos){
        long long pos = input.find(delimeter);
        cout << "POS : " << pos << "\n";
        if(pos == string::npos) break;
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);  // input의 남은 문자열은 delimeter를 포함하지 않은 문자열이기 때문에 그냥 넣어줌
    return ret;
}

int main(){
    string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!";
    string d = " ";
    vector<string> a = split(s, d);
    string s2 = "aaaa bbb cccc ee ddddd!";
    vector<string> c = split_debug(s2, d);
    for(string s : a) cout << s << "\n";
    for(string s : c) cout << s << "\n";
    return 0;
}