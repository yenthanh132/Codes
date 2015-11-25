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

struct mycmp{
    bool operator()(const int& a, const int &b){return (a>b);}
};
int n,v;
char ch;
multiset<int> sright;
multiset<int,mycmp > sleft;

void balance(){
    while(sz(sleft)<sz(sright)) sleft.insert(*sright.begin()), sright.erase(sright.begin());
    while(sz(sleft)>sz(sright)+1) sright.insert(*sleft.begin()), sleft.erase(sleft.begin());
}

void printout(ll v){
    if(v%2==0) printf("%d\n",v/2); else printf("%0.1f\n",double(v)/2);
}

void printmedian(){
    if(sleft.empty()){
        printf("Wrong!\n");
        return;
    }
    double res;
    if(sz(sleft)==sz(sright)) printout(ll(*sleft.begin()) + *sright.begin()); else printout(ll(*sleft.begin())*2);
}
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d\n",&n);
    REP(i,n){
        scanf("%c%d\n",&ch,&v);
        if(ch=='a'){
            if(!sleft.empty() && *sleft.begin()>=v) sleft.insert(v); 
            else sright.insert(v);
        }else{
            if(!sleft.empty() && *sleft.begin()>=v){
                if (sleft.find(v)!=sleft.end()) sleft.erase(sleft.find(v));
                else {printf("Wrong!\n");continue;}
            }else{
                if (!sright.empty() && sright.find(v)!=sright.end()) sright.erase(sright.find(v));
                else {printf("Wrong!\n");continue;}
            }
        }
        balance();
        printmedian();
    }
    //getch();
    return 0;
}
