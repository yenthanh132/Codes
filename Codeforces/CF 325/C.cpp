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
    ll x,y;
    cin>>x>>y;
    stringstream ss;
    while(x!=y){
        if(x<y){
            ll t=y/x;
            if(y%x==0) --t;
            ss<<t;
            ss<<"B";
            y -= t*x;
        }else{
            ll t=x/y;
            if(x%y==0) --t;
            ss<<t;
            ss<<"A";
            x -= t*y;
        }
    }
    if(x>1) cout<<"Impossible";
    else cout<<ss.str()<<endl;
}

