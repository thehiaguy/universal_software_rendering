#ifndef ENGINE_API_H
#define ENGINE_API_H

#include <stdint.h>
#include <stddef.h>
/* The platform fills this once per fram, then the core reads it. */
typedef struct{
	uint32_t buttons_down; /* bit i set == button i currently held */
	uint32_t buttons_pressed;/* bit i set == button i went down this frame */

	int16_t axis_x; /* signed int for the axis */
	int16_t axis_y;
}EngineInput;

/* This would be the canvas/screen, it is a 1d array of pixels. The platform owns the whole 
 * Window and the core owns every byte insdied this allocated area */

typedef struct{
	uint32_t *pixels;
	uint16_t width;
	uint16_t height;
	uint16_t stride;
	uint16_t _pad;
} EngineCanvas;

/* These would be the entry points. The core exports these three symbols. */
void engine_init(void *arena, size_t arena_size, EngineCanvas * canvas);
void engine_update(void *arena, const EngineInput *in, uint32_t dt_ms);
void engine_render(void *arena, EngineCanvas *canvas);
#endif
