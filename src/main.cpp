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
const SDL_Rect SPR_EYES_R  = {582,80,16,16};
const SDL_Rect SPR_EYES_L  = {600,80,16,16};
const SDL_Rect SPR_EYES_T  = {616,80,16,16};
const SDL_Rect SPR_EYES_B  = {632,80,16,16};
const SDL_Rect SPR_200     = {456,128,16,16};
const SDL_Rect SPR_400     = {472,128,16,16};
const SDL_Rect SPR_800     = {488,128,16,16};
const SDL_Rect SPR_1600    = {504,128,16,16};

const int DIR_R = 0;
const int DIR_L = 1;
const int DIR_T = 2;
const int DIR_B = 3;
const int DIR_S = 4;
const int DEAD  = -1;

const int MODE_STMENU = 4;
const int MODE_SCATTER = 0;
const int MODE_CHASE = 1;
const int MODE_FRIGHT = 2;
const int MODE_EATEN = 3;
const int MODE_OVER = 4;

const int RG = 0; // blinky - chase direct target, scatter top right
const int PG = 1; // pinky - chase four in front (four left and four front if up), scatter top left
const int BG = 2; // inky - chase negative vector to blinky from two tiles in front of pacman
   				  // (two to left and two to top if facing front), scatter bottom right
const int OG = 3; // clyde - chase direct if within 8 blocks, otherwise scatter target, scatter bottom left


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

const SDL_Rect G_MAZE = {0,16,224,248};

typedef struct Ghosts {
	int pos[4][2];
	int tgt[4][2];
	int dir[4];
	int mode[4];
	int speed;
} Ghosts;

class Game {
	
	public:
	int pacman_state = 4;
	int pacman_pos_x = 112;
	int pacman_pos_y = 188;
	int clock = 0; // stores time elapsed in s
	int gmode = MODE_SCATTER;
	int fright_start_time = -10;
	int frame = 0;
	int score = 0;

	Ghosts gdata = {
		.pos={{14*8+4,11*8+4},{14*8+4,14*8+4},{12*8+4,14*8+4},{16*8+4,14*8+4}},
		.tgt={{0,0},{0,0},{0,0},{0,0}},
		.dir={DIR_R, DIR_T, DIR_R, DIR_L},
		.mode={0,0,0,0},
		.speed=2
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

};

void render_sprite (const SDL_Rect* sprite, SDL_Rect* pos) {
	SDL_RenderCopy(ren, tex, sprite, pos);
	//std::cout << "Rendered sprite" << std::endl;
}

void render_pacman(int x, int y, int dir, int frame) {
	SDL_Rect pcm = {x-8, y+8, 16, 16};
	render_sprite(SPR_PACMAN[dir][(frame/2)%3], &pcm);
}

void render_food(const char map[31][29], int frame) {
	SDL_Rect r = {0,0,8,8};
	for (int i=0; i<31; i++) {
		for (int j=0; j<28; j++) {
			r.x = j*8;
			r.y = i*8 + 16;
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
		SDL_Rect loc =  {gdata.pos[g][0]-8,gdata.pos[g][1]+8,16,16};
		if (gmode == MODE_FRIGHT) {
			if (fmodedelta >= 4) render_sprite(SPR_FRIGHT[(frame/6)%2][(frame/2)%2], &loc);
			else render_sprite(SPR_FRIGHT[0][(frame/2)%2], &loc);
		}
		else render_sprite(SPR_GHOSTS[g][gdata.dir[g]][(frame/2)%2], &loc);
	}
}

void render_game (Game& g) {
	// render the maze first 
	SDL_RenderCopy(ren, tex, &SPR_MAZE, &G_MAZE);

	// then render the food
	render_food(g.map, g.frame);

	// finally the actors
	render_pacman(g.pacman_pos_x, g.pacman_pos_y, g.pacman_state, g.frame);
	render_ghosts(g.gdata, g.gmode, g.clock - g.fright_start_time, g.frame);
}

void load_primary_texture() {
	int img_flags = IMG_INIT_PNG;
	bool success = true;
	if (!(IMG_Init(img_flags) & img_flags)) {
		std::cout << "SDL_Image Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	if (success) {
		SDL_Surface* surf = IMG_Load("res/sprites.png");
		tex = SDL_CreateTextureFromSurface(ren, surf);
		SDL_FreeSurface(surf);
	}
}

void switch_direction (Game& g, int key) {
	if (key == -1) return;
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

void update_pacman(Game& g) {
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
		g.score += 10;
		//std::cout << "incr score" << std::endl;
		g.map[sqy][sqx] = ' '; 
	}
	else if (g.map[sqy][sqx] == 'G') {
		// change game mode
		g.gmode = MODE_FRIGHT;
		g.gdata.speed = 1;
		g.map[sqy][sqx] = ' ';
		g.fright_start_time = g.clock;
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
	if (g.gmode == MODE_FRIGHT && g.fright_start_time + 5 < g.clock) {
		std::cout << "Updating state" << std::endl;
		if (g.clock % 27 >= 7) g.gmode = MODE_CHASE;
		else g.gmode = MODE_SCATTER;
		g.gdata.speed = 2;

		// center ghosts
		int ghosts[] = {RG, PG, BG, OG};
		for (int i : ghosts) {
			g.gdata.pos[i][0] = (g.gdata.pos[i][0]/4)*4;
			g.gdata.pos[i][1] = (g.gdata.pos[i][1]/4)*4;
		}
	}
	else {
		// let fright continue	
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
			case DIR_R: dat.pos[i][0] += dat.speed; break;
			case DIR_L: dat.pos[i][0] -= dat.speed; break;
			case DIR_T: dat.pos[i][1] -= dat.speed; break;
			case DIR_B: dat.pos[i][1] += dat.speed; break;
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
	else if (g.gmode == MODE_SCATTER) {
		int ghosts[] = {RG, PG, BG, OG};
		for (int i : ghosts) {
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

	update_ghost_positions(dat, g.map);
}
	

void update_game(Game& g) {

	update_pacman(g);
	update_mode(g);
	update_ghosts(g);

}

int main() {
	srand(time(nullptr));
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 448, 560, SDL_WINDOW_SHOWN);
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
	SDL_RenderCopy(ren, tex, &SPR_MAZE, &G_MAZE);
	SDL_RenderPresent(ren);

	bool quit = false;
	int fno = 0;
	while (!quit) {
		// render game to screen
		render_game (game);

		// get events 
		int key = -1;
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
		if (fno%2 == 0) game.frame = (game.frame+1) % 12;
		if (fno%40 == 0) game.clock += 1;
		switch_direction(game, key);

		update_game(game);
		
		SDL_RenderPresent(ren);

		SDL_Delay(25);	
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}
