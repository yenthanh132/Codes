//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstdlib>
//#include <vector>
//#include <cstring>
//#include <string>
//#include <cmath>
//#include <ctime>
//#include <utility>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <sstream>
//#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
//#define FORD(a,b,c) for (int a=b;a>=c;a--)
//#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
//#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
//#define pb push_back
//#define mp make_pair
//#define fi first
//#define se second
//#define sz(a) int(a.size())
//#define reset(a,b) memset(a,b,sizeof(a))
//#define oo 1000000007
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef pair<double, int> pdi;
//
//struct RadioRange {
//    vector<pdi> list;
//    int n;
//
//
//
//	double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z)
//	{
//        n=sz(X);
//        int c=0;
//        REP(i,n){
//            double v=sqrt(1.0*X[i]*X[i]+1.0*Y[i]*Y[i]);
//            if(v-R[i]>0) list.pb(pdi(v-R[i],-1)); else c--;
//            if(v+R[i]<=Z) list.pb(pdi(v+R[i],1));
//        }
//        list.pb(pdi(Z,-1));
//        sort(list.begin(),list.end());
//
//        double lastV=0;
//        double res=0;
//        REP(i,sz(list)){
//            if(c==0) res+=list[i].fi-lastV;
//            lastV=list[i].fi;
//            c+=list[i].se;
//        }
//        return res/Z;
//	}
//
//};
//
//// BEGIN CUT HERE
//#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <ctime>
//#include <iostream>
//#include <string>
//#include <vector>
//namespace moj_harness {
//	using std::string;
//	using std::vector;
//	int run_test_case(int);
//	void run_test(int casenum = -1, bool quiet = false) {
//		if (casenum != -1) {
//			if (run_test_case(casenum) == -1 && !quiet) {
//				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
//			}
//			return;
//		}
//
//		int correct = 0, total = 0;
//		for (int i=0;; ++i) {
//			int x = run_test_case(i);
//			if (x == -1) {
//				if (i >= 100) break;
//				continue;
//			}
//			correct += x;
//			++total;
//		}
//
//		if (total == 0) {
//			std::cerr << "No test cases run." << std::endl;
//		} else if (correct < total) {
//			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
//		} else {
//			std::cerr << "All " << total << " tests passed!" << std::endl;
//		}
//	}
//
//	static const double MAX_DOUBLE_ERROR = 1e-6;
//	static bool topcoder_fequ(double expected, double result) {
//		if (std::isnan(expected)) {
//			return std::isnan(result);
//		} else if (std::isinf(expected)) {
//			if (expected > 0) {
//				return result > 0 && std::isinf(result);
//			} else {
//				return result < 0 && std::isinf(result);
//			}
//		} else if (std::isnan(result) || std::isinf(result)) {
//			return false;
//		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
//			return true;
//		} else {
//			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
//			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
//			return result > mmin && result < mmax;
//		}
//	}
//	double moj_relative_error(double expected, double result) {
//		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
//			return 0;
//		}
//		return std::fabs(result-expected) / std::fabs(expected);
//	}
//
//	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) {
//		std::cerr << "Example " << casenum << "... ";
//
//		string verdict;
//		vector<string> info;
//		char buf[100];
//
//		if (elapsed > CLOCKS_PER_SEC / 200) {
//			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
//			info.push_back(buf);
//		}
//
//		if (topcoder_fequ(expected, received)) {
//			verdict = "PASSED";
//			double rerr = moj_relative_error(expected, received);
//			if (rerr > 0) {
//				std::sprintf(buf, "relative error %.3e", rerr);
//				info.push_back(buf);
//			}
//		} else {
//			verdict = "FAILED";
//		}
//
//		std::cerr << verdict;
//		if (!info.empty()) {
//			std::cerr << " (";
//			for (size_t i=0; i<info.size(); ++i) {
//				if (i > 0) std::cerr << ", ";
//				std::cerr << info[i];
//			}
//			std::cerr << ")";
//		}
//		std::cerr << std::endl;
//
//		if (verdict == "FAILED") {
//			std::cerr << "    Expected: " << expected << std::endl;
//			std::cerr << "    Received: " << received << std::endl;
//		}
//
//		return verdict == "PASSED";
//	}
//
//	int run_test_case(int casenum__) {
//		switch (casenum__) {
//		case 0: {
//			int X[]                   = {0};
//			int Y[]                   = {0};
//			int R[]                   = {5};
//			int Z                     = 10;
//			double expected__         = 0.5;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 1: {
//			int X[]                   = {0};
//			int Y[]                   = {0};
//			int R[]                   = {10};
//			int Z                     = 10;
//			double expected__         = 0.0;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 2: {
//			int X[]                   = {10};
//			int Y[]                   = {10};
//			int R[]                   = {10};
//			int Z                     = 10;
//			double expected__         = 0.4142135623730951;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 3: {
//			int X[]                   = {11, -11, 0, 0};
//			int Y[]                   = {0, 0, 11, -11};
//			int R[]                   = {10, 10, 10, 10};
//			int Z                     = 31;
//			double expected__         = 0.3548387096774194;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 4: {
//			int X[]                   = {100};
//			int Y[]                   = {100};
//			int R[]                   = {1};
//			int Z                     = 10;
//			double expected__         = 1.0;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 5: {
//			int X[]                   = {1000000000};
//			int Y[]                   = {1000000000};
//			int R[]                   = {1000000000};
//			int Z                     = 1000000000;
//			double expected__         = 0.41421356237309503;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 6: {
//			int X[]                   = {20, -20, 0, 0};
//			int Y[]                   = {0, 0, 20, -20};
//			int R[]                   = {50, 50, 50, 50};
//			int Z                     = 100;
//			double expected__         = 0.3;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//		case 7: {
//			int X[]                   = {0, -60, -62, -60, 63, -97};
//			int Y[]                   = {-72, 67, 61, -8, -32, 89};
//			int R[]                   = {6, 7, 8, 7, 5, 6};
//			int Z                     = 918;
//			double expected__         = 0.9407071068962471;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
//
//		// custom cases
//
///*      case 8: {
//			int X[]                   = ;
//			int Y[]                   = ;
//			int R[]                   = ;
//			int Z                     = ;
//			double expected__         = ;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}*/
///*      case 9: {
//			int X[]                   = ;
//			int Y[]                   = ;
//			int R[]                   = ;
//			int Z                     = ;
//			double expected__         = ;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}*/
///*      case 10: {
//			int X[]                   = ;
//			int Y[]                   = ;
//			int R[]                   = ;
//			int Z                     = ;
//			double expected__         = ;
//
//			std::clock_t start__      = std::clock();
//			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}*/
//		default:
//			return -1;
//		}
//	}
//}
//
//
//#include <cstdlib>
//int main(int argc, char *argv[]) {
//	if (argc == 1) {
//		moj_harness::run_test();
//	} else {
//		for (int i=1; i<argc; ++i)
//			moj_harness::run_test(std::atoi(argv[i]));
//	}
//}
//// END CUT HERE
