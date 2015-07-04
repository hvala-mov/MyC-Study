#ifndef RAND_H
#define RAND_H
#include<iostream>
#include<random>
#include<ctime>
#include<memory>
using namespace std;
class Rand{//用个单例模式,咩哈哈
    //friend shared_ptr<Rand> make_shared<Rand>();
    private:
        struct initialism{};
        //explicit Rand(const initialism&){randEngine.seed(time(nullptr));}
        static shared_ptr<Rand> instance;
        default_random_engine randEngine;
    public:
        //static shared_ptr<Rand>& creatRand();
        explicit Rand(const initialism&){randEngine.seed(clock());}
        static shared_ptr<Rand> creatRand();
        int uniform_randNum(const int &begin,const int &end);
        int normal_randNum(const int &average,const double &variance);//正态分布,两个参数一个是均值,一个是方差
};
shared_ptr<Rand> Rand::instance=nullptr;
#endif
