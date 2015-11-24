#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}



const int maxn=100007;
const int base=73471;

int p[maxn][17],n,d[maxn],m,val[maxn],line[maxn];
vector<pii> e[maxn];
vector<int> arr[maxn], divisors[maxn];
vector<ll> divisorPows[maxn];
bool isPrime[maxn];

void dfs(int u, int parent){
    line[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first;
        if(v==parent) continue;
        p[v][0]=u;
        d[v] = d[u]+1;
        val[v]=e[u][i].second;
        dfs(v,u);
        line[u]=max(line[u],line[v]+1);
    }
}

int lca(int u, int v){
    if(d[u] > d[v]) swap(u,v);
    for(int i=0; i<17; ++i) if((d[v]-d[u])>>i&1) v=p[v][i];
    if(u==v) return u;
    for(int i=16; i>=0; --i) if(p[u][i]!=p[v][i]){
        u=p[u][i];
        v=p[v][i];
    }
    return p[u][0];
}

int distance(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-2*d[r];
}

//heavy-light
int pos[maxn],cnt,up[maxn],len[maxn],id[maxn];

void dfs2(int u, int parent){
    if(!id[u]){
        ++cnt;
        id[u] = cnt;
        pos[u] = 1;
        len[cnt] = 1;
        up[cnt] = parent;
        arr[cnt].clear();
    }
    arr[id[u]].pb(val[u]);

    int x=-1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first;
        if(v==parent) continue;
        if(x==-1 || line[v] > line[x]) x=v;
    }
    if(x!=-1){
        id[x] = id[u];
        pos[x] = pos[u] + 1;
        ++len[id[x]];
    }

    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first;
        if(v==parent) continue;
        dfs2(v,u);
    }
}


ll pw[maxn], invPw[maxn];
struct lineHash{
    struct ITNode{
        ITNode *left, *right;
        ll v1, v2;
    };
    vector<ITNode> IT[maxn];

    void init(vector<int> &arr, vector<ITNode> &IT, int i, int l, int r){
        if(l==r){
            IT[i].v1 = IT[i].v2 = arr[l-1];
            return;
        }
        int mid=(l+r)/2;
        init(arr, IT, i*2, l, mid);
        init(arr, IT, i*2+1, mid+1, r);
        IT[i].v1 = IT[i*2].v1 * pw[r-mid] + IT[i*2+1].v1;
        IT[i].v2 = IT[i*2+1].v2 * pw[mid-l+1] + IT[i*2].v2;
        IT[i].v1 %= oo; IT[i].v2 %= oo;

    }

    void update(vector<ITNode> &IT, int i, int l, int r, int pos, int val){
        if(l==r){
            IT[i].v1 = IT[i].v2 = val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(IT, i*2, l, mid, pos, val);
        else update(IT, i*2+1, mid+1, r, pos, val);
        IT[i].v1 = IT[i*2].v1 * pw[r-mid] + IT[i*2+1].v1;
        IT[i].v2 = IT[i*2+1].v2 * pw[mid-l+1] + IT[i*2].v2;
        IT[i].v1 %= oo; IT[i].v2 %= oo;
    }


    ll valHash;

    void get(vector<ITNode> &IT, int i, int l, int r, int s, int f){
        if(f<l || r<s) return;
        if(s<=l && r<=f){
            valHash *= pw[r-l+1];
            valHash += IT[i].v1;
            valHash %= oo;
            return;
        }
        int mid=(l+r)/2;
        get(IT, i*2, l, mid, s, f);
        get(IT, i*2+1, mid+1, r, s, f);
    }

    ll valHash2;
    void get2(vector<ITNode> &IT, int i, int l, int r, int s, int f){
        if(f<l || r<s) return;
        if(s<=l && r<=f){
            valHash2 *= pw[r-l+1];
            valHash2 += IT[i].v2;
            valHash2 %= oo;
            return;
        }
        int mid=(l+r)/2;
        get2(IT, i*2+1, mid+1, r, s, f);
        get2(IT, i*2, l, mid, s, f);
    }


    ll getHash(int idx, int l, int r, int s, int f){
        if(s > f){
            swap(s, f);
            valHash2 = 0;
            get2(IT[idx], 1, l, r, s, f);
            return valHash2;
        }else{
            valHash = 0;
            get(IT[idx], 1, l, r, s, f);
            return valHash;
        }
    }


} lineHash;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

void initDivisor(int v){
    if(!divisors[v].empty()) return;
    if(isPrime[v]){
        divisors[v].pb(1);
        divisors[v].pb(v);
    }else{
        for(int i=1; i*i<=v; ++i) if(v%i==0){
            divisors[v].pb(i);
            if(i*i!=v) divisors[v].pb(v/i);
        }
        sort(divisors[v].begin(), divisors[v].end());
    }
    divisorPows[v].resize(sz(divisors[v]),0);
    for(int i=0; i<sz(divisors[v]); ++i){
        int c=divisors[v][i];
        divisorPows[v][i] = mypow(pw[c], v/c);
    }
}

typedef pair<ll, int> pli;
typedef pair<int, pii> iii;

iii segments[maxn], segments2[maxn];
int lockMark[maxn], lockId;

int solve1(int u, int v){
    if(d[u] < d[v]) swap(u,v);
    int r=lca(u,v);
    int length = d[u]+d[v]-d[r]*2;
    if(length==1) return 1;

    //init the divisor for length
    initDivisor(length);
    vector<int> &divisor = divisors[length];
    vector<ll> &divisorPow = divisorPows[length];

    //get first char and second char
    ll firstChar, secondChar;
    firstChar=val[u];
    int t=p[u][0];
    if(t==r) secondChar=val[v];
    else secondChar=val[t];

    //fast check
    if(isPrime[length] && firstChar != secondChar) return length;

    ++lockId; //for lockMark array

    int c1=0, c2=0;

    //generate segments

    while(id[u]!=id[r]){
        segments[++c1] = iii(id[u], pii(pos[u], 1));
        u = up[id[u]];
    }
    if(u!=r) segments[++c1] = iii(id[r], pii(pos[u], pos[r]+1));
    while(id[v]!=id[r]){
        segments2[++c2] = iii(id[v], pii(1, pos[v]));
        v = up[id[v]];
    }
    if(v!=r) segments2[++c2] = iii(id[r], pii(pos[r]+1, pos[v]));

    for(int i=c2; i>=1; --i) segments[++c1] = segments2[i];

    //precalculate the totalHash
    ll totalHash = 0;
    for(int i=1; i<=c1; ++i){
        int idx = segments[i].first, l = segments[i].second.first, r = segments[i].second.second;
        int lenSegment = abs(r-l)+1;
        ll h = lineHash.getHash(idx, 1, len[idx], l, r);
        totalHash = (totalHash * pw[lenSegment] + h) % oo;
    }

    //fast check for case period = 1 or 2
    if(firstChar * (divisorPow[0]-1+oo) % oo == (pw[divisor[0]]-1+oo) * totalHash % oo) return 1;
    if(length%2 == 0
        && (firstChar * base + secondChar)%oo * (divisorPow[1]-1+oo) % oo == (pw[divisor[1]]-1+oo) * totalHash % oo)
        return 2;

    int totalLength = length;
    ll totalHash2 = totalHash;

    int it = sz(divisor)-2;
    int res=length;
    for(int i=c1; i>=1; --i){
        int idx = segments[i].first, l = segments[i].second.first, r = segments[i].second.second;
        int lenSegment = abs(r-l)+1;
        ll h = lineHash.getHash(idx, 1, len[idx], l, r);
        totalHash2 = (totalHash2 - h + oo)%oo;
        totalHash2 = totalHash2 * invPw[lenSegment] % oo;
        totalLength -= lenSegment;
        while(it>=0 && divisor[it] > totalLength){
            if(lockMark[divisor[it]] != lockId){
                int x = divisor[it] - totalLength;
                ll h;
                if(l>r) h = lineHash.getHash(idx, 1, len[idx], l, l-x+1);
                else h = lineHash.getHash(idx, 1, len[idx], l, l+x-1);
                ll val = (totalHash2 * pw[x] + h)%oo;
                if(val * (divisorPow[it]-1+oo) %oo == (pw[divisor[it]]-1+oo) * totalHash %oo){
                    //found match period with length: divisor[it]
                    res = min(res, divisor[it]);
                }else{
                    int x = divisor[it];
                    initDivisor(x);
                    for(int j=0; j<sz(divisors[x]); ++j) lockMark[divisors[x][j]]=lockId;
                }
            }
            --it;
        }
    }
    return res;

//    int it=0; //it for divisors
//    for(int i=1; i<=c1; ++i){
//        int idx = segments[i].first, l = segments[i].second.first, r = segments[i].second.second;
//        int lenSegment = abs(r-l)+1;
//        while(it<sz(divisor) && divisor[it] <= totalLength2 + lenSegment){
//            int x = divisor[it] - totalLength2;
//            ll h;
//            if(l>r) h = lineHash.getHash(idx, 1, len[idx], l, l-x+1);
//            else h = lineHash.getHash(idx, 1, len[idx], l, l+x-1);
//            ll val = (totalHash2 * pw[x] + h)%oo;
//            if(val * (divisorPow[it]-1+oo) %oo == (pw[divisor[it]]-1+oo) * totalHash %oo) return divisor[it];
//            ++it;
//        }
//        ll h = lineHash.getHash(idx, 1, len[idx], l, r);
//        totalHash2 = (totalHash2 * pw[lenSegment] + h) % oo;
//        totalLength2 += lenSegment;
//    }

}

void solve2(int u, int v, int c){
    if(d[u] < d[v]) swap(u,v);
    lineHash.update(lineHash.IT[id[u]], 1, 1, len[id[u]], pos[u], c);
    val[u] = c;
}

int main(){
    //init
    pw[0] = 1; invPw[0]=1;
    for(int i=1; i<=100000; ++i) pw[i]=pw[i-1]*base%oo, invPw[i] = mypow(pw[i], oo-2);
    isPrime[2]=1;
    for(int i=3; i<=100000; i+=2) isPrime[i]=1;
    for(int i=3; i*i<=100000; i+=2) if(isPrime[i])
        for(int j=i*i; j<=100000; j+=2*i) isPrime[j]=0;
    lockId = 0;

    //====================================

//    freopen("input.txt","r",stdin);
    int T;
    read(T);
    while(T--){
        read(n);
        for(int u=1; u<=n; ++u) e[u].clear();

        for(int i=0; i<n-1; ++i){
            int u,v;
            char s;
            read(u); read(v); s=getchar();
            e[u].pb(pii(v,s));
            e[v].pb(pii(u,s));
        }

        d[1]=0;
        dfs(1,-1);
        for(int k=1; k<17; ++k) for(int u=1; u<=n; ++u) p[u][k]=p[p[u][k-1]][k-1];

        for(int u=1; u<=n; ++u) id[u]=0;
        cnt=0;
        dfs2(1,-1);

        for(int i=1; i<=cnt; ++i){
            lineHash.IT[i].resize(len[i]*4);
            lineHash.init(arr[i], lineHash.IT[i], 1, 1, len[i]);
        }


        scanf("%d",&m);
        for(int i=0; i<m; ++i){
            int type, u, v;
            char s;
            read(type); read(u); read(v);
            if(type==1){
                int res = solve1(u,v);
                printf("%d\n",res);
            }else{
                s=getchar();
                solve2(u,v,s);
            }
        }

    }
}
