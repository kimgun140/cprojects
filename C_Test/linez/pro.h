#include<stdio.h>
#include<stdlib.h> /*랜덤함수 사용 위해 불러옴*/
#include<time.h> /*랜덤함수 사용 위해 불러옴*/
// #include"item.h"
#include "function.h"
// #include "monster1.h"

int town_movement(Boki* boki);/*이동아이템 획득 함수 전방선언*/
int drop_2teer20(Boki* boki);/*2티어 20프로*/
int drop_3teer20(Boki* boki);/*3티어 20프로*/
int drop_3teer30(Boki* boki);/*3티어 30프로*/
int drop_4teer5(Boki* boki);/*4티어 5프로*/
int drop_4teer10(Boki* boki);/*4티어 10프로*/
int drop_4teer20(Boki* boki);/*4티어 20프로*/

int gold_drop(Boki* boki,int floor);/*골드 드랍 함수*/
int gold_drop_boss(Boki* boki,int boss);/*보스 골드 드랍 함수*/
int elixir_drop(Boki* boki,Monster* monster,int a);/*엘릭서 드랍 함수*/
void consume_window(Boki* boki);

int main(void)
{
    Boki boki;
    Monster monster;
    boki.chp=0;
    boki.fhp=100;
    boki.consume.potion.redpotion=1;
    // consume_window(&boki);
    // boki.consume.elixir=0;
    elixir_drop(&boki,&monster,5);
    // a=town_movement(&boki);
    // b=drop_2teer20(&boki);
    // c=drop_3teer20(&boki);
    // d=drop_3teer30(&boki);
    // e=drop_4teer5(&boki);
    // f=drop_4teer10(&boki);
    // g=drop_4teer20(&boki);

    // j=gold_drop(&boki,1);
    // printf("%d\n",boki.gold);
    // k=gold_drop_boss(&boki,1);
    // printf("%d\n",boki.gold);
    // l=elixir_drop(&boki,&monster,4);
    // printf("%d\n",boki.consume.elixir);

}
// int town_movement(Boki* boki)/*순간이동 주문서 획득*/
// {
//     boki->consume.scroll.tmscrollpaper;
//     srand(time(NULL));/*랜덤사용*/
//     int get_chance; /*획득확률*/
//     int tm;
//     get_chance=rand()%100+1;/*1~100까지*/
//     if (get_chance<=20)/*20보다 작거나 같으면*/
//     {
//         tm=rand()%3+1; /*획득 개수는 1~3개*/
//         boki->consume.scroll.tmscrollpaper+tm;
//         //*item_address.address_tmscrollpaper=item_table.scroll.tmscrollpaper+=tm;
//         printf("순간이동주문서 %d개획득\n",tm);
//     }
//     else
//     {
//         tm=0;
//         printf("순간이동주문서를 획득하지 않았습니다.\n");
//     }
    
//     return tm;/*획득 개수 리턴*/
// }

// int drop_2teer20(Boki* boki) /*2티어 20프로 드랍 함수*/
// {
//     boki->bokiEquipment.rare.cottencape[0][0]=1;
//     boki->bokiEquipment.rare.halfarmor[0][0]=1;
//     boki->bokiEquipment.rare.k80mask[0][0]=1;
//     boki->bokiEquipment.rare.rubbergloves[0][0]=1;
//     boki->bokiEquipment.rare.slipper[0][0]=1;

//     srand(time(NULL));/*랜덤사용*/
//     int get_chance;/*획득확률*/
//     int twen;
//     get_chance=rand()%100+1;/*100퍼중에*/
//     if (get_chance<=20)/*20프로*/
//     {
//         twen=rand()%6+1;/*1~6(장비가 6개)*/
//         switch (twen)
//         {
//         case 1:
//            for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.weapon.longsword[i][0]==0)
//                 {
//                     boki->bokiEquipment.weapon.longsword[i][0]=1;
//                     printf("장검획득\n");
//                     break;
//                 }
//            }
//            break;
//         case 2:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.rare.cottencape[i][0]==0)
//                 {
//                     boki->bokiEquipment.rare.cottencape[i][0]=1;
// {
//                     printf("면망토획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 3:
//            for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.rare.halfarmor[i][0]==0)
//                 {
//                     boki->bokiEquipment.rare.halfarmor[i][0]=1;
//                     printf("반팔갑빠획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 4:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.rare.k80mask[i][0]==0)
//                 {
//                     boki->bokiEquipment.rare.k80mask[i][0]=1;
//                     printf("k80마스크획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 5:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.rare.rubbergloves[i][0]==0)
//                 {
//                     boki->bokiEquipment.rare.rubbergloves[i][0]=1;
//                     printf("고무장갑획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 6:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.rare.slipper[i][0]==0)
//                 {
//                     boki->bokiEquipment.rare.slipper[i][0]=1;
//                     printf("슬리퍼획득\n");
//                     break;
//                 }
//            }
//             break;
//         default:
//             break;
//         }
//     }
//     else
//     {
//         twen=0;
//         printf("획득한 아이템이 없습니다.\n");
//     }
//     return twen;
// }
// int drop_3teer20(Boki* boki) /*3티어 20프로 드랍 함수*/
// {
//     srand(time(NULL));/*랜덤사용*/
//     int get_chance;/*획득확률*/
//     get_chance=rand()%100+1;/*100퍼중에*/
//     int twen;
//     if (get_chance<=20)/*20프로*/
//     {
//         twen=rand()%6+1;/*1~6(장비가 6개)*/
//         switch (twen)
//         {
//         case 1:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.weapon.japensword[i][0]==0)
//                 {
//                     boki->bokiEquipment.weapon.japensword[i][0]=1;
//                     printf("일본도획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 2:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.cottengloves[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.cottengloves[i][0]=1;
//                     printf("면장갑획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 3:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.hoodarmor[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.hoodarmor[i][0]=1;
//                     printf("후드갑빠획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 4:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.k94mask[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.k94mask[i][0]=1;
//                     printf("k94마스크획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 5:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.silkcape[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.silkcape[i][0]=1;
//                     printf("비단망토획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 6:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.sneakers[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.sneakers[i][0]=1;
//                     printf("k94마스크획득\n");
//                     break;
//                 }
//            }
//             break;
//         default:
//             break;
//         }
//     }
//     else
//     {
//         twen=0;
//         printf("획득한 아이템이 없습니다.\n");
//     }
//     return twen;
// }
// int drop_3teer30(Boki* boki) /*3티어 20프로 드랍 함수*/
// {
//     srand(time(NULL));/*랜덤사용*/
//     int get_chance;/*획득확률*/
//     get_chance=rand()%100+1;/*100퍼중에*/
//     int twen;
//     if (get_chance<=30)/*20프로*/
//     {
//         twen=rand()%6+1;/*1~6(장비가 6개)*/
//         switch (twen)
//         {
//         case 1:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.weapon.japensword[i][0]==0)
//                 {
//                     boki->bokiEquipment.weapon.japensword[i][0]=1;
//                     printf("일본도획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 2:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.cottengloves[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.cottengloves[i][0]=1;
//                     printf("면장갑획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 3:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.hoodarmor[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.hoodarmor[i][0]=1;
//                     printf("후드갑빠획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 4:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.k94mask[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.k94mask[i][0]=1;
//                     printf("k94마스크획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 5:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.silkcape[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.silkcape[i][0]=1;
//                     printf("비단망토획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 6:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.epic.sneakers[i][0]==0)
//                 {
//                     boki->bokiEquipment.epic.sneakers[i][0]=1;
//                     printf("k94마스크획득\n");
//                     break;
//                 }
//            }
//             break;
//         default:
//             break;
//         }
//     }
//     else
//     {
//         twen=0;
//         printf("획득한 아이템이 없습니다.\n");
//     }
//     return twen;
// }
// int drop_4teer5(Boki* boki) /*4티어 5프로 드랍 함수*/
// {
//     srand(time(NULL));/*랜덤사용*/
//     int get_chance;/*획득확률*/
//     get_chance=rand()%100+1;/*100퍼중에*/
//     int five;
//     if (get_chance<=5)/*5프로*/
//     {
//         five=rand()%6+1;/*1~6(장비가 6개)*/
//         switch (five)
//         {
//             case 1:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.weapon.nigthsword_saj[i][0]==0)
//                 {
//                     boki->bokiEquipment.weapon.nigthsword_saj[i][0]=1;
//                     printf("싸울아비장검획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 2:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.airjodan[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.airjodan[i][0]=1;
//                     printf("에어조단획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 3:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.bulletcape[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.bulletcape[i][0]=1;
//                     printf("방탄망토획득\n");
//                     break;
//                 }
//             }
//             break;
//         case 4:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.dragonarmor[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.dragonarmor[i][0]=1;
//                     printf("용갑빠획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 5:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.leardergloves[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.leardergloves[i][0]=1;
//                     printf("가죽장갑획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 6:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.tigermask[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.tigermask[i][0]=1;
//                     printf("타이거마스크획득\n");
//                     break;
//                 }
//            }
//         default:
//             break;
//         }
//     }
//     else
//     {
//         five=0;
//         printf("획득한 아이템이 없습니다.\n");
//     }
//     return five;
// }
// int drop_4teer20(Boki* boki) /*4티어 20프로 드랍 함수*/
// {
//     srand(time(NULL));/*랜덤사용*/
//     int get_chance;/*획득확률*/
//     get_chance=rand()%100+1;/*100퍼중에*/
//     int twen;
//     if (get_chance<=20)/*20프로*/
//     {
//         twen=rand()%6+1;/*1~6(장비가 6개)*/
//         switch (twen)
//         {
//             case 1:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.weapon.nigthsword_saj[i][0]==0)
//                 {
//                     boki->bokiEquipment.weapon.nigthsword_saj[i][0]=1;
//                     printf("싸울아비장검획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 2:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.airjodan[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.airjodan[i][0]=1;
//                     printf("에어조단획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 3:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.bulletcape[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.bulletcape[i][0]=1;
//                     printf("방탄망토획득\n");
//                     break;
//                 }
//             }
//             break;
//         case 4:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.dragonarmor[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.dragonarmor[i][0]=1;
//                     printf("용갑빠획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 5:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.leardergloves[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.leardergloves[i][0]=1;
//                     printf("가죽장갑획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 6:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.tigermask[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.tigermask[i][0]=1;
//                     printf("타이거마스크획득\n");
//                     break;
//                 }
//            }
//         default:
//             break;
//         }
//     }
//     else
//     {
//         twen=0;
//         printf("획득한 아이템이 없습니다.\n");
//     }
//     return twen;
// }

// int drop_4teer10(Boki* boki) /*4티어 10프로 드랍 함수*/
// {
//     srand(time(NULL));/*랜덤사용*/
//     int get_chance;/*획득확률*/
//     int ten;
//     get_chance=rand()%100+1;/*100퍼중에*/
//     if (get_chance<=10)/*10프로*/
//     {
//         ten=rand()%6+1;/*1~6(장비가 6개)*/
//         switch (ten)
//         {
//             case 1:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.weapon.nigthsword_saj[i][0]==0)
//                 {
//                     boki->bokiEquipment.weapon.nigthsword_saj[i][0]=1;
//                     printf("싸울아비장검획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 2:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.airjodan[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.airjodan[i][0]=1;
//                     printf("에어조단획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 3:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.bulletcape[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.bulletcape[i][0]=1;
//                     printf("방탄망토획득\n");
//                     break;
//                 }
//             }
//             break;
//         case 4:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.dragonarmor[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.dragonarmor[i][0]=1;
//                     printf("용갑빠획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 5:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.leardergloves[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.leardergloves[i][0]=1;
//                     printf("가죽장갑획득\n");
//                     break;
//                 }
//            }
//             break;
//         case 6:
//             for (int i = 0; i < 5; i++)
//            {
//             if(boki->bokiEquipment.legend.tigermask[i][0]==0)
//                 {
//                     boki->bokiEquipment.legend.tigermask[i][0]=1;
//                     printf("타이거마스크획득\n");
//                     break;
//                 }
//            }
//         }
//     }
//     else
//     {
//         ten=0;
//         printf("획득한 아이템이 없습니다.\n");
//     }
//     return ten;
// }


// int gold_drop(Boki* boki,int floor)/*골드 드랍 함수*/
// {
//     srand(time(NULL));
//     int get_gold;
//     switch (floor)/*층*/
//     {
//     case 1:
//         get_gold=(rand()%26)+5;/*5~30개*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 2:
//         get_gold=(rand()%56)+5;/*5~60개*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 3:
//         get_gold=(rand()%96)+5;/*5~100개*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 4:
//         get_gold=(rand()%126)+5;/*5~130개*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 5:
//         get_gold=rand()%196+5;/*5~200개*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     default:
//         break;
//     }
//     return get_gold;
// }

// int gold_drop_boss(Boki* boki, int boss)/*보스 골드 드랍 함수*/
// {   
//     srand(time(NULL));
//     int get_gold;
//     switch (boss)
//     {
//     case 1:/*네임드 우리반학생용사들*/
//         get_gold=(rand()%496)+5;/*5~500*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 2:/*바포메트*/
//         get_gold=(rand()%696)+5;/*5~700*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 3:/*이동녘*/
//         get_gold=(rand()%996)+5;/*5~1000*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
//     case 4:/*류홍걸*/
//         get_gold=(rand()%2996)+5;/*5~3000*/
//         boki->gold+=get_gold;
//         printf("%d 골드 획득\n",get_gold);
//         break;
    
//     default:
//         break;
//     }
//     return get_gold;
// }

// int elixir_drop(Boki* boki,Monster* monster,int a)
// {
//     srand(time(NULL));
//     int get_elixir;
//     int chance_elixir;
//     chance_elixir=rand()%101;
//     switch (a)
//     {
//     case 4:
//     if (chance_elixir<=10)
//     {
//         get_elixir=rand()%3+1;
//         boki->consume.elixir+=get_elixir;
//         printf("엘릭서 %d개 획득\n",get_elixir);
//         break;
//     }
//     else
//         printf("X");
//     break;

//     case 5:
//     if (chance_elixir<=20)
//     {
//         get_elixir=rand()%3+1;
//         boki->consume.elixir+=get_elixir;
//         printf("엘릭서 %d개 획득\n",get_elixir);
//         break;
//     }
//     else
//         printf("X");
//         break;

//     default:
//         break;
//     }

//     return get_elixir;
// }


// /*int elixir_drop(Boki* boki,Monster* monster,int a)
// {
//     // boki->consume.elixir;
//     srand(time(NULL));
//     int get_elixir;
//     int chance_elixir;
//     chance_elixir=rand()%101;
//     if (chance_elixir<=20)
//     {
//         get_elixir=rand()%3+1;
//         boki->consume.elixir+=get_elixir;
//         printf("엘릭서를 %d개 획득했습니다.",get_elixir);
//     }
//     else
//     {
//         get_elixir=0;
//         printf("XXXXx");
//     }
//     return get_elixir;
// }
// */

// void consume_window(Boki* boki)
// {
//     printf("아이템을 사용\n");
//     printf("1)빨간물약\t\t2)주황물약\n3)맑은물약\t\t4)고농도물약\n5)마을이동주문서\t\t6)장비강화주문서\n"
//             "7)순간이동주문서\t\t8)엘릭서\n");
//     int item_choice;
//     printf("선택:");
//     scanf("%d",&item_choice);
//     switch (item_choice)
//     {
//     case 1:
//     if(boki->consume.potion.redpotion>0)
//     {
//         printf("빨간물약을 사용합니다.");
//         boki->consume.potion.redpotion--;
//         boki->chp+=30;
//         if(boki->chp>=boki->fhp)
//         {
//             boki->chp=boki->fhp;
//         }
//         printf("남은 빨간물약 %d개\n",boki->consume.potion.redpotion);
//         printf("사용후체력%d\n",boki->chp);
//     }
//     break;
//     case 2:
//     if(boki->consume.potion.orangepotion>0)
//     {
//         printf("주황물약을 사용합니다.\n");
//         boki->consume.potion.orangepotion--;
//         boki->chp+=50;
//         if(boki->chp>=boki->fhp)
//         {
//             boki->chp=boki->fhp;
//         }
//         printf("남은 주황물약 %d개\n",boki->consume.potion.orangepotion);
//         printf("사용후체력%d\n",boki->chp);
//     }
//     break;
//     case 3:
//     if(boki->consume.potion.purepotion>0)
//     {
//         printf("맑은물약을 사용합니다.\n");
//         boki->consume.potion.purepotion--;
//         boki->chp+=70;
//         if(boki->chp>=boki->fhp)
//         {
//             boki->chp=boki->fhp;
//         }
//         printf("남은 맑은물약 %d개\n",boki->consume.potion.purepotion);
//         printf("사용후체력%d\n",boki->chp);
//     }
//     break;
//     case 4:
//     if(boki->consume.potion.highpotion>0)
//     {
//         printf("고농도물약을 사용합니다.\n");
//         boki->consume.potion.highpotion--;
//         boki->chp+=150;
//         if(boki->chp>=boki->fhp)
//         {
//             boki->chp=boki->fhp;
//         }
//         printf("남은 고농도물약 %d개\n",boki->consume.potion.highpotion);
//         printf("사용후체력%d\n",boki->chp);
//     }
//     break;
//     case 5:
//     if(boki->consume.scroll.tmscrollpaper>0)
//     {
//         printf("마을이동주문서를 사용합니다.\n");
//         boki->consume.scroll.tmscrollpaper--;
//         printf("남은 마을 이동주문서 %d개\n",boki->consume.scroll.tmscrollpaper);
//     }
//     break;
//     case 6:
//     if(boki->consume.scroll.ermagicscroll>0)
//     {
//         printf("장비강화주문서를 사용합니다.\n");
//         boki->consume.scroll.ermagicscroll--;
//         printf("남은 장비강화주문서 %d개\n",boki->consume.scroll.ermagicscroll);
//     }
//     break;
//     case 7:
//         if(boki->consume.scroll.teleportscroll>0)
//     {
//         printf("순간이동주문서를 사용합니다.\n");
//         boki->consume.scroll.teleportscroll--;
//         printf("남은 순간이동주문서 %d개\n",boki->consume.scroll.teleportscroll);
//     }
//     break;
//     case 8:
//         if(boki->consume.elixir>0)
//     {
//         printf("엘릭서를 사용합니다.\n");
//         boki->consume.elixir--;
//         printf("남은 엘릭서 %d개\n",boki->consume.elixir);
//     }
//     break;
//     default:
//         break;
//     }

// }