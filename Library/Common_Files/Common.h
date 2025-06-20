// MIT License
//
// Copyright( c ) 2017 Packt
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Common

#ifndef COMMON
#define COMMON

#ifdef _WIN32
#include <Windows.h>

#else
#ifdef NOT_GIT 

#endif
#endif

#ifdef NOT_GIT
#include <dlfcn.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif

#ifdef __linux
#define VK_KHR_XLIB_SURFACE_EXTENSION_NAME "VK_KHR_xlib_surface"
#include <unistd.h>
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <thread>
#include <cmath>
#include <functional>
#include <memory>
#include "VulkanDestroyer.h"

namespace VulkanCookbook {

  // Vulkan library type
#ifdef _WIN32
#define LIBRARY_TYPE HMODULE
#elif defined __linux
#define LIBRARY_TYPE void*
#ifdef NOT_GIT
#undef __linux
#endif
#endif

  // OS-specific parameters
  struct WindowParameters {
#ifdef VK_USE_PLATFORM_WIN32_KHR

    HINSTANCE          HInstance;
    HWND               HWnd;
#endif

#ifdef NOT_GIT

    Display          * Dpy;
    Window             WIndow;

#endif


  };

  // Extension availability check
  bool IsExtensionSupported( std::vector<VkExtensionProperties> const & available_extensions,
                             char const * const                         extension );

} // namespace VulkanCookbook

#endif // COMMON
