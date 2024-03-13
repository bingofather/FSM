#ifndef DIRECTTRANSITION_H
#define DIRECTTRANSITION_H

#include "Transition.h"
#include "Event.h"

class DirectTransition : public Transition
{
public:
    DirectTransition(shared_ptr<State> source,
               shared_ptr<State> dest) : Transition(source, dest, INVALID) {}

    virtual ~DirectTransition() = default;

public:
    bool Hit(const Event& msg) override;
};

#endif