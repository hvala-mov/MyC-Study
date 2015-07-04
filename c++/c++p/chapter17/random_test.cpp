#include<iostream>
#include<random>
#include<vector>
#include<ctime>
using namespace std;
class test{
    public:
    default_random_engine e;
};
int main (){
    default_random_engine e(time(0));
    default_random_engine xs(111);
    cout<<"min:"<<e.min()<<"max:"<<e.max()<<endl;
    for(size_t i=0;i<5;++i){
        cout<<e()<<endl;
    }
    uniform_int_distribution<unsigned> u(0,9);
    for(size_t i=0;i<5;++i){
        cout<<u(e)<<endl;
    }
    uniform_real_distribution<double> x(0,1);
    for(size_t i=0;i<5;++i){
        cout<<x(e)<<endl;
    }
    normal_distribution<> n(4,1.5);
    vector<unsigned> vals(9,0);
    for(size_t i=0;i!=200;++i){
        auto v=lround(n(e));
        if(v<vals.size()){
            ++vals[v];
        }
    }
    for(size_t j=0;j!=vals.size();++j){
        cout<<j<<": "<<string(vals[j],'*')<<endl;
    }
    test t;
    return 0;
}
