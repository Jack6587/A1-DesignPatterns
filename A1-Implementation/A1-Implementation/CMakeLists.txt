# CMakeList.txt : CMake project for A1-Implementation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (A1-Implementation "A1-Implementation.cpp" "A1-Implementation.h" "Player.h" "Player.cpp" "Card.h" "Card.cpp" "Game.h" "Game.cpp" "CardCollection.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET A1-Implementation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
