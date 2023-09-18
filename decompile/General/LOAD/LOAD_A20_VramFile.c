#include <common.h>

void DECOMP_MEMPACK_PopState();
void DECOMP_MEMPACK_PushState();
void DECOMP_LOAD_VramFileCallback();
void* DECOMP_LOAD_ReadFile(int ptr, int type, int index, void* ptrDest, int* size, int callback);

void* DECOMP_LOAD_VramFile(void* bigfilePtr, int subfileIndex, int* ptrDestination, int* size, int callbackOrFlags)
{
	struct LoadQueueSlot lqs;
	
	// SCEA Presents, Copyright, UI Textures
	if(ptrDestination == 0)
	{
		DECOMP_MEMPACK_PushState();
	}
	
	if(callbackOrFlags == -1)
	{
		lqs.ptrBigfileCdPos = bigfilePtr;
		lqs.flags = 0;
		lqs.type = LT_VRAM;
		lqs.subfileIndex = subfileIndex;
		lqs.ptrDestination = DECOMP_LOAD_ReadFile(bigfilePtr, LT_VRAM, subfileIndex, 0, size, 0);
		lqs.size = *size;
		lqs.callback.funcPtr = 0;
		
		DECOMP_LOAD_VramFileCallback(&lqs);
		
		VSync(2);
		
		sdata->frameWhenLoadingFinished = 0;
		
		// SCEA Presents, Copyright, UI Textures
		if(ptrDestination == 0)
		{
			DECOMP_MEMPACK_PopState();
		}
		
		return;
	}
	
	if(callbackOrFlags == -2)
	{
		void* ptrDest = DECOMP_LOAD_ReadFile(bigfilePtr, LT_VRAM, subfileIndex, 0, size, DECOMP_LOAD_VramFileCallback);
		
		*ptrDestination = ptrDest;
		data.currSlot.ptrDestination = ptrDest;
		
		return ptrDest;
	}
	
	// valid callback
	
	return DECOMP_LOAD_ReadFile(bigfilePtr, LT_VRAM, subfileIndex, ptrDestination, size, DECOMP_LOAD_VramFileCallback);
}