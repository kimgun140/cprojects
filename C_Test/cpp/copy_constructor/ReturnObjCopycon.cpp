#include<iostream>
using namespace std;

class SoSimple{
    private:
    int num;
    public:
    SoSimple(int n): num(n)
    { }
    SoSimple(const SoSimple& copy): num(copy.num){
        cout << "Called SoSimple(const SoSimple& copy) " << endl;
    }
    SoSimple& AddNum(int n){
        num += n;
        return *this;
    }
    void ShowData(){
        cout <<"num: " << num << endl;

    }
};

SoSimple SimpleFuncObj(SoSimple ob){
    cout << "return 이전" << endl;
    // obj랑 같은 값을 가진 ob를 만들어서 ob를 리턴한다. 
    return ob;
}


int main(void){
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}