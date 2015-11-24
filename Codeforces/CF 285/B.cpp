#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
map<string,int> mm;
string old[maxn], newh[maxn];
int q,n;
set<string> mys;

int main(){
//    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin>>q;
    n=0;
    for(int i=0; i<q; ++i){
        string s1,s2;
        cin>>s1>>s2;
        if(mm.count(s1)==0){
            mm[s1]=++n;
            old[n]=s1;
        }
        if(mys.count(s2)) continue;
        newh[mm[s1]]=s2;
        mm[s2]=mm[s1];
        mys.insert(s1); mys.insert(s2);
    }
    cout<<n<<endl;
    for(int i=1; i<=n; ++i) cout<<old[i]<<' '<<newh[i]<<endl;
}

