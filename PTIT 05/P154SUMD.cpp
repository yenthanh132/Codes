#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

vector<int> lst;
int a[maxn],n;
int r1,r2;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    r1=r2=0;
    for(int i=1; i<=n; ++i){
        int s;
        cin>>s;
        for(int j=1; j<=s; ++j) cin>>a[j];
        for(int j=1; j<=s/2; ++j) r1+=a[j], r2+=a[s-j+1];
        if(s&1) lst.pb(a[s/2+1]);
    }
    if(!lst.empty()){
        sort(lst.begin(),lst.end(),greater<int>());
        for(int i=0; i<sz(lst); ++i) if(i%2==0) r1+=lst[i]; else r2+=lst[i];
    }
    cout<<r1<<' '<<r2<<endl;

}

