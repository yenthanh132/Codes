#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

const int maxn=100007;

int sum[26][maxn],n,q;
char s[maxn],buf[10];

int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        printf("Case #%d:\n",tt);
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1; i<=n; ++i){
            for(int j=0; j<26; ++j) sum[j][i]=sum[j][i-1];
            sum[s[i]-'A'][i]++;
        }
        scanf("%d",&q);
        int x,y;
        for(int i=0; i<q; ++i){
            scanf("%s%d%d",buf,&x,&y);
            ++x; ++y;
            if(buf[0]=='g'){
                for(int j=0; j<26; ++j) printf("%d ",sum[j][y]-sum[j][x-1]);
                puts("");
            }else{
                sort(s+x,s+y+1);
                for(int k=x; k<=y; ++k){
                    for(int j=0; j<26; ++j) sum[j][k]=sum[j][k-1];
                    sum[s[k]-'A'][k]++;
                }
            }
        }
    }
    return 0;
}


