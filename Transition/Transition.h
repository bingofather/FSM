#ifndef TRANSITION_H
#define TRANSITION_H

#include <memory>

#include "Noncopyable.h"
#include "Event.h"
#include "StateTransChain.h"
#include "State.h"

using std::weak_ptr;
using std::shared_ptr;

class State;

class Transition : public NonCopyableForAll
{
public:
    Transition(shared_ptr<State> source,
               shared_ptr<State> dest,
               EventId eventId) : from(source), to(dest), id(eventId), chain(source->Name(), dest->Name()) {}

    virtual ~Transition() = default;

public:
    virtual bool Hit(const Event& msg);
    virtual bool Trans();
    virtual void Init();
    virtual weak_ptr<State> ReportDest();
    virtual bool IsSliding() { return false; }

protected:
    virtual void Action() {}

private:
    void GeneralTrans(const StateTransChain& transChain);

protected:
    weak_ptr<State> from, to;
    const EventId id;
    StateTransChain chain;
};

#endif // TRANSITION_H
