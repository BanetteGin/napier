#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
namespace mpi = boost::multiprecision;
using Bint = mpi::cpp_int;
using Real = mpi::number<mpi::cpp_dec_float<1024>>;

typedef long long ll;

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