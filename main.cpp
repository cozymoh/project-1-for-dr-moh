#include <iostream>
using namespace std;

const int max = 100; //more than enough 
const int cap = 50;

struct Song {
    char title[cap];
    char artist[cap];
};

Song playlist[max] = {
    {"Beat It", "Michael Jackson"},
    {"Billie Jean", "Michael Jackson"},
    {"Smooth Criminal", "Michael Jackson"}
}; // continue after tea and biscuits 
