#include <bits/stdc++.h>
using namespace std;
string dopa = "amumu is best";
int main(){
    cout << dopa << "\n";
    if(dopa.find("amumu") != string::npos){
        cout << "dopa속에 아무무있다!\n";
    }
    cout << dopa.substr(0,3) << "\n";
    reverse(dopa.begin(), dopa.end());
    cout << dopa << "\n";
    
return 0;
/*
amumu is best
dopa속에 아무무있다!
amu
tseb si umuma
*/
}
