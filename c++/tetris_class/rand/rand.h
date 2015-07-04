#ifndef RAND_H
#define RAND_H
#include<iostream>
#include<random>
#include<ctime>
//#include<memory>
using namespace std;
class Rand{//用个单例模式,咩哈哈
    //friend shared_ptr<Rand> make_shared<Rand>();
    private:
        Rand(){randEngine.seed(time(nullptr));}
        static Rand *instance;
        default_random_engine randEngine;
        class DeleteRand{//注意这个类的作用,用于删除那个唯一实例
        public:
            DeleteRand();
            ~DeleteRand(){
                if(Rand::instance!=nullptr){
                    delete Rand::instance;
                }
            }
        };
        static DeleteRand deleter;//起到类似智能指针的作用,必须是静态变量,因为在全局变量区,离开作用域后会调用自动析构函数
    public:
        //static shared_ptr<Rand>& creatRand();
        static Rand* creatRand();
        int uniform_randNum(const int &begin,const int &end);
        int normal_randNum(const int &average,const double &variance);//正态分布,两个参数一个是均值,一个是方差
};
Rand* Rand::instance=nullptr;
#endif
