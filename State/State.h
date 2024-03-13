#ifndef STATE_H
#define STATE_H

#include <string>
#include <memory>
#include <vector>

#include "Noncopyable.h"
#include "Event.h"

using std::string;
using std::weak_ptr;
using std::shared_ptr;
using std::vector;

class Transition;

class State : public NonCopyableForAll
{
public:
    State(string stateName,
          shared_ptr<State> p) : name(stateName), parent(p) {}
    virtual ~State() = default;

public:
    virtual void OnEnter();
    virtual void DoRoutine();
    virtual void OnExit();
    virtual void UpdateDirectTransitions(shared_ptr<Transition> jump);
    virtual void Feed(const Event& msg);

public:
    virtual bool IsSimple();
    virtual bool IsComposite();
    virtual bool IsHistory();
    virtual bool IsPseudo();
    virtual bool IsFinal();
    virtual bool IsTop();
    virtual bool IsInitial();
    virtual bool IsJunction();

public:
    void SetParent(shared_ptr<State> p);
    string Name();
    weak_ptr<State> Parent();

private:
    bool TryObscureTrans(const Event& msg);
    bool TestIfAcceptEvent(const Event& msg);

protected:
    string name;
    weak_ptr<State> parent;
    vector<shared_ptr<Transition> > transitions;
};

#endif // STATE_H
