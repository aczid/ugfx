/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

static const ltdcConfig driverCfg = {
	480, 270,								// Width, Height (pixels)
	10, 2,									// Horizontal, Vertical sync (pixels)
	20, 2,									// Horizontal, Vertical back porch (pixels)
	10, 4,									// Horizontal, Vertical front porch (pixels)
	0,										// Sync flags
	0x000000,								// Clear color (RGB888)

	{										// Background layer config
		(LLDCOLOR_TYPE *)SDRAM_BANK_ADDR,	// Frame buffer address
		480, 270,							// Width, Height (pixels)
		480 * LTDC_PIXELBYTES,				// Line pitch (bytes)
		LTDC_PIXELFORMAT,					// Pixel format
		0, 0,								// Start pixel position (x, y)
		480, 270,							// Size of virtual layer (cx, cy)
		LTDC_COLOR_FUCHSIA,					// Default color (ARGB8888)
		0x980088,							// Color key (RGB888)
		LTDC_BLEND_FIX1_FIX2,				// Blending factors
		0,									// Palette (RGB888, can be NULL)
		0,									// Palette length
		0xFF,								// Constant alpha factor
		LTDC_LEF_ENABLE						// Layer configuration flags
	},
	LTDC_UNUSED_LAYER_CONFIG				// Foreground layer config
};

static inline void init_board(GDisplay *g) {

	// As we are not using multiple displays we set g->board to NULL as we don't use it.
	g->board = 0;

	switch(g->controllerdisplay) {
	case 0:											// Set up for Display 0
		// Your init here
		break;
	}
}

static inline void post_init_board(GDisplay* g)
{
}

static inline void set_backlight(GDisplay* g, uint8_t percent)
{
}

static inline void acquire_bus(GDisplay* g)
{
}

static inline void release_bus(GDisplay* g)
{
}

static inline void write_index(GDisplay* g, uint8_t index)
{
}

static inline void write_data(GDisplay* g, uint8_t data)
{
}

#endif /* _GDISP_LLD_BOARD_H */
