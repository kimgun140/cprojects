#include <iostream>
#include "stock00.cpp"
int main()
{

    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    // 클래스 안에 값을 저장했기 때문에 함수가 종료되어도 값이 남아 있네??
    //  그렇구만 
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    return 0;
}
// 생성자