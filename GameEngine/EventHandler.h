#pragma once
#include <queue>
#include "coroutine"
#include <string>
#include <mutex>
#include "Command.h"

struct promise;

struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;
};

struct promise {
    coroutine get_return_object() { return {coroutine::from_promise(*this)}; }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }

    void return_void() {
    }

    void unhandled_exception() {
    }
};

struct S {
    int i;

    coroutine f() {
        co_return;
    }
};

class EventHandler {
private:
    static std::queue<std::shared_ptr<Command>> CommandQueue;
    

public:
    static std::shared_ptr<Command> TryPop() {
        
        std::shared_ptr<Command> item = CommandQueue.front();
        if (!item->Execute()) {
            CommandQueue.pop();
        }
        return item;
    }

    static void Push(const std::shared_ptr<Command>& command) {
        CommandQueue.push(command);
    }

    bool Empty() const {
        return CommandQueue.empty();
    }
};
