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

string s,s1,s2;
vector<int> next1,next2;

vector<int> getarr(string &s){
    vector<int> next(s.length()+1,0);
    next[0]=-1;
    int i=0, j=-1;
    while(i<s.length()){
        while(j!=-1 && s[j]!=s[i]) j=next[j];
        i++; j++;
        if(s[i]!=s[j]) next[i]=j; else next[i]=next[j];
    }
    return next;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    getline(cin,s);
    getline(cin,s1); getline(cin,s2);
    next1=getarr(s1); 
    next2=getarr(s2);
    //forward
    bool forward=0;
    int i,j,r1,r2;
    i=j=0; r1=r2=-1;
    while(i<s.length()){
        while(j!=-1 && s[i]!=s1[j]) j=next1[j];
        i++; j++;
        if(j==s1.length()){
            r1=i-1;
            break;
        }
    }
    j=0; if(r1!=-1){
        i=j=0;
        while(i<s.length()){
            while(j!=-1 && s[i]!=s2[j]) j=next2[j];
            i++; j++;
            if(j==s2.length()){
                r2=i-j;
                j=next2[j];
            }
        }
        if(r1!=-1 && r2!=-1) forward=(r1<r2);
    }
    //backward
    bool backward=0;
    j=0; r1=r2=-1; i=s.length()-1;
    while(i>=0){
        while(j!=-1 && s[i]!=s1[j]) j=next1[j];
        i--; j++;
        if(j==s1.length()){
            r1=i+1;
            break;
        }
    }
    j=0; if(r1!=-1){
        j=0; i=s.length()-1;
        while(i>=0){
            while(j!=-1 && s[i]!=s2[j]) j=next2[j];
            i--; j++;
            if(j==s2.length()){
                r2=i+j;
                j=next2[j];
            }
        }
        if(r1!=-1 && r2!=-1) backward=(r2<r1);
    }
    if(forward && backward) cout<<"both";
    else if(forward) cout<<"forward";
    else if(backward) cout<<"backward";
    else cout<<"fantasy";
    //getch();
    return 0;
}
    
