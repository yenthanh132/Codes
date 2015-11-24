#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=307;
int N,T;
pii a[maxn],b[maxn];
int na,nb;
bool fa[maxn],fb[maxn];

int val(string s){
    return ((s[0]-'0')*10 + s[1]-'0')*60 + (s[3]-'0')*10+s[4]-'0';
}

void dfs(int side, int u){
    if(side==0){
        fa[u]=0;
        for(int i=1; i<=nb; ++i) if(fb[i] && b[i].first >= a[u].second + T){
            dfs(1,i);
            break;
        }
    }else{
        fb[u]=0;
        for(int i=1; i<=na; ++i) if(fa[i] && a[i].first >= b[u].second + T){
            dfs(0,i);
            break;
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>N;
    for(int tt=1; tt<=N; ++tt){
        cin>>T;
        cin>>na>>nb;
        string s1,s2;
        for(int i=1; i<=na; ++i){
            cin>>s1>>s2;
            a[i]=pii(val(s1),val(s2));
        }
        for(int i=1; i<=nb; ++i){
            cin>>s1>>s2;
            b[i]=pii(val(s1),val(s2));
        }
        sort(a+1,a+na+1);
        sort(b+1,b+nb+1);
        reset(fa,1); reset(fb,1);
        int res1 = 0, res2 = 0;
        int i=1, j=1;
        while (i<=na || j<=nb){
            if(j>nb || (i<=na && a[i].first<=b[j].first)){
                dfs(0,i);
                ++i;
                ++res1;
            }else{
                dfs(1,j);
                ++j;
                ++res2;
            }
            while(i<=na && !fa[i]) ++i;
            while(j<=nb && !fb[j]) ++j;
        }
        printf("Case #%d: %d %d\n",tt,res1,res2);
    }

}
