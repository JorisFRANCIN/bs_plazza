/*
** EPITECH PROJECT, 2023
** Consumer.hpp
** File description:
** .hpp file
*/

#pragma once

#ifndef CONSUMER_HPP_
    #define CONSUMER_HPP_

    #include "ISafeQueue.hpp"

template<typename T>
class Consumer {
    public:
        void operator()(SafeQueue<T>& queue) {
            while (1) {
                // int value;
                // while (!queue.tryPop(value)) {
                //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
                // }
                int value = queue.pop();
                std::cout << "Consumer " << std::this_thread::get_id() << " - Consumed value: " << value << std::endl;
            }
        }
    protected:
    private:
};

#endif /* !CONSUMER_HPP_ */
