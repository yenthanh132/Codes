#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;
const int maxk=62;

int pos[maxk];
int cnt[maxn],f[maxn],k,T;
char s[maxn];

int id(char ch){
    if('a'<=ch && ch<='z') return ch-'a';
    if('A'<=ch && ch<='Z') return ch-'A'+26;
    return ch-'0'+52;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        f[0]=0; cnt[0]=1;
        scanf("%d",&k);
        for(int i=0; i<k; ++i) pos[i]=0;
        int len;
        scanf("%s",s+1); len=strlen(s+1);
        int smallest=0, cntSmallest=k;
        for(int i=1; i<=len+1; ++i){
            f[i]=smallest+1; cnt[i]=cntSmallest;
            int p=id(s[i]);
            if(f[pos[p]]==smallest){
                cntSmallest = (cntSmallest-cnt[pos[p]]+oo)%oo;
            }
            pos[p]=i;
            if(f[pos[p]]==smallest){
                cntSmallest = (cntSmallest+cnt[pos[p]])%oo;
            }
            if(cntSmallest == 0){
                smallest = oo;
                for(int j=0; j<k; ++j){
                    if(f[pos[j]] < smallest){
                        smallest = f[pos[j]];
                        cntSmallest = cnt[pos[j]];
                    }else if(f[pos[j]] == smallest)
                        cntSmallest = (cntSmallest + cnt[pos[j]])%oo;
                }
            }
        }
        printf("%d %d\n",f[len+1],cnt[len+1]);
    }
}

