#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=400007;
const int maxq=500007;

char s[maxn];
int len,n,pos[maxn],q,id[maxn],slen[maxn];

//suffix array
int sa[maxn],tsa[maxn],ra[maxn],tra[maxn],cnt[maxn],pre[maxn],lcp[maxn],plcp[maxn],rev_sa[maxn];
int fra(int i){ return (i<=len)?ra[i]:0; }

int L[maxn],R[maxn],mys[maxn];

int BIT[maxn];

struct query{
    int id, i, k, sign, pos;
};
vector<int> pos_by_id[maxn];
vector<query> qlist;
bool cmp(const query &a, const query&b){
    return a.i<b.i;
}
int ans[maxq];

void update(int i, int v){
    for(;i<=len;i+=i&(-i)) BIT[i]+=v;
}

int get(int i){
    int res=0;
    for(;i>0; i-=i&(-i)) res+=BIT[i];
    return res;
}

void sort(int k){
    int maxv=max(300,len);
    for(int i=0; i<=maxv; ++i) cnt[i]=0;
    for(int i=1; i<=len; ++i) cnt[fra(sa[i]+k)]++;
    for(int i=0, sum=0, tmp; i<=maxv; ++i){
        tmp=sum;
        sum+=cnt[i];
        cnt[i]=tmp;
    }
    for(int i=1; i<=len; ++i) tsa[++cnt[fra(sa[i]+k)]]=sa[i];
    for(int i=1; i<=len; ++i) sa[i]=tsa[i];
}

void constructSA(){
    for(int i=1; i<=len; ++i){
        sa[i]=i;
        ra[i]=s[i];
    }
    for(int k=1; k<len; k*=2){
        sort(k); sort(0);
        tra[sa[1]]=1;
        int r=1;
        for(int i=2; i<=len; ++i){
            if(ra[sa[i]]!=ra[sa[i-1]] || fra(sa[i]+k)!=fra(sa[i-1]+k)) ++r;
            tra[sa[i]]=r;
        }
        for(int i=1; i<=len; ++i) ra[i]=tra[i];
    }

    pre[sa[1]]=-1;
    for(int i=2; i<=len; ++i) pre[sa[i]]=sa[i-1];
    int x=0;
    for(int i=1; i<=len; ++i){
        if(pre[i]==-1){
            plcp[i]=0;
            x=0;
            continue;
        }
        while(i+x<=len && pre[i]+x<=len && s[i+x]==s[pre[i]+x] && s[i+x]!='@') ++x;
        plcp[i]=x;
        x=max(0,x-1);
    }

    for(int i=1; i<=len; ++i) lcp[i]=plcp[sa[i]];
}

int main(){
//    freopen("input.txt","r",stdin);
    len=0;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i){
        scanf("%s",s+len+1);
        int len2=strlen(s+len+1);
        pos[i]=len+1;
        for(int j=len+1; j<=len+len2; ++j) id[j]=i;
        len+=len2+1;
        slen[i]=len2;
        s[len]='@';
    }
    constructSA();
    for(int i=1; i<=len; ++i) rev_sa[sa[i]] = i;
    int last=0;
    mys[0]=0;
    for(int i=1; i<=len; ++i){
        while(last>0 && lcp[mys[last]]>=lcp[i]) --last;
        L[i]=mys[last];
        mys[++last]=i;
    }
    mys[0]=len+1;
    last=0;
    for(int i=len; i>=1; --i){
        while(last>0 && lcp[mys[last]]>=lcp[i]) --last;
        R[i]=mys[last];
        mys[++last]=i;
    }


    for(int i=1; i<=len; ++i)
        if(id[sa[i]]!=0)
            pos_by_id[id[sa[i]]].pb(i);

    for(int i=1; i<=q; ++i){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        query q1,q2;
        q1.id = q2.id = i;
        q1.i = l-1;
        q2.i = r;
        q1.sign=-1;
        q2.sign=1;
        q1.pos = q2.pos = rev_sa[pos[k]];
        q1.k = q2.k = k;
        qlist.pb(q1); qlist.pb(q2);
    }

    sort(qlist.begin(),qlist.end(), cmp);
    int it=1;
    reset(ans,0);

//    for(int i=1; i<=len; ++i) printf("%2d %2d %2d %s\n",L[i],R[i],lcp[i],s+sa[i]);

    for(int i=0; i<sz(qlist); ++i){
        query q=qlist[i];
        while(it<=q.i){
            for(int j=0; j<sz(pos_by_id[it]); ++j)
                update(pos_by_id[it][j],1);
            ++it;
        }
        int l=q.pos-1;
        int r=q.pos;
        if(lcp[q.pos]>=slen[q.k]){
            l=L[q.pos]-1;
            r=R[q.pos]-1;
        }else if(lcp[q.pos+1]>=slen[q.k]){
            l=L[q.pos+1]-1;
            r=R[q.pos+1]-1;
        }
        ans[q.id] += q.sign * (get(r)-get(l));
    }



    for(int i=1; i<=q; ++i) printf("%d\n",ans[i]);
}

