#include <common.h>

// Budget 488 / 628 bytes

force_inline void UI_DrawSlideMeter_LowLevel(POLY_F4 *p, short posX, short posY, short length, short height, u_int color, u_long *ot)
{
	*(u_int *)&p->r0 = color;
	p->x0 = length;
	p->y0 = height;
	p->x1 = posX;
	p->y1 = height;
	p->x2 = length;
	p->y2 = posY;
	p->x3 = posX;
	p->y3 = posY;

	*(int *)p = *ot | 0x5000000;
	*ot = (u_int)p & 0xffffff;
}

void DECOMP_UI_DrawSlideMeter(short posX, short posY, struct Driver *driver)
{
	u_int colorAndCode;
	int maxRoom;
	struct DB *backDB;
	POLY_F4 *p;
	u_long *ot;
	short meterHeight;
	short meterLength;
	RECT box;
	int currentRoomRemaining;
	struct GameTracker *gGT = sdata->gGT;

	meterLength = 0;

	// height of bar in 1P or 2P
	meterHeight = (2 < gGT->numPlyrCurrGame) ? 3 : 7;

	// if powerslide meter is not zero
	if (driver->turbo_MeterRoomLeft != 0)
	{
		// current room remaining
		currentRoomRemaining = driver->turbo_MeterRoomLeft * 0x31;

		// max amount of room in turbo
		maxRoom = (u_int)driver->const_turboMaxRoom << 5;

		// length of rectangle is currentRoom / maxRoom
		meterLength = 0x31 - (short)(currentRoomRemaining / maxRoom);
	}
	box.x = posX - 0x31;
	box.y = posY - meterHeight;
	box.w = 0x31;
	box.h = meterHeight;

	backDB = gGT->backBuffer;
	// pointer to OT memory
	ot = gGT->tileView_UI.ptrOT;

	CTR_Box_DrawWireBox(&box, 0, ot, &backDB->primMem);

	p = backDB->primMem.curr;

	// if there is room remaining to draw
	if (p > (u_long *)backDB->primMem.endMin100)
		return;

	// increment "curr" for next draw after powerslide meter
	backDB->primMem.curr = p + 1;

	// if remaining room is more than the "low warning"
	if ((driver->const_turboLowRoomWarning << 5) < driver->turbo_MeterRoomLeft)
	{
		// set color to green
		colorAndCode = 0x2800ff00;
	}

	// if room remaining is lower than "low warning"
	else
	{
		// set color to red
		colorAndCode = 0x280000ff;
	}

	meterHeight = posY - meterHeight;

	UI_DrawSlideMeter_LowLevel(p, posX, posY, posX - meterLength, meterHeight, colorAndCode, ot);

	p = backDB->primMem.curr;

	if (p > (u_long *)backDB->primMem.endMin100)
		return;

	backDB->primMem.curr = p + 1;
	
	// GRAY
	colorAndCode = 0x28808080;

	UI_DrawSlideMeter_LowLevel(p, posX, posY, posX - 0x31, meterHeight, colorAndCode, ot);
}