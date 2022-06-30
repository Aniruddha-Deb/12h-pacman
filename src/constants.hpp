#include <SDL2/SDL.h>

const SDL_Rect SPR_MAZED   = {0,0,224,248};
const SDL_Rect SPR_MAZE    = {228,0,224,248};
const SDL_Rect SPR_FOOD    = {8,8,8,8};
const SDL_Rect SPR_POWER   = {8,24,8,8};
const SDL_Rect SPR_PCM_0   = {488,0,16,16};
const SDL_Rect SPR_PCM_R1  = {472,0,16,16};
const SDL_Rect SPR_PCM_R2  = {456,0,16,16};
const SDL_Rect SPR_PCM_L1  = {472,16,16,16};
const SDL_Rect SPR_PCM_L2  = {456,16,16,16};
const SDL_Rect SPR_PCM_T1  = {472,32,16,16};
const SDL_Rect SPR_PCM_T2  = {456,32,16,16};
const SDL_Rect SPR_PCM_B1  = {472,48,16,16};
const SDL_Rect SPR_PCM_B2  = {456,48,16,16};
const SDL_Rect SPR_PCM_D1  = {504,0,16,16};
const SDL_Rect SPR_PCM_D2  = {520,0,16,16};
const SDL_Rect SPR_PCM_D3  = {536,0,16,16};
const SDL_Rect SPR_PCM_D4  = {552,0,16,16};
const SDL_Rect SPR_PCM_D5  = {568,0,16,16};
const SDL_Rect SPR_PCM_D6  = {584,0,16,16};
const SDL_Rect SPR_PCM_D7  = {600,0,16,16};
const SDL_Rect SPR_PCM_D8  = {616,0,16,16};
const SDL_Rect SPR_PCM_D9  = {632,0,16,16};
const SDL_Rect SPR_PCM_D10 = {648,0,16,16};
const SDL_Rect SPR_PCM_D11 = {664,0,16,16};
const SDL_Rect SPR_RG_R1   = {456,64,16,16};
const SDL_Rect SPR_RG_R2   = {472,64,16,16};
const SDL_Rect SPR_RG_L1   = {488,64,16,16};
const SDL_Rect SPR_RG_L2   = {504,64,16,16};
const SDL_Rect SPR_RG_T1   = {520,64,16,16};
const SDL_Rect SPR_RG_T2   = {536,64,16,16};
const SDL_Rect SPR_RG_B1   = {552,64,16,16};
const SDL_Rect SPR_RG_B2   = {568,64,16,16};
const SDL_Rect SPR_PG_R1   = {456,80,16,16};
const SDL_Rect SPR_PG_R2   = {472,80,16,16};
const SDL_Rect SPR_PG_L1   = {488,80,16,16};
const SDL_Rect SPR_PG_L2   = {504,80,16,16};
const SDL_Rect SPR_PG_T1   = {520,80,16,16};
const SDL_Rect SPR_PG_T2   = {536,80,16,16};
const SDL_Rect SPR_PG_B1   = {552,80,16,16};
const SDL_Rect SPR_PG_B2   = {568,80,16,16};
const SDL_Rect SPR_BG_R1   = {456,96,16,16};
const SDL_Rect SPR_BG_R2   = {472,96,16,16};
const SDL_Rect SPR_BG_L1   = {488,96,16,16};
const SDL_Rect SPR_BG_L2   = {504,96,16,16};
const SDL_Rect SPR_BG_T1   = {520,96,16,16};
const SDL_Rect SPR_BG_T2   = {536,96,16,16};
const SDL_Rect SPR_BG_B1   = {552,96,16,16};
const SDL_Rect SPR_BG_B2   = {568,96,16,16};
const SDL_Rect SPR_OG_R1   = {456,112,16,16};
const SDL_Rect SPR_OG_R2   = {472,112,16,16};
const SDL_Rect SPR_OG_L1   = {488,112,16,16};
const SDL_Rect SPR_OG_L2   = {504,112,16,16};
const SDL_Rect SPR_OG_T1   = {520,112,16,16};
const SDL_Rect SPR_OG_T2   = {536,112,16,16};
const SDL_Rect SPR_OG_B1   = {552,112,16,16};
const SDL_Rect SPR_OG_B2   = {568,112,16,16};
const SDL_Rect SPR_PMGB_1  = {584,64,16,16};
const SDL_Rect SPR_PMGB_2  = {600,64,16,16};
const SDL_Rect SPR_PMGW_1  = {616,64,16,16};
const SDL_Rect SPR_PMGW_2  = {632,64,16,16};
const SDL_Rect SPR_EYES_R  = {584,80,16,16};
const SDL_Rect SPR_EYES_L  = {600,80,16,16};
const SDL_Rect SPR_EYES_T  = {616,80,16,16};
const SDL_Rect SPR_EYES_B  = {632,80,16,16};
const SDL_Rect SPR_200     = {456,128,16,16};
const SDL_Rect SPR_400     = {472,128,16,16};
const SDL_Rect SPR_800     = {488,128,16,16};
const SDL_Rect SPR_1600    = {504,128,16,16};
const SDL_Rect SPR_SCR0    = {456,144,8,8};
const SDL_Rect SPR_SCR1    = {464,144,8,8};
const SDL_Rect SPR_SCR2    = {472,144,8,8};
const SDL_Rect SPR_SCR3    = {480,144,8,8};
const SDL_Rect SPR_SCR4    = {488,144,8,8};
const SDL_Rect SPR_SCR5    = {496,144,8,8};
const SDL_Rect SPR_SCR6    = {504,144,8,8};
const SDL_Rect SPR_SCR7    = {512,144,8,8};
const SDL_Rect SPR_SCR8    = {520,144,8,8};
const SDL_Rect SPR_SCR9    = {528,144,8,8};
const SDL_Rect SPR_HEXA    = {536,144,8,8};
const SDL_Rect SPR_HEXB    = {544,144,8,8};
const SDL_Rect SPR_HEXC    = {552,144,8,8};
const SDL_Rect SPR_TXT0    = {456,160,8,8};
const SDL_Rect SPR_TXT1    = {464,160,8,8};
const SDL_Rect SPR_TXT2    = {472,160,8,8};
const SDL_Rect SPR_TXT3    = {480,160,8,8};
const SDL_Rect SPR_TXT4    = {488,160,8,8};
const SDL_Rect SPR_TXT5    = {496,160,8,8};
const SDL_Rect SPR_TXT6    = {504,160,8,8};
const SDL_Rect SPR_TXT7    = {512,160,8,8};
const SDL_Rect SPR_TXT8    = {520,160,8,8};
const SDL_Rect SPR_TXT9    = {528,160,8,8};
const SDL_Rect SPR_TXTA    = {456,168,8,8};
const SDL_Rect SPR_TXTB    = {464,168,8,8};
const SDL_Rect SPR_TXTC    = {472,168,8,8};
const SDL_Rect SPR_TXTD    = {480,168,8,8};
const SDL_Rect SPR_TXTE    = {488,168,8,8};
const SDL_Rect SPR_TXTF    = {496,168,8,8};
const SDL_Rect SPR_TXTG    = {504,168,8,8};
const SDL_Rect SPR_TXTH    = {512,168,8,8};
const SDL_Rect SPR_TXTI    = {520,168,8,8};
const SDL_Rect SPR_TXTJ    = {528,168,8,8};
const SDL_Rect SPR_TXTK    = {536,168,8,8};
const SDL_Rect SPR_TXTL    = {544,168,8,8};
const SDL_Rect SPR_TXTM    = {552,168,8,8};
const SDL_Rect SPR_TXTN    = {456,176,8,8};
const SDL_Rect SPR_TXTO    = {464,176,8,8};
const SDL_Rect SPR_TXTP    = {472,176,8,8};
const SDL_Rect SPR_TXTQ    = {480,176,8,8};
const SDL_Rect SPR_TXTR    = {488,176,8,8};
const SDL_Rect SPR_TXTS    = {496,176,8,8};
const SDL_Rect SPR_TXTT    = {504,176,8,8};
const SDL_Rect SPR_TXTU    = {512,176,8,8};
const SDL_Rect SPR_TXTV    = {520,176,8,8};
const SDL_Rect SPR_TXTW    = {528,176,8,8};
const SDL_Rect SPR_TXTX    = {536,176,8,8};
const SDL_Rect SPR_TXTY    = {544,176,8,8};
const SDL_Rect SPR_TXTZ    = {552,176,8,8};
const SDL_Rect SPR_COPY    = {544,160,8,8};
const SDL_Rect SPR_EXCLM   = {552,160,8,8};
const SDL_Rect SPR_HYPHEN  = {544,152,8,8};
const SDL_Rect SPR_PTS     = {512,152,18,8};

const SDL_Rect G_MAZE = {0,24,224,248};
const SDL_Rect G_SCORE = {0,0,248,24};
const SDL_Rect G_STATUS = {0,272,224,16};

const SDL_Rect* SPR_TXTALPH[26]    = {
	 &SPR_TXTA,&SPR_TXTB,&SPR_TXTC,&SPR_TXTD,&SPR_TXTE,&SPR_TXTF,&SPR_TXTG,
	 &SPR_TXTH,&SPR_TXTI,&SPR_TXTJ,&SPR_TXTK,&SPR_TXTL,&SPR_TXTM,&SPR_TXTN,
	 &SPR_TXTO,&SPR_TXTP,&SPR_TXTQ,&SPR_TXTR,&SPR_TXTS,&SPR_TXTT,&SPR_TXTU,
	 &SPR_TXTV,&SPR_TXTW,&SPR_TXTX,&SPR_TXTY,&SPR_TXTZ
};

const SDL_Rect* SPR_TXTNUM[10]    = {
	&SPR_TXT0,&SPR_TXT1,&SPR_TXT2,&SPR_TXT3,&SPR_TXT4,&SPR_TXT5,&SPR_TXT6,
	&SPR_TXT7,&SPR_TXT8,&SPR_TXT9
};

const SDL_Rect* SPR_SCR[10]    = {
	&SPR_SCR0,&SPR_SCR1,&SPR_SCR2,&SPR_SCR3,&SPR_SCR4,&SPR_SCR5,&SPR_SCR6,
	&SPR_SCR7,&SPR_SCR8,&SPR_SCR9
};


const SDL_Rect* SPR_PACMAN[5][3] = {
	{ &SPR_PCM_0, &SPR_PCM_R1, &SPR_PCM_R2 },
	{ &SPR_PCM_0, &SPR_PCM_L1, &SPR_PCM_L2 },
	{ &SPR_PCM_0, &SPR_PCM_T1, &SPR_PCM_T2 },
	{ &SPR_PCM_0, &SPR_PCM_B1, &SPR_PCM_B2 },
	{ &SPR_PCM_0, &SPR_PCM_0,  &SPR_PCM_0  },
};

const SDL_Rect* SPR_GHOSTS[4][4][2] = {
	{{&SPR_RG_R1, &SPR_RG_R2},
	 {&SPR_RG_L1, &SPR_RG_L2},
	 {&SPR_RG_T1, &SPR_RG_T2},
	 {&SPR_RG_B1, &SPR_RG_B2}},
	
	{{&SPR_PG_R1, &SPR_PG_R2},
	 {&SPR_PG_L1, &SPR_PG_L2},
	 {&SPR_PG_T1, &SPR_PG_T2},
	 {&SPR_PG_B1, &SPR_PG_B2}},
	
	{{&SPR_BG_R1, &SPR_BG_R2},
	 {&SPR_BG_L1, &SPR_BG_L2},
	 {&SPR_BG_T1, &SPR_BG_T2},
	 {&SPR_BG_B1, &SPR_BG_B2}},
	
	{{&SPR_OG_R1, &SPR_OG_R2},
	 {&SPR_OG_L1, &SPR_OG_L2},
	 {&SPR_OG_T1, &SPR_OG_T2},
	 {&SPR_OG_B1, &SPR_OG_B2}}
};

const SDL_Rect* SPR_FRIGHT[2][2] = {
	{&SPR_PMGB_1, &SPR_PMGB_2},
	{&SPR_PMGW_1, &SPR_PMGW_2}
};

const int GHOSTS[4] = {RG, PG, BG, OG};
const SDL_Rect* SPR_EYES[4] = 
	{ &SPR_EYES_R, &SPR_EYES_L, &SPR_EYES_T, &SPR_EYES_B };
const SDL_Rect* SPR_GSCORES[4] = 
	{ &SPR_200, &SPR_400, &SPR_800, &SPR_1600 };

const SDL_Rect* SPR_DEAD[12] = 
	{ &SPR_PCM_0, &SPR_PCM_D1, &SPR_PCM_D2, &SPR_PCM_D3, &SPR_PCM_D4, 
	  &SPR_PCM_D5, &SPR_PCM_D6, &SPR_PCM_D7, &SPR_PCM_D8, &SPR_PCM_D9, 
	  &SPR_PCM_D10, &SPR_PCM_D11 };


const int DIR_R = 0;
const int DIR_L = 1;
const int DIR_T = 2;
const int DIR_B = 3;
const int DIR_S = 4;
const int DEAD  = -1;

const int MODE_SCATTER = 0;
const int MODE_CHASE = 1;
const int MODE_FRIGHT = 2;
const int MODE_STMENU = 4;
const int MODE_DEATH = 5;
const int MODE_READY = 6;
const int MODE_AGAIN = 7;

const int FMST_FRIGHT = 0;
const int FMST_BACK = 1;
const int FMST_ACTIVE = 2;

const int RG = 0; // blinky - chase direct target, scatter top right
const int PG = 1; // pinky - chase four in front (four left and four front if up), scatter top left
const int BG = 2; // inky - chase negative vector to blinky from two tiles in front of pacman
   				  // (two to left and two to top if facing front), scatter bottom right
const int OG = 3; // clyde - chase direct if within 8 blocks, otherwise scatter target, scatter bottom left

