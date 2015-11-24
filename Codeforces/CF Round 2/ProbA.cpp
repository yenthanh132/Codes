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

map<string,int> point;
map<string,vector<pii> > plog;
int n,maxpoint=0,v;
string winner,name;

int gettime(string s,int v){
    vector<pii>::iterator it;
    for(it=plog[s].begin(); it!=plog[s].end(); it++) if(it->fi >= v) return it->se;
}
        

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    REP(i,n){
        cin>>name;
        cin>>v;
        point[name]+=v;
        plog[name].pb(pii(point[name],i));
    }
    map<string,int>::iterator it;
    for(it=point.begin(); it!=point.end(); it++)
        if(maxpoint<it->se){
            maxpoint=it->se;
            v=gettime(it->fi,maxpoint);
            winner=it->fi;
        }else if(maxpoint==it->se){
            int t=gettime(it->fi,maxpoint);
            if(t<v){
                winner=it->fi;
                v=t;
            }
        }
    cout<<winner<<endl;
    //getch();
    return 0;
}
