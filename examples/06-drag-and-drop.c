#define NUKLEAR_IMPLEMENTATION
#include <nuklear.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 * 1024

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_user_font font;
    static int dragging = 0;
    static struct nk_rect drag_rect = {100, 100, 100, 100};

    nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

    if (nk_begin(&ctx, "Drag and Drop", nk_rect(50, 50, 400, 300), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        nk_layout_row_dynamic(&ctx, 30, 1);
        nk_label(&ctx, "Drag the rectangle below:", NK_TEXT_LEFT);

        nk_layout_space_begin(&ctx, NK_STATIC, 300, INT_MAX);
        nk_layout_space_push(&ctx, drag_rect);
        if (nk_input_is_mouse_hovering_rect(&ctx.input, drag_rect) && nk_input_is_mouse_down(&ctx.input, NK_BUTTON_LEFT)) {
            dragging = 1;
        }
        if (dragging && nk_input_is_mouse_down(&ctx.input, NK_BUTTON_LEFT)) {
            drag_rect.x = ctx.input.mouse.pos.x - drag_rect.w / 2;
            drag_rect.y = ctx.input.mouse.pos.y - drag_rect.h / 2;
        } else {
            dragging = 0;
        }
        nk_fill_rect(&ctx, drag_rect, 0, nk_rgb(255, 0, 0));
        nk_layout_space_end(&ctx);
    }
    nk_end(&ctx);

    nk_free(&ctx);
    free(memory);
    return 0;
}
