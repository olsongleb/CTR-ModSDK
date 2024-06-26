#include <common.h>

void DECOMP_RB_Warpball_TurnAround(struct Thread* t)
{
  struct TrackerWeapon* tw;
  struct Instance* inst;
  unsigned short flags;
  struct GameTracker* gGT = sdata->gGT;
  short sVar3;
  short rot;
  
  tw = t->object;
  inst = t->inst;
  flags = tw->flags;
  
  if (
		// if not snap to point???
		((flags & 0x100) != 0) || 
		
		// if no driver is being chased
		(tw->driverTarget == NULL)
	  ) 
  {
    if ((flags & 4) != 0) {
     tw->flags = flags & 0xfffb | 0x208;
    }
	
	// turn around
	// velX = -velX
	// velZ = -velZ
	// velY = -velY
    tw->vel[0] = -tw->vel[0];
    tw->vel[2] = -tw->vel[2];
    tw->vel[1] = -tw->vel[1];
	
	// posX += velX
    inst->matrix.t[0] += (int)tw->vel[0] * gGT->elapsedTimeMS >> 5;
		 
	// posY += velY
    inst->matrix.t[1] += (int)tw->vel[1] * gGT->elapsedTimeMS >> 5;
		 
	// posZ += velZ
    inst->matrix.t[2] += (int)tw->vel[2] * gGT->elapsedTimeMS >> 5;
    
	// increment counter
	sVar3 = *(short *)((int)tw + 0x52) + 1;
  *(short *)((int)tw + 0x52) += 1;
    
	if (
			// if count too high
			(0x78 < sVar3) || 
			
			// pointer to driver being chased,
			// is null, so warpball is chasing nobody
			(tw->driverTarget == 0)
		) 
	{
      tw->driverParent->instBombThrow = 0;
	  
	  // play sound warpball death
      PlaySound3D(0x4f,inst);
      
	  RB_Warpball_Death(t);
    }
	
	// if attempted to turn around 3 times
    if ((*(unsigned short *)((int)tw + 0x52) & 3) == 0) 
	{
	  // move backwards on path
		
	  // start = end (current)
      tw[0x10] = tw[0xf];
	  
	  // set new end to 10 path indices ahead of current
      tw[0xf] = sdata->gGT->level1->ptr_restart_points + (unsigned int)(tw[0xf] + 10) * 0xc;
    }
	
	// rotation
    rot = ratan2((int)*(short *)tw[0xf] - inst->matrix.t[0], (int)((short *)tw[0xf])[2] - inst->matrix.t[2]);
		
	// rotation
    tw->dir[1] = rot;
  }
  return;
}
 