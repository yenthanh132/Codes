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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 1001

vector<pii> lst1,lst2,lst3;
bool a1[maxn][maxn], a2[maxn][maxn];
int n,k,x,y,u,v;
bool ok;

void inc(int &u, int &v){
    if(v<n) v++; else u++, v=1;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    FOR(i,1,maxn) FOR(j,1,maxn) a2[i][j]=1, a1[i][j]=0;
    char s[4];
    REP(i,3) s[i]=getchar();
    while(strncmp(s,"END",3)!=0){
        if(strncmp(s,"NEW",3)==0){
            scanf("%d%d\n",&n,&k);
            if(k==0){
                while(!lst1.empty()){
                    x=lst1.back().fi; y=lst1.back().se;
                    a1[x][y]=0;
                    lst1.pop_back();
                }
            }else{
                while(!lst2.empty()){
                    x=lst2.back().fi; y=lst2.back().se;
                    a2[x][y]=1;
                    lst2.pop_back();
                }
                lst3=vector<pii>();
                u=v=1;
            }
        }else if(strncmp(s,"ADD",3)==0){
            scanf("%d%d\n",&x,&y);
            if(k==0){
                if(a1[x][y]==0) a1[x][y]=1, lst1.pb(pii(x,y));
            }else
                if(a2[x][y]==0) a2[x][y]=1, lst3.pb(pii(x,y));
        }else if(strncmp(s,"DEL",3)==0){
            scanf("%d%d\n",&x,&y);
            if(k==0) a1[x][y]=0;
            else if (a2[x][y]==1) a2[x][y]=0, lst2.pb(pii(x,y));
        }else if(strncmp(s,"EDG",3)==0){
            scanf("%d%d\n",&x,&y);
            if(k==0) puts((a1[x][y]?"YES\n":"NO\n"));
            else puts((a2[x][y]?"YES\n":"NO\n"));
        }else if(strncmp(s,"ANY",3)==0){
            scanf("\n");
            ok=false;
            if(k==0){
                while(!lst1.empty()){
                    x=lst1.back().fi; y=lst1.back().se;
                    lst1.pop_back();
                    if(a1[x][y]){a1[x][y]=0; ok=true; break;}
                }
            }else{
                while(!lst3.empty()){
                    x=lst3.back().fi; y=lst3.back().se;
                    lst3.pop_back();
                    if(a2[x][y]){a2[x][y]=0; ok=true; lst2.pb(pii(x,y)); break;}
                }
                if(!ok)
                    while(u<=n){
                        x=u; y=v;
                        inc(u,v);
                        if(a2[x][y]){ok=true; a2[x][y]=0; lst2.pb(pii(x,y)); break;}
                    }
            }
            if(ok) printf("%d %d\n",x,y); else printf("-1\n");
        }
        REP(i,3) s[i]=getchar();
    }
    //getch();
    return 0;
}
