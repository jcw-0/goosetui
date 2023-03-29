
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/*  */
#include "goose-tui.h"

static unsigned int vt_width;
static unsigned int vt_height;
static uint8_t** screen_buffer_buffers;
static uint8_t* focused_screen_buffer = *buffers;

static GTUI_window* focused_window;
static GTUI_window* focused_element;

static int n_windows;

void cleanup(void) {
    say("\x1b[2J");
    say("\x1b[?1049l");
    say("\x1b[?25h");
}

void resize(int i) {
    struct winsize wsz;
    ioctl(1, TIOCGWINSZ, &wsz);
    vt_width  = wsz.ws_col;
    vt_height = wsz.ws_row;
}

static void setup() {
    atexit(cleanup);
    signal(SIGWINCH, resize); 
    resize(0);
    screen_buffer = malloc(vt_width * vt_height);
}

int GTUI_draw(GTUI_window* w, bool affect_children) {
    
    switch (w->type) {
	    case container:
	    case input:
	    case output:
	    case button:
	    default:
    }	    

    if (focused_window == w) {
        /* highlight */
    } 

    if (redraw_children && w->n_children > 0) 
        for (int x = 0; x < w->n_children; x++) {
            GTUI_draw((w->children + x));    	
}


/* w =  null -> initialize new window;
 * w = !null -> initialize a new window, exact copy of w */
GTUI_window* GTUI_window_create(GTUI_window* parent, GTUI_window* w) {
    static GTUI_window* _w = NULL;
    if (NULL == parent) { focused_screen_buffer = malloc(64 * sizeof (GTUI_window)); n_windows += (!NULL == _w)? 64: NULL; }
    
    if (NULL == w) return _w;
    else 
}

int GTUI_window_destroy(GTUI_window* w, bool affect_children) {}

void GTUI_window_reposition(GTUI_window* w, bool affect_children) {}

void GTUI_window_change_color(GTUI_window* w) {}

void GTUI_window_update(GTUI_window* wsrc, GTUI_window* dsrc, int GTUI_WINDOW_UPDATE_TYPE) {}

int GTUI_read_scene_from_xml(GTUI_window* src) {}
int GTUI_read_scene_from_script(GTUI_window* src) {}
