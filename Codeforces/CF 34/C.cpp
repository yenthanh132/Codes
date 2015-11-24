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

string s;
vector<int> list;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>s;
    while(s[0]==',') s.erase(0,1);
    while(s.find(",")!=string::npos){
        list.pb(atoi(s.substr(0,s.find(",")).c_str()));
        s.erase(0,s.find(",")+1);
    }
    list.pb(atoi(s.c_str()));
    sort(list.begin(),list.end());
    list.resize(unique(list.begin(),list.end())-list.begin());
    int i=0,j;
    while(i<sz(list)){
        j=i;
        while(j<sz(list)-1 && list[j+1]==list[j]+1) j++;
        if(i==j) cout<<list[i];
        else cout<<list[i]<<'-'<<list[j];
        i=j+1;
        if(i<sz(list)) cout<<',';
    }
    //getch();
    return 0;
}
