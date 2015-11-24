#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

char S[maxn];
int K,n;
vector<int> v1,v2;

bool check(){
    int d=0;
    for(int i=1; i<=n; ++i){
        int v=1;
        if(S[i]==')') v=-1;
        d+=v;
        if(d<0) return 0;
    }
    return d==0;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",S+1); n=strlen(S+1);
        scanf("%d",&K);
        if(!check()){
            if(K>1) cout<<-1<<endl;
            else cout<<string(S+1,S+n+1)<<endl;
        }else{
            int c=0;
            int i=1;
            v1.clear();
            v2.clear();
            while(i<=n){
                int j=i;
                while(j+1<=n && S[i]==S[j+1]) ++j;
                ++c;
                if(S[i]==')') v1.pb(i);
                else v2.pb(i);
                i=j+1;
            }
            if(c<K) puts("-1");
            else{
                int x;
                if(K<=sz(v1)) x=v1[K-1];
                else{
                    K-=sz(v1);
                    x=v2[sz(v2)-K];
                }
                for(int i=1; i<=n; ++i) if(i!=x) putchar(S[i]);
                puts("");
            }
        }
    }
}

