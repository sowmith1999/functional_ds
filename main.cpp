// This file has a bunch of things related to using std::forward_list
#include <forward_list>
#include <iostream>
#include <random>
#include <chrono>
#include <linked_list/linked_list.h>
void test_standard();
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    test_standard();
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count()/1000000.0 << " seconds" << std::endl;

    return 0;
}

void test_standard()
{
    std::forward_list<int> llist;
    std::random_device rd;
    std::mt19937 generator(rd()); // Mersenne Twister engine

    // Create a uniform distribution from 1 to 100000
    std::uniform_int_distribution<int> distribution(1, 100000);

    // initializing the llist with 10000 random numbers
    for (int i = 0; i < 100000; i++)
    {
        int random_number = distribution(generator);
        llist.push_front(random_number);
    }

    // searching for a thousand elements
    std::random_device rand_seed;
    std::mt19937 temp_generator(rand_seed());
    for (int i = 0; i < 10000; i++)
    {
        int elem_search = distribution(temp_generator);
        for (auto j = llist.begin(); j != llist.end(); ++j)
        {
            if (*j == elem_search)
            {
                break;
            }
        }
    }

    std::cout << "" << std::endl;
}