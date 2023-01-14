#include <bits/stdc++.h>
using namespace std;

void Init();
bool FindMaxBinaryNumber();
bool DecreaseBinaryNumber();

vector< int > N;
int x, y;
vector< bool > binary_number;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    
    int T;
    cin >>T;
    
    for(int t = 1; t <= T; t++) {
        Init();
        
        cout << '#' << t << ' ';
        if (FindMaxBinaryNumber()) {
            for (const bool &b: binary_number) {
                cout << (b? y: x);
            }
        } else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}

void Init() {
    string s;
    cin >> s >> x >> y;
    
    N.resize(s.size());
    for (int i = 0; i < (int) s.size(); i++) {
        N[i] = s[i] - '0';
    }
    binary_number = {};
}

bool FindMaxBinaryNumber() {
    bool decreased = false;
    bool is_leading_zero = true;
    for (const int &n: N) {
        bool m;
        if (decreased) {
            m = true;
        } else if (n < x) {
            if (! DecreaseBinaryNumber()) {
                decreased = true;
                continue;
            }
            m = true;
        } else if (n < y) {
            m = false;
        } else {
            m = true;
        }
        if (! decreased && n != x && n != y) {
            decreased = true;
        }
        if (is_leading_zero) {
            if (x == 0 && m == false) {
                continue;
            }
            is_leading_zero = false;
        }
        binary_number.push_back(m);
    }
    return ! binary_number.empty();
}

bool DecreaseBinaryNumber() {
    for (int i = binary_number.size() - 1; i >= 0; i--) {
        if (binary_number[i]) {
            binary_number[i] = false;
            return true;
        }
        binary_number[i] = true;
    }
    return false;
}