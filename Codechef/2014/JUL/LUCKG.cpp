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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=2007;
const int dx[3][4] = {{1,3,10,11},{2,7,8,9},{4,5,6,12}};
int a[maxn][maxn],n,m,p[maxn],q[maxn],t;
bool mark[maxn];

bool check(){
    int m2=m*m;
    REP(i,n) sort(a[i],a[i]+m);
    REP(i,n){
        int j=p[i];
        int c=0;
        int sum=0;
        REP(y,m){
            while(c<m && a[i][y]>a[j][c]) ++c;
            sum+=c;
        }
        if(sum*2<=m2) return 0;
    }
    return 1;
}

int main(){

//    int per[20];
//    n=3; m=4;
//    FOR(i,1,n*m) per[i]=i;
//    p[0]=1; p[1]=2; p[2]=0;
//    do{
//        int p=1;
//        REP(i,n) REP(j,m) a[i][j]=per[p++];
//        if(check()){
//            REP(i,n){
//                REP(j,m) cout<<a[i][j]<<' ';
//                cout<<endl;
//            }
//            break;
//        }
//    }while(next_permutation(per+1,per+m*n+1));
//    return 0;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d%d",&n,&m);
        REP(i,n) scanf("%d",&p[i]), q[p[i]]=i;

        reset(mark,1);
        int v=1;
        REP(i,n) if(mark[i]){
            int cnt=1;
            int pos=i;
            mark[i]=0;
            while(mark[q[pos]]){
                pos=q[pos];
                mark[pos]=0;
                ++cnt;
            }
            pos=i;
            if(cnt==3 && m==4){
                REP(x,cnt){
                    REP(y,m) a[pos][y]=dx[x][y]+v-1;
                    pos=p[pos];
                }
                v+=12;
                continue;
            }
            REP(y,m){
                REP(x,cnt){
                    a[pos][y]=v++;
                    pos=q[pos];
                }
                pos=q[pos];
            }
        }
        if(check()){
            REP(x,n){
                REP(y,m-1) printf("%d ",a[x][y]);
                printf("%d\n",a[x][m-1]);
            }

        }else printf("No Solution\n");
    }

    return 0;
}
