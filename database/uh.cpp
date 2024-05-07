// #include <iostream>
// #include <string>
// #include"dp_class.cpp"
// // 지역 입력, 지역의 관광지,축제 정보 입력
// // 선택할것들만 쿼리문 바꿔주면 됨 ㅇㅋ? ㅇㅋ
// int main() {
//     std::string input;
//     std:: string input_region;
//     std:: string input_place;
//     std:: string input_medical;
//     std:: string input_festival;
//     gg asdf;
    



//     while (true) {
//         std::cout << "\n*** 관광 정보 시스템 ***\n";
//         std::cout << "1. 지역 보기\n";
//         std::cout << "2. 즐겨찾기\n";
//         std::cout << "3. 종료\n";
//         std::cout << "선택: ";
//         std::getline(std::cin, input);

//         if (input == "3") {
//             std::cout << "\n프로그램을 종료합니다.\n";
//             break;
//         } else if (input == "1") {
//             while (true) {
//                 std::cout << "\n--- 지역 목록 ---\n";
//                 std::cout << "1. 서울\n";
//                 std::cout << "2. 경기/인천\n";
//                 std::cout << "3. 강원\n";
//                 std::cout << "4. 충청/대전/세종\n";
//                 std::cout << "5. 전라/광주\n";
//                 std::cout << "6. 경남/부산/울산\n";
//                 std::cout << "7. 경북/대구\n";
//                 std::cout << "8. 제주\n";
//                 std::cout << "9. 뒤로가기\n";
//                 std::cout << "지역 선택: ";
//                 std::getline(std::cin, input);
//                 // 묵여있는 것들을 같이 출력하려면 함수를 두번 실행 시키기 "경기"한번, "인천" 두번
//                 // 서울 받으면 관광지

//                 input_region = input;

//                 std::string region_name;
//                 if (input == "1") {
//                     region_name = "서울";
//                 } else if (input == "2") {
//                     region_name = "경기/인천";
//                 } else if (input == "3") {
//                     region_name = "강원";
//                 } else if (input == "4") {
//                     region_name = "충청/대전/세종";
//                 } else if (input == "5") {
//                     region_name = "전라/광주";
//                 } else if (input == "6") {
//                     region_name = "경남/부산/울산";
//                 } else if (input == "7") {
//                     region_name = "경북/대구";
//                 } else if (input == "8") {
//                     region_name = "제주";
//                 } else if (input == "9") {
//                     break;
//                 } else {
//                     std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
//                     continue;
//                 }

//                 std::cout << "\n** " << region_name << " 지역 관광 정보 시스템 **\n";
//                 while (true) {
//                     std::cout << "1. 관광지 정보\n";
//                     // 해당 관광지에 대한 정보 출력
                    
//                     std::cout << "2. 축제 정보\n";
//                     std::cout << "3. 뒤로가기\n";
//                     std::cout << "선택: ";
//                     std::getline(std::cin, input);
//                     input_place = input;
//                     if (input == "3") {
//                         break; // 뒤로가기 선택 시 지역 선택 메뉴로 복귀
//                     } else if (input == "1" || input == "2") {
//                         std::cout << (input == "1" ? "관광지 정보를 출력합니다.\n" : "축제 정보를 출력합니다.\n");
//                         // 관광지 또는 축제 정보 출력 함수 호출
//                         input_festival = input;
//                     } else {
//                         std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
//                     }
//                 }
//             }
//         } else if (input == "2") {
//             std::cout << "즐겨찾기 기능을 구현합니다.\n";
//             // 즐겨찾기 기능 관련 코드
//         } else {
//             std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
//         }
//     }

//     return 0;
// }