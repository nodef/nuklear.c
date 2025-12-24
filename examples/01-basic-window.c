#define NK_IMPLEMENTATION
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "../nuklear/nuklear.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024 * 1024

/* Custom text width calculation function */
float font_width_calculator(nk_handle handle, float height, const char *text, int len) {
    (void)handle; /* Unused */
    (void)height; /* Unused */
    float width = 0.0f;
    for (int i = 0; i < len; ++i) {
        width += 7; /* Assume each character is 7 pixels wide */
    }
    return width;
}

int main() {
    struct nk_context ctx;
    void *memory = calloc(1, MAX_MEMORY);
    struct nk_font_atlas atlas;
    struct nk_font *default_font;

    nk_init_fixed(&ctx, memory, MAX_MEMORY, NULL);

    /* Load default font */
    nk_font_atlas_init_default(&atlas);
    nk_font_atlas_begin(&atlas);
    default_font = nk_font_atlas_add_default(&atlas, 13, NULL);
    const void *image = nk_font_atlas_bake(&atlas, NULL, NULL, NK_FONT_ATLAS_RGBA32);
    nk_font_atlas_end(&atlas, nk_handle_ptr(NULL), NULL);

    /* Fully initialize the nk_user_font structure */
    default_font->handle.height = 13;
    default_font->handle.width = font_width_calculator;
    default_font->handle.userdata = nk_handle_ptr(NULL);

    /* Assign the default font to the context */
    nk_style_set_font(&ctx, &default_font->handle);

    if (nk_begin(&ctx, "Basic Window", nk_rect(50, 50, 200, 200), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE)) {
        nk_layout_row_static(&ctx, 30, 80, 1);
        if (nk_button_label(&ctx, "Click Me")) {
            printf("Button clicked!\n");
        }
    }
    nk_end(&ctx);

    nk_free(&ctx);
    nk_font_atlas_clear(&atlas);
    free(memory);
    return 0;
}
