#include "app/libc/print.h"
#include "app/libc/std.h"
#include "app/libdraw/draw.h"

int main()
{
    void *m = shm_open("shm-1");
    *(char *)m = 'S';

    struct mode_info mode_info;
    get_mode_info(&mode_info);

    unsigned long fbbase = fbmap();

    while (1)
    {
        draw_rect(10, 100, 150, 100, RED, fbbase, &mode_info);
        sleep(1000);
        draw_rect(10, 100, 150, 100, GREEN, fbbase, &mode_info);
        sleep(1000);
        draw_rect(10, 100, 150, 100, BLUE, fbbase, &mode_info);
        sleep(1000);
    }
}