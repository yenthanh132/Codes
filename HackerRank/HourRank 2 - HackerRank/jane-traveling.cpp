#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;
int n;
int dis[maxn*5],trace[maxn*5];
int a[5][5];
queue<int> myq;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    reset(a,-1);
    for(int i=0; i<5; ++i){
        for(int v=1; v<=2; ++v){
            int j=(i+v)%5;
            cin>>a[i][j];
        }
    }
    reset(dis,-1);
    myq.push(0);
    while(!myq.empty()){
        int u=myq.front(); myq.pop();
        int i=u%5, len=u/5;
        if(len==n){
            vector<int> ans;
            while(u!=0){
                ans.pb(u%5+1);
                u=trace[u];
            }
            ans.pb(1);
            for(int i=sz(ans)-1; i>=0; --i) printf("%d ",ans[i]);
            return 0;
        }
        for(int j=0; j<5; ++j) if(a[i][j]!=-1){
            int len2=len+a[i][j];
            if(len2>n) continue;
            int v=len2*5+j;
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                myq.push(v);
                trace[v]=u;
            }
        }
    }
    puts("-1");
}

