#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,a[30],b[30],m,k,cnt;
ll frac[20],S,sum;
map<ll, int> mapidx;
vector<int> setk[2000000];
ll res;

int getidx(ll v, bool make_new = 1){
    if(mapidx.count(v)) return mapidx[v];
    if(!make_new) return -1;
    ++cnt;
    mapidx[v]=cnt;
    return cnt;
}

int dem(vector<int> &arr, int x){
    return upper_bound(arr.begin(),arr.end(),x)-arr.begin();
}

void duyet(int a[], int n, int i, int j, bool step2){
    if(sum > S) return;
    if(j > k) return;
    if(i>n){
        if(step2){
            int idx = getidx(S-sum,0);
            if(idx!=-1){
                res += dem(setk[idx], k-j);
            }
        }else{
            int idx = getidx(sum);
            setk[idx].pb(j);
        }
        return;
    }

    duyet(a,n,i+1,j,step2);
    sum+=a[i];
    duyet(a,n,i+1,j,step2);
    sum-=a[i];

    if(a[i]<=19 && frac[a[i]]<=S){
        sum+=frac[a[i]];
        duyet(a,n,i+1,j+1,step2);
        sum-=frac[a[i]];
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>k>>S;
    m=n/2;
    n-=m;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=m; ++i) cin>>b[i];
    frac[0]=1;
    for(int i=1; i<20; ++i) frac[i]=frac[i-1]*i;
    cnt = 0;
    sum = 0;
    res = 0;
    duyet(a,n,1,0,0);
    for(int i=1; i<=cnt; ++i) sort(setk[i].begin(),setk[i].end());
    duyet(b,m,1,0,1);
    cout<<res<<endl;
}
