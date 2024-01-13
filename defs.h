#ifndef DEFS_H

#define DEFS_H

typedef unsigned long long U64;

#define NAME "Chess Bot 1.0 by Ganeshdarshan"
#define BRD_SQ_NUM 120
#define MAX_GAME_MOVES 1024

//Macro 

// #define FileRankToSq(f,r) ((21+f)+(r*10))

int FileRankToSq(int f,int r)
{
    return ((21+f)+(r*10));
}

enum {EMPTY,wP,wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK};
enum {FILE_A,FILE_B,FILE_C,FILE_D,FILE_E,FILE_F,FILE_G,FILE_H,FILE_NONE};
enum {RANK_1,RANK_2,RANK_3,RANK_4,RANK_5,RANK_6,RANK_7,RANK_8,RANK_NONE};
enum {WHITE,BLACK,BOTH};

enum {
    A1=21,B1,C1,D1,E1,F1,G1,H1,
    A2=31,B2,C2,D2,E2,F2,G2,H2,
    A3=41,B3,C3,D3,E3,F3,G3,H3,
    A4=51,B4,C4,D4,E4,F4,G4,H4,
    A5=61,B5,C5,D5,E5,F5,G5,H5,
    A6=71,B6,C6,D6,E6,F6,G6,H6,
    A7=81,B7,C7,D7,E7,F7,G7,H7,
    A8=91,B8,C8,D8,E8,F8,G8,H8,NO_SQ
};

enum {FALSE,TRUE};

enum {wKCa = 1 , wQCa = 2 , bKCa =4 , bQCa = 8};

typedef struct
{
    int move;
    int canCastle;
    int enPass;
    int fiftyMove;
    U64 posKey;  
}S_UNDO;


typedef struct
{
    int pieces[BRD_SQ_NUM];
    U64 pawns[3]; // total 8 bit -> each bit represents whether the pawn is present in particular position or not
    // if present bit is set to 1 , or else it will be zero 
    int KingSquare[2];
    int sideToMove;
    int enPass;
    int fiftyMove;
    int ply;
    int hisPly;

    U64 posKey;
    int pcNum[13];
    int bigPiece[3]; // other pieces except pawns i.e 13-10 = 3
    int majorPiece[3];
    int minorPiece[3];

    int canCastle;

    S_UNDO History[MAX_GAME_MOVES];
    
}S_BOARD;


//global

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

//fun

extern void AllInit();

#endif