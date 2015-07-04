#ifndef _SCORE_H_
#define _SCORE_H_

#include<iostream>
#include<string>
using namespace std;

class Score{
    private:
        string player;
        int score;
    public:
        Score():player("viMer"),score(0){}
        void setName(const string &name){
            player=name;
        }
        void setScore(const int &s){
            score=s;
        }
        void printMessage();
};

#endif
