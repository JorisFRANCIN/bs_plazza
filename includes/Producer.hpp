/*
** EPITECH PROJECT, 2023
** Produer.hpp
** File description:
** .hpp file
*/

#pragma once

#ifndef PRODUCER_HPP_
    #define PRODUCER_HPP_

    #include "ISafeQueue.hpp"

template<typename T>
class Producer {
    public:
        void operator()(SafeQueue<T>& queue) {
            while (1) {
                int value = std::rand() / (RAND_MAX / 10);

                queue.push(value);
                std::cout << "Producer " << std::this_thread::get_id() << " - Produced value: " << value << std::endl;
            }
        }
    protected:
    private:
};

#endif /* !PRODUCER_HPP_ */
