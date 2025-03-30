add_executable(c-paper-terminal main.cpp)

add_subdirectory(screens)

target_link_libraries(c-paper-terminal PRIVATE VirtualScreen)

#add_library(VirtualScreen VirtualScreen/VirtualScreen.cpp VirtualScreen/VirtualScreen.h)
# target_include_directories(VirtualScreen PRIVATE "VirtualScreen")
# target_link_libraries(BlogParser PRIVATE md4c) use this to link a library to this
