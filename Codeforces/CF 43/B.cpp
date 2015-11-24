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

const string s[5]={"S","M","L","XL","XXL"};
int k,a[5];

int del(int v){
    for(int j=0; j<5; j++){
        if(0<=v+j && v+j<5 && a[v+j]>0){
            a[v+j]--;
            return v+j;
        }
        if(0<=v-j && v-j<5 && a[v-j]>0){
            a[v-j]--;
            return v-j;
        }
    }
    return 0;
}

int main(){
    REP(i,5) cin>>a[i];
    cin>>k;
    string st;
    REP(i,k){
        cin>>st;
        int j=0;
        for(j=0;j<5;++j) if(st==s[j]) break;
        j=del(j);
        cout<<s[j]<<endl;
    }
    return 0;
}
