#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,k,odd;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        int sum=0;
        for(int i=0,v; i<n; ++i){
            cin>>v;
            sum ^= v&1;
        }
        for(int i=0; i<k-1; ++i){
            int v=sum^1;
            sum^=v;
        }
        if(sum^1) cout<<"odd"<<endl;
        else cout<<"even"<<endl;
    }
}

