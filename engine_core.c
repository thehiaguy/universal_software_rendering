#include "engine_api.h"

#define SCREEN_W 320 
#define SCREEN_H 240 

static uint32_t g_pixels[SCREEN_W * SCREEN_H]; /* need variable to store the pixel storage*/
static uint32_t g_frame; /* just a counter a placeholder to change the color of the frame*/

/* initializing the engine before the first frame, bsically setting everything up */
void engine_init(void *arena, size_t arena_size, EngineCanvas *canvas){
	(void)arena; (void)arena_size;
	/* we are just loading in the empty struct with variables to test if it can run */
	canvas -> pixels = g_pixels;
	canvas -> width = SCREEN_W;
	canvas -> height = SCREEN_H;
	canvas -> stride = SCREEN_W;
	g_frame = 0;
}



/* called every frame to update the engine */
void engine_update(void *arena, const EngineInput *in, uint32_t dt_ms){
	/*literally jsut counting the frames for now*/
	(void)arena; (void)in; (void)dt_ms;/* voiding these out so no warnings */
	g_frame++;
	
}



/* also called every frame but right before we update and put the current state into 
 * the pixel array*/
void engine_render(void *arena, EngineCanvas *canvas){
	(void)arena;

	/*we need to render frame stuff
	 * 1.color per frame 
	 * 2.total frames we have
	 * we have a lot of frames so we need uint32 varaibles to hold 
	*/
	uint32_t color = 0xFF000000u | (g_frame & 0xFFu);
	uint32_t total = (uint32_t)canvas->width * canvas->height;

	for (uint32_t i = 0; i < total; i++){
		canvas->pixels[i] = color;
	}
	
}


