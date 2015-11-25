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

#define maxn 101

double res, mul[maxn];
int dA[maxn], dB[maxn],n,prob[maxn],score[3][maxn],choose[maxn];

void duyet(int i){
    if (i>n){
        
        if(dA[n]>dB[n]) res=res+mul[n];
        else if(dA[n]==dB[n]) res=res+mul[n]/2;
        return;
    }
    FOR(j,1,2){
        if (j==1) mul[i]=mul[i-1]*double(prob[i])/100; else mul[i]=mul[i-1]*double(100-prob[i])/100;
        if(i%2==1) dA[i]=dA[i-1]+score[j][i]*int(j==choose[i]), dB[i]=dB[i-1];
        else dB[i]=dB[i-1]+score[j][i]*int(j==choose[i]), dA[i]=dA[i-1];
        duyet(i+1);
    }
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n){
        cin>>prob[i]>>score[1][i]>>score[2][i];
        if(prob[i]*score[1][i]>=(100-prob[i])*score[2][i]) choose[i]=1; else choose[i]=2;
    }
    res=0;
    reset(dA,0); reset(dB,0);
    mul[0]=1;
    duyet(1);
    printf("%0.6f",res);
    getch();
    return 0;
}
