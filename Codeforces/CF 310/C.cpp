#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007*3;

vector<int> coor;
int n,q,M;
struct queryNode{
    int x, y;
    char dir[5];
} query[maxn];


struct ITNode{
    int maxV;
    int t;
}IT_H[maxn*4], IT_V[maxn*4];

set<pii> mark;

void IT_lazyupdate(ITNode *IT, int i, int l, int r){
    if(IT[i].t==0) return;
    IT[i].maxV = max(IT[i].maxV, IT[i].t);
    if(l<r){
        IT[i*2].t = max(IT[i*2].t, IT[i].t);
        IT[i*2+1].t = max(IT[i*2+1].t, IT[i].t);
    }
    IT[i].t = 0;
}

void IT_update(ITNode *IT, int i, int l, int r, int s, int f, int v){
    IT_lazyupdate(IT, i, l, r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i].t = v;
        IT_lazyupdate(IT, i, l, r);
        return;
    }
    int mid=(l+r)/2;
    IT_update(IT, i*2, l, mid, s, f, v);
    IT_update(IT, i*2+1, mid+1, r, s, f, v);
    IT[i].maxV = max(IT[i*2].maxV, IT[i*2+1].maxV);
}

int IT_ret;
void IT_get(ITNode *IT, int i, int l, int r, int p){
    IT_lazyupdate(IT, i, l, r);
    if(p<l || p>r) return;
    if(l==r){
        IT_ret = IT[i].maxV;
        return;
    }
    int mid=(l+r)/2;
    IT_get(IT, i*2, l, mid, p);
    IT_get(IT, i*2+1, mid+1, r, p);
    IT[i].maxV = max(IT[i*2].maxV, IT[i*2+1].maxV);
}

void update(ITNode *IT, int l, int r, int v){
    IT_update(IT, 1, 1, M, l, r, v);
}

int get(ITNode *IT, int p){
    IT_ret = 0;
    IT_get(IT, 1, 1, M, p);
    return IT_ret;
}

int getPos(int v){
    return lower_bound(coor.begin(), coor.end(), v) - coor.begin() + 1;
}

int main(){
//    freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&q);
    for(int i=1; i<=q; ++i){
        scanf("%d%d%s",&query[i].x, &query[i].y, query[i].dir);
        coor.pb(query[i].x);
        coor.pb(query[i].y);
        if(query[i].dir[0]=='L') coor.pb(query[i].y+1);
        else coor.pb(query[i].x+1);
    }
    coor.pb(0);
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(),coor.end())-coor.begin());
    M = sz(coor);

    for(int i=1; i<=q; ++i){
        if(mark.count(pii(query[i].x,query[i].y))){
            puts("0");
            continue;
        }
        mark.insert(pii(query[i].x,query[i].y));
        if(query[i].dir[0]=='U'){
            int pos = getPos(query[i].x);
            int maxY = get(IT_H, pos);
            int res = query[i].y - maxY;

            if(res>0){
                int pos_l = getPos(maxY+1);
                int pos_r = getPos(query[i].y);
                update(IT_V, pos_l, pos_r, query[i].x);
            }
            printf("%d\n", res);

        }else{
            int pos = getPos(query[i].y);
            int maxX = get(IT_V, pos);
            int res = query[i].x - maxX;
            if(res>0){
                int pos_l = getPos(maxX+1);
                int pos_r = getPos(query[i].x);
                update(IT_H, pos_l, pos_r, query[i].y);
            }
            printf("%d\n",res);
        }
    }
}

