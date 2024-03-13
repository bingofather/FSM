#include "Transition.h"

#include "HistoryState.h"

bool Transition::Trans()
{
    if (!(from.expired() && to.expired()))
    {        
        // restore to history
        if (to.lock()->IsHistory())
        {
            StateTransChain trans(from.lock()->Name(), dynamic_cast<HistoryState*>(to.lock().get())->Name());
            GeneralTrans(trans);
            return true;
        }
            
        //general transitio
        GeneralTrans(chain);
        
        return true;
    }

    return false;
}

void Transition::Init()
{
    if (!from.expired())
    {
        from.lock()->UpdateDirectTransitions(shared_ptr<Transition>(this));
    }
}

bool Transition::Hit(const Event& msg)
{
    return msg.id == id;
}

weak_ptr<State> Transition::ReportDest()
{
    return to;
}

void Transition::GeneralTrans(const StateTransChain& transChain)
{
    chain.ExitState();
    Action();
    chain.EnterState();
}