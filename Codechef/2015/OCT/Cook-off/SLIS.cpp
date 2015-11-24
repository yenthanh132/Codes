#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int a[maxn],n,T,m;
pii bit[maxn],cbit[maxn];
map<int,int> mm;

void update(pii &v, pii &cnt, int newv, int newcnt){
    if(v.first < newv){
        v.second = v.first;
        cnt.second = cnt.first;
        v.first = newv;
        cnt.first = newcnt;
    }else if(v.first == newv){
        cnt.first = (cnt.first + newcnt)%oo;
    }else if(v.second < newv){
        v.second = newv;
        cnt.second = newcnt;
    }else if(v.second == newv){
        cnt.second = (cnt.second + newcnt)%oo;
    }
}

void update(pii &v, pii &cnt, pii v2, pii cnt2){
    update(v, cnt, v2.first, cnt2.first);
    update(v, cnt, v2.second, cnt2.second);
}

void update(int i, pii v, pii cnt){
    for( ; i<=m; i+=i&(-i)){
        update(bit[i],cbit[i], v, cnt);
    }
}

void get(int i, pii &v, pii &cnt){
    v = pii(0,0);
    cnt = pii(0,0);
    for( ; i; i-=i&(-i)){
        update(v, cnt, bit[i], cbit[i]);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mm.clear();
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]), mm[a[i]]=0;
        m=0;
        for(map<int,int>::iterator it=mm.begin(); it!=mm.end(); ++it) it->second = ++m;
        for(int i=1; i<=n; ++i) a[i]=mm[a[i]];

        for(int i=1; i<=m; ++i)
            bit[i]=cbit[i]=pii(0,0);

        pii r1,r2;
        r1=pii(0,0); r2=pii(0,0);
        for(int i=1; i<=n; ++i){
            pii v,cnt;
            get(a[i]-1,v,cnt);
            v.first++;
            if(v.first>1) v.second++;
            if(v.first==1) cnt.first=1;
            if(v.second==1) cnt.second=1;
            update(r1,r2,v,cnt);
            update(a[i],v,cnt);
        }

        cout<<r2.second<<endl;
    }
}

