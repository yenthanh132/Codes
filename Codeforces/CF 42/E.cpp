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

const int maxn=107;
const double eps=1e-12;

int n,k[maxn],S;
struct seg{
    int v,len;
}a[maxn][maxn], list[2][maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&S);
    FOR(i,1,n){
        scanf("%d",&k[i]);
        FOR(j,1,k[i]) scanf("%d%d",&a[i][j].v,&a[i][j].len);
    }
    
    int res=0,s1,s2,x,y,M,N;
    FOR(i,1,n-1) FOR(j,i+1,n){
        M=k[i];
        FOR(z,1,M) list[0][z]=a[i][z];
        N=k[j];
        FOR(z,1,N) list[1][z]=a[j][z];
        
        x=y=1; s1=s2=0;
        int prev,last,cur;
        prev=last=0;
        while(x<=M && y<=N){
            if(list[0][x].len==list[1][y].len){
                s1+=list[0][x].v*list[0][x].len;
                s2+=list[1][y].v*list[1][y].len;
                x++;
                y++;
            }else if(list[0][x].len < list[1][y].len){
                s1+=list[0][x].v*list[0][x].len;
                s2+=list[1][y].v*list[0][x].len;
                list[1][y].len-=list[0][x].len;
                x++;
            }else{
                s1+=list[0][x].v*list[1][y].len;
                s2+=list[1][y].v*list[1][y].len;
                list[0][x].len-=list[1][y].len;
                y++;
            }
            if(s1<s2) cur=-1; else if(s1>s2) cur=1; else cur=0;
            if(cur==-prev && cur) res++;
            else if(!prev && cur==-last && cur) res++;
            if(cur || prev){
                last=prev;
                prev=cur;
            }
        }
    }
    printf("%d\n",res);
    
    //getch();
    return 0;
}
            
        
