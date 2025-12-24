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
float font_width_calculator(nk_handle handle, float height, const char *text,
                            int len) {
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
  struct nk_user_font font;

  /* Initialize font */
  font.userdata = nk_handle_ptr(NULL);
  font.height = 13;
  font.width = font_width_calculator;

  /* Initialize GUI state */
  nk_init_fixed(&ctx, memory, MAX_MEMORY, &font);

  enum { EASY, HARD };
  static int op = EASY;
  static float value = 0.6f;
  static int i = 20;

  if (nk_begin(&ctx, "Show", nk_rect(50, 50, 220, 220),
               NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_CLOSABLE)) {
    /* Fixed widget pixel width */
    nk_layout_row_static(&ctx, 30, 80, 1);
    if (nk_button_label(&ctx, "button")) {
      /* Event handling */
    }

    /* Fixed widget window ratio width */
    nk_layout_row_dynamic(&ctx, 30, 2);
    if (nk_option_label(&ctx, "easy", op == EASY))
      op = EASY;
    if (nk_option_label(&ctx, "hard", op == HARD))
      op = HARD;

    /* Custom widget pixel width */
    nk_layout_row_begin(&ctx, NK_STATIC, 30, 2);
    {
      nk_layout_row_push(&ctx, 50);
      nk_label(&ctx, "Volume:", NK_TEXT_LEFT);
      nk_layout_row_push(&ctx, 110);
      nk_slider_float(&ctx, 0, &value, 1.0f, 0.1f);
    }
    nk_layout_row_end(&ctx);
  }
  nk_end(&ctx);

  nk_free(&ctx);
  free(memory);
  return 0;
}
