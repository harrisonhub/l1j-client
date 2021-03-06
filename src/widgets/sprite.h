#ifndef __sprite_H
#define __sprite_H

#include <vector>

#include "resources/global_resource_template.h"
#include "sprite_motion.h"

struct sprite_action_frame
{
	short sprite;
	short sub_sprite;
	short sub_frame;
	short length;
	short audio;
};

struct sprite_action
{
	char num_frames;
	sprite_action_frame *frames;
};

struct sprite_definition
{
	sprite_action actions[72];
	short mspf;
	short shadow;
	short type;
	short attr;
	short num_clothing;
	short *clothing;
};

class sprite : public sdl_widget
{
	public:
		sprite(int x, int y, sdl_user *who);
		virtual void draw(SDL_Surface *display);
		virtual void drawat(int x, int y, SDL_Surface *display);
		~sprite();
		void load(int x, int y, int sprnum);
		void move(int x, int y, int heading);
		void change_heading(uint8_t heading);
		void kill();
		void hit();
		void attack();
		void stand();
		void set_action(int action);
		void set_weapon(char wpn);
		void reset_frame();
		screen_coord get_screen();
		static void load_generic_sprite_data();	//loads sprite data not specific to any server
		void valid_actions(char *data);
		void load_sprite_gfx(unsigned int id);
		void print_actions();
	private:
		int cur_action;
		int cur_heading;
		int cur_frame;
		int posx, posy;
		int sprite_num;
		char wpn_stat;
		char action_num;
		Uint32 change_time;
		SDL_mutex *delay_mtx;
		bool delay_loading;
		int delay_load_id;
		static server_resource<sprite_motion> sprite_gfx;
};


#endif

