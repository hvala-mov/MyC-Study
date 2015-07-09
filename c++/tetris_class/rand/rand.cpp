#include"rand.h"

shared_ptr<Rand> Rand::instance;


shared_ptr<Rand>  Rand::creatRand(){
    if(!instance){
        instance=make_shared<Rand>(initialism{});
    }
    return instance;
}

int Rand::uniform_randNum(const int &begin,const int &end){
    uniform_int_distribution<unsigned> uniform_d(begin,end);
    uniform_d(randEngine);//为什么要加这一句,因为发现每次产生的第一项总是相同的,可能是编译器的问题,只好抛弃第一项
    return uniform_d(randEngine);//均匀分布的整数
}

int Rand::normal_randNum(const int &average,const double &variance,const int &begin,const int &end){
    normal_distribution<> normal_d(average,variance);//均值,方差
    normal_d(randEngine);//同上
    int int_num=lround(normal_d(randEngine));
    while(int_num<begin||int_num>end){
        int_num=lround(normal_d(randEngine));
    }
    /*do{//这里的做法是错误的,因为do while语句,while中的变量必须在循环体之外定义!
        int int_num=lround(normal_d(randEngine));
    }while(int_num<begin||int_num>end);*/
    return int_num;
}


int main (){
    shared_ptr<Rand> test=Rand::creatRand();
    //default_random_engine e(time(0));
    //Rand *test=Rand::creatRand();
    for(size_t i=0;i<5;++i){
        cout<<test->uniform_randNum(1,9)<<endl;
    }
    cout<<"******************"<<endl;
    for(size_t i=0;i<15;++i){
        cout<<test->normal_randNum(8,1.0,1,15)<<endl;
    }
    return 0;
}

