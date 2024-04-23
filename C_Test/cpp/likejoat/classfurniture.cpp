#include <iostream>
#include <cstring>
class remote_control
// p.142
{
private:
    char name;
    char company;
    char position;

public:
    remote_control(char machine_name, char made_company, char where_position)
    :name(machine_name), company(made_company), position(where_position)
   //멤버 이니셜라이저 
    {// 생성자 
        // name = machine_name;
        // company = made_company;
        // position = where_position;

    }
    void on(void)
    {
    }
    void off(void)
    {
    }
};