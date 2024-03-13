#include "StateTransChain.h"

#include <algorithm>
#include <exception>

#include "Fsm.h"
#include "State.h"

using std::find;
using std::copy;
using std::reverse_copy;
using std::back_inserter;

 void StateTransChain::ExitState()
 {
    if (exitList.empty())
        BuildChain();

    for (const auto& name : exitList)
    {
        auto state = FSM::GentInstance()->SearchState(name);
        if (state)
            state->OnExit();
    }
 }
    
void StateTransChain::EnterState()
{
    if (enterList.empty())
        BuildChain();

    for (const auto& name : enterList)
    {
        auto state = FSM::GentInstance()->SearchState(name);
        if (state)
            state->OnEnter();
    }
}


void StateTransChain::BuildChain()
{
    vector<string> srcInherChain, destInherChain;
    auto sp = FSM::GentInstance()->SearchState(from);
    while (sp && !sp->IsTop())
    {
        srcInherChain.push_back(sp->Name());
        sp = sp->Parent().lock();
    }
    sp = FSM::GentInstance()->SearchState(to);
    while (sp && !sp->IsTop())
    {
        destInherChain.push_back(sp->Name());
        sp = sp->Parent().lock();
    }
    
    auto common = FindCommonParent(srcInherChain, destInherChain);
    if (!common.empty())
    {
        exitList.clear();
        copy(srcInherChain.begin(), 
             find(srcInherChain.begin(), srcInherChain.end(), common), 
             back_inserter(exitList));

        enterList.clear();
        reverse_copy(destInherChain.begin(),
                     find(destInherChain.begin(), destInherChain.end(), common),
                     back_inserter(enterList));
    }
    else
    {
        exitList.swap(srcInherChain);
        reverse_copy(destInherChain.begin(),
                     destInherChain.end(), back_inserter(enterList));
    }
}

string StateTransChain::FindCommonParent(const vector<string>& srcParents,
                                         const vector<string>& sinkParents)
{
    if (!srcParents.empty() && !sinkParents.empty())
    {
        for (const auto& srcPa : srcParents)
        {
            if (find(sinkParents.begin(), sinkParents.end(), srcPa) != 
            sinkParents.end())
            {
                auto state = FSM::GentInstance()->SearchState(srcPa);
                if (state && !state->IsTop())
                    return srcPa;
            }
        }
    }
    return string();
}