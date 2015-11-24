#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<pii,int> iii;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int maxn=107;
const int maxv=1007;

struct cmpclass{
    bool operator()(const iii &a, const iii &b) const{
        if(a.second != b.second) return a.second > b.second;
        return a.first<b.first;
    }
};

int a[maxn][maxn],n,m;
int c[maxv],d[maxv];
int mark[maxn][maxn];
set<iii,cmpclass> mys;
int bit[maxn][maxn];

int getpoint(int x, int y){
    int res=0;
    for(int k=0; k<4; ++k){
        int xt=x+dx[k];
        int yt=y+dy[k];
        if(1<=xt && xt<=n && 1<=yt && yt<=m && mark[xt][yt]) ++res;
    }
    return res;
}

void doMark(int x, int y){
    for(int k=0; k<4; ++k){
        int xt=x+dx[k];
        int yt=y+dy[k];
        if(1<=xt && xt<=n && 1<=yt && yt<=m && !mark[xt][yt]){
            mys.erase(iii( pii(xt,yt), getpoint(xt,yt) ));
        }
    }
    mark[x][y] = 1;
    for(int k=0; k<4; ++k){
        int xt=x+dx[k];
        int yt=y+dy[k];
        if(1<=xt && xt<=n && 1<=yt && yt<=m && !mark[xt][yt]){
            mys.insert(iii( pii(xt,yt), getpoint(xt,yt) ));
        }
    }
}

int get(int i, int j){
    int res = 0;
    for(int i2=i; i2; i2-=i2&(-i2))
        for(int j2=j; j2; j2-=j2&(-j2))
            res+=bit[i2][j2];
    return res;
}

int get(int x1, int y1, int x2, int y2){
    return get(x2,y2) - get(x1-1,y2) - get(x2,y1-1) + get(x1-1,y1-1);
}

void update(int i, int j, int v){
    for(int i2=i; i2<=n; i2+=i2&(-i2))
        for(int j2=j; j2<=m; j2+=j2&(-j2))
            bit[i2][j2]+=v;
}

vector<pii> ans1,ans2;

void putRectangle(int x1, int y1, int x2, int y2){
    ans1.pb(pii(x1,y1)); ans2.pb(pii(x2,y2));
    for(int i=x1; i<=x2; ++i) for(int j=y1; j<=y2; ++j)
        update(i,j,-1);
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scanf("%d",&a[i][j]);
        reset(c,0); reset(d,0);
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) c[a[i][j]]++;

        reset(mark,0);
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) mys.insert(iii(pii(i,j),0));
        while(!mys.empty()){
            iii p = *mys.begin(); mys.erase(mys.begin());
            int x=p.first.first, y=p.first.second;
            int v=a[x][y];
            if(d[v]*2<c[v]){
                doMark(x,y);
                ++d[v];
            }
        }


//        for(int i=1; i<=n; ++i){
//            for(int j=1; j<=m; ++j) cout<<mark[i][j];
//            cout<<endl;
//        }
        ans1.clear(); ans2.clear();
        reset(bit,0);
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(mark[i][j]) update(i,j,1);
        for(int len=n; len>=1; --len){
            for(int i=1; i<=n-len+1; ++i){
                int i2=i+len-1;
                int j=1;
                while(j<=m && get(i,j,i2,j)<len) ++j;
                while(j<=m){
                    int j2=j+1;
                    while(j2<=m && get(i,j2,i2,j2)==len) ++j2;
                    putRectangle(i,j,i2,j2-1);

                    j=j2;
                    while(j<=m && get(i,j,i2,j)<len) ++j;
                }
            }
        }

        printf("%d\n",sz(ans1));
        for(int i=0; i<sz(ans1); ++i) printf("%d %d %d %d\n",ans1[i].first,ans1[i].second,ans2[i].first,ans2[i].second);

    }
}

