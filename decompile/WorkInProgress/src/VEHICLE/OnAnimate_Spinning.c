#include <common.h>

void OnAnimate_Spinning(struct Thread *t, struct Driver *d)
{
    u_short interp;
    char animIndex;
    int numFrames;
    int startFrame;
    struct Instance *inst;

    // get instance from thread
    inst = t->inst;

    animIndex = inst->animIndex;

    numFrames = VehAnim_Instance_GetNumAnimFrames(inst, animIndex);

    // if there are no frames
    if (numFrames <= 0)
        // quit
        return;

    // if animation is not zero
    if (animIndex)
    {
        startFrame = VehAnim_Instance_GetStartFrame(animIndex, numFrames);

        // If animType is anything but Steering/Driving
        if ((animIndex - 2) < 2)
        {
            // reset animation id and frame
            d->matrixArray = 0;
            d->matrixIndex = 0;
        }

        // if just starting the animation
        if (inst->animFrame == startFrame)
        {
            // get number of frames in animation
            numFrames = VehAnim_Instance_GetNumAnimFrames(inst, 0);

            if (numFrames <= 0)
                // quit
                return;

            // set animation to just driving
            inst->animIndex = 0;
        }

        if (animIndex != 0)
            goto ANIM_SPIN;
    }

    startFrame = 0;

    if (d->KartStates.Spinning.spinDir >= 0)
    {
        // last frame
        startFrame = numFrames - 1;
    }

ANIM_SPIN:

    // Interpolate animation frame by speed
    interp = VehMath_InterpBySpeed(inst->animFrame, 4, startFrame);

    // set animation frame
    inst->animFrame = interp;
}
