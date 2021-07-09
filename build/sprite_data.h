/*
 * Exported with nin10kit v1.8
 * Invocation command was nin10kit --mode=sprites --bpp=8 --for_bitmap --transparent=FF00FF ./build/sprite_data ./sprites/tomato.png 
 * Time-stamp: Friday 07/09/2021, 15:57:31
 * 
 * Image Information
 * -----------------
 * ./sprites/tomato.png 16@16
 * Transparent color: (255, 0, 255)
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#define SPRITE_DATA_PALETTE_TYPE (1 << 13)
#define SPRITE_DATA_DIMENSION_TYPE (1 << 6)

extern const unsigned short sprite_data_palette[256];
#define SPRITE_DATA_PALETTE_SIZE 512
#define SPRITE_DATA_PALETTE_LENGTH 256

extern const unsigned short sprite_data[128];
#define SPRITE_DATA_SIZE 256
#define SPRITE_DATA_LENGTH 128

#define TOMATO_PALETTE_ID (0 << 12)
#define TOMATO_SPRITE_SHAPE (0 << 14)
#define TOMATO_SPRITE_SIZE (1 << 14)
#define TOMATO_ID 512

#endif

