#include "CompositeState.h"
#include "HistoryState.h"
#include "Fsm.h"
#include "Transition.h"

void CompositeState::AddKid(shared_ptr<State> kid)
{
    if (kid)
        kids.push_back(kid);
}

void CompositeState::OnEnter()
{
    for (auto& kid : kids)
    {
        if (!kid.expired())
        {
            if (kid.lock()->IsInitial())
            {
                Event ev;
                ev.id = INVALID;
                kid.lock()->Feed(ev);
                return;
            }
        }
    }
}

void CompositeState::OnExit()
{
    for (auto& kid : kids)
    {
        if (!kid.expired())
        {
            if (kid.lock()->IsHistory())
            {
                dynamic_cast<HistoryState*>(kid.lock().get())->UpdateRecord(FSM::GentInstance()->FootPrint());
            }
        }
    }
}

bool CompositeState::LookUpCompleteTransition()
{
    for (const auto& iter : transitions)
    {
        if (iter->IsSliding())
            return true;
    }
    return false;
}







