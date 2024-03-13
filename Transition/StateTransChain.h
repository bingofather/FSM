#ifndef STATETRANSCHAIN_H
#define STATETRANSCHAIN_H

#include <memory>
#include <vector>
#include <string>

using std::weak_ptr;
using std::shared_ptr;
using std::vector;
using std::string;

class StateTransChain
{
public:
    StateTransChain(string src, string sink) : from(src), to(sink) {}

    ~StateTransChain() = default;

public:
    void ExitState();
    void EnterState();

private:
    void BuildChain();
    string FindCommonParent(const vector<string>& srcParents,
                            const vector<string>& sinkParents);

private:
    string from, to;
    vector<string> exitList;
    vector<string> enterList;
};

#endif // STATETRANSCHAIN_H
