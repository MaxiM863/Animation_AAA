cmake_minimum_required (VERSION 3.0)

add_library(Cookbook STATIC

"../Library/Source_Files/01_Instance_and_Devices/compacte.cpp"
"../Library/Source_Files/01_Instance_and_Devices/compacte.h"

"../Library/Source_Files/02_Image_Presentation/compacte.cpp"
"../Library/Source_Files/02_Image_Presentation/compacte.h"

"../Library/Source_Files/03_Command_Buffers_and_Synchronization/compacte.cpp"
"../Library/Source_Files/03_Command_Buffers_and_Synchronization/compacte.h"

"../Library/Source_Files/04_Resources_and_Memory/compacte.cpp"
"../Library/Source_Files/04_Resources_and_Memory/compacte.h"

"../Library/Source_Files/05_Descriptor_Sets/compacte.cpp"
"../Library/Source_Files/05_Descriptor_Sets/compacte.h"

"../Library/Source_Files/06_Render_Passes_and_Framebuffers/compacte.cpp"
"../Library/Source_Files/06_Render_Passes_and_Framebuffers/compacte.h"

"../Library/Source_Files/08_Graphics_and_Compute_Pipelines/compacte.cpp"
"../Library/Source_Files/08_Graphics_and_Compute_Pipelines/compacte.h"

"../Library/Source_Files/09_Command_Recording_and_Drawing/compacte.cpp"
"../Library/Source_Files/09_Command_Recording_and_Drawing/compacte.h"

"../Library/Source_Files/10_Helper_Recipes/compacte.cpp"
"../Library/Source_Files/10_Helper_Recipes/compacte.h"

"../Library/Common_Files/VulkanFunctions.h"
"../Library/Common_Files/VulkanFunctions.cpp"
"../Library/Common_Files/AllHeaders.h"
"../Library/Common_Files/Common.cpp"
"../Library/Common_Files/Common.h"
"../Library/Common_Files/ListOfVulkanFunctions.inl"
"../Library/Common_Files/Tools.cpp"
"../Library/Common_Files/Tools.h"
"../Library/Common_Files/VulkanDestroyer.h"
)

if(WIN32)

    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)

endif(WIN32)

if(UNIX)   
    
    find_package(X11)

    message(STATUS "X11_FOUND = ${X11_FOUND}")
    message(STATUS "X11_INCLUDE_DIR = ${X11_INCLUDE_DIR}" )
    message(STATUS "X11_LIBRARIES = ${X11_LIBRARIES}")
    
    if(X11_FOUND)
        add_definitions(-DVK_USE_PLATFORM_XLIB_KHR)
        target_compile_definitions(Cookbook PUBLIC NOT_GIT=1) 
        message(STATUS "GIT")
    else()  
        
        message(STATUS "GIT Library")
    endif()

endif(UNIX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_target_properties(Cookbook PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Cookbook PUBLIC "../Library/Source_Files" "../Library/Common_Files" "../External")