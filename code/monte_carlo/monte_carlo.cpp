#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
namespace mpi = boost::multiprecision;
using Bint = mpi::cpp_int;
using Real = mpi::number<mpi::cpp_dec_float<1024>>;


#define rep(i, n) for(ll i = 0, n_f = (ll)(n); i < n_f; ++i)
#define all(a) (a).begin(),(a).end()
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define sp fixed<<setprecision(20)
#define mpa(a,b) make_pair(a,b)

typedef long long ll;
typedef __int128_t int128;
typedef double dou;
typedef long double ld;
typedef vector<double> vdou;
typedef vector<string> vstr;
typedef vector<bool> vbol;
typedef vector<vector<bool>> vvbol;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

const ll dx[] = {-1,0,1,0};
const ll dy[] = {0,1,0,-1};
const ll dx2[] = {-1,-1,0,1,1,1,0,-1};
const ll dy2[] = {0,1,1,1,0,-1,-1,-1};
const ll mod99ll = 998244353LL;
const ll mod107ll = 1000000007LL;
const ll INFL = numeric_limits<ll>::max();

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(void){
    const ll digit=10;

    ifstream npfilest;
    string npfilename = "../npnum.txt";
    npfilest.open(npfilename, ios::in);
    string npfileread;
    getline(npfilest, npfileread);
    Real epdef = boost::lexical_cast<Real>(npfileread);
    npfilest.close();
    Real epsl=pow((Real)10,(Real)-digit);

    random_device rnd;
    mt19937 mt(rnd());
    uniform_real_distribution<> rand01(0,1);

    double timavg=0;
    ll step;
    cin>>step;
    for(ll i=0;i<step;++i){
        Real epap = 0;
        Real frpl = 1;
        ll stp=1;
        bool avoid=true;

        clock_t start = clock();
        while(abs(epdef-epap/(Real)stp)>=epsl){
            if(avoid) avoid=false;
            else stp++;
            Real sum=0;
            ll cnt=0;
            while(sum<=1){
                sum+=rand01(mt);
                cnt++;
            }
            epap+=(Real)cnt;
        }
        clock_t end = clock();
        timavg+=(double)(end - start)/CLOCKS_PER_SEC;
    }
    cout<<setprecision(20)<<timavg/(double)step<<endl;
    return 0;
}