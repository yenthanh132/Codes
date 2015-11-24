#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    int T,n;
    ll k,v;
    cin>>T;
    while(T--){
        cin>>n>>k;
        ll res = 0, last=0;
        for(int i=0; i<n; ++i){
            if(last>0) --last;
            cin>>v;
            if(v<=last){
                last-=v;
            }else{
                v-=last; last=0;
                res += v/k;
                v%=k;
                if(v>0){
                    ++res;
                    last=k-v;
                }
            }
        }
        cout<<res<<endl;
    }
}

