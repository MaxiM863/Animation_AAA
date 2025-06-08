cmake_minimum_required(VERSION 3.31)

project(EngineMaxim)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(TextEngine)

add_executable(EngineMaxim main.cpp)

target_sources(EngineMaxim PRIVATE 
"../Samples/Common_Files/OS.cpp"
"../Samples/Common_Files/Camera.cpp"
"../Samples/Common_Files/CookbookSampleFramework.cpp"
"../Samples/Common_Files/OrbitingCamera.cpp")


#include(FetchContent)

#FetchContent_Declare(
#    OpenAL-lib
#    GIT_REPOSITORY https://github.com/kcat/openal-soft.git
#    GIT_TAG makemhr        
#)

#FetchContent_MakeAvailable(OpenAL-lib)

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

if(WIN32)
    
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
    target_link_libraries(EngineMaxim PUBLIC Cookbook)

    add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/../Data
                ${CMAKE_CURRENT_BINARY_DIR}/Debug/Data)

#    add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy
#            ${CMAKE_CURRENT_BINARY_DIR}/../_deps/openal-lib-build/Debug/OpenAL32.dll
#            ${CMAKE_CURRENT_BINARY_DIR}/Debug/OpenAL32.dll)

endif(WIN32)

if(UNIX)



    include(FetchContent)

    FetchContent_Declare(
        freetype
        GIT_REPOSITORY	https://github.com/freetype/freetype.git
        GIT_TAG 	320b72a
    )

    FetchContent_MakeAvailable(freetype)   
    
    find_package(X11)

    message(STATUS "X11_FOUND = ${X11_FOUND}")
    message(STATUS "X11_INCLUDE_DIR = ${X11_INCLUDE_DIR}" )
    message(STATUS "X11_LIBRARIES = ${X11_LIBRARIES}")

    if(${X11_FOUND})
        add_definitions(-DVK_USE_PLATFORM_XLIB_KHR)
    else()        
        add_definitions(-DNOT_GIT)
    endif(${X11_FOUND})

    include_directories(${X11_INCLUDE_DIR})

    link_directories(${X11_LIBRARIES})

    target_link_libraries( EngineMaxim ${X11_LIBRARIES} Cookbook freetype )

    add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/../Data
                ${CMAKE_CURRENT_BINARY_DIR}/Data)

endif(UNIX)

target_include_directories(EngineMaxim PRIVATE "../Samples/Common_Files" "../Library/Common_Files" "../Library/Source_Files" "../External" "../build/_deps/glm-src/" ${FREETYPE_INCLUDE_DIRS})