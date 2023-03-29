#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP2023_A5P2
{
    cnPtrQueue::cnPtrQueue(): numItems(0){
        //constructor
    }

    bool cnPtrQueue::empty() const {
        //empty
        return inStack.empty() and outStack.empty();
    }

    cnPtrQueue::size_type cnPtrQueue::size() const {
        //size
        return numItems;
    }

    CNode* cnPtrQueue::front() {
        //front
        assert(!inStack.empty() or !outStack.empty());
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    void cnPtrQueue::push(CNode* cnPtr) {
        //push
        inStack.push(cnPtr);
        numItems++;
    }

    void cnPtrQueue::pop() {
        //pop
        assert(!inStack.empty() or !outStack.empty());
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        outStack.pop();
        numItems--;
    }
}
