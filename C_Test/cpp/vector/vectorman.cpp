// #include <iostream>
// #include <vector>

// namespace samples
// {

// }
// int main()
// {
//     // std::vector<int> scores;
//     // scores.reserve(2);

//     // scores.push_back(30);
//     // scores.push_back(30);
//     // scores[1]= 4;
//     // scores.pop_back();

//     // std::cout << "Current capacity : " << scores.capacity() << std::endl;
//     // std::cout<< "Current size : " << scores.size() << std::endl;
//     // std::cout<< "Current operator : " << scores[1] << std::endl;

//     // 특정 위치에 요소 삽입하기
//     std::vector<int> scores;
//     scores.reserve(4);

//     scores.push_back(30);
//     scores.push_back(20);
//     scores.push_back(10);
//     scores.push_back(100);
//     for (std::vector<int>::iterator it = scores.begin(); it != scores.end(); ++it)
//     {
//         std::cout << *it << std::endl;
//         // scores.insert(it, 80);
//     }
//     return 0;
// }


// //예시 : 벡터 만들기
// #include<iostream>
// #include<vector>
// namespace sample
// {}
// int main(){
// std::vector<int> scores; // scores라는 이름의 int형 벡터를 만들었다.
// scores.reserve(2); // 벡터의 크기를 2로 정해줬다.

// scores.push_back(30); // 벡터에 값을 넣어준다.
// scores.push_back(30); // 벡터에 값을 넣어준다.

// scores.pop_back(); // 벡터의 가장 뒤 값을 삭제한다. 
// std::cout << "Current capacity : " << scores.capacity() << std::endl;
// std::cout << "Current size : " << scores.size() << std::endl;

// return 0;

// }

//예시 2
#include<iostream>
#include<vector>
namespace samples{}
int main(){
    std::vector<int> scores;
    scores.reserve(10); // socres벡터의 공간은 2로 할당했다.

   scores.push_back(30); // 벡터에 값을 넣어준다.
    scores.push_back(30); // 벡터에 값을 넣어준다.
    scores.push_back(30); // 벡터에 값을 넣어준다.
    scores.push_back(30); // 벡터에 값을 넣어준다.
    scores.push_back(30); // 벡터에 값을 넣어준다.
    scores.push_back(30); // 벡터에 값을 넣어준다.


scores.pop_back(); // 벡터의 가장 뒤 값을 삭제한다. 
std::cout << "Current capacity : " << scores.capacity() << std::endl;
for (size_t i = 0;  i<scores.size(); i++){
    std::cout << "value : " << scores[i] <<" ";
}


return 0;
}