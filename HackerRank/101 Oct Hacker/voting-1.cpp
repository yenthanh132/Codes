#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

map<string,int> mm;

int main(){
//    freopen("input.txt","r",stdin);
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>s;
        ++mm[s];
    }
    string res;
    int best=0;
    for(map<string,int>::iterator it=mm.begin(); it!=mm.end(); ++it)
        if(it->second > best){
            best = it->second;
            res = it->first;
        }
    cout<<res<<endl;
}

