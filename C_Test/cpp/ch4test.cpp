#include <iostream>
#include<array>
int main() //p.253 p.256
{   using namespace std;
    char actors [30];
    short bestie [100];
    float chuck[13];
    long double dipsea[64];

    array<char,30>  actors;
    array<short,100> bestie;
    array<float, 13> chuck;
    array<long double,64> dipsea;

    int a[5] = {1,3,5,7,9};
//4
    int even = dipsea[0] + dipsea[63];
//5
    float ideas[2] = {1,2};
    cout <<ideas[1];
//6
    char b[] = {"cheeseburger"};
//7
string s = "Waldorf Salad";
//8
struct  fish  {
    char kind;
    int weight;
    float length;
};
// 9 문제 6에서 정의한 구조체형으로 변수를 하나 선언하고 초기화 하라


}