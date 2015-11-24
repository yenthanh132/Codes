#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int n,m,x[maxn],pos[maxn];
pii y[maxn];
int yv[maxn];

int toRight(int id, int len){
    int left=id+1, right=n, mid, res=id;
    while(left<=right){
        mid=(left+right)/2;
        if(yv[mid]-yv[id] <= len){
            res=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    return res;
}

int toLeft(int id, int len){
    int left=1, right=id-1, mid, res=id;
    while(left<=right){
        mid=(left+right)/2;
        if(yv[id] - yv[mid] <= len){
            res=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    return res;
}

int solve(int id, int len){
    if(n==1) return 1;
    int p = pos[id];
    int dir = 1;

    while(len>0){
        if(dir==1 && p==n) dir=-1;
        else if(dir==-1 && p==1) dir=1;
        if(dir==1){
            int p2 = toRight(p, len);
            if(p2==p){
                p2 = toLeft(p, len);
                if(p2!=p){
                    dir = -1;
                    continue;
                }
                return p;
            }
            int dis = yv[p2] - yv[p];
            int p3 = toLeft(p2, len - dis);
            if(p3==p){
                len%=dis*2;
            }else{
                len-=dis;
                p=p2;
                dir = -1;
            }
        }else if(dir==-1){
            int p2 = toLeft(p, len);
            if(p2==p){
                p2 = toRight(p, len);
                if(p2!=p){
                    dir = 1;
                    continue;
                }
                return p;
            }
            int dis = yv[p] - yv[p2];
            int p3 = toRight(p2, len - dis);
            if(p3==p){
                len%=dis*2;
            }else{
                len-=dis;
                p=p2;
                dir = 1;
            }
        }
    }
    return p;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        scanf("%d",&x[i]);
        y[i] = pii(x[i], i);
    }
    sort(y+1,y+n+1);
    for(int i=1; i<=n; ++i) pos[y[i].second] = i, yv[i] = y[i].first;

    for(int i=0; i<m; ++i){
        int id, len;
        scanf("%d%d",&id,&len);
        printf("%d\n",y[solve(id,len)].second);
    }
}

