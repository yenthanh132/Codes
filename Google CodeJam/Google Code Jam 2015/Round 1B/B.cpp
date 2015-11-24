#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> iii;
typedef long long ll;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int r,c,n;
set<pii> contains;
set<iii> heap;
int cal(int r, int c){
    int line1=(c+1)/2;
    int line2=c-line1;
    int row1=(r+1)/2;
    int row2=r-row1;
    return row1*line1+row2*line2;
}

int deg(int x, int y){
    int res=0,xt,yt;
    for(int k=0; k<4; ++k){
        xt=x+dx[k]; yt=y+dy[k];
        res+=contains.count(pii(xt,yt));
    }
    return res;
}
int cal1();
int cal2();

int main(){
//    freopen("input.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d%d",&r,&c,&n);
        if(r>c) swap(r,c);
        int x=cal(r,c);
        int res = min(cal1(),cal2());

        printf("Case #%d: %d\n",tt,res);
    }
}


int cal1(){
        int x=cal(r,c);
        int res = 0;
        if(n<=x) res = 0;
        else{
            contains.clear();
            for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j)
                contains.insert(pii(i,j));

            heap.clear();
            for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j){
                int d=deg(i,j);
                res+=d;
                heap.insert(iii(-d,pii(i,j)));
            }
            res/=2;

            int total=r*c;
            while(total>n){
                --total;
                iii u = *heap.begin(); heap.erase(heap.begin());
                vector<pii> lst;
                int x=u.second.first, y=u.second.second, xt, yt;
                for(int k=0; k<4; ++k){
                    xt=x+dx[k]; yt=y+dy[k];
                    if(xt<1 || xt>r || yt<1 || yt>c) continue;
                    int d=deg(xt,yt);
                    heap.erase(iii(-d,pii(xt,yt)));
                    lst.pb(pii(xt,yt));
                }
                contains.erase(pii(x,y));
                res -= -u.first;
                for(int i=0; i<sz(lst); ++i){
                    int d=deg(lst[i].first, lst[i].second);
                    heap.insert(iii(-d,lst[i]));
                }
            }



        }
    return res;
}

int cal2(){
    int res=0;
        contains.clear();
            heap.clear();
            for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j){
                int d=deg(i,j);
                heap.insert(iii(0,pii(i,j)));
            }

            for(int total=1; total<=n; ++total){
                iii u = *heap.begin(); heap.erase(heap.begin());
                vector<pii> lst;
                int x=u.second.first, y=u.second.second, xt, yt;
                for(int k=0; k<4; ++k){
                    xt=x+dx[k]; yt=y+dy[k];
                    if(xt<1 || xt>r || yt<1 || yt>c || contains.count(pii(xt,yt))) continue;
                    int d=deg(xt,yt);
                    heap.erase(iii(d,pii(xt,yt)));
                    lst.pb(pii(xt,yt));
                }
                contains.insert(pii(x,y));
                res += u.first;
                for(int i=0; i<sz(lst); ++i){
                    int d=deg(lst[i].first, lst[i].second);
                    heap.insert(iii(d,lst[i]));
                }
            }
    return res;
}
