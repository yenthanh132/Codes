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

map<string,int> mapname;

string int2str(int v){
    stringstream ss;
    ss<<v;
    return string(ss.str());
}

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    int n;
    string s,st;
    cin>>n;
    FOR(i,1,n){
        cin>>s;
        if(mapname[s]==0){
            cout<<"OK\n";
            mapname[s]=1;
        }else{
            st=s+int2str(mapname[s]);
            while(mapname[st]!=0){
                mapname[s]++;
                st=s+int2str(mapname[s]);
            }
            cout<<st<<endl;
            mapname[st]=1;
        }
    }
    //getch();
    return 0;
}
