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

char s[maxn];
int a[maxn];
int n,T,k;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        for(int i=1; i<=n; ++i) a[i]=s[i]-'0';
        int res = 0;
        if(k>1){
            int cur=-1;
            int len=0;
            for(int i=1; i<=n; ++i){
                if(cur!=a[i]){
                    cur=a[i];
                    len=1;
                }else{
                    ++len;
                    if(len>k){
                        ++res;
                        if(i==n || a[i+1]==cur || (i>2 && a[i-2]==1^cur)){
                            a[i]^=1;
                            cur=a[i];
                            len=1;
                        }else{
                            a[i-1]^=1;
                            len=1;
                        }
                    }
                }
            }
        }else{
            int t1=0, t2=0;
            for(int i=1; i<=n; ++i){
                int b=i&1;
                if(a[i]!=b) ++t1;
                b^=1;
                if(a[i]!=b) ++t2;
            }
            if(t1<t2){
                res=t1;
                for(int i=1; i<=n; ++i) a[i]=i&1;
            }else{
                res=t2;
                for(int i=1; i<=n; ++i) a[i]=(i+1)&1;
            }
        }
        printf("%d\n",res);
        for(int i=1; i<=n; ++i) printf("%d",a[i]); puts("");
    }
}
