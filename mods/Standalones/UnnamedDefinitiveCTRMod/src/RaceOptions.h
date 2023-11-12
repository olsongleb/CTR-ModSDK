#define NUM_ROWS 4
#define MenuBoxBG_w 448
#define MenuBoxBG_x 32
#define MenuBoxBG_y 39

RECT menuBoxBG =
{
	.x = MenuBoxBG_x,
	.y = MenuBoxBG_y,
	.w = MenuBoxBG_w,
	.h = 130,
};

RECT titleSeparatorLine =
{
	.x = MenuBoxBG_x + 10,
	.y = MenuBoxBG_y + 23,
	.w = MenuBoxBG_w - 20,
	.h = 2,
};

RECT glowingcursor =
{
	.x = MenuBoxBG_x + 18,
	.y = 0,
	.w = MenuBoxBG_w - 46,
	.h = 9,
};

void RaceOptions_FuncPtr(struct MenuBox*);

struct MenuBox RaceOptions =
{
	.stringIndexTitle = 45,

	.posX_curr = SCREEN_WIDTH/2,
	.posY_curr = SCREEN_HEIGHT/2,

	.unk1 = 0,

	.state = (DISABLE_INPUT_ALLOW_FUNCPTRS | 0x800 | USE_SMALL_FONT | CENTER_ON_COORDS),

	.rows = 0,

	.funcPtr = RaceOptions_FuncPtr,

	.drawStyle = 0,

	.posX_prev = 0,
	.posY_prev = 0,

	.rowSelected = 0,

	.unk1c = 0,
	.unk1e = 0,

	.width = 448,
	.height = 130,

	.ptrNextBox_InHierarchy = 0,
	.ptrPrevBox_InHierarchy = 0,
};