# 12h pacman

Making pacman in 12 hours

## Log

Hour 1. Setup 
- created C++ project, SDL hello world window, got pacman sprites

Hour 2-3.5. Sprites
- first sprite file was art rather than usable stuff, so tossed that out and 
  got a better file
- gridded out sprites and made defining rectangles around sprites
- rendered pacman onto the screen, alongwith animation

Hour 3.5-5. Events. Failed collision checking
- figured out scaling, transformations and some other SDL texture stuff
- Tried implementing collision checking by checking pixel value of maze. Did 
  not work out. 

Hour 5-6. Game map creation, collision detection, food and scores
- Created the game map as a text file, with food and powerups. Stored as char[][] in game
- rendered food and made scoring logic
- implemented turning logic for pacman
- implemented collision logic for pacman with game map
- saw some videos on ghost AI logic. Blinky, inky, pinky and clyde.  

## TODO
- implement ghost motion logic
- test ghost motion logic
- implement powerups
- implement eating ghosts, score sprites
- render score and high score
- (MINOR) different frequency of render loop and game loop? 
