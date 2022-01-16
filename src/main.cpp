#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>

#include <iostream>
#include <cmath>

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
const SDL_Rect SPR_PMGB_1  = {582,64,16,16};
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

const int RG = 0;
const int PG = 1;
const int BG = 2;
const int OG = 3;


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


const SDL_Rect G_MAZE = {0,16,224,248};

class Game {
	
	public:
	int pacman_state = 4;
	int pacman_pos_x = 112;
	int pacman_pos_y = 188;
	int pacman_frame = 0;
	int score = 0;

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
     "######.## #      # ##.######",
     "      .   #      #   .      ",
     "######.## #      # ##.######",
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
	render_sprite(SPR_PACMAN[dir][frame%3], &pcm);
}

void render_food(const char map[31][29]) {
	SDL_Rect r = {0,0,8,8};
	for (int i=0; i<31; i++) {
		for (int j=0; j<28; j++) {
			if (map[i][j] == '.') {
				r.x = j*8;
				r.y = i*8 + 16;
				render_sprite( &SPR_FOOD, &r );
			}
		}
	}
}

void render_game (Game& g) {
	// render the maze first 
	SDL_RenderCopy(ren, tex, &SPR_MAZE, &G_MAZE);

	// then render the food
	render_food(g.map);

	// finally the actors
	render_pacman(g.pacman_pos_x, g.pacman_pos_y, g.pacman_state, g.pacman_frame);
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
	std::cout << "(" << sqx << ", " << sqy << ")" << std::endl;
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

void update_game(Game& g) {
	
	int sqx = g.pacman_pos_x/8;
	int sqy = g.pacman_pos_y/8;
	int x = g.pacman_pos_x;
	int y = g.pacman_pos_y;
	int st = g.pacman_state;
	int addend = 2;

	if (g.map[sqy][sqx] == '.') {
		g.score += 10;
		std::cout << "incr score" << std::endl;
		g.map[sqy][sqx] = ' '; 
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

int main() {
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

		game.pacman_frame = (game.pacman_frame+1) % 12;
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
