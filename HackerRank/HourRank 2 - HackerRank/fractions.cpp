#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,a[5555];

int main(){
//    freopen("input.txt","r",stdin);

    cin>>n;
    int minv=oo;
    for(int i=1; i<=n; ++i) cin>>a[i], minv=min(minv,a[i]);

    for(int v=minv; v>=1; --v){
        bool ok=1;
        int sum=0;
        for(int i=1; i<=n; ++i){
            int l=1, r=a[i], mid, pos=0;
            while(l<=r){
                mid=(l+r)/2;
                if(a[i]/mid <= v){
                    pos = mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            if(pos==0 || a[i]/pos != v){
                ok=0;
                break;
            }else{
                sum += pos;
            }
        }
        if(ok){
            cout<<sum<<endl;
            return 0;
        }
    }
}

