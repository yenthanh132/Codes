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
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0; i<m; ++i){
            int x,y;
            cin>>x>>y;
        }
        if(n&1) cout<<"Artur"<<endl;
        else cout<<"Alex"<<endl;
    }
}
