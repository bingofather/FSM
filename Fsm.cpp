#include "Fsm.h"

#include <mutex>

#include "State.h"

using std::once_flag;
using std::call_once;
using std::unique_lock;

namespace
{
once_flag flag;
}

shared_ptr<FSM> FSM::instance = nullptr;

shared_ptr<FSM> FSM::GentInstance()
{
    call_once(flag, [] {
        instance.reset(new FSM);
    });

    return instance;
}

void FSM::BuildStateChart()
{

}

shared_ptr<State> FSM::FootPrint()
{
    lock_guard<mutex> gu(lock);
    return curState;
}

void FSM::UpdateFootPrint(shared_ptr<State> s)
{
    lock_guard<mutex> gu(lock);
    curState = s;
}

shared_ptr<State> FSM::SearchState(const string name)
{
    if (states.find(name) != states.end())
        return states[name];
    return nullptr;
}

void FSM::Birth()
{
    for (auto iter = states.begin(); iter != states.end(); ++iter)
    {
        if (iter->second->IsInitial())
        {
            iter->second->OnEnter();
            return;
        }
    }
}
    
void FSM::Feed(const Event& msg)
{
    {
        unique_lock<mutex> cvLock(eventLock);
        messageQue.push(msg);
    }

    cv.notify_all();
    return;
}
    
void FSM::Consume(const Event& event)
{
    vector<Event> availableMsg;
    {
        unique_lock<mutex> cvLock(eventLock);
        cv.wait(cvLock, [this]{
            return !messageQue.empty();
        });

        while (!messageQue.empty())
        {

            availableMsg.push_back(messageQue.front());
            messageQue.pop();
        }
    }

    for (const auto& iter : availableMsg)
    {
        if (curState)
            curState->Feed(iter);
    }
}


















