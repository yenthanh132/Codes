
/*
  Hrvatska informaticka olimpijada 2006
  Zadatak KOKOS

  Potrebno je uociti da su lijeva i desna "polovica" grafa potpuno neovisne,
  tj. vrh K-tog slova smijemo spojiti sa bilo kojim vrhom (K+1)-og slova.
  Dakle, minimalan broj vrhova lijeve polovice grafa ovisi samo o prvih K
  slova zadanih rijeci (samo o lijevim polovicama rijeci).

  Minimalnu lijevu polovicu grafa gradit cemo postupnim dodavanjem polovica
  rijeci. Za prvu polu-rijec trebamo tocno K vrhova.

  Za svaku sljedecu polu-rijec potrebno je pronaci koja vec dodana polu-rijec
  joj je "najslicnija", tj. kolika je duljina najduljeg zajednickog prefiksa
  trenutne polu-rijeci i vec dodanih polu-rijeci.

  Ako je ta duljina L, tada je potrebno dodati jos K-L novih vrhova u lijevu
  polovicu grafa (jer se prvih L slova vec nalazi u grafu, iz njih se smijemo
  granati u preostalih K-L slova, a spajanje je zabranjeno).

  Prije dodavanja u graf, polu-rijeci cemo sortirati leksikografski jer parovi
  susjednih rijeci u tom poretku imaju najdulje zajednicke prefikse.

  Za desnu polovicu grafa vrijedi slican algoritam: umjesto lijevih polovica
  rijeci gledamo obrnute desne polovice rijeci, a bridove grafa usmjeravamo u
  obrnutom smjeru.
*/

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#define MAXK 100

int n, k;

int rijesi( vector<string> &a ) {
   sort( a.begin(), a.end() );

   int ret = k, i, j;
   for( i = 1; i < n; ++i ) {
      for( j = 0; j < k; ++j )
         if( a[i][j] != a[i-1][j] ) break;
      ret += k-j;
   }
   return ret;
}

#include <conio.h>
int main( void ) {
    freopen("MKOKOS\\kokos.in.10","r",stdin);
   vector<string> lijevo, desno;
   char buff[2*MAXK+1];

   scanf( "%d%d", &n, &k );
   for( int i = 0; i < n; ++i ) {
      scanf( "%s", &buff );

      string a = buff;
      string b = buff;
      reverse( b.begin(), b.end() );
      a.resize( k );
      b.resize( k );

      lijevo.push_back( a );
      desno.push_back( b );
   }
   printf( "%d\n", rijesi( lijevo ) + rijesi( desno ) );
   getch();
   return 0;
}
