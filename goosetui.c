#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <termios.h>
#include <signal.h>

/*  */
#include "goosetui.h"
#include "stack.c"

/* collection of windows and attributes */
struct GTUI_screen {
    int n_windows;    
    struct stack_t* first;
}


static unsigned int te_width;
static unsigned int te_height;
static struct window* focused_window;

static int n_screen;
static struct stack_t** screen_window_stack;

static void cleanup(void) {
    write(1, "\x1b[2J", sizeof ("\x1b[2J"));
    write(1, "\x1b[?1049l", sizeof ("\x1b[?1049l"));
    write(1, "\x1b[?25h", sizeof ("\x1b[?25h"));
    /* free pointers */
}

void resize(int i) {
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

    if (focused_window == w) {
        /* highlight */
    } 

    if (w->n_children > 0) 
        for (int x = 0; x < w->n_children; x++) {
            GTUI_draw((w->children + x));    	
}


/* w =  null -> initialize new window;
 * w = !null -> initialize a new window, exact copy of w */
GTUI_window* GTUI_window_create(GTUI_window* w) {
    if (NULL == parent) { *(screen_window_stack + n_screen) = malloc(64 * sizeof (GTUI_window)); n_windows += (!NULL == _w)? 64: NULL; }
    
    if (NULL == w) return _w;
    else 
}

int GTUI_window_destroy(GTUI_window* w, bool affect_children) {}

void GTUI_window_reposition(GTUI_window* w, bool affect_children) {}

void GTUI_window_change_color(GTUI_window* w) {}

void GTUI_window_update(GTUI_window* wsrc, GTUI_window* dsrc, int GTUI_WINDOW_UPDATE_TYPE) {}

int GTUI_read_scene_from_xml(GTUI_window* src) {}
int GTUI_read_scene_from_script(GTUI_window* src) {}
