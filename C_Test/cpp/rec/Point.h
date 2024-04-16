#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
    int x;
    int y;

public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const; // 멤버변수에 저장된 값을 변경하지 않겠다 const 그냥 가져오기만 할겁니다. const 함수 안에서 const가 아닌 함수들의 호출이 제한된다.
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif