#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2507;

vector<int> ylist,xlist;
vector<pii> poly[55];
int T,p,n,width,height;
int yard[maxn][maxn];

int topoList[55],length[55],cnt;
bool free1[55];
vector<int> e[55];

int pos(vector<int> &lst, int v){
    return lower_bound(lst.begin(),lst.end(),v)-lst.begin()+1;
}

bool invalid, intersect, nesting;

void doMark(int x1, int y1, int x2, int y2, int id){
    if(x1==x2){
        if(y1>y2) swap(y1,y2);
        for(int y=y1; y<=y2; ++y){
            if(yard[x1][y]){
                if(yard[x1][y]==id){
                    invalid = 1;
                }else{
                    intersect = 1;
                }
            }
            yard[x1][y]=id;
        }
    }else{
        if(x1>x2) swap(x1,x2);
        for(int x=x1; x<=x2; ++x){
            if(yard[x][y1]){
                if(yard[x][y1]==id){
                    invalid = 1;
                }else{
                    intersect = 1;
                }
            }
            yard[x][y1]=id;
        }
    }
}

bool inside(int i, int j){ //i inside j
    int x=poly[i][0].first, y=poly[i][0].second;
    int n=sz(poly[j]);
    int cnt=0;
    for(int z=0; z<n-1; ++z){
        int x1=poly[j][z].first, y1=poly[j][z].second;
        int x2=poly[j][z+1].first, y2=poly[j][z+1].second;
        if(x1==x2){
            if(y1>y2) swap(y1,y2);
            if(x2>x && y1<=y && y<y2) ++cnt;
        }
    }
    return cnt&1;
}

void dfs(int u){
    free1[u]=0;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs(v);
    }
    topoList[cnt--]=u;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&p);
        ylist.clear(); xlist.clear();
        reset(yard,0);
        for(int i=1; i<=p; ++i){
            scanf("%d",&n);
            poly[i].clear();
            int x,y;
            for(int j=0; j<n; ++j){
                scanf("%d%d",&x,&y);
                xlist.pb(x); ylist.pb(y);
                poly[i].pb(pii(x,y));
            }
        }
        sort(xlist.begin(),xlist.end());
        xlist.resize(unique(xlist.begin(),xlist.end())-xlist.begin());
        sort(ylist.begin(),ylist.end());
        ylist.resize(unique(ylist.begin(),ylist.end())-ylist.begin());
        width = sz(xlist); height=sz(ylist);

        invalid = 0;
        intersect = 0;
        nesting = 0;
        for(int i=1; i<=p; ++i){
            n=sz(poly[i]);
            for(int j=0; j<n; ++j){
                poly[i][j].first = pos(xlist,poly[i][j].first);
                poly[i][j].second = pos(ylist,poly[i][j].second);
            }

            for(int j=0; j<n; ++j){
                int x1=poly[i][j].first, y1=poly[i][j].second;
                int x2=poly[i][(j+1)%n].first, y2=poly[i][(j+1)%n].second;
                if(j==n-1){
                    if(x1!=x2 || y1!=y2) invalid = 1;
                    break;
                }
                if(x1==x2){
                    if(y1<y2) doMark(x1,y1+1,x1,y2,i);
                    else doMark(x1,y2,x1,y1-1,i);
                }else{
                    if(x1<x2) doMark(x1+1,y1,x2,y1,i);
                    else doMark(x2,y1,x1-1,y1,i);
                }
            }

            if(invalid) break;
        }
//        for(int j=height; j>=1; --j){
//            for(int i=1; i<=width; ++i) cout<<yard[i][j];
//            cout<<endl;
//        }

        if(!invalid && !intersect){
            for(int i=1; i<=p; ++i){
                length[i]=1;
                e[i].clear();
                for(int j=1; j<=p; ++j) if(i!=j && inside(i,j)) e[i].pb(j);
            }

            reset(free1,1); cnt=p;
            for(int i=1; i<=p; ++i) if(free1[i]) dfs(i);
            for(int i=1; i<=p; ++i){
                int u=topoList[i];
                for(int j=0; j<sz(e[u]); ++j){
                    int v=e[u][j];
                    length[v]=max(length[v],length[u]+1);
                    if(length[v]>2){
                        nesting = 1;
                    }
                }
            }
        }

        if(invalid) puts("INVALID POLYGON");
        else{
            if(intersect) puts("INTERSECTING POLYGONS");
            else{
                if(nesting) puts("INVALID NESTING");
                else{
                    puts("CORRECT");
                }
            }
        }
    }
}

