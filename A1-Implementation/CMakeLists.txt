# CMakeList.txt : CMake project for A1-Implementation, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("A1-Implementation")

# Add source to this project's executable.
add_executable (A1-Implementation "A1-Implementation.cpp" "A1-Implementation.h" "Bank.cpp" "Bank.h" "CardCollection.h" "Card.h" "Card.cpp" "Deck.h" "Deck.cpp" "DiscardPile.h" "DiscardPile.cpp" "PlayArea.h" "PlayArea.cpp" "Player.h" "Player.cpp" "Game.h" "Game.cpp" "Cards/CannonCard.cpp" "Cards/CannonCard.h" "Cards/ChestCard.h" "Cards/ChestCard.cpp" "Cards/HookCard.h" "Cards/HookCard.cpp" "Cards/KeyCard.h" "Cards/KeyCard.cpp" "Cards/KrakenCard.cpp" "Cards/KrakenCard.h" "Cards/MapCard.h" "Cards/MapCard.cpp" "Cards/MermaidCard.cpp" "Cards/MermaidCard.h" "Cards/OracleCard.h" "Cards/OracleCard.cpp" "Cards/SwordCard.h" "Cards/SwordCard.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET A1-Implementation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
