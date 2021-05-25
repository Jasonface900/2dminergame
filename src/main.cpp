#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>

int WIDTH = 160;
int HEIGHT = 120;
int SCALE = 4;

bool RUNNING = true;

enum KEYS{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SHIFT, KEY_ESC
};

void launcher(){

}

void update(){
}

void render(){
}

void run(){
	while(RUNNING){
		update();
		render();
	}
}

int main()
{
	al_install_system(ALLEGRO_VERSION_INT, atexit);
	al_install_keyboard();
	al_install_mouse();

	ALLEGRO_DISPLAY *display = al_create_display(WIDTH*SCALE, HEIGHT*SCALE);
	ALLEGRO_BITMAP *predisplay = al_create_bitmap(WIDTH, HEIGHT);
	ALLEGRO_EVENT_QUEUE *eventqueue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

	al_register_event_source(eventqueue, al_get_keyboard_event_source());
	al_register_event_source(eventqueue, al_get_mouse_event_source());
	al_register_event_source(eventqueue, al_get_display_event_source(display));
	al_register_event_source(eventqueue, al_get_timer_event_source(timer));

	bool keys[] = {false, false, false, false, false, false};
	bool quit = false;

	ALLEGRO_EVENT event;
	al_start_timer(timer);

	//future gameloop
	//	handle_inputs <- start here gamer
	//	handle_updates
	//	handle_render

	while(!quit){
		al_wait_for_event(eventqueue, &event);
		switch(event.type){
		case ALLEGRO_EVENT_TIMER:
			if(keys[KEY_ESC])
				quit = true;
			break;

		case ALLEGRO_EVENT_KEY_DOWN:
			switch(event.keyboard.keycode){
			case ALLEGRO_KEY_ESCAPE:
				quit = true;
				break;
			}
			break;
		}
	}

    return 0;
}
