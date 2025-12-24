#define NUKLEAR_IMPLEMENTATION
#include <nuklear.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 * 1024

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_user_font font;

    nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

    if (nk_begin(&ctx, "Layouts", nk_rect(50, 50, 300, 300), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        nk_layout_row_static(&ctx, 30, 100, 3);
        nk_button_label(&ctx, "Button 1");
        nk_button_label(&ctx, "Button 2");
        nk_button_label(&ctx, "Button 3");

        nk_layout_row_dynamic(&ctx, 30, 2);
        nk_label(&ctx, "Dynamic Layout", NK_TEXT_LEFT);
        nk_button_label(&ctx, "Button");
    }
    nk_end(&ctx);

    nk_free(&ctx);
    free(memory);
    return 0;
}
