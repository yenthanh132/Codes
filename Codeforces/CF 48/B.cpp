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

vector<int> list;
vector<int> a;
string s,st;

void count_table(int,int);

int count_cell(int l, int r){
    if(l>r) return 0;
    stack<int> mys;
    int val=0;
    FOR(x,l,r) if(a[x]==3) mys.push(x+1);
    else if(a[x]==-3){
        if(sz(mys)==1){
            count_table(mys.top(),x-1);
            val++;
        }
        mys.pop();
    }
    return val;
}

int count_row(int l, int r){
    if(l>r) return 0;
    stack<int> mys;
    int val=0;
    FOR(x,l,r) if(a[x]==2) mys.push(x+1);
    else if(a[x]==-2){
        if(sz(mys)==1) val+=count_cell(mys.top(),x-1);
        mys.pop();
    }
    return val;
}

void count_table(int l, int r){
    if(l>r) return;
    stack<int> mys;
    FOR(x,l,r) if(a[x]==1) mys.push(x+1);
    else if(a[x]==-1){
        if(sz(mys)==1) list.pb(count_row(mys.top(),x-1));
        mys.pop();
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    s="";
    while(getline(cin,st))
        s+=st;
    int i=0;
    while(i<sz(s)){
        int j=i+1;
        st="";
        while(s[j]!='>') st+=s[j++];   
        i=j+1;
        if(st=="table") a.pb(1); 
        else if(st=="/table") a.pb(-1);
        else if(st=="tr") a.pb(2);
        else if(st=="/tr") a.pb(-2);
        else if(st=="td") a.pb(3);
        else if(st=="/td") a.pb(-3);
        else puts("ERROR");
    }
    count_table(0,sz(a)-1);
    sort(list.begin(),list.end());
    REP(i,sz(list)) cout<<list[i]<<' ';
    //getch();
    return 0;
}
