#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define SCALE 2

SDL_Texture* tex;
SDL_Renderer* ren;

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

const int GHOSTS[] = {RG, PG, BG, OG};
const SDL_Rect* SPR_EYES[4] = 
	{ &SPR_EYES_R, &SPR_EYES_L, &SPR_EYES_T, &SPR_EYES_B };
const SDL_Rect* SPR_GSCORES[4] = 
	{ &SPR_200, &SPR_400, &SPR_800, &SPR_1600 };

const SDL_Rect* SPR_DEAD[12] = 
	{ &SPR_PCM_0, &SPR_PCM_D1, &SPR_PCM_D2, &SPR_PCM_D3, &SPR_PCM_D4, 
	  &SPR_PCM_D5, &SPR_PCM_D6, &SPR_PCM_D7, &SPR_PCM_D8, &SPR_PCM_D9, 
	  &SPR_PCM_D10, &SPR_PCM_D11 };

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

const SDL_Rect G_MAZE = {0,24,224,248};
const SDL_Rect G_SCORE = {0,0,248,24};
const SDL_Rect G_STATUS = {0,272,224,16};

typedef struct Ghosts {
	int pos[4][2];
	int tgt[4][2];
	int dir[4];
	int fmstate[4];
	int speed[4];
} Ghosts;

class Game {
	
	public:
	int pacman_state = DIR_R;
	int pacman_pos_x = 112;
	int pacman_pos_y = 188;
	int clock = 0; // stores time elapsed in s
	int gmode = MODE_STMENU;
	int num_eaten = 0;
	int lives = 3;
	int hscore = 0;
	int fright_start_time = -10;
	int frame = 0;
	int score = 0;

	Ghosts gdata = {
		.pos={{14*8+4,11*8+4},{14*8+4,14*8+4},{12*8+4,14*8+4},{16*8+4,14*8+4}},
		.tgt={{0,0},{0,0},{0,0},{0,0}},
		.dir={DIR_R, DIR_T, DIR_R, DIR_L},
		.fmstate={0,0,0,0},
		.speed={2,2,2,2}
	};

	// Don't ask how much effort this took.
	char map[31][29] = {
     "############################",
     "#............##............#",
     "#.####.#####.##.#####.####.#",
     "#G####.#####.##.#####.####G#",
     "#.####.#####.##.#####.####.#",
     "#..........................#",
     "#.####.##.########.##.####.#",
     "#.####.##.########.##.####.#",
     "#......##....##....##......#",
     "######.##### ## #####.######",
     "     #.##### ## #####.#     ",
     "     #.##          ##.#     ",
     "     #.## ###--### ##.#     ",
     "######.## ###  ### ##.######",
     "      .   #      #   .      ",
     "######.## ######## ##.######",
     "     #.## ######## ##.#     ",
     "     #.##          ##.#     ",
     "     #.## ######## ##.#     ",
     "######.## ######## ##.######",
     "#............##............#",
     "#.####.#####.##.#####.####.#",
     "#.####.#####.##.#####.####.#",
     "#G..##.......  .......##..G#",
     "###.##.##.########.##.##.###",
     "###.##.##.########.##.##.###",
     "#......##....##....##......#",
     "#.##########.##.##########.#",
     "#.##########.##.##########.#",
     "#..........................#",
     "############################"
	};

	void incr_score(int incr) {
		score += incr;
		if (score > hscore) hscore = score;
	}

};

void render_sprite (const SDL_Rect* sprite, SDL_Rect* pos) {
	SDL_RenderCopy(ren, tex, sprite, pos);
	//std::cout << "Rendered sprite" << std::endl;
}

void render_pacman(int x, int y, int dir, int frame) {
	SDL_Rect pcm = {x-8, y+16, 16, 16};
	render_sprite(SPR_PACMAN[dir][(frame/2)%3], &pcm);
}

void render_num(int x, int y, int num) {
	SDL_Rect r = {x*8, y*8, 8, 8};
	if (num == 0) {
		render_sprite(SPR_SCR[0],&r);
		r.x -= 8;
		render_sprite(SPR_SCR[0],&r);
		// render two zeros
	}
	while (num > 0) {
		render_sprite(SPR_SCR[num%10],&r);
		r.x -= 8;
		num /= 10;
	}
}

void render_character(int x, int y, char t) {
	SDL_Rect r = {x*8, y*8, 8, 8};
	if ('0' <= t && t <= '9') {
		render_sprite(SPR_TXTNUM[t-'0'], &r);
	}
	else if (t == '!') render_sprite(&SPR_EXCLM, &r);
	else if (t == '~') render_sprite(&SPR_COPY, &r);
	else if (t == '-') render_sprite(&SPR_HYPHEN, &r);
	else if (t == ';') {
		r.w = 18;
		render_sprite(&SPR_PTS, &r);
		r.w = 8;
	}
	else if ('a' <= t && t <= 'z') {
		render_sprite(SPR_TXTALPH[t-'a'], &r);
	}
	else if ('A' <= t && t <= 'Z') {
		render_sprite(SPR_TXTALPH[t-'A'], &r);
	}
}

void render_text(int x, int y, std::string text) {
	for (int i=0; i<text.length(); i++) {
		render_character(x+i,y,text[i]);
	}
}

void render_food(const char map[31][29], int frame) {
	SDL_Rect r = {0,0,8,8};
	for (int i=0; i<31; i++) {
		for (int j=0; j<28; j++) {
			r.x = j*8;
			r.y = i*8 + 24;
			if (map[i][j] == '.') {
				render_sprite( &SPR_FOOD, &r );
			}
			else if (map[i][j] == 'G' && (frame/6)%2) {
				render_sprite( &SPR_POWER, &r );
			}
		}
	}
}

void render_ghosts(const Ghosts& gdata, int gmode, int fmodedelta, int frame) {
	int ghosts[] = {RG, PG, BG, OG};
	for (int g : ghosts) {
		SDL_Rect loc =  {gdata.pos[g][0]-8,gdata.pos[g][1]+16,16,16};
		if (gmode == MODE_FRIGHT) {
			if (gdata.fmstate[g] == FMST_BACK) render_sprite(SPR_EYES[gdata.dir[g]], &loc);
			else if (fmodedelta >= 3) render_sprite(SPR_FRIGHT[(frame/6)%2][(frame/2)%2], &loc);
			else render_sprite(SPR_FRIGHT[0][(frame/2)%2], &loc);
		}
		else render_sprite(SPR_GHOSTS[g][gdata.dir[g]][(frame/2)%2], &loc);
	}
}

void render_scores(int score, int hs, int frame) {
	SDL_RenderFillRect(ren, &G_SCORE);
	if ((frame/6)%2) render_text(3,0,"1UP");
	render_text(9,0,"HIGH SCORE");
	render_num(6,1,score);
	render_num(16,1,hs);
}

void render_lives(int nlives) {
	SDL_RenderFillRect(ren, &G_STATUS);
	SDL_Rect r = {16,272,16,16};
	for (int i=0; i<nlives; i++) {
		render_sprite(&SPR_PCM_L1, &r);
		r.x += 16;
	}
}

void render_game (Game& g) {

	render_scores(g.score, g.hscore, g.frame);
	render_lives(g.lives);

	if (g.gmode == MODE_STMENU) {
		SDL_RenderFillRect(ren, &G_MAZE);
		render_text(7, 14, "Push any button");
		render_text(8, 17, "1 Player only");
		render_text(1, 20, "Bonus pac-man for 10000 ;");
		render_text(4, 23, "~ 2022 Aniruddha Deb");
	}
	else {
		// render the maze first 
		SDL_RenderCopy(ren, tex, &SPR_MAZE, &G_MAZE);

		// then render the food 
		render_food(g.map, g.frame);

		if (g.gmode == MODE_READY) {
			render_text(9,14,"Player One");
			render_text(11,20,"Ready!");
		}
		else {
			// finally the actors
			render_pacman(g.pacman_pos_x, g.pacman_pos_y, g.pacman_state, g.frame);
			render_ghosts(g.gdata, g.gmode, g.clock - g.fright_start_time, g.frame);
		}
	}
}


void load_primary_texture() {
	int img_flags = IMG_INIT_PNG;
	bool success = true;
	if (!(IMG_Init(img_flags) & img_flags)) {
		std::cout << "SDL_Image Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	if (success) {
		SDL_Surface* surf = IMG_Load("res/sprites_transparent.png");
		tex = SDL_CreateTextureFromSurface(ren, surf);
		SDL_FreeSurface(surf);
	}
}

void switch_direction (Game& g, int key) {
	if (key == -1) return;
	if (key != -1 && g.gmode == MODE_STMENU) {
		std::cout << "In ready mode " << std::endl;
		g.gmode = MODE_READY;
		return;
	}
	if (g.gmode == MODE_STMENU || g.gmode == MODE_DEATH || g.gmode == MODE_READY ||
		g.gmode == MODE_AGAIN) return;
		
	int sqx = g.pacman_pos_x/8;
	int sqy = g.pacman_pos_y/8;
	//std::cout << "(" << sqx << ", " << sqy << ")" << std::endl;
	int new_state = -5;
	if (key == SDLK_LEFT && g.map[sqy][sqx-1] != '#') new_state = DIR_L;
	if (key == SDLK_RIGHT && g.map[sqy][sqx+1] != '#') new_state = DIR_R;
	if (key == SDLK_UP && g.map[sqy-1][sqx] != '#') new_state = DIR_T;
	if (key == SDLK_DOWN && g.map[sqy+1][sqx] != '#') new_state = DIR_B;
	if (new_state != -5 && new_state != g.pacman_state) {
		g.pacman_state = new_state;
		g.pacman_pos_x = sqx*8 + 4;
		g.pacman_pos_y = sqy*8 + 4;
	}
}

void check_pacman_collision(Game& g) {
	int sqx = g.pacman_pos_x/8;
	int sqy = g.pacman_pos_y/8;
	
	for (int i : GHOSTS) {
		int gx = g.gdata.pos[i][0]/8;
		int gy = g.gdata.pos[i][1]/8;

		if (sqx == gx && sqy == gy) {
			if (g.gmode == MODE_FRIGHT && g.gdata.fmstate[i] == FMST_FRIGHT){
				// eat ghost
				std::cout << "Eating ghost" << std::endl;
				g.gdata.fmstate[i] = FMST_BACK;
				g.gdata.speed[i] = 4;
				g.score += ((1<<(++g.num_eaten))*100);
			}
			else if ((g.gmode == MODE_CHASE || g.gmode == MODE_SCATTER) || (g.gmode == MODE_FRIGHT && g.gdata.fmstate[i] == FMST_ACTIVE)) {
				// ded
				g.lives -= 1;
				g.gmode = MODE_DEATH;
			}
		}		
	}
}


void update_pacman(Game& g) {

	check_pacman_collision(g);
	if (g.gmode == MODE_DEATH) {
		return;
	}
	int sqx = g.pacman_pos_x/8;
	int sqy = g.pacman_pos_y/8;
	if (sqx == 0 && sqy == 14 && g.pacman_state == DIR_L) {
		g.pacman_pos_x = 27*8+4;
		return;
	}
	else if (sqx == 27 && sqy == 14 && g.pacman_state == DIR_R) {
		g.pacman_pos_x = 4;
		return;
	}
	int x = g.pacman_pos_x;
	int y = g.pacman_pos_y;
	int st = g.pacman_state;
	int addend = 2;

	if (g.map[sqy][sqx] == '.') {
		g.incr_score(10);
		//std::cout << "incr score" << std::endl;
		g.map[sqy][sqx] = ' '; 
	}
	else if (g.map[sqy][sqx] == 'G') {
		// change game mode
		g.gmode = MODE_FRIGHT;
		g.map[sqy][sqx] = ' ';
		g.fright_start_time = g.clock;
		for (int i : GHOSTS) {
			g.gdata.speed[i] = 1;
		}
		g.incr_score(50);
	}

	if (x%8 <= 4 && st == DIR_L && g.map[sqy][sqx-1] == '#') addend = 0;
	if (x%8 >= 4 && st == DIR_R && g.map[sqy][sqx+1] == '#') addend = 0;
	if (y%8 <= 4 && st == DIR_T && g.map[sqy-1][sqx] == '#') addend = 0;
	if (y%8 >= 4 && st == DIR_B && g.map[sqy+1][sqx] == '#') addend = 0;

	switch (st) {
		case DIR_R: g.pacman_pos_x += addend; break;
		case DIR_L: g.pacman_pos_x -= addend; break;
		case DIR_T: g.pacman_pos_y -= addend; break;
		case DIR_B: g.pacman_pos_y += addend; break;
	}
}

void update_mode(Game& g) {
	if (g.gmode == MODE_READY && g.clock > 2) {
		g.gmode = MODE_SCATTER;
	}
	else if (g.gmode == MODE_FRIGHT && g.fright_start_time + 4 < g.clock) {
		std::cout << "Updating state" << std::endl;
		if ((g.clock-2)% 27 >= 7) g.gmode = MODE_CHASE;
		else g.gmode = MODE_SCATTER;

		g.num_eaten = 0;
		// center ghosts
		int ghosts[] = {RG, PG, BG, OG};
		for (int i : ghosts) {
			g.gdata.pos[i][0] = (g.gdata.pos[i][0]/4)*4;
			g.gdata.pos[i][1] = (g.gdata.pos[i][1]/4)*4;
			g.gdata.fmstate[i] = FMST_FRIGHT;
			g.gdata.speed[i] = 2;
		}
	}
	else if (g.gmode == MODE_SCATTER || g.gmode == MODE_CHASE) {
		if ((g.clock-2) % 27 >= 7) g.gmode = MODE_CHASE;
		else g.gmode = MODE_SCATTER;
	}
}
		
int ssq(int x, int y) { return x*x + y*y; }

int opp_dir(int dir) {
	if (dir == DIR_R) return DIR_L;
	else if (dir == DIR_L) return DIR_R;
	else if (dir == DIR_T) return DIR_B;
	else if (dir == DIR_B) return DIR_T;
	return 0;
}

void update_ghost_directions(Ghosts& dat, char map[31][29]) {
	int ghosts[] = {RG, PG, BG, OG};
	for (int i : ghosts) {
		if (dat.pos[i][0]%8 == 4 && dat.pos[i][1]%8 == 4) {
			int dir = dat.dir[i];
			int sgx = dat.pos[i][0]/8;
			int sgy = dat.pos[i][1]/8;
			int tgx = dat.tgt[i][0];
			int tgy = dat.tgt[i][1];
			//std::cout << "dir: " << dir << " sgx " << sgx << " sgy " << sgy << " tgx " << tgx << " tgy " << tgy << std::endl;
			int dists[4] = {0,0,0,0};
			dists[DIR_R] = ssq(sgx+1-tgx, sgy-tgy);
			dists[DIR_L] = ssq(sgx-1-tgx, sgy-tgy);
			dists[DIR_T] = ssq(sgx-tgx, sgy-tgy-1);
			dists[DIR_B] = ssq(sgx-tgx, sgy-tgy+1);
			dists[opp_dir(dir)] = INT_MAX;
			
			//std::cout << g.map[sgx-1][sgy-1] << g.map[sgx][sgy-1] << g.map[sgx+1][sgy-1] << std::endl;
			//std::cout << g.map[sgx-1][sgy] << g.map[sgx][sgy] << g.map[sgx+1][sgy] << std::endl;
			//std::cout << g.map[sgx-1][sgy+1] << g.map[sgx][sgy+1] << g.map[sgx+1][sgy+1] << std::endl;

			// baka! g.map has [y,x] indexing

			if (map[sgy][sgx-1] == '#') dists[DIR_L] = INT_MAX;
			if (map[sgy][sgx+1] == '#') dists[DIR_R] = INT_MAX;
			if (map[sgy-1][sgx] == '#') dists[DIR_T] = INT_MAX;
			if (map[sgy+1][sgx] == '#') dists[DIR_B] = INT_MAX;

			int midx = 0;
			for (int i=1; i<4; i++) {
				if (dists[i] < dists[midx]) midx = i;
			}

			dat.dir[i] = midx;
			//std::cout << " midx " << midx << " mval " << dists[midx] << std::endl;
		}
	}
}

void update_ghost_positions(Ghosts& dat, char map[31][29]) {
	// caclulating new directions
	update_ghost_directions(dat, map);

	int ghosts[] = {RG, PG, BG, OG};
	for (int i : ghosts) {
		if (dat.pos[i][0]/8 == 0 && dat.pos[i][1]/8 == 14 && dat.dir[i] == DIR_L) {
			dat.pos[i][0] = 27*8+4;
			continue;
		}
		else if (dat.pos[i][0]/8 == 27 && dat.pos[i][1]/8 == 14 && dat.dir[i] == DIR_R) {
			dat.pos[i][0] = 4;
			continue;
		}
		switch (dat.dir[i]) {
			case DIR_R: dat.pos[i][0] += dat.speed[i]; break;
			case DIR_L: dat.pos[i][0] -= dat.speed[i]; break;
			case DIR_T: dat.pos[i][1] -= dat.speed[i]; break;
			case DIR_B: dat.pos[i][1] += dat.speed[i]; break;
		}
	}
}

void update_ghosts(Game& g) {
	
	Ghosts& dat = g.gdata;
	int sqx = g.pacman_pos_x/8;
	int sqy = g.pacman_pos_y/8;

	if (g.gmode == MODE_SCATTER) {
		dat.tgt[RG][0] = 28; dat.tgt[RG][1] = 0;
		dat.tgt[PG][0] = 0; dat.tgt[PG][1] = 0;
		dat.tgt[BG][0] = 28; dat.tgt[BG][1] = 31;
		dat.tgt[OG][0] = 0; dat.tgt[OG][1] = 31;
	}
	else if (g.gmode == MODE_CHASE) {
		dat.tgt[RG][0] = g.pacman_pos_x/8; dat.tgt[RG][1] = g.pacman_pos_y/8;
		switch (g.pacman_state) {
			case DIR_R:
				dat.tgt[PG][0] = sqx + 4; dat.tgt[PG][1] = sqy;
				dat.tgt[BG][0] = sqx + 2 - (dat.pos[RG][0]/8-sqx-2); dat.tgt[BG][1] = sqy - (dat.pos[RG][1]/8-sqy);
				break;
			case DIR_L:
				dat.tgt[PG][0] = sqx - 4; dat.tgt[PG][1] = sqy;
				dat.tgt[BG][0] = sqx - 2 - (dat.pos[RG][0]/8-sqx+2); dat.tgt[BG][1] = sqy - (dat.pos[RG][1]/8-sqy);
				break;
			case DIR_T:
				dat.tgt[PG][0] = sqx+4; dat.tgt[PG][1] = sqy-4;
				dat.tgt[BG][0] = sqx + 2 - (dat.pos[RG][0]/8-sqx-2); dat.tgt[BG][1] = sqy - 2 - (dat.pos[RG][1]/8-sqy+2);
				break;
			case DIR_B:
				dat.tgt[PG][0] = sqx; dat.tgt[PG][1] = sqy-4;
				dat.tgt[BG][0] = sqx - (dat.pos[RG][0]/8-sqx); dat.tgt[BG][1] = sqy + 2 - (dat.pos[RG][1]/8-sqy-2);
				break;
		}

		if (ssq(sqx-dat.pos[OG][0]/8,sqy-dat.pos[OG][1]/8) < 64 ) {
			dat.tgt[OG][0] = dat.tgt[RG][0]; dat.tgt[OG][1] = dat.tgt[RG][1];
		}
		else {
			dat.tgt[OG][0] = 0; dat.tgt[OG][1] = 31;
		}

	}
	else if (g.gmode == MODE_FRIGHT) {
		int ghosts[] = {RG, PG, BG, OG};
		for (int i : ghosts) {
			// TODO return to home logic here if eaten / active logic if not eaten
			if (dat.fmstate[i] == FMST_BACK) {
				dat.tgt[i][0] = 14;
				dat.tgt[i][1] = 13;
				dat.pos[i][0] = (dat.pos[i][0]/4)*4;
				dat.pos[i][1] = (dat.pos[i][1]/4)*4;
			}
			else {
				int gx = dat.pos[i][0]/8;
				int gy = dat.pos[i][1]/8;
				int dirs[4] = {-1,-1,-1,-1};
				int ndirs = 0;
				if (g.map[gy][gx-1] != '#') dirs[ndirs++] = DIR_L;
				if (g.map[gy][gx+1] != '#') dirs[ndirs++] = DIR_R;
				if (g.map[gy-1][gx] != '#') dirs[ndirs++] = DIR_T;
				if (g.map[gy+1][gx] != '#') dirs[ndirs++] = DIR_B;
				int ridx = (int)(((float)rand()/RAND_MAX) * ndirs);

				switch(dirs[ridx]) {
					case DIR_R:
						dat.tgt[i][0] = ((gx+1)*8+4); dat.tgt[i][1] = (gy*8+4); break;
					case DIR_L:
						dat.tgt[i][0] = ((gx-1)*8+4); dat.tgt[i][1] = (gy*8+4); break;
					case DIR_T:
						dat.tgt[i][0] = ((gx)*8+4); dat.tgt[i][1] = ((gy-1)*8+4); break;
					case DIR_B:
						dat.tgt[i][0] = ((gx)*8+4); dat.tgt[i][1] = ((gy+1)*8+4); break;
				}
			}
		}
	}

	update_ghost_positions(dat, g.map);
}
	

void update_game(Game& g) {

	update_mode(g);
	if (g.gmode == MODE_SCATTER || g.gmode == MODE_FRIGHT || g.gmode == MODE_CHASE) {
		update_pacman(g);
		update_ghosts(g);
	}
}

// Minor todo's:
// add one more row at the heading

int main() {
	srand(time(nullptr));
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 448, 576, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	SDL_RenderSetScale(ren, SCALE, SCALE);

	Game game;

	const Uint8* state = SDL_GetKeyboardState(nullptr);

	load_primary_texture();

	SDL_Event e;
	SDL_SetRenderDrawColor(ren, 0,0,0,SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(ren, tex, &SPR_MAZE, &G_MAZE);
	SDL_RenderPresent(ren);

	bool quit = false;
	int fno = 0;
	int key = -1;
	while (!quit) {
		// render game to screen
		if (fno%2 == 0)
		render_game (game);

		// get events 
		if (state[SDL_SCANCODE_RIGHT]) key = SDLK_RIGHT;
		else if (state[SDL_SCANCODE_LEFT]) key = SDLK_LEFT;
		else if (state[SDL_SCANCODE_UP]) key = SDLK_UP;
		else if (state[SDL_SCANCODE_DOWN]) key = SDLK_DOWN;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
		}

		fno++;
		if (fno%4 == 0) {
			game.frame = (game.frame+1) % 12;
			if (fno%100 == 0 && game.gmode != MODE_STMENU) game.clock += 1;
			switch_direction(game, key);

			if (game.gmode == MODE_READY || game.gmode == MODE_CHASE || game.gmode == MODE_SCATTER || game.gmode == MODE_FRIGHT)
			update_game(game);
			
			SDL_RenderPresent(ren);
			key = -1;
		}

		SDL_Delay(10);	
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}
