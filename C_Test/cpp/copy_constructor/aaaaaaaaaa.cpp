#include <iostream>
#include <cstring>

using namespace std;
namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };
    void ShowPositionInfo(int pos)
    {
        switch (pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "eofl" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
        }
    }
}
class NameCard
{
private:
    char *name;
    char *company;
    char *phone;
    int position;

public:
    NameCard(char *name, char *company, char *phone, int pos)
        : position(pos)
    {
        this->name = new char[strlen(name) + 1];
        this->company = new char[strlen(company) + 1];
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->name, name);
        strcpy(this->company, company);
        strcpy(this->phone, phone);
    }
    NameCard(const NameCard &ref) : position(ref.position)
    {
        name = new char[strlen(ref.name) + 1];
        company = new char[strlen(ref.company) + 1];
        phone = new char[strlen(ref.phone) + 1];
        strcpy(name, ref.name);
        strcpy(company, ref.company);
        strcpy(phone, ref.phone);
    }
    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phone << endl;
        cout << "직급: ";  COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }
    ~NameCard()
    {
        delete[] name;
        delete[] company;
        delete[] phone;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "orangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}