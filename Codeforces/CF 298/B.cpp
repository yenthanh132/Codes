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
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    int res=0;
    for(int i=1; i<=t; ++i){
        v1 = min(v1,v2+d*(t-i));
        res+=v1;
        v1+=d;

    }
    cout<<res<<endl;
}

