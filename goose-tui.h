
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define POS_CENTER -1
#define POS_

enum GTUI_window_type {
    /* containers have no data */
    container = 1, 
    /* inputs expects data to be written to it */
    input = 2,
    /* is expected to be drawn with data as content */
    output = 3,
    /* when pressed, it will emit a trigger and run a callback function */
    button = 4
};

static struct v2 { uint16_t x, uint16_t y };

struct GTUI_window {
    bool is_hidden;
    bool render_each_frame;
    GTUI_window_type type;
    char* id;
    char** classes;
    char* data;
    struct v2 cached_cursor_state; 
    
    bool position_relative_to_parent;
    struct v2 pos, length;
    
    bool has_border;
    char* border_color;
    char* color;
    char* hl_color;

    GTUI_window* parent;
    GTUI_window** children;
    uint8_t n_children;

    uint8_t id_trigger;
    (void)** on_trigger;
};

/* w =  null -> initialize new window;
 * w = !null -> initialize a new window, exact copy of w */
GTUI_window* GTUI_window_create(GTUI_window* w) {
    static int n_windows;
    static GTUI_window* _w = NULL;
    if (NULL == w->parent) { void* _w = malloc(64 * sizeof (GTUI_window)); n_windows += (!NULL == _w)? 64: NULL; }
    
    if (NULL == w) return _w;
    else 
}

int GTUI_window_destroy(GTUI_window* w, bool keep_children) {}

void GTUI_window_reposition(GTUI_window* w) {}

void GTUI_window_change_color(GTUI_window* w) {}


int GTUI_read_view_from_xml(GTUI_window* src) {}
