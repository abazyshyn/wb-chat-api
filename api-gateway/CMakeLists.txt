cmake_minimum_required(VERSION 3.16)
project(api-gateway VERSION 1.0 LANGUAGES C CXX)
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
# Paths
# ==============================================================================
set(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BOOST_ASIO_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/asio")
set(BOOST_BEAST_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/beast")
set(BOOST_CONFIG_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/config")
set(BOOST_ASSERT_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/assert")
set(BOOST_THROW_EXCEPTION_ROOT
    "${PROJECT_ROOT_DIR}/vendor/boost/throw_exception"
)
set(BOOST_SYSTEM_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/system")
set(BOOST_CORE_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/core")
set(BOOST_TYPE_TRAITS_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/type_traits")
set(BOOST_SMART_PTR_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/smart_ptr")
set(BOOST_MP11_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/mp11")
set(BOOST_OPTIONAL_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/optional")
set(BOOST_BIND_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/bind")
set(BOOST_INTRUSIVE_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/intrusive")
set(BOOST_MOVE_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/move")
set(BOOST_LOGIC_ROOT "${PROJECT_ROOT_DIR}/vendor/boost/logic")


# ==============================================================================
# Sources
# ==============================================================================
add_executable(${PROJECT_NAME}
    src/main.cpp
)


# ==============================================================================
# Dependencies
# ==============================================================================
target_include_directories(${PROJECT_NAME} PRIVATE
    "${BOOST_ASIO_ROOT}/include"
    "${BOOST_BEAST_ROOT}/include"
    "${BOOST_CONFIG_ROOT}/include"
    "${BOOST_ASSERT_ROOT}/include"
    "${BOOST_THROW_EXCEPTION_ROOT}/include"
    "${BOOST_SYSTEM_ROOT}/include"
    "${BOOST_CORE_ROOT}/include"
    "${BOOST_TYPE_TRAITS_ROOT}/include"
    "${BOOST_SMART_PTR_ROOT}/include"
    "${BOOST_MP11_ROOT}/include"
    "${BOOST_OPTIONAL_ROOT}/include"
    "${BOOST_BIND_ROOT}/include"
    "${BOOST_INTRUSIVE_ROOT}/include"
    "${BOOST_MOVE_ROOT}/include"
    "${BOOST_LOGIC_ROOT}/include"
)
