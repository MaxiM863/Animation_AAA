// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  01 Creating a Vulkan Instance with WSI extensions enabled

#include "01_Instance_and_Devices/compacte.h"
#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool CreateVulkanInstanceWithWsiExtensionsEnabled( std::vector<char const *> & desired_extensions,
                                                     char const * const          application_name,
                                                     VkInstance                & instance ) {
    desired_extensions.emplace_back( VK_KHR_SURFACE_EXTENSION_NAME );
    desired_extensions.emplace_back(
#ifdef VK_USE_PLATFORM_WIN32_KHR
      VK_KHR_WIN32_SURFACE_EXTENSION_NAME

#elif defined VK_USE_PLATFORM_XCB_KHR
      VK_KHR_XCB_SURFACE_EXTENSION_NAME

#elif defined VK_USE_PLATFORM_XLIB_KHR
      VK_KHR_XLIB_SURFACE_EXTENSION_NAME
#endif
    );

    return CreateVulkanInstance( desired_extensions, application_name, instance );
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  02 Creating a presentation surface

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool CreatePresentationSurface( VkInstance         instance,
                                  WindowParameters   window_parameters,
                                  VkSurfaceKHR     & presentation_surface ) {
    VkResult result;

#ifdef VK_USE_PLATFORM_WIN32_KHR

    VkWin32SurfaceCreateInfoKHR surface_create_info = {
      VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,  // VkStructureType                 sType
      nullptr,                                          // const void                    * pNext
      0,                                                // VkWin32SurfaceCreateFlagsKHR    flags
      window_parameters.HInstance,                      // HINSTANCE                       hinstance
      window_parameters.HWnd                            // HWND                            hwnd
    };

    result = vkCreateWin32SurfaceKHR( instance, &surface_create_info, nullptr, &presentation_surface );

#elif defined VK_USE_PLATFORM_XLIB_KHR

    VkXlibSurfaceCreateInfoKHR surface_create_info = {
      VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR,   // VkStructureType                 sType
      nullptr,                                          // const void                    * pNext
      0,                                                // VkXlibSurfaceCreateFlagsKHR     flags
      window_parameters.Dpy,                            // Display                       * dpy
      window_parameters.WIndow                          // Window                          window
    };

    result = vkCreateXlibSurfaceKHR( instance, &surface_create_info, nullptr, &presentation_surface );

#elif defined VK_USE_PLATFORM_XCB_KHR

    VkXcbSurfaceCreateInfoKHR surface_create_info = {
      VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR,    // VkStructureType                 sType
      nullptr,                                          // const void                    * pNext
      0,                                                // VkXcbSurfaceCreateFlagsKHR      flags
      window_parameters.Connection,                     // xcb_connection_t              * connection
      window_parameters.Window                          // xcb_window_t                    window
    };

    result = vkCreateXcbSurfaceKHR( instance, &surface_create_info, nullptr, &presentation_surface );

#endif

    if( (VK_SUCCESS != result) ||
        (VK_NULL_HANDLE == presentation_surface) ) {
      std::cout << "Could not create presentation surface." << std::endl;
      return false;
    }
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  03 Selecting a queue family that supports presentation to a given surface

#include "01_Instance_and_Devices/compacte.h"
#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool SelectQueueFamilyThatSupportsPresentationToGivenSurface( VkPhysicalDevice   physical_device,
                                                                VkSurfaceKHR       presentation_surface,
                                                                uint32_t         & queue_family_index ) {
    std::vector<VkQueueFamilyProperties> queue_families;
    if( !CheckAvailableQueueFamiliesAndTheirProperties( physical_device, queue_families ) ) {
      return false;
    }

    for( uint32_t index = 0; index < static_cast<uint32_t>(queue_families.size()); ++index ) {
      VkBool32 presentation_supported = VK_FALSE;
      VkResult result = vkGetPhysicalDeviceSurfaceSupportKHR( physical_device, index, presentation_surface, &presentation_supported );
      if( (VK_SUCCESS == result) &&
          (VK_TRUE == presentation_supported) ) {
        queue_family_index = index;
        return true;
      }
    }
    return false;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  04 Creating a logical device with WSI extensions enabled

#include "01_Instance_and_Devices/compacte.h"
#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool CreateLogicalDeviceWithWsiExtensionsEnabled( VkPhysicalDevice            physical_device,
                                                    std::vector< QueueInfo >    queue_infos,
                                                    std::vector<char const *> & desired_extensions,
                                                    VkPhysicalDeviceFeatures  * desired_features,
                                                    VkDevice                  & logical_device ) {
    desired_extensions.emplace_back( VK_KHR_SWAPCHAIN_EXTENSION_NAME );

    return CreateLogicalDevice( physical_device, queue_infos, desired_extensions, desired_features, logical_device );
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  05 Selecting a desired presentation mode

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool SelectDesiredPresentationMode( VkPhysicalDevice   physical_device,
                                      VkSurfaceKHR       presentation_surface,
                                      VkPresentModeKHR   desired_present_mode,
                                      VkPresentModeKHR & present_mode ) {
    // Enumerate supported present modes
    uint32_t present_modes_count = 0;
    VkResult result = VK_SUCCESS;

    result = vkGetPhysicalDeviceSurfacePresentModesKHR( physical_device, presentation_surface, &present_modes_count, nullptr );
    if( (VK_SUCCESS != result) ||
        (0 == present_modes_count) ) {
      std::cout << "Could not get the number of supported present modes." << std::endl;
      return false;
    }

    std::vector<VkPresentModeKHR> present_modes( present_modes_count );
    result = vkGetPhysicalDeviceSurfacePresentModesKHR( physical_device, presentation_surface, &present_modes_count, present_modes.data() );
    if( (VK_SUCCESS != result) ||
      (0 == present_modes_count) ) {
      std::cout << "Could not enumerate present modes." << std::endl;
      return false;
    }

    // Select present mode
    for( auto & current_present_mode : present_modes ) {
      if( current_present_mode == desired_present_mode ) {
        present_mode = desired_present_mode;
        return true;
      }
    }

    std::cout << "Desired present mode is not supported. Selecting default FIFO mode." << std::endl;
    for( auto & current_present_mode : present_modes ) {
      if( current_present_mode == VK_PRESENT_MODE_FIFO_KHR ) {
        present_mode = VK_PRESENT_MODE_FIFO_KHR;
        return true;
      }
    }

    std::cout << "VK_PRESENT_MODE_FIFO_KHR is not supported though it's mandatory for all drivers!" << std::endl;
    return false;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  06 Getting capabilities of a presentation surface

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool GetCapabilitiesOfPresentationSurface( VkPhysicalDevice           physical_device,
                                             VkSurfaceKHR               presentation_surface,
                                             VkSurfaceCapabilitiesKHR & surface_capabilities ) {
    VkResult result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR( physical_device, presentation_surface, &surface_capabilities );

    if( VK_SUCCESS != result ) {
      std::cout << "Could not get the capabilities of a presentation surface." << std::endl;
      return false;
    }
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  07 Selecting a number of swapchain images

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool SelectNumberOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                      uint32_t                       & number_of_images ) {
    number_of_images = surface_capabilities.minImageCount + 1;
    if( (surface_capabilities.maxImageCount > 0) &&
        (number_of_images > surface_capabilities.maxImageCount) ) {
      number_of_images = surface_capabilities.maxImageCount;
    }
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  08 Choosing a size of swapchain images

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool ChooseSizeOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                    VkExtent2D                     & size_of_images ) {
    if( 0xFFFFFFFF == surface_capabilities.currentExtent.width ) {
      size_of_images = { 640, 480 };

      if( size_of_images.width < surface_capabilities.minImageExtent.width ) {
        size_of_images.width = surface_capabilities.minImageExtent.width;
      } else if( size_of_images.width > surface_capabilities.maxImageExtent.width ) {
        size_of_images.width = surface_capabilities.maxImageExtent.width;
      }

      if( size_of_images.height < surface_capabilities.minImageExtent.height ) {
        size_of_images.height = surface_capabilities.minImageExtent.height;
      } else if( size_of_images.height > surface_capabilities.maxImageExtent.height ) {
        size_of_images.height = surface_capabilities.maxImageExtent.height;
      }
    } else {
      size_of_images = surface_capabilities.currentExtent;
    }
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  09 Selecting desired usage scenarios of swapchain images

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool SelectDesiredUsageScenariosOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                                     VkImageUsageFlags                desired_usages,
                                                     VkImageUsageFlags              & image_usage ) {
    image_usage = desired_usages & surface_capabilities.supportedUsageFlags;

    return desired_usages == image_usage;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  10 Selecting a transformation of swapchain images

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool SelectTransformationOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                              VkSurfaceTransformFlagBitsKHR    desired_transform,
                                              VkSurfaceTransformFlagBitsKHR  & surface_transform ) {
    if( surface_capabilities.supportedTransforms & desired_transform ) {
      surface_transform = desired_transform;
    } else {
      surface_transform = surface_capabilities.currentTransform;
    }
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  11 Selecting a format of swapchain images

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool SelectFormatOfSwapchainImages( VkPhysicalDevice     physical_device,
                                      VkSurfaceKHR         presentation_surface,
                                      VkSurfaceFormatKHR   desired_surface_format,
                                      VkFormat           & image_format,
                                      VkColorSpaceKHR    & image_color_space ) {
    // Enumerate supported formats
    uint32_t formats_count = 0;
    VkResult result = VK_SUCCESS;

    result = vkGetPhysicalDeviceSurfaceFormatsKHR( physical_device, presentation_surface, &formats_count, nullptr );
    if( (VK_SUCCESS != result) ||
        (0 == formats_count) ) {
      std::cout << "Could not get the number of supported surface formats." << std::endl;
      return false;
    }

    std::vector<VkSurfaceFormatKHR> surface_formats( formats_count );
    result = vkGetPhysicalDeviceSurfaceFormatsKHR( physical_device, presentation_surface, &formats_count, surface_formats.data() );
    if( (VK_SUCCESS != result) ||
        (0 == formats_count) ) {
      std::cout << "Could not enumerate supported surface formats." << std::endl;
      return false;
    }

    // Select surface format
    if( (1 == surface_formats.size()) &&
        (VK_FORMAT_UNDEFINED == surface_formats[0].format) ) {
      image_format = desired_surface_format.format;
      image_color_space = desired_surface_format.colorSpace;
      return true;
    }

    for( auto & surface_format : surface_formats ) {
      if( (desired_surface_format.format == surface_format.format) &&
          (desired_surface_format.colorSpace == surface_format.colorSpace) ) {
        image_format = desired_surface_format.format;
        image_color_space = desired_surface_format.colorSpace;
        return true;
      }
    }

    for( auto & surface_format : surface_formats ) {
      if( (desired_surface_format.format == surface_format.format) ) {
        image_format = desired_surface_format.format;
        image_color_space = surface_format.colorSpace;
        std::cout << "Desired combination of format and colorspace is not supported. Selecting other colorspace." << std::endl;
        return true;
      }
    }

    image_format = surface_formats[0].format;
    image_color_space = surface_formats[0].colorSpace;
    std::cout << "Desired format is not supported. Selecting available format - colorspace combination."<< image_format << ":" << image_color_space << std::endl;
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  12 Creating a swapchain

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool CreateSwapchain( VkDevice                        logical_device,
                        VkSurfaceKHR                    presentation_surface,
                        uint32_t                        image_count,
                        VkSurfaceFormatKHR              surface_format,
                        VkExtent2D                      image_size,
                        VkImageUsageFlags               image_usage,
                        VkSurfaceTransformFlagBitsKHR   surface_transform,
                        VkPresentModeKHR                present_mode,
                        VkSwapchainKHR                & old_swapchain,
                        VkSwapchainKHR                & swapchain ) {
    VkSwapchainCreateInfoKHR swapchain_create_info = {
      VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,  // VkStructureType                  sType
      nullptr,                                      // const void                     * pNext
      0,                                            // VkSwapchainCreateFlagsKHR        flags
      presentation_surface,                         // VkSurfaceKHR                     surface
      image_count,                                  // uint32_t                         minImageCount
      surface_format.format,                        // VkFormat                         imageFormat
      surface_format.colorSpace,                    // VkColorSpaceKHR                  imageColorSpace
      image_size,                                   // VkExtent2D                       imageExtent
      1,                                            // uint32_t                         imageArrayLayers
      image_usage,                                  // VkImageUsageFlags                imageUsage
      VK_SHARING_MODE_EXCLUSIVE,                    // VkSharingMode                    imageSharingMode
      0,                                            // uint32_t                         queueFamilyIndexCount
      nullptr,                                      // const uint32_t                 * pQueueFamilyIndices
      surface_transform,                            // VkSurfaceTransformFlagBitsKHR    preTransform
      VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,            // VkCompositeAlphaFlagBitsKHR      compositeAlpha
      present_mode,                                 // VkPresentModeKHR                 presentMode
      VK_TRUE,                                      // VkBool32                         clipped
      old_swapchain                                 // VkSwapchainKHR                   oldSwapchain
    };

    VkResult result = vkCreateSwapchainKHR( logical_device, &swapchain_create_info, nullptr, &swapchain );
    if( (VK_SUCCESS != result) ||
        (VK_NULL_HANDLE == swapchain) ) {
      std::cout << "Could not create a swapchain." << std::endl;
      return false;
    }

    if( VK_NULL_HANDLE != old_swapchain ) {
      vkDestroySwapchainKHR( logical_device, old_swapchain, nullptr );
      old_swapchain = VK_NULL_HANDLE;
    }

    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  13 Getting handles of swapchain images

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool GetHandlesOfSwapchainImages( VkDevice               logical_device,
                                    VkSwapchainKHR         swapchain,
                                    std::vector<VkImage> & swapchain_images ) {
    uint32_t images_count = 0;
    VkResult result = VK_SUCCESS;

    result = vkGetSwapchainImagesKHR( logical_device, swapchain, &images_count, nullptr );
    if( (VK_SUCCESS != result) ||
        (0 == images_count) ) {
      std::cout << "Could not get the number of swapchain images." << std::endl;
      return false;
    }

    swapchain_images.resize( images_count );
    result = vkGetSwapchainImagesKHR( logical_device, swapchain, &images_count, swapchain_images.data() );
    if( (VK_SUCCESS != result) ||
      (0 == images_count) ) {
      std::cout << "Could not enumerate swapchain images." << std::endl;
      return false;
    }

    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  14 Creating a swapchain with R8G8B8A8 format and a MAILBOX present mode

#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool CreateSwapchainWithR8G8B8A8FormatAndMailboxPresentMode( VkPhysicalDevice       physical_device,
                                                               VkSurfaceKHR           presentation_surface,
                                                               VkDevice               logical_device,
                                                               VkImageUsageFlags      swapchain_image_usage,
                                                               VkExtent2D           & image_size,
                                                               VkFormat             & image_format,
                                                               VkSwapchainKHR       & old_swapchain,
                                                               VkSwapchainKHR       & swapchain,
                                                               std::vector<VkImage> & swapchain_images ) {
    VkPresentModeKHR desired_present_mode;
    if( !SelectDesiredPresentationMode( physical_device, presentation_surface, VK_PRESENT_MODE_MAILBOX_KHR, desired_present_mode ) ) {
      return false;
    }

    VkSurfaceCapabilitiesKHR surface_capabilities;
    if( !GetCapabilitiesOfPresentationSurface( physical_device, presentation_surface, surface_capabilities ) ) {
      return false;
    }

    uint32_t number_of_images;
    if( !SelectNumberOfSwapchainImages( surface_capabilities, number_of_images ) ) {
      return false;
    }

    if( !ChooseSizeOfSwapchainImages( surface_capabilities, image_size ) ) {
      return false;
    }
    if( (0 == image_size.width) ||
        (0 == image_size.height) ) {
      return true;
    }

    VkImageUsageFlags image_usage;
    if( !SelectDesiredUsageScenariosOfSwapchainImages( surface_capabilities, swapchain_image_usage, image_usage ) ) {
      return false;
    }

    VkSurfaceTransformFlagBitsKHR surface_transform;
    SelectTransformationOfSwapchainImages( surface_capabilities, VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR, surface_transform );

    VkColorSpaceKHR image_color_space;
    if( !SelectFormatOfSwapchainImages( physical_device, presentation_surface, { VK_FORMAT_B8G8R8A8_SRGB, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR }, image_format, image_color_space ) ) {
      return false;
    }

    if( !CreateSwapchain( logical_device, presentation_surface, number_of_images, { image_format, image_color_space }, image_size, image_usage, surface_transform, desired_present_mode, old_swapchain, swapchain ) ) {
      return false;
    }

    if( !GetHandlesOfSwapchainImages( logical_device, swapchain, swapchain_images ) ) {
      return false;
    }
    return true;
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  15 Acquiring a swapchain image

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool AcquireSwapchainImage( VkDevice         logical_device,
                              VkSwapchainKHR   swapchain,
                              VkSemaphore      semaphore,
                              VkFence          fence,
                              uint32_t       & image_index ) {
    VkResult result;

    result = vkAcquireNextImageKHR( logical_device, swapchain, 2000000000, semaphore, fence, &image_index );
    switch( result ) {
      case VK_SUCCESS:
      case VK_SUBOPTIMAL_KHR:
        return true;
    default:
      return false;
    }
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  16 Presenting an image

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  bool PresentImage( VkQueue                  queue,
                     std::vector<VkSemaphore> rendering_semaphores,
                     std::vector<PresentInfo> images_to_present ) {
    VkResult result;
    std::vector<VkSwapchainKHR> swapchains;
    std::vector<uint32_t> image_indices;

    for( auto & image_to_present : images_to_present ) {
      swapchains.emplace_back( image_to_present.Swapchain );
      image_indices.emplace_back( image_to_present.ImageIndex );
    }

    VkPresentInfoKHR present_info = {
      VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,                   // VkStructureType          sType
      nullptr,                                              // const void*              pNext
      static_cast<uint32_t>(rendering_semaphores.size()),   // uint32_t                 waitSemaphoreCount
      rendering_semaphores.data(),                          // const VkSemaphore      * pWaitSemaphores
      static_cast<uint32_t>(swapchains.size()),             // uint32_t                 swapchainCount
      swapchains.data(),                                    // const VkSwapchainKHR   * pSwapchains
      image_indices.data(),                                 // const uint32_t         * pImageIndices
      nullptr                                               // VkResult*                pResults
    };

    result = vkQueuePresentKHR( queue, &present_info );
    switch( result ) {
    case VK_SUCCESS:
      return true;
    default:
      return false;
    }
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  17 Destroying a swapchain

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  void DestroySwapchain( VkDevice         logical_device,
                         VkSwapchainKHR & swapchain ) {
    if( swapchain ) {
      vkDestroySwapchainKHR( logical_device, swapchain, nullptr );
      swapchain = VK_NULL_HANDLE;
    }
  }

} // namespace VulkanCookbook
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// © Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  18 Destroying a presentation surface

#include "02_Image_Presentation/compacte.h"

namespace VulkanCookbook {

  void DestroyPresentationSurface( VkInstance     instance,
                                   VkSurfaceKHR & presentation_surface ) {
    if( presentation_surface ) {
      vkDestroySurfaceKHR( instance, presentation_surface, nullptr );
      presentation_surface = VK_NULL_HANDLE;
    }
  }

} // namespace VulkanCookbook
