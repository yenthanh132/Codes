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
    ll res = 0;
    int n,v;
    scanf("%d",&n);
    int last=0;
    for(int i=0; i<n; ++i){
        scanf("%d",&v);
        res += abs(v-last);
        last = v;
    }
    cout<<res<<endl;
}

