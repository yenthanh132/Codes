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
    int T,n,v,last;
    ll sum=0;
    cin>>T;
    while(T--){
        cin>>n;
        last=0; sum=0;
        for(int i=0; i<n; ++i){
            cin>>v;
            if(v>last) sum+=v-last;
            last=v;
        }
        cout<<sum<<endl;
    }
}

