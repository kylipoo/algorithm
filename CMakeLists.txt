cmake_minimum_required(VERSION 3.21)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("${PROJECT_SOURCE_DIR}/aw837_graph_count_nodes" "${PROJECT_SOURCE_DIR}/aw837_graph_count_nodes/output")
add_subdirectory("${PROJECT_SOURCE_DIR}/aw240-graph_foodchain" "${PROJECT_SOURCE_DIR}/aw240-graph_foodchain/output")
add_subdirectory("${PROJECT_SOURCE_DIR}/aw838_heap_down" "${PROJECT_SOURCE_DIR}/aw838_heap_down/output")
add_subdirectory("${PROJECT_SOURCE_DIR}/aw841_simulate_heap" "${PROJECT_SOURCE_DIR}/aw841_simulate_heap/output")


