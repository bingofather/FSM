#include "PseudoState.h"

#include "Event.h"
#include "SlideTransition.h"

using std::shared_ptr;

void PseudoState::OnEnter()
{
    for (const auto& iter : transitions)
    {
        if (iter->IsSliding())
        {
            if (dynamic_cast<SlideTransition*>(iter.get())->Hit())
            {
                iter->Trans();
                return;
            }
        }
    }
}


