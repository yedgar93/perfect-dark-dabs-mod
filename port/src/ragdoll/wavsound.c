#include "rd_internal.h"
#ifdef PD_PHYSICS
bool rdWavAvailable(s32 which)
{ return false; }
void rdWavPlay(s32 which, struct prop *prop, s16 likesound)
{  }
void rdWavTick(void)
{  }
void rdWavStopAll(void)
{  }
s32 rdWavActive(void)
{ return 0; }
void rdWavMix(s16 *front, s16 *rear, u32 frames, s32 dolby)
{  }
#endif
