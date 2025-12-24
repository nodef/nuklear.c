#define NUKLEAR_IMPLEMENTATION
#include <nuklear.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 * 1024

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_user_font font;
    static int active_tab = 0;

    nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

    if (nk_begin(&ctx, "Tabs Example", nk_rect(50, 50, 400, 300), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        nk_layout_row_dynamic(&ctx, 30, 3);
        if (nk_button_label(&ctx, "Tab 1")) active_tab = 0;
        if (nk_button_label(&ctx, "Tab 2")) active_tab = 1;
        if (nk_button_label(&ctx, "Tab 3")) active_tab = 2;

        nk_layout_row_dynamic(&ctx, 200, 1);
        if (active_tab == 0) {
            nk_label(&ctx, "Content of Tab 1", NK_TEXT_CENTERED);
        } else if (active_tab == 1) {
            nk_label(&ctx, "Content of Tab 2", NK_TEXT_CENTERED);
        } else if (active_tab == 2) {
            nk_label(&ctx, "Content of Tab 3", NK_TEXT_CENTERED);
        }
    }
    nk_end(&ctx);

    nk_free(&ctx);
    free(memory);
    return 0;
}
