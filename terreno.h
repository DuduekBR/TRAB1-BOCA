#ifndef _TERRENO
#define _TERRENO
typedef struct Terreno{
    char tag_Solo;
    int p_m2;
} tGround;
void read_Ground(tGround*, FILE*);
float price_calc(tGround *x, float *area);
char ret_tag(tGround *x);
#endif