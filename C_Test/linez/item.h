
typedef struct sword_table
{
    int basicsword[5][3];/*기본검*/
    int longsword[5][3]; /*장검*/
    int japensword[5][3]; /*일본도*/
    int nigthsword_saj[5][3];/*싸울아비장검*/
}sword_table;
typedef struct first_depend_table
{
    int basicarmor[5][3];/*기본 갑빠*/
    int basicboots[5][3];/*기본 장화*/
    int basiccape[5][3];/*기본 망토*/
    int basicgloves[5][3];/*기본 장갑*/
    int basicmask[5][3];/*기본 마스크*/
}first_depend_table;
typedef struct second_depend_table
{
    int halfarmor[5][3];/*반팔 갑빠*/
    int slipper[5][3];/*슬리퍼*/
    int rubbergloves[5][3];/*고무장갑*/
    int cottencape[5][3];/*면 망토*/
    int k80mask[5][3];/*k80 마스크*/
}second_depend_table;
typedef struct third_depend_table
{
    int hoodarmor[5][3];/*후드갑빠*/
    int sneakers[5][3];/*운동화*/
    int cottengloves[5][3];/*면 장갑*/
    int silkcape[5][3];/*비단 망토*/
    int k94mask[5][3];/*k94마스크*/
}third_depend_table;
typedef struct fourth_depend_table
{
    int dragonarmor[5][3];/*용 갑빠*/
    int airjodan[5][3];/*에어조단*/
    int leardergloves[5][3];/*가죽장갑*/
    int bulletcape[5][3];/*방탄 망토*/
    int tigermask[5][3];/*타이거 마스크*/
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
//장비 구조체
typedef struct equipment
{
    sword_table weapon;
    first_depend_table nomal;
    second_depend_table rare;
    third_depend_table epic;
    fourth_depend_table legend;
}equipment;
//보키 구조체
typedef struct Boki
{
    int fhp;
    int chp;
    int gold;
    int damage;
    int def;
    struct item_table consume;
    equipment bokiEquipment;
}Boki;