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

#define maxn 100001
int n,a[maxn],k;
//#include<conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    sort(a,a+n);
    int i=0,j,res=0;
    for(j=1;j<n;j++){
        while(a[j]-k>a[i]) i++;
        if (a[j]-k==a[i]) res++;
    }
    printf("%d",res);
    //getch();
    return 0;
}
