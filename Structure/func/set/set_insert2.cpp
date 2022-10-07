#include <bits/stdc++.h>
using namespace std; int main(){
50
set<pair<string, int>> _set; _set.insert({"test", 1}); _set.insert({"test", 1});
_set.insert({"test", 1}); _set.insert({"test", 1}); cout <<_set.size() <<"\n"; return 0;
}
/* 1 */

#include <bits/stdc++.h>
using namespace std;
int main(){
    set<pair<string, int>> _set;
    _set.insert({"test", 1});
    _set.insert({"test", 1});
    _set.insert({"test", 1});
    _set.insert({"test", 2});

    cout << _set.size() << "\n";
    return 0;
}