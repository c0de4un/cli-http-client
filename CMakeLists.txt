# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(CMAKE_VERSION 3.22)
cmake_minimum_required(VERSION ${CMAKE_VERSION})

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROEJCT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project("CLI Http Client" VERSION 0.1.0)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(SOLUTION_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(SRC_DIR "${SOLUTION_DIR}/src")
set(TESTS_DIR "${SOLUTION_DIR}/tests")

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

add_definitions(-DAPPLICATION_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_definitions(-DAPPLICATION_VERSION_MINOR=${PROJECT_VERSION_MINOR})

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(SOURCES
  "${SRC_DIR}/main.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# RESOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(WIN32_RESOURCES "${SOLUTION_DIR}/res/")

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add Executable-Object
if (WIN32 OR MSVC OR MINGW) # WINDOWS
  add_executable(exe ${SOURCES} ${WIN32_RESOURCES})
else () # LINUX, ANDROID, DARWIN
  add_executable(exe ${SOURCES})
endif ()

# Configure Executable Object
set_target_properties(exe PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${SOLUTION_DIR}/bin"
  RUNTIME_OUTPUT_NAME "http-client"
)

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
