/*
** EPITECH PROJECT, 2023
** main
** File description:
** bootstrap
*/

#include "macro.hpp"
#include "ISafeQueue.hpp"
#include "Consumer.hpp"
#include "Producer.hpp"
#include "simple_thread_pool.hpp"

// int main()
// {
//     const int num_producers = 3;
//     const int num_consumers = 1;

//     SafeQueue<int> queue;

//     std::vector<std::thread> threads;

//     for (int i = 0; i < num_producers; ++i)
//         threads.emplace_back(Producer<int>(), std::ref(queue));
//     for (int i = 0; i < num_consumers; ++i)
//         threads.emplace_back(Consumer<int>(), std::ref(queue));

//     for (auto& t : threads)
//         t.join();

//     return 0;
// }

void run()
{
    thread_pool pool;
    SafeQueue<int> queue;
    std::cout << "Simple thread pool created" << std::endl;
    
    for (int i = 0; i < 1; i++) {
        Producer<int> producer;
        pool.submit(std::bind(producer, std::ref(queue)));
    }
    for (int i = 0; i < 1; i++) {
        Consumer<int> consumer;
        pool.submit(std::bind(consumer, std::ref(queue)));
    }
    for (auto& t : pool.threads)
        t.join();
    system("pause");
}

int main()
{
    run();
}