#include <iostream>
#include <algorithm>
#include <cstdio>
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

#define maxn 15000

int main(){
    //freopen("test.txt","r",stdin);
    priority_queue<int> heap;
    char ch;
    int v;
    while (scanf("%c",&ch)!=EOF){
        if(ch=='+'){
            scanf("%d\n",&v);
            if (sz(heap)<maxn) heap.push(v);
        }else{
            scanf("\n");
            if (!heap.empty()){
                v=heap.top();
                while(!heap.empty() && heap.top()==v) heap.pop();
            }
        }
    }
    vector<int> ds;
    while (!heap.empty()){
        if (ds.empty() || ds.back()!=heap.top()) ds.pb(heap.top());
        heap.pop();
    }
    printf("%d\n",ds.size());
    for(vector<int>::iterator it=ds.begin();it<ds.end();it++) printf("%d\n",*it);
    return 0;
}
