#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string s;
int n;
vector<string> res;
vector<int> pos;

bool ispalind(string &s){
    for(int i=0; i<n/2; ++i) if(s[i]!=s[n-i-1]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin>>s;
    n=sz(s);
    if(n&1) pos.pb(n/2);
    for(int i=0; i<n/2; ++i) if(s[i]!=s[n-i-1]){
        pos.pb(i);
        pos.pb(n-i-1);
    }

    sort(pos.begin(),pos.end());
    if(sz(pos)<=5){
        for(int i=0; i<sz(pos); ++i) for(int j=i+1; j<sz(pos); ++j){
            swap(s[pos[i]],s[pos[j]]);
            if(ispalind(s)) res.pb(s);
            swap(s[pos[i]],s[pos[j]]);
        }
    }
    if(ispalind(s)) res.pb(s);
    sort(res.begin(),res.end());
    cout<<sz(res)<<endl;
    for(int i=0; i<sz(res); ++i) cout<<res[i]<<endl;

}

