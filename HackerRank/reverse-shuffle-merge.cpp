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
int pos[maxn][26],sum[maxn][26],n;
int cnt[26];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1; i<=n; ++i) cnt[s[i]-'a']++;
    for(int i=0; i<26; ++i) cnt[i]/=2;

    for(int i=0; i<26; ++i) pos[0][i]=0;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<26; ++j) pos[i][j]=pos[i-1][j], sum[i][j]=sum[i-1][j];
        pos[i][s[i]-'a']=i;
        sum[i][s[i]-'a']++;
    }

    for(int u=n, i=0; i<n/2; ++i, --u){
        int x=-1;
        for(int v=0; v<26; ++v) if(cnt[v]>0){
            int p=pos[u][v];
            if(p==0) continue;
            bool ok=1;
            for(int ch=0; ch<26; ++ch) if(cnt[ch] > sum[p][ch]){
                ok=0;
                break;
            }
            if(ok){
                x=v;
                break;
            }
        }
        u=pos[u][x];
        cnt[x]--;
        printf("%c",x+'a');
    }
}

