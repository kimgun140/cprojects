#include<iostream>
#include <string>
using namespace std;
template <typename A>
A Sum(A a, A b){
    return a +b;
}

int main()
{
    int a=1,b=2;
    double d1=2.2;
    double d2=3.3;
    string s1 ="Show me ";
    string s2 = "The Money";
    cout<<"int 합 : "<< Sum<int>(a,b) <<endl;
    cout<<"double 합: "<< Sum<double>(d1,d2)<<endl;
    cout<<"string 합: "<< Sum<string>(s1,s2)<<endl;
    return 0;
}
