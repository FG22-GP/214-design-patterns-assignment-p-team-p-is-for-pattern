#pragma once
#include <queue>
#include "coroutine"
#include <string>
#include <mutex>
#include "Command.h"

struct promise;
 
struct coroutine : std::coroutine_handle<promise>
{
    using promise_type = ::promise;
};
 
struct promise
{
    coroutine get_return_object() { return {coroutine::from_promise(*this)}; }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};
 
struct S
{
    int i;
    coroutine f()
    {
        co_return;
    }
};

class EventHandler {

private: 
    std::queue<std::shared_ptr<Command>> CommandQueue;
    std::mutex Mutex;
    std::condition_variable Condition;
    
public:
    std::shared_ptr<Command> Pop() {
        std::unique_lock<std::mutex> lock(Mutex);
        Condition.wait(lock, [this](){return !CommandQueue.empty(); });
        std::shared_ptr<Command> item = CommandQueue.front();
        CommandQueue.pop();
        item->Execute();
        return item;
    }
    void Push(const std::shared_ptr<Command>& command) {
        std::unique_lock<std::mutex> lock(Mutex);
        CommandQueue.push(command);
        Condition.notify_one();
    }

    bool Empty() const {
        return CommandQueue.empty();
    }



    

    
    
};
