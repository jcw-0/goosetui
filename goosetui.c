#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <termios.h>
#include <signal.h>

#include "goosetui.h"


struct { 
    
} GTUI_div;
struct {
    int n_divs;
    struct div* root_div;
} GTUI_window;


static unsigned int tern_width;
static unsigned int term_height;
static unsigned int n_windows;
static struct stack_t** window_stack;
static struct window* focused_window;
static struct div* focused_div;

static void cleanup(void) {
    write(1, "\x1b[2J", sizeof ("\x1b[2J"));
    write(1, "\x1b[?1049l", sizeof ("\x1b[?1049l"));
    write(1, "\x1b[?25h", sizeof ("\x1b[?25h"));
    /* free pointers */
}

static void resize(int i) {
    struct winsize wsz;
    ioctl(1, TIOCGWINSZ, &wsz);
    te_width  = wsz.ws_col;
    te_height = wsz.ws_row;
}

static void setup() {
    atexit(cleanup);
    signal(SIGWINCH, resize); 
    resize(0);
    screen_buffer = malloc(vt_width * vt_height);
}

int GTUI_draw(GTUI_window* w) {
    
    switch (w->type) {
	    case container:
	    case input:
	    case output:
	    case button:
	    default:
    }	    
    for (
    if (!focused_window == w) {
        
    } 

    if (w->n_children > 0) 
        for (int x = 0; x < w->n_children; x++)
            GTUI_draw((w->children + x));    	
}


/* w =  null -> initialize a new window;
 * w = !null -> initialize a new window, child of w */
GTUI_window* GTUI_window_create(GTUI_window* p) {
    if (NULL == p) { *(screen_window_stack + n_screen) = malloc(64 * sizeof (GTUI_window)); n_windows += (!NULL == _w)? 64: NULL; }
    return _w;
}

int GTUI_window_destroy(GTUI_window* w, bool affect_children) {}

void GTUI_window_reposition(GTUI_window* w, bool affect_children) {}

void GTUI_window_change_color(GTUI_window* w) {}

void GTUI_window_update(GTUI_window* wsrc, GTUI_window* dsrc, int GTUI_WINDOW_UPDATE_TYPE) {}

int GTUI_read_scene_from_xml(GTUI_window* src) {}
int GTUI_read_scene_from_script(GTUI_window* src) {}
