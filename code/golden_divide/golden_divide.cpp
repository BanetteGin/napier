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

    ifstream glfilest;
    string glfilename = "../golden_ratio.txt";
    glfilest.open(glfilename, ios::in);
    string glfileread;
    getline(glfilest, glfileread);
    Real gldef = boost::lexical_cast<Real>(glfileread);
    Real suml = 1+gldef*2;
    glfilest.close();

    double timavg=0;
    ll step;
    cin>>step;
    for(ll i=0;i<step;++i){
        Real epap = 0;
        Real epapng = 3;
        Real mid1=epap+(epapng-epap)*gldef/suml;
        Real mid2=epap+(epapng-epap)*(suml-gldef)/suml;
        Real frpl = 1;

        clock_t start = clock();
        while(abs(epdef-epap)>=epsl){
            Real mid1f=pow(mid1,1/mid1);
            Real mid2f=pow(mid2,1/mid2);
            if(mid1f<=mid2f) {
                epap=mid1;
                mid1=mid2;
                mid2=epap+(epapng-epap)*(suml-gldef)/suml;
            } else {
                epapng=mid2;
                mid2=mid1;
                mid1=epap+(epapng-epap)*gldef/suml;
            }
        }
        clock_t end = clock();
        timavg+=(double)(end - start)/CLOCKS_PER_SEC;
    }
    cout<<setprecision(20)<<timavg/(double)step<<endl;
    return 0;
}