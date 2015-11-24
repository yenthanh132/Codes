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

const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
const string move[8]={"U","RU","R","RD","D","LD","L","LU"};

#include <conio.h>
int main(){
    int x1,y1,x2,y2;
    char ch;
    cin>>ch>>x1; y1=ch-'a'+1; x1=9-x1;
    cin>>ch>>x2; y2=ch-'a'+1; x2=9-x2;
    cout<<max(abs(x2-x1),abs(y2-y1))<<endl;
    while(x1!=x2 || y1!=y2){
        int k,dis=abs(x2-x1)+abs(y2-y1);
        REP(kk,8){
            int v=abs(x2-(x1+dx[kk]))+abs(y2-(y1+dy[kk]));
            if(v<dis) dis=v, k=kk;
        }
        x1+=dx[k]; y1+=dy[k];
        cout<<move[k]<<endl;
    }
    //getch();
    return 0;
}
