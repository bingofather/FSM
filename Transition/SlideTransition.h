#ifndef SLIDETRANSITION_H
#define SLIDETRANSITION_H

#include "Transition.h"
#include "Event.h"

class SlideTransition : public Transition
{
public:
    SlideTransition(shared_ptr<State> source,
               shared_ptr<State> dest) : Transition(source, dest, INVALID) {}

    virtual ~SlideTransition() = default;

public:
    virtual bool Hit() { return true; }
    bool IsSliding() override { return true; }
};

#endif