#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=4007;
const int maxm=100007;

struct edge{
    int x,y,c,f;
}e[maxm];
int head[maxn],lnk[maxm],M,N,fi,st,trace[maxn],myq[maxn];

void push(int x, int y, int c, int f){
    e[M].x = x; e[M].y = y; e[M].c = c; e[M].f = 0;
    lnk[M] = head[x]; head[x] = M++;
    e[M].x = y; e[M].y = x; e[M].c = 0; e[M].f = 0;
    lnk[M] = head[y]; head[y] = M++;
}

bool findpath(){
    for(int i=1; i<=N; ++i) trace[i]=-1; trace[st] = 0;
    int first=1, last = 1;
    myq[1] = st;
    while(first<=last){
        int u=myq[first++];
        for(int i=head[u]; i!=-1; i=lnk[i]){
            if(e[i].c > e[i].f && trace[e[i].y]==-1){
                trace[e[i].y] = i;
                if(e[i].y==fi) return 1;
                myq[++last]=e[i].y;
            }
        }
    }
    return 0;
}

int incflow(){
    int delta = oo;
    int i,v;
    v=fi;
    do{
        i=trace[v];
        delta=min(delta, e[i].c-e[i].f);
        v=e[i].x;
    }while(v!=st);

    v=fi;
    do{
        i=trace[v];
        e[i].f+=delta;
        e[i^1].f-=delta;
        v=e[i].x;
    }while(v!=st);

    return delta;
}

int T,n,num;
map<string,int> mark;
char buf[111111];
vector<int> lst[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    freopen("C-large-practice.in","r",stdin);
    freopen("C-large-practice.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        num = 0; gets(buf);
        mark.clear();
        for(int i=1; i<=n; ++i){
            gets(buf);
            stringstream ss;
            ss<<string(buf);
            string word;
            lst[i].clear();
            while(ss>>word){
                if(!mark[word]) mark[word]=++num;
                lst[i].pb(mark[word]);
            }
        }
        N = num*2+2;
        fi = num*2+2; st = num*2+1;
        M = 0;
        for(int i=1; i<=N; ++i) head[i]=-1;

        for(vector<int>::iterator it=lst[1].begin(); it!=lst[1].end(); ++it)
            push(st, *it, 1, 0);
        for(vector<int>::iterator it=lst[2].begin(); it!=lst[2].end(); ++it)
            push(*it+num,fi, 1, 0);
        for(int u=1; u<=num; ++u)
            push(u, u+num, 1, 0);
        for(int i=3; i<=n; ++i){
            for(int x=0; x<sz(lst[i]); ++x)
                for(int y=0; y<sz(lst[i]); ++y)
                    push(lst[i][x]+num, lst[i][y], oo, 0);
        }

        int res = 0;
        while(findpath()) res+=incflow();
        printf("Case #%d: %d\n",tt,res);
    }

}
