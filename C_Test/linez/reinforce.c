#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include"item.h"

enum weapon{basicsword,longsword,japensword,nigthsword_saj};
enum depndI {armor,boots,cape,gloves,mask};
int main(void)
{
Boki* a=(Boki*)malloc(sizeof(Boki));
//강화하려는 아이템 정보를 출력하고 전부다 출력 1~5번까지 
//그리고 어떤 아이템을 강화할건지 선택
//강화함수의 카운트 부분을 선택받아주고
// 어떤 아이템이 강
    WReinForcement(a,0,basicsword);
}

void WReinForcement(Boki* boki,int count,int armed)
{
    srand(time(NULL));
    int aaaa=rand()%10;
    printf("aaaa:%d\n",aaaa);
    if(aaaa>=8){
        switch (armed)
        {
        case basicsword:          
            if(boki->bokiEquipment.weapon.basicsword[count][0] !=0 &&boki->bokiEquipment.weapon.basicsword[count][2]!=10)
            {
                boki->bokiEquipment.weapon.basicsword[count][1]*=1.1;
                boki->bokiEquipment.weapon.basicsword[count][2]+=1;            
            }
            break;
        case longsword:
            if(boki->bokiEquipment.weapon.longsword[count][0] !=0&&boki->bokiEquipment.weapon.longsword[count][2]!=10)
            {
                boki->bokiEquipment.weapon.longsword[count][1]*=1.1;
                boki->bokiEquipment.weapon.longsword[count][2]+=1;            
            }
            break;
        
        case japensword:
        if(boki->bokiEquipment.weapon.japensword[count][0] !=0&&boki->bokiEquipment.weapon.japensword[count][2]!=10)
            {
                boki->bokiEquipment.weapon.japensword[count][1]*=1.1;
                boki->bokiEquipment.weapon.japensword[count][2]+=1;            
            }
        break;
        
        case nigthsword_saj:
            if(boki->bokiEquipment.weapon.nigthsword_saj[count][0] !=0&&boki->bokiEquipment.weapon.nigthsword_saj[count][2]!=10)
            {
                boki->bokiEquipment.weapon.nigthsword_saj[count][1]*=1.1;
                boki->bokiEquipment.weapon.nigthsword_saj[count][2]+=1;            
            }
            break;    
        }
    }
    else
    {
        switch (armed)
        {
         case basicsword:          
            boki->bokiEquipment.weapon.basicsword[count][0]=0;    
            break;
        
        case longsword:
            boki->bokiEquipment.weapon.longsword[count][0]=0;
            break;
        
        case japensword:
            boki->bokiEquipment.weapon.japensword[count][0]=0;
        break;
        
        case nigthsword_saj:
            boki->bokiEquipment.weapon.nigthsword_saj[count][0]=0;
            break;    
        }
    }    
}

void FDepReinForce(Boki* boki,int count,int armed)
{
    srand(time(NULL));
    int aaaa=rand()%10;
    if(aaaa>=8){
        switch (armed)
        {
        case armor:          
            if(boki->bokiEquipment.nomal.basicarmor[count][0] !=0&&boki->bokiEquipment.nomal.basicarmor[count][2]!=10)
            {
                boki->bokiEquipment.nomal.basicarmor[count][1]*=1.1;
                boki->bokiEquipment.nomal.basicarmor[count][2]+=1;            
            }
            break;
        case boots:
            if(boki->bokiEquipment.nomal.basicboots[count][0] !=0&&boki->bokiEquipment.nomal.basicboots[count][2]!=10)
            {
                boki->bokiEquipment.nomal.basicboots[count][1]*=1.1;
                boki->bokiEquipment.nomal.basicboots[count][2]+=1;            
            }
            break;
        
        case cape:
        if(boki->bokiEquipment.nomal.basiccape[count][0] !=0&&boki->bokiEquipment.nomal.basiccape[count][2]!=10)
            {
                boki->bokiEquipment.nomal.basiccape[count][1]*=1.1;
                boki->bokiEquipment.nomal.basiccape[count][2]+=1;            
            }
        break;
        
        case gloves:
            if(boki->bokiEquipment.nomal.basicgloves[count][0] !=0&&boki->bokiEquipment.nomal.basicgloves[count][2]!=10)
            {
                boki->bokiEquipment.nomal.basicgloves[count][1]*=1.1;
                boki->bokiEquipment.nomal.basicgloves[count][2]+=1;            
            }
            break;    
        case mask:
        if(boki->bokiEquipment.nomal.basicmask[count][0] !=0&&boki->bokiEquipment.nomal.basicmask[count][2]!=10)
            {
                boki->bokiEquipment.nomal.basicmask[count][1]*=1.1;
                boki->bokiEquipment.nomal.basicmask[count][2]+=1;            
            }
        break;
        }
    }
    
    else
    {
        switch (armed)
        {
         case armor:          
            boki->bokiEquipment.nomal.basicarmor[count][0]=0;    
            break;
        
        case boots:
            boki->bokiEquipment.nomal.basicboots[count][0]=0;
            break;
        
        case cape:
           boki->bokiEquipment.nomal.basiccape[count][0]=0;
        break;
        case gloves:
            boki->bokiEquipment.nomal.basicgloves[count][0]=0;
        break;
        case mask:
           boki->bokiEquipment.nomal.basicmask[count][0]=0;
            break;    
        }
    }
}

void SDepReinForce(Boki* boki,int count,int armed)
{
    srand(time(NULL));
    int aaaa=rand()%10;
    if(aaaa>=8){
        switch (armed)
        {
        case armor:          
            if(boki->bokiEquipment.rare.halfarmor[count][0] !=0&&boki->bokiEquipment.rare.halfarmor[count][2]!=10)
            {
                boki->bokiEquipment.rare.halfarmor[count][1]*=1.1;
                boki->bokiEquipment.rare.halfarmor[count][2]+=1;            
            }
            break;
        case boots:
            if(boki->bokiEquipment.rare.slipper[count][0] !=0&&boki->bokiEquipment.rare.slipper[count][2]!=10)
            {
                boki->bokiEquipment.rare.slipper[count][1]*=1.1;
                boki->bokiEquipment.rare.slipper[count][2]+=1;            
            }
            break;
        
        case cape:
        if(boki->bokiEquipment.rare.cottencape[count][0] !=0&&boki->bokiEquipment.rare.cottencape[count][2]!=10)
            {
                boki->bokiEquipment.rare.cottencape[count][1]*=1.1;
                boki->bokiEquipment.rare.cottencape[count][2]+=1;            
            }
        break;
        
        case gloves:
            if(boki->bokiEquipment.rare.rubbergloves[count][0] !=0&&boki->bokiEquipment.rare.rubbergloves[count][2]!=10)
            {
                boki->bokiEquipment.rare.rubbergloves[count][1]*=1.1;
                boki->bokiEquipment.rare.rubbergloves[count][2]+=1;            
            }
            break;    
        case mask:
        if(boki->bokiEquipment.rare.k80mask[count][0] !=0&&boki->bokiEquipment.rare.k80mask[count][2]!=10)
            {
                boki->bokiEquipment.rare.k80mask[count][1]*=1.1;
                boki->bokiEquipment.rare.k80mask[count][2]+=1;            
            }
        break;
        }
    }
    
    else
    {
        switch (armed)
        {
         case armor:          
            boki->bokiEquipment.rare.halfarmor[count][0]=0;    
            break;
        
        case boots:
            boki->bokiEquipment.rare.slipper[count][0]=0;
            break;
        
        case cape:
           boki->bokiEquipment.rare.cottencape[count][0]=0;
        break;
        case gloves:
            boki->bokiEquipment.rare.rubbergloves[count][0]=0;
        break;
        case mask:
           boki->bokiEquipment.rare.k80mask[count][0]=0;
            break;    
        }
    }
}

void TDepReinForce(Boki* boki,int count,int armed)
{
    srand(time(NULL));
    int aaaa=rand()%10;
    if(aaaa>=8){
        switch (armed)
        {
        case armor:          
            if(boki->bokiEquipment.epic.hoodarmor[count][0] !=0&&boki->bokiEquipment.epic.hoodarmor[count][2]!=10)
            {
                boki->bokiEquipment.epic.hoodarmor[count][1]*=1.1;
                boki->bokiEquipment.epic.hoodarmor[count][2]+=1;            
            }
            break;
        case boots:
            if(boki->bokiEquipment.epic.sneakers[count][0] !=0&&boki->bokiEquipment.epic.sneakers[count][2]!=10)
            {
                boki->bokiEquipment.epic.sneakers[count][1]*=1.1;
                boki->bokiEquipment.epic.sneakers[count][2]+=1;            
            }
            break;
        
        case cape:
        if(boki->bokiEquipment.epic.silkcape[count][0] !=0&&boki->bokiEquipment.epic.silkcape[count][2]!=10)
            {
                boki->bokiEquipment.epic.silkcape[count][1]*=1.1;
                boki->bokiEquipment.epic.silkcape[count][2]+=1;            
            }
        break;
        
        case gloves:
            if(boki->bokiEquipment.epic.cottengloves[count][0] !=0&&boki->bokiEquipment.epic.cottengloves[count][2]!=10)
            {
                boki->bokiEquipment.epic.cottengloves[count][1]*=1.1;
                boki->bokiEquipment.epic.cottengloves[count][2]+=1;            
            }
            break;    
        case mask:
        if(boki->bokiEquipment.epic.k94mask[count][0] !=0&&boki->bokiEquipment.epic.k94mask[count][2]!=10)
            {
                boki->bokiEquipment.epic.k94mask[count][1]*=1.1;
                boki->bokiEquipment.epic.k94mask[count][2]+=1;            
            }
        break;
        }
    }
    
    else
    {
        switch (armed)
        {
         case armor:          
            boki->bokiEquipment.epic.hoodarmor[count][0]=0;    
            break;
        
        case boots:
            boki->bokiEquipment.epic.sneakers[count][0]=0;
            break;
        
        case cape:
           boki->bokiEquipment.epic.silkcape[count][0]=0;
        break;
        case gloves:
            boki->bokiEquipment.epic.cottengloves[count][0]=0;
        break;
        case mask:
           boki->bokiEquipment.epic.k94mask[count][0]=0;
            break;    
        }
    }
}

void FoDepReinForce(Boki* boki,int count,int armed)
{
    srand(time(NULL));
    int aaaa=rand()%10;
    if(aaaa>=8){
        switch (armed)
        {
        case armor:          
            if(boki->bokiEquipment.legend.dragonarmor[count][0] !=0&&boki->bokiEquipment.legend.dragonarmor[count][2]!=10)
            {
                boki->bokiEquipment.legend.dragonarmor[count][1]*=1.1;
                boki->bokiEquipment.legend.dragonarmor[count][2]+=1;            
            }
            break;
        case boots:
            if(boki->bokiEquipment.legend.airjodan[count][0] !=0&&boki->bokiEquipment.legend.airjodan[count][2]!=10)
            {
                boki->bokiEquipment.legend.airjodan[count][1]*=1.1;
                boki->bokiEquipment.legend.airjodan[count][2]+=1;            
            }
            break;
        
        case cape:
        if(boki->bokiEquipment.legend.bulletcape[count][0] !=0&&boki->bokiEquipment.legend.bulletcape[count][2]!=10)
            {
                boki->bokiEquipment.legend.bulletcape[count][1]*=1.1;
                boki->bokiEquipment.legend.bulletcape[count][2]+=1;            
            }
        break;
        
        case gloves:
            if(boki->bokiEquipment.legend.leardergloves[count][0] !=0&&boki->bokiEquipment.legend.leardergloves[count][2]!=10)
            {
                boki->bokiEquipment.legend.leardergloves[count][1]*=1.1;
                boki->bokiEquipment.legend.leardergloves[count][2]+=1;            
            }
            break;    
        case mask:
        if(boki->bokiEquipment.legend.tigermask[count][0] !=0&&boki->bokiEquipment.legend.tigermask[count][2]!=10)
            {
                boki->bokiEquipment.legend.tigermask[count][1]*=1.1;
                boki->bokiEquipment.legend.tigermask[count][2]+=1;            
            }
        break;
        }
    }
    
    else
    {
        switch (armed)
        {
         case armor:          
            boki->bokiEquipment.legend.dragonarmor[count][0]=0;    
            break;
        
        case boots:
            boki->bokiEquipment.legend.airjodan[count][0]=0;
            break;
        
        case cape:
           boki->bokiEquipment.legend.bulletcape[count][0]=0;
        break;
        case gloves:
            boki->bokiEquipment.legend.leardergloves[count][0]=0;
        break;
        case mask:
           boki->bokiEquipment.legend.tigermask[count][0]=0;
            break;    
        }
    }
}