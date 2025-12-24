#define NUKLEAR_IMPLEMENTATION
#include <nuklear.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 * 1024

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_user_font font;
    float slider_value = 0.5f;
    int progress_value = 50;

    nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

    if (nk_begin(&ctx, "Sliders and Progress", nk_rect(50, 50, 300, 200), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        nk_layout_row_dynamic(&ctx, 30, 1);
        nk_label(&ctx, "Adjust the slider:", NK_TEXT_LEFT);
        nk_slider_float(&ctx, 0.0f, &slider_value, 1.0f, 0.1f);

        nk_label(&ctx, "Progress bar:", NK_TEXT_LEFT);
        nk_progress(&ctx, &progress_value, 100, NK_MODIFIABLE);
    }
    nk_end(&ctx);

    nk_free(&ctx);
    free(memory);
    return 0;
}
