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

struct team{string name; int win,lose,score;} a[5],b[5];

bool mycmp(team a, team b){
    if(a.score>b.score) return true; else if(a.score<b.score) return false;
    else if(a.win-a.lose>b.win-b.lose) return true; else if(a.win-a.lose<b.win-b.lose) return false;
    else if(a.win>b.win) return true; else if(a.win<b.win) return false;
    else return(a.name<b.name);
}

map<pair<string,string>,bool> mapvs;
map<string,bool> mapname;
int n,X,Y;

void update(int x, int y, int &X, int &Y){
    if(X==-1 || ((x-y<X-Y) || (x-y==X-Y && y<Y))) X=x, Y=y;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s1,s2,s3;
    int p1,p2,count1[5],w,l;
    reset(count1,0);
    n=0;
    FOR(index,1,5){
        cin>>s1>>s2>>s3;
        p1=p2=0;
        w=int(s3[0])-48; l=int(s3[2])-48;
        FOR(i,1,n) if(a[i].name==s1){p1=i; break;};
        if(p1==0){p1=++n; a[n].name=s1; a[n].win=a[n].lose=a[n].score=0;}
        FOR(i,1,n) if(a[i].name==s2){p2=i; break;};
        if(p2==0){p2=++n; a[n].name=s2; a[n].win=a[n].lose=a[n].score=0;}
        count1[p1]++; count1[p2]++;
        a[p1].win+=w; a[p1].lose+=l;
        a[p2].win+=l; a[p2].lose+=w;
        if(w==l) a[p1].score++, a[p2].score++;
        else if(w>l) a[p1].score+=3; else a[p2].score+=3;
    }
    FOR(i,1,n) if(a[i].name=="BERLAND"){p1=i; break;};
    FOR(i,1,n) if(count1[i]==2 && i!=p1){p2=i; break;};
    X=Y=-1;
    FOR(w,1,100)
        FOR(l,0,w-1){
            FOR(i,1,4) b[i]=a[i];
            b[p1].score+=3;
            b[p1].win+=w; b[p1].lose+=l;
            b[p2].win+=l; b[p2].lose+=w;
            sort(b+1,b+5,mycmp);
            if(b[1].name=="BERLAND" || b[2].name=="BERLAND") update(w,l,X,Y);
        }
    if(X==-1) cout<<"IMPOSSIBLE"<<endl; else cout<<X<<":"<<Y<<endl;
    //getch();
    return 0;
}
