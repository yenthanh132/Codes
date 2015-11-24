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

int T,n,q,type;
ll A,B,L,R,X,Y;
int cnt[26], val[maxn];
map<int, ll> dem, sum, sum2;
char s[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);

        reset(cnt, 0);
        val[0] = 0;
        for(int i=1; i<=n; ++i){
            int v=s[i]-'a';
            cnt[v]^=1;
            v = 0;
            for(int c=0; c<26; ++c)
                v |= (cnt[c] << c);
            val[i] = v;
        }

        scanf("%d",&q);
        ll res = 0;
        A = B = 0;
        for(int i=0; i<q; ++i){
            scanf("%lld%lld%d",&X,&Y,&type);
            L = (X + A)%n + 1;
            R = (Y + B)%n + 1;
            if ( L > R ) swap(L, R);
            res = 0;
            dem.clear();
            sum.clear();
            sum2.clear();
            if(type == 0){
                for(int i=L-1; i<=R; ++i){
                    int v=val[i];
                    res += dem[v];
                    ++dem[v];
                }
            }else if(type == 1){
                for(int i=L-1; i<=R; ++i){
                    int v=val[i];
                    res += dem[v]*i - sum[v];
                    sum[v] += i;
                    ++dem[v];
                }
            }else if(type == 2){
                for(int i=L-1; i<=R; ++i){
                    int v=val[i];
                    res += 1ll*i*i*dem[v] - 2ll*i*sum[v] + sum2[v];
                    sum2[v] += 1ll*i*i;
                    sum[v] += i;
                    ++dem[v];
                }
            }

            A = B; B = res;

            printf("%lld\n",res);
        }



    }
}

