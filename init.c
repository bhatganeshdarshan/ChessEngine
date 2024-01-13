#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

void InitSq120ToSq64()
{
    int idx = 0 ;
    int sq = A1;
    int file = FILE_A;
    int rank = RANK_1;
    int sq64 = 0;
    for(idx=0;idx<BRD_SQ_NUM;idx++)
    {
        Sq120ToSq64[idx]=65;
    }
    for(idx=0;idx<64;idx++)
    {
        Sq64ToSq120[idx]=120;
    }
    for(rank=RANK_1;rank<=RANK_8;rank++)
    {
        for(file=FILE_A;file<=FILE_H;file++)
        {
            sq=FileRankToSq(file,rank);
            Sq64ToSq120[sq64]=sq;
            Sq120ToSq64[sq]=sq64;
            sq64++;
        }
    }
}

void AllInit()
{

}