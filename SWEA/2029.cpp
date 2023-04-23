#include <iostream>
using namespace std;
int test_case, a, b;
int main(){
    cin >> test_case;
    for(int i = 1; i <= test_case; i++){
        cin >> a >> b;
        cout << "#" << i << " " << (a / b) << " " << (a % b) << "\n";
    }
}