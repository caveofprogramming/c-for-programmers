#ifndef GRAPHICS_H_INCLUDED_
#define GRAPHICS_H_INCLUDED_

#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Functions for initialising SDL graphics with pixel access.
 *
 * Contains functions for initialising and cleaning up SDL, and for
 * running an event loop.
 */

typedef struct {
    int width;
    int height;
    int n_buffer_bytes;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t *buffer;
    uint32_t *back_buffer;
} graphics_t;

/**
 * Initialise window of specified width, height
 */
graphics_t *graphics_init(char title[], int width, int height);

/*
 * Draw pixels from g->buffer to the screen.
 */
void graphics_update(graphics_t *g);

/*
 * Check if quit has been requested by user closing window.
 * Returns false only if quit requested, otherwise true.
 * Call in a loop to keep window open. 
 * 
 */
bool graphics_process_events();

/*
 * Clean up. 
 */
void graphics_dispose(graphics_t *g);

#endif
