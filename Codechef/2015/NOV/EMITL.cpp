#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const string ss="LTIME";

bool check(int *cnt, int len){
    for(int i=0; i<5; ++i){
        int c=cnt[ss[i]-'A'];
        if(c<2){
            if(i!=4 || c!=1 || len!=9) return 0;
        }
    }
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int cnt[26];
        reset(cnt,0);
        for(int i=0; i<sz(s); ++i) ++cnt[s[i]-'A'];
        if(check(cnt,sz(s))) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

