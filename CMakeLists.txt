# Copied Cmake file from Naive Bayes project, adjusting accordingly to fit final project
# Will mirror core and visualizer separation, but instead with entity and game

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(final-project) # name TBD

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.11.1
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

# Need to add more as I add more files to the entity directory
list(APPEND ENTITY_SOURCE_FILES src/entity/obstacle.cc
                                src/entity/player.cc
                                src/entity/portal.cc)

list(APPEND SOURCE_FILES    ${ENTITY_SOURCE_FILES}
                            src/game/game_engine.cc
                            src/game/item.cc
                            src/game/level.cc
                            src/game/room.cc)

# Need to add more test files
list(APPEND TEST_FILES tests/test_game_engine.cc
        tests/test_player.cc
        tests/test_room.cc)

# This works
ci_make_app(
        APP_NAME        game
        CINDER_PATH     ${CINDER_PATH}
        SOURCES         apps/game_main.cc ${SOURCE_FILES}
        INCLUDES        include
)

# When this is configuration is ran it still goes through each test but looks very different from previous projects
# Need to fix (bring up in week0 code review?)
ci_make_app(
        APP_NAME        game-tests
        CINDER_PATH     ${CINDER_PATH}
        SOURCES tests/test_main.cc ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES        include
        LIBRARIES       catch2
)

if(MSVC)
    set_property(TARGET game-tests APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif()