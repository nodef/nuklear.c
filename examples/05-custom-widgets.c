#define NUKLEAR_IMPLEMENTATION
#include <nuklear.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 * 1024

void draw_custom_widget(struct nk_context *ctx) {
    nk_layout_row_dynamic(ctx, 30, 1);
    nk_label(ctx, "This is a custom widget!", NK_TEXT_CENTERED);
}

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_user_font font;

    nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

    if (nk_begin(&ctx, "Custom Widgets", nk_rect(50, 50, 300, 200), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        draw_custom_widget(&ctx);
    }
    nk_end(&ctx);

    nk_free(&ctx);
    free(memory);
    return 0;
}
