#include "FinalState.h"

#include "CompositeState.h"
#include "Fsm.h"
#include "Event.h"

void FinalState::OnEnter()
{
    MakeCompleteTransition();
}

string FinalState::LookUpCompleteTransition()
{
    weak_ptr<State> p = parent;
    while (!p.expired() && !p.lock()->IsTop())
    {
        if (p.lock()->IsComposite())
        {
            if (dynamic_cast<CompositeState*>(p.lock().get())->LookUpCompleteTransition())
            {
                return string(p.lock()->Name());
            }
        }
        p = p.lock()->Parent();
    }

    return string("");
}

void FinalState::MakeCompleteTransition()
{
    string name = LookUpCompleteTransition();
    if (!name.empty())
    {
        weak_ptr<State> sp = parent;
        while (!sp.expired() && sp.lock()->Name() != name)
        {
            sp.lock()->OnExit();
            sp = sp.lock()->Parent();
        }
        Event ev;
        FSM::GentInstance()->SearchState(name)->Feed(ev);
    }
}