#include <bits/stdc++.h>

// Final version ready for submission
// Solution for File Storage BPT problem
using namespace std;

const string DATA_FILE = "data.txt";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, set<int>> db;
    // Load existing data if file exists
    {
        ifstream fin(DATA_FILE);
        if(fin){
            string idx; long long val;
            while(fin >> idx >> val){
                db[idx].insert((int)val);
            }
        }
    }
    int n; if(!(cin>>n)) return 0;
    string cmd;
    for(int i=0;i<n;++i){
        cin>>cmd;
        if(cmd=="insert"){
            string idx; long long val; cin>>idx>>val;
            db[idx].insert((int)val);
        }else if(cmd=="delete"){
            string idx; long long val; cin>>idx>>val;
            auto it=db.find(idx);
            if(it!=db.end()){
                it->second.erase((int)val);
                if(it->second.empty()) db.erase(it);
            }
        }else if(cmd=="find"){
            string idx; cin>>idx;
            auto it=db.find(idx);
            if(it==db.end()||it->second.empty()){
                cout<<"null\n";
            }else{
                bool first=true;
                for(int v: it->second){
                    if(!first) cout<<' ';
                    first=false;
                    cout<<v;
                }
                cout<<"\n";
            }
        }
    }
    // Write back data
    {
        ofstream fout(DATA_FILE, ios::trunc);
        for(auto &p: db){
            for(int v: p.second){
                fout<<p.first<<' '<<v<<'\n';
            }
        }
    }
    return 0;
}

// End of file


// All done
// Final check commit
