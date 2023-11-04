# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required(VERSION ${CMAKE_VERSION})

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROEJCT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project("CLI Handler Library" VERSION 0.1.0)

# C++ Version
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(CLI_HANDLER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CLI_HANDLER_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/c0de4un/cli/")

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(SOURCES
  "${CLI_HANDLER_SRC_DIR}/CLIHandler.cpp"
  "${CLI_HANDLER_SRC_DIR}/commands/Help.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add STATIC Library-Object
add_library(cli_handler ${SOURCES})
target_include_directories(cli_handler PRIVATE ${CLI_HANDLER_INCLUDE_DIR})

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
