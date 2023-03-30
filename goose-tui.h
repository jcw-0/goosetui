
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>



#define GTUI_POS_CENTER              -1
#define GTUI_POS_DISTANCE_FROM_LEFT  -2
#define GTUI_POS_DISTANCE_FROM_RIGHT -3

/* triggers */
#define GTUI_TRIGGER_MOVE               -1
#define GTUI_TRIGGER_SELECT             -2
#define GTUI_TRIGGER_RESIZE             -3
#define GTUI_TRIGGER_CLOSE              -5
#define GTUI_TRIGGER_OPEN               -6

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

struct GTUI_v2 { uint16_t x, uint16_t y };

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

    uint8_t* triggers;
    (void) trigger**;
};
struct GTUI_window_attr {
    bool GTUI_window_type type;
    
}

int GTUI_window_destroy(struct GTUI_window* w, bool keep_children);
void GTUI_window_reposition(struct GTUI_window* w);
void GTUI_window_change_color(struct GTUI_window* w);
int GTUI_read_view_from_xml(struct GTUI_window* src);
