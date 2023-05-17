/*
** EPITECH PROJECT, 2023
** ISafeQueue.hpp
** File description:
** .hpp file
*/

#ifndef ISAFEQUEUE_HPP_
    #define ISAFEQUEUE_HPP_

    #include <thread>
    #include <mutex>
    #include <queue>
    #include <string>
    #include <chrono>
    #include <iostream>
    #include <condition_variable>
    #include <atomic>
    #include <functional>
    #include <future>

    #include "macro.hpp"

template<typename T>
class ISafeQueue {
public:
    virtual ~ISafeQueue() = default;
    virtual void push(T value) = 0;
    virtual bool tryPop(T& value) = 0;
    virtual T pop() = 0;
};

template<typename T>
class SafeQueue : virtual public ISafeQueue<T> {
    public:
        void push(T value) override {
            {
                std::lock_guard<std::mutex> lock(_mutex);
                _queue.push(value);
            }
            _condition.notify_one();
        }

        bool tryPop(T& value) override {
            std::lock_guard<std::mutex> lock(_mutex);

            if(_queue.empty())
                return false;
            value = _queue.front();
            _queue.pop();
            return true;
        }

        T pop() override {
            std::unique_lock<std::mutex> lock(_mutex);

            while (_queue.empty())
                _condition.wait(lock);
            T value = _queue.front();
            _queue.pop();
            return value;
        }
        std::queue<T> _queue;
    private:
        std::mutex _mutex;
        std::condition_variable _condition;
};

#endif /* !ISAFEQUEUE_HPP_ */
