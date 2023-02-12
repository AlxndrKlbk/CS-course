#include <ncurses.h>

enum { delay_duration = 100 };
enum { key_escape = 27 };

struct star {
    int cur_x, cur_y, dx, dy;
};

static void show_star(const struct star *s)
{
    move(s->cur_y, s->cur_x);
    addch('*');
    refresh();
}

static void hide_star(const struct star *s)
{
    move(s->cur_y, s->cur_x);
    addch(' ');
    refresh();
}

static void check(int *coord, int max)
{
    if(*coord < 0)
        *coord += max;
    else
    if(*coord > max)
        *coord -= max;
}

static void move_star(struct star *s, int max_x, int max_y)
{
    hide_star(s);
    s->cur_x += s->dx;
    check(&s->cur_x, max_x);
    s->cur_y += s->dy;
    check(&s->cur_y, max_y);
    show_star(s);
}

static void set_direction(struct star *s, int dx, int dy)
{
    s->dx = dx;
    s->dy = dy;
}

static void handle_resize(struct star *s, int *col, int *row)
{
    getmaxyx(stdscr, *row, *col);
    if(s->cur_x > *col)
        s->cur_x = *col;
    if(s->cur_y > *row)
        s->cur_y = *row;
}

int main()
{
    int row, col, key;
    struct star s;
    initscr();
    cbreak();
    timeout(delay_duration);
    keypad(stdscr, 1);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, row, col);
    s.cur_x = col/2;
    s.cur_y = row/2;
    set_direction(&s, 0, 0);
    while((key = getch()) != key_escape) {
        switch(key) {
        case ' ':
            set_direction(&s, 0, 0);
            break;
        case KEY_UP:
            set_direction(&s, 0, -1);
            break;
        case KEY_DOWN:
            set_direction(&s, 0, 1);
            break;
        case KEY_LEFT:
            set_direction(&s, -1, 0);
            break;
        case KEY_RIGHT:
            set_direction(&s, 1, 0);
            break;
        case ERR:
            move_star(&s, col-1, row-1);
            break;
        case KEY_RESIZE:
            handle_resize(&s, &col, &row);
            break;
        }
    }
    endwin();
    return 0;
}
