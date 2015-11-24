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

int n,m,len;
char s[maxn];
bool mark[maxn];
bool ok[maxn];
int pre[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1); len=strlen(s+1);
    pre[0]=0;
    int i=1,j=0;
    while(i<=len){
        while(j>0 && s[i]!=s[j]) j=pre[j];
        ++i; ++j;
        pre[i]=j;
    }

    j=pre[len+1];
    while(j){
        ok[j-1]=1;
        j=pre[j];
    }

    reset(mark,0);
    int last=-1;
    for(int i=0; i<m; ++i){
        int p;
        scanf("%d",&p);
        if(last!=-1 && last+len-1>=p){
            int v = last+len-p;
            if(!ok[v]){
                cout<<0<<endl;
                return 0;
            }
            for(int j=last+len; j<p+len; ++j) mark[j]=1;
        }else{
            for(int j=p; j<p+len; ++j) mark[j]=1;
        }
        last = p;
    }
    ll res = 1;
    for(int i=1; i<=n; ++i) if(!mark[i]) res=res*26%oo;
    cout<<res<<endl;
}

