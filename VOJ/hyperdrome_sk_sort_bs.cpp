/******************************************************************/
/* ACM ICPC 2012-2013                                             */
/* Northeastern European Regional Contest                         */
/* St Petersburg - Barnaul - Tashkent - Tbilisi, December 2, 2012 */
/******************************************************************/
/* Problem H. Hyperdrome                                          */
/*                                                                */
/* Original idea         Vitaliy Aksenov                          */
/* Problem statement     Vitaliy Aksenov                          */
/* Test set              Vitaliy Aksenov                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Sergey Kopeliovich                       */
/******************************************************************/

/**                   
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.11.23
 */

#include <cstdio>
#include <cstring>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

const int maxN = (int)3e5 + 1;
const int E = 52;

int k, n, cnt[maxN];
ll h[maxN];
ll x = 0, res = 0;

inline int num( ll x )
{
  int i = lower_bound(h, h + k, x) - h;
  return h[i] == x ? cnt[i] : 0;
}

#include <conio.h>

int main()
{
  #define NAME "hyperdrome"
  assert(freopen("test.txt", "r", stdin));
  //assert(freopen(NAME ".out", "w", stdout));
  
  assert(scanf("%d ", &n) == 1);
  assert(1 <= n && n <= maxN);

  forn(i, n)
  {
    char c;
    assert(scanf("%c", &c) == 1);
    int a = ('a' <= c && c <= 'z') ? c - 'a' : (('A' <= c && c <= 'Z') ? c - 'A' + 26 : -1);
    assert(0 <= a && a < E);
    h[i] = x, x ^= 1LL << a;
  }
  h[n++] = x;
  sort(h, h + n);
  h[n] = (ll)-1;
  for (int j, i = 0; i < n; i = j)
  {
    for (j = i; j < n && h[i] == h[j]; j++)
      ;
    int n = j - i;
    h[k] = h[i], cnt[k++] = n;
    res += (ll)n * (n - 1) / 2;
  }
  h[k] = (ll)-1;
  cout<<k<<endl;
  forn(i,k) cout<<h[i]<<' '<<cnt[i]<<endl;
  forn(i, k)
  {
    int x = 0;
    forn(k, E)
    {
      ll b = 1LL << k;
      if (!(h[i] & b))
        x += num(h[i] ^ b);
    }
    res += (ll)x * cnt[i];
  }
  cout << res << endl;
  getch();
  return 0;
}

