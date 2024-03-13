#include "DirectTransition.h"

bool DirectTransition::Hit(const Event& /*unused*/)
{
    if (!from.expired())
    {
        if (from.lock()->IsHistory())
        {
            return true;
        }
    }
    return false;
}

