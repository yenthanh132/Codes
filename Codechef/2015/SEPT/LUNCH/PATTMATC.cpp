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

int n,m,nTest,cnt,len[maxn],start[maxn],pre[maxn];
char S[maxn],T[maxn],t[maxn];
bool startAsterisk;
vector<int> pos[maxn];

int main(){

//    freopen("input.txt","r",stdin);
    scanf("%d",&nTest);
    while(nTest--){
        scanf("%s",T+1);
        int lenT = strlen(T+1);
        cnt=0;

        int i=1;
        while(i<=lenT){
            while(i<=lenT && T[i]=='*') ++i;
            if(i>lenT) break;
            int j=i;
            while(j+1<=lenT && T[j+1]!='*') ++j;

            ++cnt;
            len[cnt] = j-i+1;
            start[cnt] = i;

            i=j+1;
        }

        scanf("%s",S+1);
        int lenS = strlen(S+1);


        for(int i=1; i<=cnt; ++i){
            pos[i].clear();
            for(int j=1; j<=len[i]; ++j) t[j]=T[start[i]+j-1];
            pre[1]=0;
            int x=1,y=0;
            t[len[i]+1]=0;
            while(x<=len[i]){
                while(y>0 && t[x] != t[y]) y=pre[y];
                ++x; ++y;
                if(t[x]==t[y]) pre[x]=pre[y]; else pre[x]=y;
            }
            x=1; y=1;
            while(x<=lenS){
                while(y>0 && t[y]!=S[x]) y=pre[y];
                ++x; ++y;
                if(y>len[i]){
                    pos[i].pb(x-len[i]);
                    y=pre[y];
                }
            }
        }

        for(int i=1; i<=lenS; ++i){
            if(cnt==0){
                printf("%d ",i);
                continue;
            }
            int ans=-1;
            int current = i;
            for(int j=1; j<=cnt; ++j){
                int position = lower_bound(pos[j].begin(),pos[j].end(), current) - pos[j].begin();
                if(position >= sz(pos[j])) break;
                current = pos[j][position] + len[j];
                if(j==cnt) ans=current-1;
            }
            printf("%d ",ans);
        }
        puts("");
    }
}

