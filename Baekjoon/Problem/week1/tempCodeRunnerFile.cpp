int i = 0; i < n; i++){
            cin >> s1 >> s2;
            mp[s2]++;

            // if(find(type.begin(), type.end(), s2) != type.end()){ // 존재하지 않는다면
            //     type.push_back(s2);
            // }

        }
        for(auto it : mp) cout << it.first << " : " << it.second << "\n";
        