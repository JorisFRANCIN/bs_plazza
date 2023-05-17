/*
** EPITECH PROJECT, 2023
** simple_thread_pool.hpp
** File description:
** .hpp file
*/

#ifndef SIMPLE_THREAD_POOL_HPP_
    #define SIMPLE_THREAD_POOL_HPP_

    #include <atomic>
    #include <vector>
    #include <iostream>

    #include "ISafeQueue.hpp"

class thread_pool {
    public:
        thread_pool() : done(false) {
            int const thread_count = std::thread::hardware_concurrency();

            try {
                for (int i = 0; i != thread_count; i++)
                    threads.push_back(std::thread(&thread_pool::worker_thread, this));
            } catch (const std::exception &e) {
                done = true;
                throw;
            }
        }
        ~thread_pool() {}
        template<typename F>
        void submit(F fptr) {
            work_queue.push(std::function<void()>(fptr));
        }
        std::vector<std::thread> threads;
    private:
        // This flag will be used to terminate all threads and thus stop the thread pool
        std::atomic_bool done;
        SafeQueue<std::function<void()>> work_queue;

        void worker_thread() {
            while (!done) {
                std::function<void()> task;
                if (work_queue.tryPop(task))
                    task();
                else
                    std::this_thread::yield();
            }
        }
};


#endif /* !SIMPLE_THREAD_POOL_HPP_ */
