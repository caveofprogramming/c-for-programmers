#ifndef GRAPHICS_H_INCLUDED_
#define GRAPHICS_H_INCLUDED_

#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Functions for initialising SDL graphics with pixel access.
 *
 * Contains functions for initialising and cleaning up SDL, and for
 * running an event loop.
 */

#define RED(color) ((color >> 24) & 0xFF)
#define GREEN(color) ((color >> 16) & 0xFF)
#define BLUE(color) ((color >> 8) & 0xFF)
#define RGB(r, g, b) ((r << 24) | (g << 16) | (b << 8))

/*
 * Run tests on the blur.
 */
void graphics_test_blur();

/*
 * Print only when DEBUG is defined.
 *
 * params:
 * message The message to print.
 * 
 */
static void dprint(const char *message);

typedef struct {
    int width;
    int height;
    int n_buffer_bytes;
    SDL_Window *window;
    SDL_Surface* screen;
    SDL_Surface* pixels;
    uint32_t *buffer;
    uint32_t *back_buffer;
} graphics_t;

/**
 * Initialise window of specified width, height
 */
graphics_t *graphics_init(char title[], int width, int height);


/*
 * Read a pixel from the buffer
 */
void graphics_set_pixel(graphics_t *g, int x, int y, uint32_t color);

/*
 * Blurs buffer
 */

void graphics_blur(graphics_t *g);

/*
 * Check if quit has been requested by user closing window.
 * Returns false only if quit requested, otherwise true.
 * Call in a loop to keep window open. 
 * 
 */
bool graphics_process_events();

/*
 * Draw the contents of the buffer held by g onto the screen. 
 */
void graphics_update(graphics_t *g);

/*
 * Clean up. 
 */
void graphics_dispose(graphics_t *g);

#endif
