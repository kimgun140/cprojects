/*stock 클래스 구현 version 00 */

#include <iostream>

#include "stock00.h"

void Stock::acquire(const std::string &co, long n, double pr)
{// 해당 회사 주식의 첫 취득을 관리
    company = co;
    if (n < 0)
    {
        std::cout << "주식 수는 음수가 될 수 없으므로, "
                  << company << " shares를 0으로 설정합니다.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{// 기존 보유 주식의 증가와 감소를 관리
    if (num < 0)
    {
        std::cout << "매입 주식 수는 음수가 될 수 없으므로, "
                  << "거래가 취소되었습니다.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
// 기존 보유 주식의 증가와 감소를 관리
{
    using std::cout;
    if (num < 0)
    {
        cout << "매도 주식 수는 음수가 될 수 없으므로, "
             << "거래가 취소되었습니다.\n";
    }
    else if (num > shares)
    {
        cout << "보유 쥬식보다 만은 주식을 매도할 수 없으르모, "
             << "거래가 취소되었습니다.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
void Stock::show()
{
    std::cout << "회사명" << company
              << " 주식 수:" << shares << '\n'
              << " 주가: $" << share_val
              << " 주식 총 가치: $" << total_val << '\n';
}