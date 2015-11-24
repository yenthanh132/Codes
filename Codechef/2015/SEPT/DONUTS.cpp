#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> a;
int n,m;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        a.clear();
        scanf("%d%d",&n,&m);
        for(int i=0, v; i<m; ++i){
            scanf("%d",&v);
            a.pb(v);
        }
        sort(a.begin(),a.end());
        int res=m-1, sum=0;
        for(int i=0; i<m; ++i){
            sum+=a[i];
            int left=m-i-1;
            if(sum+1>left){
                break;
            }else{
                int val=left-1;
                res=min(res, val);
            }
        }
        cout<<res<<endl;
    }
}

