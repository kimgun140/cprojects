#ifndef CF_H
#define CF_H

#include "DB.h"


class CFavorites {
private:
    struct Fav_fs {
        int fsID; // 즐겨찾기 ID
        std::string fsname; // 즐겨찾기 이름
        std::string Addr; // 주소
        std::string PhoneNumber; // 전화번호
    }fav_fs;
    std::vector<Fav_fs> favorite; // 즐겨찾기 목록 벡터

public:
    CFavorites() {}
    CFavorites(int id, std::string name, std::string addr, std::string phonenumber) {
        fav_fs.fsID = id;
        fav_fs.fsname = name;
        fav_fs.Addr = addr;
        fav_fs.PhoneNumber = phonenumber;
        favorite.push_back(fav_fs);
        std::cout << favorite.size() << "번에 저장되었습니다.\n";
    }
    CFavorites(std::string id, std::string name, std::string addr, std::string phonenumber) {
        int save = stoi(id);
        fav_fs.fsID = save;
        fav_fs.fsname = name;
        fav_fs.Addr = addr;
        fav_fs.PhoneNumber = phonenumber;
        favorite.push_back(fav_fs);
        std::cout << favorite.size() << "번에 저장되었습니다.\n";
    }

    // 즐겨찾기 항목을 관리하는 메서드
    int favoritemenu() {
        while (true) {
            char choose;
            std::cout << "원하시는 항목을 선택해 주세요.\n";
            std::cout << "1) 즐겨찾기 선택 \t2) 즐겨찾기 삭제 \tq) 나가기\n";
            std::cin >> choose;
            std::cin.ignore(); // 입력 버퍼 클리어

            if (choose == '1') {
                return favchoice();
            } else if (choose == '2') {
                favdelete();
            } else if (choose == 'q' || choose == 'Q') {
                std::cout << "즐겨찾기를 종료합니다.\n";
                return -1;
            } else {
                std::cout << "잘못 선택했습니다. 다시 선택해주세요.\n";
            }
        }
    }

    // 즐겨찾기 항목을 선택하는 메서드
    int favchoice() {
        if (favorite.empty()) {
            std::cout << "저장된 즐겨찾기가 없습니다. 즐겨찾기를 나갑니다.\n";
            return -1;
        }
        for (int i = 0; i < favorite.size(); i++) {
            std::cout << i + 1 << ". " << favorite[i].fsname << "\n";
        }
        std::string choose;
        std::cout << "원하시는 즐겨찾기를 골라주세요. 나갈려면 q\n";
        getline(std::cin, choose);
        if (choose == "q" || choose == "Q") {
            std::cout << "즐겨찾기에서 나갑니다.\n";
            return -1;
        }
        int num = std::stoi(choose);
        if (num > 0 && num <= favorite.size()) {
            return favorite[num - 1].fsID;
        } else {
            std::cout << "잘못된 번호입니다. 다시 시도하세요.\n";
            return -1;
        }
    }

    // 즐겨찾기 항목을 삭제하는 메서드
    void favdelete() {
        if (favorite.empty()) {
            std::cout << "삭제할 즐겨찾기가 없습니다.\n";
            return;
        }
        for (int i = 0; i < favorite.size(); i++) {
            std::cout << i + 1 << ". " << favorite[i].fsname << "\n";
        }
        std::string choose;
        std::cout << "삭제할 즐겨찾기 번호를 입력하세요: ";
        std::cin >> choose;
        std::cin.ignore(); // 입력 버퍼 클리어

        int index = std::stoi(choose);
        if (index > 0 && index <= favorite.size()) {
            favorite.erase(favorite.begin() + (index - 1));
            std::cout << "즐겨찾기가 성공적으로 삭제되었습니다.\n";
        } else {
            std::cout << "잘못된 번호입니다. 다시 시도하세요.\n";
        }
    }

    // ID를 기반으로 즐겨찾기에 추가하는 메서드
    void addFavoriteFromID(int id, DB& db, std::unique_ptr<sql::Connection>& conn) {
        auto details = db.sendRowTasks(conn, "TD", id);
        if (!details->empty()) {
            Fav_fs newFav;
            newFav.fsID = id;
            newFav.fsname = (*details)[1]; // 관광지명
            newFav.Addr = (*details)[3]; // 주소
            newFav.PhoneNumber = (*details)[4]; // 전화번호
            favorite.push_back(newFav);
            std::cout << "새로운 즐겨찾기가 추가되었습니다.\n";
        }
        delete details;
    }
    
};

#endif // CF_H
