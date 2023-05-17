/*
** EPITECH PROJECT, 2023
** test
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ISafeQueue.hpp"

Test(queue, insert_values)
{
    SafeQueue<int> obj;
    obj.push(1);
    int result = obj._queue.front();
    cr_assert_eq(result, 1);
}

Test(queue, popped_value)
{
    SafeQueue<int> obj;
    int value = 0;

    obj.push(4);
    obj.push(1);
    obj.push(2);
    cr_assert_eq(obj.tryPop(value), true);
    cr_assert_eq(value, 4);
}

Test(queue, popped_value_empty)
{
    SafeQueue<int> obj;
    int value = 0;

    cr_assert_eq(obj.tryPop(value), false);
    cr_assert_eq(value, 0);
}

Test(queue, pop)
{
    SafeQueue<int> obj;
    auto f1 = [](SafeQueue<int>& obj)
    {
        obj.push(1);
    };
    auto f2 = [](SafeQueue<int>& obj)
    {
        obj.pop();
    };
    std::thread th1(f2, std::ref(obj));
    std::thread th2(f1, std::ref(obj));

    th1.join();
    th2.join();
    cr_assert_eq(obj._queue.empty(), true);
}
