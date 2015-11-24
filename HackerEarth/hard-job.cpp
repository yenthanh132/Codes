#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1500007;
const int base=500000;
int bit[maxn];
int pos[maxn],n,m,L,R;

void update(int i, int v){
    for(;i<=base*3;i+=i&(-i)) bit[i]+=v;
}

int get(int i){
    int res=0;
    for(;i;i-=i&(-i)) res+=bit[i];
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    L=base+1;
    R=base+n;
    for(int i=L; i<=R; ++i){
        int v;
        scanf("%d",&v);
        pos[v]=i;
        update(i,1);
    }
    char key[5];
    int x;
    ll res=0;
    for(int i=0; i<m; ++i){
        scanf("%d%s",&x,key);
        int toLeft=get(pos[x]-1)-get(L-1);
        int toRight=get(R)-get(pos[x]);
        res+=min(toLeft,toRight);
        update(pos[x],-1);
        if(key[0]=='l'){
            --L;
            pos[x]=L;
            update(L,1);
        }else{
            ++R;
            pos[x]=R;
            update(R,1);
        }
    }

    cout<<res<<endl;
}

