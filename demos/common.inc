#include "base/timer.h"

static ret_t on_timer(const timer_info_t* timer) {
  widget_t* progress_bar = (widget_t*)timer->ctx;
  uint8_t value = (PROGRESS_BAR(progress_bar)->value + 5) % 100;
  progress_bar_set_value(progress_bar, value);

  return RET_REPEAT;
}

static ret_t on_inc(void* ctx, event_t* e) {
  widget_t* progress_bar = (widget_t*)ctx;
  uint8_t value = (PROGRESS_BAR(progress_bar)->value + 10) % 100;
  progress_bar_set_value(progress_bar, value);
  (void)e;
  return RET_OK;
}

static ret_t on_dec(void* ctx, event_t* e) {
  widget_t* progress_bar = (widget_t*)ctx;
  uint8_t value = (PROGRESS_BAR(progress_bar)->value + 90) % 100;
  progress_bar_set_value(progress_bar, value);
  (void)e;
  return RET_OK;
}

static ret_t on_ok(void* ctx, event_t* e) {
  widget_t* dialog = (widget_t*)ctx;

  dialog_quit(dialog, 0);
  (void)e;
  tk_mem_info_dump();
  return RET_OK;
}

static ret_t on_close(void* ctx, event_t* e) {
  widget_t* win = (widget_t*)ctx;
  (void)e;
  return window_close(win);
}

static ret_t on_cancel(void* ctx, event_t* e) {
  widget_t* dialog = (widget_t*)ctx;

  dialog_quit(dialog, 1);
  (void)e;
  tk_mem_info_dump();
  return RET_OK;
}
