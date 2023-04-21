#include <iostream>
using namespace std;
int test_case;
int main(){
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        int a = 0;
        int b = 0;
        char ret = ' '; 
        cin >> a >> b;
        if(a > b) ret = '>';
        else if (a == b) ret = '=';
        else ret = '<';

        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}
