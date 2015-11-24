#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;

int n,dis[6][maxn],len[6],arr[maxn],a[maxn];
int jump[maxn];
int mark[maxn];

ll gcd(ll a, ll b, ll &x, ll &y){
    if(a<b) return gcd(b,a,y,x);
    if(b==0){
        x=1; y=0;
        return a;
    }
    ll x2,y2;
    ll d = gcd(b,a%b,x2,y2);
    x=y2; y=x2-y2*(a/b);
    return d;
}
\
void dfs(int u, int i){
    ++len[u];
    int j = jump[i];
    if(dis[u][j]==-1){
        dis[u][j]=dis[u][i]+1;
        dfs(u,j);
    }
}

int main(){
    //freopen("cards.in","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n),n>0){
        for(int i=0; i<n*5; ++i) arr[i]=i;
        for(int i=0, p=0, x=0, y=2*n, z=4*n; i<n; ++i){
            jump[x++]=p++;
            jump[x++]=p++;
            jump[y++]=p++;
            jump[y++]=p++;
            jump[z++]=p++;
        }

        for(int i=0; i<n*5; ++i) scanf("%d",&a[i]);

        reset(dis,-1);
        for(int i=0; i<n*5; ++i) if(1<=a[i] && a[i]<=5){
            int u=a[i];
            len[u]=0;
            dis[u][i]=0;
            dfs(u,i);
        }

        ll res = oo, player = -1;
        reset(mark,0);
        int imark=0;
        for(int i=0; i<n; ++i){
            int per[6],pos[6];
            for(int j=0; j<5; ++j) per[j]=j;
            do{
                for(int j=1; j<=5; ++j) pos[j]=per[j-1]+i*5;
                ll length=1, ans = 0, val, val2, length2, d,x,y;
                bool ok=1;
                for(int j=1; j<=5; ++j){
                    val = ans;
                    val2 = dis[j][pos[j]];
                    length2 = len[j];
                    if(val2==-1){
                        ok=0;
                        break;
                    }

                    d = gcd(length, length2, x, y);
                    if((val2 - val)%d!=0){
                        ok=0;
                        break;
                    }
                    x *= (val2 - val)/d;
                    if(x<0){
                        x += length2 * (-x/length2);
                        if(x<0) x+=length2;
                    }else{
                        x -= length2 * (x/length2);
                    }
                    ans += length * x;
                    length = length / d * length2;
                    /*
                        length * x + val = y * length2 + val2
                        length * x - length2 * y = val2 - val
                    */

                }
                if(!ok) continue;
                ans %= length;
                if( ans == 0 ) ans = length;

                if(res > ans){
                    res = ans;
                    player = i+1;
                }

            }while(next_permutation(per,per+5));

        }

        if(player == -1) puts("Neverending game.");
        else printf("Player %lld wins game number %lld.\n",player,res);
    }

    return 0;
}

