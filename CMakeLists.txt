cmake_minimum_required(VERSION 3.20)
project(pvz_console LANGUAGES CXX)
if(NOT WIN32 OR NOT MSVC)
  message(FATAL_ERROR "This console game requires Windows and the MSVC toolchain.")
endif()
add_executable(pvz main.cpp Game.cpp Map.cpp Plant.cpp Zombie.cpp Bullet.cpp Store.cpp fengmian.cpp ui_tools.cpp)
target_compile_features(pvz PRIVATE cxx_std_17)
# Keep the existing GBK sources and Chinese console strings in code page 936.
target_compile_options(pvz PRIVATE /source-charset:.936 /execution-charset:.936 /W3)
target_compile_definitions(pvz PRIVATE _CRT_SECURE_NO_WARNINGS)
target_link_libraries(pvz PRIVATE winmm)
set(PVZ_TEXT_RESOURCES
  "Conversation content.txt" daifu.txt declaration.txt fengmian.txt
  jiangwang.txt menu.txt plant.txt zombie.txt)
file(GLOB PVZ_SOUND_RESOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.wav")
foreach(resource IN LISTS PVZ_TEXT_RESOURCES PVZ_SOUND_RESOURCES)
  if(NOT IS_ABSOLUTE "${resource}")
    set(resource "${CMAKE_CURRENT_SOURCE_DIR}/${resource}")
  endif()
  add_custom_command(TARGET pvz POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${resource}" "$<TARGET_FILE_DIR:pvz>"
    VERBATIM)
endforeach()
