set(SDL2_IMAGE_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

message(STATUS "${CMAKE_SIZEOF_VOID_P}")

#The appropriate version of the dll must be included in the .exe directory. The appropriate target machine must
#be selected in File > Settings > Toolchain > Architecture (In my case, for an intel processor, x86 for 32 bit and
#x64 for 64 bit)

set(SDL2_IMAGE_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_image.lib")

# Support both 32 and 64 bit builds
#if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
#    set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
#else ()
#    set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
#endif ()

string(STRIP "${SDL2_IMAGE_LIBRARIES}" SDL2_IMAGE_LIBRARIES)