#include <common.h>

void UI_VsQuipReadDriver();
void UI_BattleDrawHeadArrows();
void GAMEPAD_JogCon1(struct Driver* driver, char param_2, u_short param_3);
void howl_VolumeGet();

void Mods1_EndOfFile();
void Mods2_EndOfFile();
void Mods3_EndOfFile();
void Mods4_EndOfFile();
void Mods5_EndOfFile();
void Mods6_EndOfFile();

void ModsMain()
{
	#ifndef REBUILD_PC
	#ifdef USE_60FPS
	void ui60_entryHook(); ui60_entryHook();
	#endif
	#endif
	
	printf("\n\nMods:\n");
	
	int modSizes[6] =
	{
		// UI defrag Block1
		(int)UI_VsQuipReadDriver - (int)Mods1_EndOfFile,
		
		// UI defrag Block2
		(int)UI_BattleDrawHeadArrows - (int)Mods2_EndOfFile,
		
		// GAMEPAD defrag Block1
		(int)GAMEPAD_JogCon1 - (int)Mods3_EndOfFile,
		
		// HOWL defrag Block1
		(int)howl_VolumeGet - (int)Mods4_EndOfFile,
		
		// LOAD defrag Block1
		(int)LOAD_AppendQueue - (int)Mods5_EndOfFile,
		
		// UI defrag Block3
		(int)UI_Map_GetIconPos - (int)Mods6_EndOfFile
	};
	
	for(int i = 0; i < 6; i++)
	{
		printf("Mods%d.c: %d\n", i+1, modSizes[i]);
	}
	
	// MultiplayerWumpaHUD is never called, therefore
	// TileView_SetDrawEnv_DecalMP can be taken
	
	// add more...
	
	
	// For Oxide Fix when we get to it,
	// these Heap spaces will have thread or instance
	printf("\n\nHeap:\n");
	
	// count ModsMain, and MainStateZero, free to overwrite after runtime
	printf("ModsMain: %d\n", (int)MainRaceTrack_StartLoad - (int)ModsMain);
	printf("VBMT: %d\n", 0x80057c44-0x80057884);
	printf("RDATA: 4096, after fixing rdataPauseData\n\n");
	
	
	// add more...
}