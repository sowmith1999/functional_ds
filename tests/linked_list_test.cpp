#include <chrono>
#include <forward_list>
#include <iostream>
#include <linked_list/linked_list.hpp>
#include <random>

void test_standard();
void test_standard_self();

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    test_standard();
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by test_standard: "
              << duration.count() / 1000000.0 << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    test_standard_self();
    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by test_standard_self: "
              << duration.count() / 1000000.0 << " seconds" << std::endl;
    // LinkedList llist1;
    // // llist1.push_front(10);
    // LinkedList llist2 = llist1;
    // std::cout << llist2.get_value() << std::endl;
}

void test_standard_self()
{
    LinkedList llist;
    std::random_device rd;
    std::mt19937 generator(rd()); // Mersenne Twister engine

    // Create a uniform distribution from 1 to 100000
    std::uniform_int_distribution<int> distribution(1, 100000);

    // initializing the llist with 10000 random numbers
    for (int i = 0; i < 100000; i++) {
        int random_number = distribution(generator);
        llist.push_front(random_number);
    }

    long count = 0;
    // searching for a thousand elements
    std::random_device rand_seed;
    std::mt19937 temp_generator(rand_seed());
    for (int i = 0; i < 10000; i++) {
        int elem_search = distribution(temp_generator);
        for (Node* j = llist.get_head(); j->next != 0; j = llist.get_next()) {
            if (j->val == elem_search) {
                count++;
                break;
            }
        }
        llist.reset_head();
    }

    std::cout << "Number of elements found: " << count << std::endl;
}

void test_standard()
{
    std::forward_list<int> llist;
    std::random_device rd;
    std::mt19937 generator(rd()); // Mersenne Twister engine

    // Create a uniform distribution from 1 to 100000
    std::uniform_int_distribution<int> distribution(1, 100000);

    // initializing the llist with 10000 random numbers
    for (int i = 0; i < 100000; i++) {
        int random_number = distribution(generator);
        llist.push_front(random_number);
    }

    long count = 0;
    // searching for a thousand elements
    std::random_device rand_seed;
    std::mt19937 temp_generator(rand_seed());
    for (int i = 0; i < 10000; i++) {
        int elem_search = distribution(temp_generator);
        for (auto j = llist.begin(); j != llist.end(); ++j) {
            if (*j == elem_search) {
                count++;
                break;
            }
        }
    }
    std::cout << "Number of elements found: " << count << std::endl;

}