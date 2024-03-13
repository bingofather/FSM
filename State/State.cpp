#include "State.h"
#include "Fsm.h"
#include "Transition.h"

void State::OnEnter()
{
    FSM::GentInstance()->UpdateFootPrint(shared_ptr<State>(this));
}

void State::DoRoutine() {}

void State::OnExit() {}

void State::UpdateDirectTransitions(shared_ptr<Transition> jump)
{
    if (jump)
        transitions.push_back(jump);
}

void State::Feed(const Event& msg)
{
    for (const auto& iter : transitions)
    {
        if (iter->Hit(msg))
        {
            iter->Trans();
            return;
        }
    }

    if (TryObscureTrans(msg))
    {
        OnExit();
        if (!parent.expired())
            parent.lock()->Feed(msg);
    }
}

bool State::IsSimple()    { return false; }
bool State::IsComposite() { return false; }
bool State::IsHistory()   { return false; }
bool State::IsPseudo()    { return false; }
bool State::IsFinal()     { return false; }
bool State::IsTop()       { return false; }
bool State::IsInitial()   { return false; }

void State::SetParent(shared_ptr<State> p)
{
    if (p)
        parent = p;
}
string State::Name() { return name; }
weak_ptr<State> State::Parent() { return parent; }

bool State::TryObscureTrans(const Event& msg)
{
    weak_ptr<State> p = parent;
    while(!p.expired() && !p.lock()->IsTop())
    {
        if (p.lock()->TestIfAcceptEvent(msg))
        {
            return true;
        }
        p = p.lock()->Parent();
    }

    return false;
}

bool State::TestIfAcceptEvent(const Event& msg)
{
    for (const auto& transition : transitions)
    {
        if (transition->Hit(msg))
            return true;
    }
    return false;
}

