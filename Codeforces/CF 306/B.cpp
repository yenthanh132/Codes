#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,l,r,x;
int c[22];

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>l>>r>>x;
    for(int i=0; i<n; ++i) cin>>c[i];

    int res = 0;
    for(int i=0; i<(1<<n); ++i){
        int cbit = 0, sum = 0, maxc=-oo, minc = oo;
        for(int j=0; j<n; ++j) if(i>>j&1){
            ++cbit;
            maxc=max(maxc,c[j]);
            minc=min(minc,c[j]);
            sum+=c[j];
        }
        if(cbit>=2 && l<=sum && sum<=r && x<=maxc-minc) ++res;
    }
    cout<<res<<endl;
}

