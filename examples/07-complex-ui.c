#define NUKLEAR_IMPLEMENTATION
#include <nuklear.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 * 1024

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_user_font font;
    static int checkbox = 0;
    static float slider = 0.5f;
    static int progress = 50;

    nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

    if (nk_begin(&ctx, "Complex UI", nk_rect(50, 50, 500, 400), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        nk_layout_row_dynamic(&ctx, 30, 2);
        nk_checkbox_label(&ctx, "Enable Feature", &checkbox);
        nk_slider_float(&ctx, 0.0f, &slider, 1.0f, 0.1f);

        nk_layout_row_dynamic(&ctx, 30, 1);
        nk_label(&ctx, "Progress Bar:", NK_TEXT_LEFT);
        nk_progress(&ctx, &progress, 100, NK_MODIFIABLE);

        nk_layout_row_dynamic(&ctx, 200, 1);
        nk_label(&ctx, "Custom Content Area", NK_TEXT_CENTERED);
    }
    nk_end(&ctx);

    nk_free(&ctx);
    free(memory);
    return 0;
}
