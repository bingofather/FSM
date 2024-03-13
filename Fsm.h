#ifndef FSM_H
#define FSM_H

#include <memory>
#include <mutex>
#include <map>
#include <string>
#include <condition_variable>
#include <queue>

#include "Event.h"
#include "Noncopyable.h"

using std::shared_ptr;
using std::mutex;
using std::lock_guard;
using std::map;
using std::string;
using std::condition_variable;
using std::queue;

class State;

class FSM : public NonCopyableForAll
{
private:
    FSM() : curState(nullptr) {}

public:
    ~FSM() = default;

public:
    static shared_ptr<FSM> GentInstance();

public:
    void BuildStateChart();
    shared_ptr<State> FootPrint();
    void UpdateFootPrint(shared_ptr<State> s);
    shared_ptr<State> SearchState(const string name);
    void Birth();
    void Feed(const Event& msg);
    void Consume(const Event& event);

private:
    shared_ptr<State> curState;
    mutex lock;
    mutex eventLock;
    map<string, shared_ptr<State> > states;
    condition_variable cv;
    mutex cvMutex;
    queue<Event> messageQue;
    static shared_ptr<FSM> instance;
};

#endif // FSM_H
