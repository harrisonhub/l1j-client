#ifndef __SPRITE_MOTION_H
#define __SPRITE_MOTION_H

#include "sdl_widget.h"

struct sprite_tile
{
	char x;	/**< offset in map coordinates*/
	char y;	/**< offset in mapp coordinates*/
	char h;	/**< unknown*/
	short tile;	/**< reference to the array of tiles on sprite_frame*/
};

struct sprite_frame
{
	short x1;	/**< unknown */
	short y1;	/**< unknown */
	short x2;	/**< unknown */
	short y2;	/**< unknown */
	short num_tiles;	/**< Number of tiles to draw for this frame */
	sprite_tile *tiles;	/**< The array of tiles for the frame */
};

class sprite_motion
{
	public:
		sprite_motion();
		sprite_motion(const sprite_motion &ref);
		sprite_motion(int x, int y);
		void draw(int frame, SDL_Surface *display) const;
		void drawat(int x, int y, int frame, SDL_Surface *display) const;
		~sprite_motion();
		char is_loaded() const;
		void load(int x, int y, char *filename, sdl_user *loader);
		void delay_load(int x, int y, char *filename, sdl_user *loader);
		void move(int x, int y);
		screen_coord get_screen();
	private:
		sdl_graphic **tiles;
		int num_tiles;
		
		int num_frames;
		sprite_frame *frames;
		
		//sequence and frame to draw
		int frame_num;
		
		int loc_x, loc_y;

		char loaded;
		
		SDL_mutex *delay_mtx;
		bool delay_loading;
		int delay_load_id;
		sdl_user *loader;
};


#endif

