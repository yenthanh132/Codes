#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef long long ll;

const int maxn=1007;

struct piece{
    int w,h,n,id,x0,y0;
    vector<int> x;
    vector<int> y;
};

vector<piece> lst;
int w,h,n;
int arr[maxn][maxn],ans[maxn][maxn],best;
set<iii> mys;

bool cmp(const piece &a, const piece &b){
    return a.n>b.n;
}

bool check(int x, int y, piece &p){
    x=x-p.x0+1; y=y-p.y0+1;
    if(x<1 || x+p.h-1>h || y<1 || y+p.w-1>w) return 0;
    for(int k=0; k<p.n; ++k){
        int xt=x+p.x[k]-1;
        int yt=y+p.y[k]-1;
        if(xt<1 || xt>h || yt<1 || yt>w || arr[xt][yt]) return 0;
    }
    return 1;
}

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

void fill(int x, int y, piece &p){
    x=x-p.x0+1; y=y-p.y0+1;
    for(int k=0; k<p.n; ++k){
        int xt=x+p.x[k]-1;
        int yt=y+p.y[k]-1;
        arr[xt][yt]=p.id;
        mys.erase(iii(xt+yt,pii(xt,yt)));
    }
    for(int k=0; k<p.n; ++k){
        int xt=x+p.x[k]-1;
        int yt=y+p.y[k]-1;
        for(int k2=0; k2<4; ++k2){
            int xt2=xt+dx[k2], yt2=yt+dy[k2];
            if(1<=xt2 && xt2<=h && 1<=yt2 && yt2<=w && arr[xt2][yt2]==0)
                mys.insert(iii(xt2+yt2,pii(xt2,yt2)));
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1; i<=n; ++i){
        piece p;
        p.id=i;
        scanf("%d",&p.n);
        p.w=p.h=1;
        p.x0=oo;
        for(int j=1; j<=p.n; ++j){
            int x,y;
            scanf("%d%d",&x,&y);
            p.x.pb(x); p.y.pb(y);
            p.w=max(p.w,y);
            p.h=max(p.h,x);
            if(x<p.x0 || (x==p.x0 && y<p.y0)){
                p.x0=x;
                p.y0=y;
            }
        }
        lst.pb(p);
    }
    srand(time(NULL));
    best=0; reset(ans,0);
    sort(lst.begin(),lst.end(),cmp);
    for(int rr=0; rr<100000; ++rr){
        mys.clear();
        for(int i=1; i<=h; ++i) for(int j=1; j<=w; ++j) arr[i][j]=0;
        for(int i=1; i<=h; ++i) mys.insert(iii(i+1,pii(i,1)));
        for(int j=1; j<=w; ++j) mys.insert(iii(j+1,pii(1,j)));
        set<iii>::iterator it;
        int x,y;
        int val=0;
        for(int i=0; i<n; ++i){
            if(1.0*clock()/CLOCKS_PER_SEC>4.5) break;
            piece &p = lst[i];
            for(it=mys.begin(); it!=mys.end(); ++it){
                x=it->second.first; y=it->second.second;
                int vv=rand()%10;
//                if(vv==0) continue;
                if(check(x,y,p)){
                    fill(x,y,p);
                    val+=p.n;
                    mys.erase(iii(x+y,pii(x,y)));
                    break;
                }
            }
        }
        if(1.0*clock()/CLOCKS_PER_SEC>4.5) break;
        if(val>best){
            best=val;
            for(int i=1; i<=h; ++i) for(int j=1; j<=w; ++j) ans[i][j]=arr[i][j];
        }
        for(int i=0; i<n; ++i){
            int u=rand()%n, v=rand()%n;
            if(rr>=100 || lst[u].n==lst[v].n) swap(lst[u],lst[v]);
        }
    }

//    cout<<best<<endl;
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j){
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
}
