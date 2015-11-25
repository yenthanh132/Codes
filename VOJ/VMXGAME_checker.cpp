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

bool mark[100][100],ok;

#include <conio.h>
int main(){
    freopen("out.txt","r",stdin);
    int n,m,x1,y1,x2,y2,count=0;
    while(cin>>n){
        ok=true;
        reset(mark,false);
        FOR(i,1,n) FOR(j,1,n) mark[i][j]=1;
        cin>>m;
        FOR(i,1,m){
            cin>>x1>>y1>>x2>>y2;
            if(ok){
                if(mark[x1][y1]==0 || mark[x2][y2]==1 || (abs(x1-x2)+abs(y1-y2)!=2) || mark[(x1+x2)/2][(y1+y2)/2]==0) ok=false;
                if(ok){
                    mark[x1][y1]=mark[(x1+x2)/2][(y1+y2)/2]=0;
                    mark[x2][y2]=1;
                }
            }
        }
        cout<<++count<<": "<<ok<<endl;
    }
    getch();
    return 0;
}
        
    
