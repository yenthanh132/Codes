#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char a[55][55];
int m,n;

bool check(int x, int y){
    int c[26];
    reset(c,0);
    c[a[x][y]-'a']++;
    c[a[x][y+1]-'a']++;
    c[a[x+1][y]-'a']++;
    c[a[x+1][y+1]-'a']++;
    return c['f'-'a']==1 && c['a'-'a']==1 && c['c'-'a']==1 && c['e'-'a']==1;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1; i<=m; ++i) scanf("%s",a[i]+1);
    int res=0;
    for(int i=1; i<m; ++i) for(int j=1; j<n; ++j) res+=check(i,j);
    cout<<res<<endl;
}

