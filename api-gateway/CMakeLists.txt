cmake_minimum_required(VERSION 3.16)
project(api_gateway VERSION 1.0 LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

# ==============================================================================
# C++ Standard
# ==============================================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# ==============================================================================
# Platform
# ==============================================================================
set(REQUIRED_OS "Linux")
if(NOT CMAKE_SYSTEM_NAME STREQUAL REQUIRED_OS)
  message(FATAL_ERROR "${PROJECT_NAME} supports Linux only")
endif()


# ==============================================================================
# Sources
# ==============================================================================
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/server/server.cpp
)


# ==============================================================================
# Properties
# ==============================================================================
set(API_GATEWAY_OUTPUT_DIR
    "${PROJECT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}_${CMAKE_HOST_SYSTEM_PROCESSOR}/${PROJECT_NAME}/$<CONFIG>"
)

set_target_properties("${PROJECT_NAME}"
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    "${API_GATEWAY_OUTPUT_DIR}"
)

# ==============================================================================
# Dependencies
# ==============================================================================
find_package(Boost CONFIG REQUIRED)

target_link_libraries("${PROJECT_NAME}" PRIVATE Boost::headers)
