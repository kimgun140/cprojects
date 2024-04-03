#include<stdio.h>
#include<stdlib.h> /*랜덤함수 사용 위해 불러옴*/
#include<time.h> /*랜덤함수 사용 위해 불러옴*/

int town_movement(int tm);/*이동아이템 획득 함수 전방선언*/
int drop_2teer20(int );/*2티어 20프로*/
int drop_3teer20(int );/*3티어 20프로*/
int drop_3teer30(int);/*3티어 30프로*/
int drop_4teer5(int);/*4티어 5프로*/
int drop_4teer10(int);/*4티어 10프로*/
int drop_4teer20(int);/*4티어 20프로*/

int drop_thirty(int thir);/*30프로 드랍 함수*/
int drop_five(int five);/*5프로 드랍함수*/
int gold_drop(int floor);/*골드 드랍 함수*/
int gold_drop_boss(int boss);/*보스 골드 드랍 함수*/



struct sword_table
{
    int basicsword;/*기본검*/
    int longsword; /*장검*/
    int japensword; /*일본도*/
    int nigthsword_saj;/*싸울아비장검*/
}sword_table;
struct first_depend_table
{
    int basicarmor;/*기본 갑빠*/
    int basicboots;/*기본 장화*/
    int basiccape;/*기본 망토*/
    int basicgloves;/*기본 장갑*/
    int basicmask;/*기본 마스크*/
}first_depend_table;
struct second_depend_table
{
    int halfarmor;/*반팔 갑빠*/
    int slipper;/*슬리퍼*/
    int rubbergloves;/*고무장갑*/
    int cottencape;/*면 망토*/
    int k80mask;/*k80 마스크*/
}second_depend_table;
struct third_depend_table
{
    int hoodarmor;/*후드갑빠*/
    int sneakers;/*운동화*/
    int cottengloves;/*면 장갑*/
    int silkcape;/*비단 망토*/
    int k94mask;/*k94마스크*/
}third_depend_table;
struct fourth_depend_table
{
    int dragonarmor;/*용 갑빠*/
    int airjodan;/*에어조단*/
    int leardergloves;/*가죽장갑*/
    int bulletcape;/*방탄 망토*/
    int tigermask;/*타이거 마스크*/
}fourth_depend_table;
struct potion_table
{
    int redpotion;/*빨간 물약*/
    int orangepotion;/*주황 물약*/
    int purepotion;/*맑은 물약*/
    int highpotion;/*고농도 물약*/
}potion_table;
struct scroll_table
{
    int tmscrollpaper;/*마을 이동 주문서*/
    int ermagicscroll;/*장비 강화 주문서*/
    int teleportscroll; /*순간 이동 주문서*/
}scroll_table;

//아이템 구조체
struct item_table /*총 아이템 개수 테이블*/
{
    int gold;/*골드*/
    struct potion_table potion;/*포션*/
    struct scroll_table scroll;/*주문서*/
}item_table;

struct item_address/*포인터주소값함수*/
{
    int* address_basicsword;/*기본검*/
    int* address_longsword; /*장검*/
    int* address_japensword; /*일본도*/
    int* address_nigthsword_saj;/*싸울아비장검*/
    int* address_basicarmor;/*기본 갑빠*/
    int* address_basicboots;/*기본 장화*/
    int* address_basiccape;/*기본 망토*/
    int* address_basicgloves;/*기본 장갑*/
    int* address_basicmask;/*기본 마스크*/  
    int* address_halfarmor;/*반팔 갑빠*/
    int* address_slipper;/*슬리퍼*/
    int* address_rubbergloves;/*고무장갑*/
    int* address_cottencape;/*면 망토*/
    int* address_k80mask;/*k80 마스크*/  
    int* address_hoodarmor;/*후드갑빠*/
    int* address_sneakers;/*운동화*/
    int* address_cottengloves;/*면 장갑*/
    int* address_silkcape;/*비단 망토*/
    int* address_k94mask;/*k94마스크*/
    int* address_dragonarmor;/*용 갑빠*/
    int* address_airjodan;/*에어조단*/
    int* address_leardergloves;/*가죽장갑*/
    int* address_bulletcape;/*방탄 망토*/
    int* address_tigermask;/*타이거 마스크*/
    int* address_redpotion;/*빨간 물약*/
    int* address_orangepotion;/*주황 물약*/
    int* address_purepotion;/*맑은 물약*/
    int* address_highpotion;/*고농도 물약*/
    int* address_tmscrollpaper;/*마을 이동 주문서*/
    int* address_ermagicscroll;/*장비 강화 주문서*/
    int* address_teleportscroll; /*순간 이동 주문서*/
    int* address_gold;/*골드*/
    struct potion_table* address_potion;/*포션*/
    struct scroll_table* address_scroll;/*주문서*/
}item_address;

int main(void)
{
    int a;
    // struct item_table item;
    // a=town_movement(a);
    // printf("%d\n",a);
    // int b;
    // b=drop_2teer20(b);
    // printf("%d\n",b);
    // int c;
    // c=gold_drop_boss(c);  
    // printf("%d",item_table.gold);
    int d;
    d=gold_drop(1);
    printf("%d",item_table.gold);
    
}
void item(struct item_table*);
void consume(struct item_table);

int town_movement(int tm)/*순간이동 주문서 획득*/
{
    item_address.address_tmscrollpaper=&item_table.scroll.tmscrollpaper;
    srand(time(NULL));/*랜덤사용*/
    int get_chance; /*획득확률*/
    get_chance=rand()%100+1;/*1~100까지*/
    if (get_chance<=20)/*20보다 작거나 같으면*/
    {
        tm=rand()%3+1; /*획득 개수는 1~3개*/
        *item_address.address_tmscrollpaper=item_table.scroll.tmscrollpaper+=tm;
        printf("순간이동주문서획득");
    }
    else
        tm=0;
    
    return tm;/*획득 개수 리턴*/
}

int drop_2teer20(int twen) /*2티어 20프로 드랍 함수*/
{
    item_address.address_cottencape=&second_depend_table.cottencape;
    item_address.address_longsword=&sword_table.longsword;
    item_address.address_halfarmor=&second_depend_table.halfarmor;
    item_address.address_k80mask=&second_depend_table.k80mask;
    item_address.address_rubbergloves=&second_depend_table.rubbergloves;
    item_address.address_slipper=&second_depend_table.slipper;

    srand(time(NULL));/*랜덤사용*/
    int get_chance;/*획득확률*/
    get_chance=rand()%100+1;/*100퍼중에*/
    if (get_chance<=20)/*20프로*/
    {
        twen=rand()%6+1;/*1~6(장비가 6개)*/
        switch (twen)
        {
        case 1:
            *item_address.address_longsword=sword_table.longsword++;
            printf("장검획득");
            break;
        case 2:
            *item_address.address_cottencape=second_depend_table.cottencape;
            second_depend_table.cottencape++;
            printf("면망토획득");
            break;
        case 3:
            *item_address.address_halfarmor=second_depend_table.halfarmor++;
            printf("반팔갑빠획득");
            break;
        case 4:
            *item_address.address_k80mask=second_depend_table.k80mask++;
            printf("k80마스크획득");
            break;
        case 5:
            *item_address.address_rubbergloves=second_depend_table.rubbergloves++;
            printf("고무장갑획득");
            break;
        case 6:
            *item_address.address_slipper=second_depend_table.slipper++;
            printf("슬리퍼획득");
            break;
        default:
            break;
        }
    }
    else
        twen=0;
    return twen;
}
int drop_3teer20(int twen) /*3티어 20프로 드랍 함수*/
{
    item_address.address_japensword=&sword_table;
    item_address.address_cottengloves=&third_depend_table.cottengloves;
    item_address.address_hoodarmor=&third_depend_table.hoodarmor;
    item_address.address_k94mask=&third_depend_table.k94mask;
    item_address.address_silkcape=&third_depend_table.silkcape;
    item_address.address_sneakers=&third_depend_table.sneakers;
    srand(time(NULL));/*랜덤사용*/
    int get_chance;/*획득확률*/
    get_chance=rand()%100+1;/*100퍼중에*/
    if (get_chance<=20)/*20프로*/
    {
        twen=rand()%6+1;/*1~6(장비가 6개)*/
        switch (twen)
        {
        case 1:
            *item_address.address_japensword=sword_table.japensword++;
            printf("일본도획득");
            break;
        case 2:
            *item_address.address_cottengloves=third_depend_table.cottengloves++;
            printf("면장갑획득");
            break;
        case 3:
            *item_address.address_hoodarmor=third_depend_table.hoodarmor++;
            printf("후드갑빠획득");
            break;
        case 4:
            *item_address.address_k94mask=third_depend_table.k94mask++;
            printf("k94마스크획득");
            break;
        case 5:
            *item_address.address_silkcape=third_depend_table.silkcape++;
            printf("비단망토획득");
            break;
        case 6:
            *item_address.address_sneakers=third_depend_table.sneakers++;
            printf("운동화획득");
            break;
        default:
            break;
        }
    }
    else
        twen=0;
    return twen;
    }

int drop_4teer20(int twen) /*4티어 20프로 드랍 함수*/
{
    item_address.address_airjodan=&fourth_depend_table.airjodan;
    item_address.address_nigthsword_saj=&sword_table.nigthsword_saj;
    item_address.address_bulletcape=&fourth_depend_table.bulletcape;
    item_address.address_dragonarmor=&fourth_depend_table.dragonarmor;
    item_address.address_leardergloves=&fourth_depend_table.leardergloves;
    item_address.address_tigermask=&fourth_depend_table.tigermask;
    srand(time(NULL));/*랜덤사용*/
    int get_chance;/*획득확률*/
    get_chance=rand()%100+1;/*100퍼중에*/
    if (get_chance<=20)/*20프로*/
    {
        twen=rand()%6+1;/*1~6(장비가 6개)*/
            twen=rand()%6+1;/*1~6(장비가 6개)*/
        switch (twen)
        {
        case 1:
            *item_address.address_airjodan=sword_table.nigthsword_saj++;
            printf("싸울아비장검 획득");
            break;
        case 2:
            *item_address.address_airjodan=fourth_depend_table.airjodan++;
            printf("에어조단획득");
            break;
        case 3:
            *item_address.address_bulletcape=fourth_depend_table.bulletcape++;
            printf("방탄망토획득");
            break;
        case 4:
            *item_address.address_dragonarmor=fourth_depend_table.dragonarmor++;
            printf("용갑빠획득");
            break;
        case 5:
            *item_address.address_leardergloves=fourth_depend_table.leardergloves++;
            printf("가죽장갑획득");
            break;
        case 6:
            *item_address.address_tigermask=fourth_depend_table.tigermask++;
            printf("타이커마스크획득");
        default:
            break;
        }
    }
    else
        twen=0;
    return twen;
}

int drop_4teer10(int ten) /*4티어 10프로 드랍 함수*/
{
    item_address.address_airjodan=&fourth_depend_table.airjodan;
    item_address.address_nigthsword_saj=&sword_table.nigthsword_saj;
    item_address.address_bulletcape=&fourth_depend_table.bulletcape;
    item_address.address_dragonarmor=&fourth_depend_table.dragonarmor;
    item_address.address_leardergloves=&fourth_depend_table.leardergloves;
    item_address.address_tigermask=&fourth_depend_table.tigermask;
    srand(time(NULL));/*랜덤사용*/
    int get_chance;/*획득확률*/
    get_chance=rand()%100+1;/*100퍼중에*/
    if (get_chance<=10)/*10프로*/
    {
        ten=rand()%6+1;/*1~6(장비가 6개)*/
        switch (ten)
        {
        case 1:
            *item_address.address_airjodan=sword_table.nigthsword_saj++;
            printf("싸울아비장검 획득");
            break;
        case 2:
            *item_address.address_airjodan=fourth_depend_table.airjodan++;
            printf("에어조단획득");
            break;
        case 3:
            *item_address.address_bulletcape=fourth_depend_table.bulletcape++;
            printf("방탄망토획득");
            break;
        case 4:
            *item_address.address_dragonarmor=fourth_depend_table.dragonarmor++;
            printf("용갑빠획득");
            break;
        case 5:
            *item_address.address_leardergloves=fourth_depend_table.leardergloves++;
            printf("가죽장갑획득");
            break;
        case 6:
            *item_address.address_tigermask=fourth_depend_table.tigermask++;
            printf("타이커마스크획득");
        default:
            break;
        }
    }
    else
        ten=0;
    return ten;
}

int drop_thirty(int thir)/*3티어 30프로 드랍 함수*/
{
    item_address.address_japensword=&sword_table;
    item_address.address_cottengloves=&third_depend_table.cottengloves;
    item_address.address_hoodarmor=&third_depend_table.hoodarmor;
    item_address.address_k94mask=&third_depend_table.k94mask;
    item_address.address_silkcape=&third_depend_table.silkcape;
    item_address.address_sneakers=&third_depend_table.sneakers;

    srand(time(NULL));/*랜덤사용*/
    int get_chance;/*획득확률*/
    get_chance=rand()%100+1;/*100퍼중에*/
    if (get_chance<=30)/*30프로*/
    {
        thir=rand()%6+1;/*1~6(장비가 6개)*/
        switch (thir)
        {
        case 1:
            *item_address.address_japensword=sword_table.japensword++;
            printf("일본도획득");
            break;
        case 2:
            *item_address.address_cottengloves=third_depend_table.cottengloves++;
            printf("면장갑획득");
            break;
        case 3:
            *item_address.address_hoodarmor=third_depend_table.hoodarmor++;
            printf("후드갑빠획득");
            break;
        case 4:
            *item_address.address_k94mask=third_depend_table.k94mask++;
            printf("k94마스크획득");
            break;
        case 5:
            *item_address.address_silkcape=third_depend_table.silkcape++;
            printf("비단망토획득");
            break;
        case 6:
            *item_address.address_sneakers=third_depend_table.sneakers++;
            printf("운동화획득");
            break;
        default:
            break;
        }
    }
    else
        thir=0;
    return thir;
}
int drop_five(int five)/*4티어 5프로 드랍함수*/
{
    item_address.address_airjodan=&fourth_depend_table.airjodan;
    item_address.address_nigthsword_saj=&sword_table.nigthsword_saj;
    item_address.address_bulletcape=&fourth_depend_table.bulletcape;
    item_address.address_dragonarmor=&fourth_depend_table.dragonarmor;
    item_address.address_leardergloves=&fourth_depend_table.leardergloves;
    item_address.address_tigermask=&fourth_depend_table.tigermask;
    srand(time(NULL));/*랜덤사용*/
    int get_chance;/*획득확률*/
    get_chance=rand()%100+1;/*100퍼중에*/
    if (get_chance<=5)/*5개*/
    {
        five=rand()%6+1;/*1~6(장비가 6개)*/
            five=rand()%6+1;/*1~6(장비가 6개)*/
        switch (five)
        {
        case 1:
            *item_address.address_airjodan=sword_table.nigthsword_saj++;
            printf("싸울아비장검 획득");
            break;
        case 2:
            *item_address.address_airjodan=fourth_depend_table.airjodan++;
            printf("에어조단획득");
            break;
        case 3:
            *item_address.address_bulletcape=fourth_depend_table.bulletcape++;
            printf("방탄망토획득");
            break;
        case 4:
            *item_address.address_dragonarmor=fourth_depend_table.dragonarmor++;
            printf("용갑빠획득");
            break;
        case 5:
            *item_address.address_leardergloves=fourth_depend_table.leardergloves++;
            printf("가죽장갑획득");
            break;
        case 6:
            *item_address.address_tigermask=fourth_depend_table.tigermask++;
            printf("타이커마스크획득");
        default:
            break;
        }
    }
    else
        five =0;
    return five;
}

int gold_drop(int floor)/*골드 드랍 함수*/
{
    item_address.address_gold=&item_table.gold;
    srand(time(NULL));
    int get_gold;
    switch (floor)/*층*/
    {
    case 1:
        get_gold=(rand()%26)+5;/*5~30개*/
        *item_address.address_gold+=get_gold;
        break;
    case 2:
        get_gold=(rand()%56)+5;/*5~60개*/
        *item_address.address_gold+=get_gold;
        break;
    case 3:
        get_gold=(rand()%96)+5;/*5~100개*/
        *item_address.address_gold+=get_gold;
        break;
    case 4:
        get_gold=(rand()%126)+5;/*5~130개*/
        *item_address.address_gold+=get_gold;
        break;
    case 5:
        get_gold=rand()%196+5;/*5~200개*/
        *item_address.address_gold+=get_gold;
        break;
    default:
        break;
    }
    return get_gold;
}

int gold_drop_boss(int boss)/*보스 골드 드랍 함수*/
{   
    item_address.address_gold=&item_table.gold;
    srand(time(NULL));
    int get_gold;
    switch (boss)
    {
    case 1:/*네임드 우리반학생용사들*/
        get_gold=(rand()%496)+5;/*5~500*/
        *item_address.address_gold+=get_gold;
        break;
    case 2:/*바포메트*/
        get_gold=(rand()%696)+5;/*5~700*/
        *item_address.address_gold+=get_gold;
        break;
    case 3:/*이동녘*/
        get_gold=(rand()%996)+5;/*5~1000*/
        *item_address.address_gold+=get_gold;
        break;
    case 4:/*류홍걸*/
        get_gold=(rand()%2996)+5;/*5~3000*/
        *item_address.address_gold+=get_gold;
        break;
    
    default:
        break;
    }
    return get_gold;
}


/*소비창*/
// void consume(struct item_table)
// {

// }
