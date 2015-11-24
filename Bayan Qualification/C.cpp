#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[10][20];
int id[10],tmp[10];

int  ds[3][4] = {{1,2,6,3} , {2,5,3,4} , {1,5,6,4}};

int main(){
    freopen("5.in","r",stdin);
    freopen("5.out","w",stdout);
    int T,n,m;
    char buf[10];
    scanf("%d",&T);
    while(T--){
        for(int i=1; i<=6; ++i) scanf("%s",s[i]), id[i]=i;
        scanf("%d",&n);
        for(int i=0; i<n; ++i){
            scanf("%s%d",buf,&m);
            m%=4;
            int x=buf[0]-'X';
            for(int y=0; y<4; ++y) tmp[ds[x][(y+m)%4]]=id[ds[x][y]];
            for(int y=0; y<4; ++y) id[ds[x][y]]=tmp[ds[x][y]];
        }
        for(int i=1; i<6; ++i) printf("%s ",s[id[i]]);
        printf("%s\n",s[id[6]]);
    }
    return 0;
}

