#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

void dfs(int d);
void search(int &d, int x, ll S);

int T,n,k;
ll v[25],sum,val,Rsum[25];
bool mark[25],found;

void search(int &d, int x, ll S){
    if(found) return;
    mark[x]=1;
    if(S<=val){
        if(S==val){
            dfs(d+1);
        }else{
            for(int i=x+1; Rsum[i]+S>=val && i<=n; ++i)
                if(!mark[i])
                    search(d,i,S+v[i]);
        }
    }
    mark[x]=0;
}

void dfs(int d){
    if(found) return;
    if(d>k){
        found=1;
        return;
    }
    int i=1;
    while(mark[i]) ++i;
    if(i<=n) search(d,i,v[i]);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    for(int tt=0; tt<T; ++tt){
        cin>>n>>k;
        sum=0;
        for(int i=1; i<=n; ++i){
            cin>>v[i];
            sum+=v[i];
        }
        if(sum%k){
            cout<<"no"<<endl;
            continue;
        }
        Rsum[n+1]=0;
        for(int i=n; i>=1; --i) Rsum[i]=Rsum[i+1]+v[i];
        val=sum/k;
        found=0;
        reset(mark,0);
        dfs(1);
        if(found) cout<<"yes"<<endl; else cout<<"no"<<endl;
    }
}

