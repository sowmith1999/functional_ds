add_executable(linked_list_test linked_list_test.cpp)

target_link_libraries(linked_list_test
    PRIVATE
    linked_list)

add_executable(binary_tree_test binary_tree_test.cpp)
target_link_libraries(binary_tree_test
    PRIVATE
    binary_tree)