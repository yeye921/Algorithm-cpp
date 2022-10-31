vector<int> era(int max_n){
//     vector<int> v;
//     for(int i = 2; i <= max_n; i++){
//         if(che[i]) continue;                  // 이미 초기화 된 것들은 건너뜀
//         for(int j = 2*i; j <= max_n; j += i){ // 특정한 수의 배수들을 1로 초기화 (자기자신 제외 ex.2)
//             che[j] = 1;
//         }
//     }
//     for(int i = 2; i <= max_n; i++) if(che[i] == 0) v.push_back(i); // 1로 초기화되지 않은 것들만 v에 담음
//     return v;
// } 