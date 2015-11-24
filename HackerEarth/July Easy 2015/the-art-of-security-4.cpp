#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[10],n,p[10],b[10];

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    int res=0, total=0;
    for(int i=0; i<n; ++i) cin>>a[i], p[i]=i, total+=a[i];
    do{
        for(int i=0; i<n; ++i) b[i]=a[p[i]];

        for(int mask=0; mask<(1<<n); ++mask){
            int x=0,y=0;
            bool ok=1;
            for(int i=0; i<n; ++i){
                if(mask>>i&1) x+=b[i];
                else y+=b[i];
                if(x>y) ok=0;
            }
            if(ok) ++res;
        }

    }while(next_permutation(p,p+n));
    cout<<res<<' '<<total<<endl;
    if(res<=total) cout<<"Got no way out!"<<endl;
    else cout<<"We will win!"<<endl;
}

