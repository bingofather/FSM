#ifndef INTERNALTRANSITION_H
#define INTERNALTRANSITION_H

#include "Transition.h"
#include "Event.h"

class InternalTransition : public Transition
{
public:
    InternalTransition(shared_ptr<State> source,
               shared_ptr<State> dest) : Transition(source, dest, INVALID) {}
    
    virtual ~InternalTransition() = default;

public:
    bool Trans() override;
};

#endif // INTERNALTRANSITION_H
