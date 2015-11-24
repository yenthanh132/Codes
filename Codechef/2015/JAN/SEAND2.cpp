#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;
const int maxlen=1007;

int T,len,a[maxn],n,v[maxn];
ll p10[maxn][maxlen];
int num[maxlen];
char str[maxlen];

ll calc_swap(int i, int j, ll &cur){
    ll ret = 0;
    for(int idx = 1; idx<=n; ++idx){
        ret += (v[idx] + ((num[j]-num[i])*p10[idx][len-i] + (num[i]-num[j])*p10[idx][len-j])%a[idx] + a[idx])%a[idx];
        if(ret >= cur) return ret;
    }
    return ret;
}


int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        len=strlen(str+1);
        for(int i=1; i<=len; ++i) num[i]=str[i]-'0';
        scanf("%d",&n);
        ll cur=0;
        for(int i=1; i<=n; ++i){
            scanf("%d",&a[i]);
            v[i]=0;
            p10[i][0]=1;
            for(int j=len,d=0; j>=1; --j){
                v[i]=(v[i]+p10[i][d]*num[j])%a[i];
                ++d;
                p10[i][d]=p10[i][d-1]*10%a[i];
            }
            cur += v[i];
        }
        for(int i=1; i<=max(1100,len*25); ++i){
            int x=rand()%len+1, y=rand()%len+1;
            while(x==y) y=rand()%len+1;
            ll new_v = calc_swap(x,y,cur);
            if(new_v<cur){
                cur=new_v;
                for(int idx=1; idx<=n; ++idx)
                    v[idx] = (v[idx] + ((num[y]-num[x])*p10[idx][len-x] + (num[x]-num[y])*p10[idx][len-y])%a[idx] + a[idx])%a[idx];
                swap(num[x],num[y]);
            }
        }
        for(int i=1; i<=len; ++i) printf("%d",num[i]);
        puts("");
    }
}

