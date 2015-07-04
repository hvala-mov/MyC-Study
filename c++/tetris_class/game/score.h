#ifndef SCORE_H
#define SCORE_H

#include<iostream>
#include<string>
#include<unistd.h>
#include"cubePoint.h"
#include"cur.h"
using namespace std;

class Score{
    private:
        string player;
        int score;
    public:
        Score():player("hvala"),score(0){};
        Score(const string &name):player(name),score(0){}
        Score(istream&);
        void setName(const string &name){player=name;}
        void setScore(const int &s){score=s;}
        void printMessage();
};

#endif
