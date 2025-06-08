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

#ifndef CREATING_A_VULKAN_INSTANCE_WITH_WSI_EXTENSIONS_ENABLED
#define CREATING_A_VULKAN_INSTANCE_WITH_WSI_EXTENSIONS_ENABLED

#include "Common.h"

namespace VulkanCookbook {

  bool CreateVulkanInstanceWithWsiExtensionsEnabled( std::vector<char const *> & desired_extensions,
                                                     char const * const          application_name,
                                                     VkInstance                & instance );

} // namespace VulkanCookbook

#endif // CREATING_A_VULKAN_INSTANCE_WITH_WSI_EXTENSIONS_ENABLED
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

#ifndef CREATING_A_PRESENTATION_SURFACE
#define CREATING_A_PRESENTATION_SURFACE

#include "Common.h"

namespace VulkanCookbook {

  bool CreatePresentationSurface( VkInstance         instance,
                                  WindowParameters   window_parameters,
                                  VkSurfaceKHR     & presentation_surface );

} // namespace VulkanCookbook

#endif // CREATING_A_PRESENTATION_SURFACE
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

#ifndef SELECTING_A_QUEUE_FAMILY_THAT_SUPPORTS_PRESENTATION_TO_A_GIVEN_SURFACE
#define SELECTING_A_QUEUE_FAMILY_THAT_SUPPORTS_PRESENTATION_TO_A_GIVEN_SURFACE

#include "Common.h"

namespace VulkanCookbook {

  bool SelectQueueFamilyThatSupportsPresentationToGivenSurface( VkPhysicalDevice   physical_device,
                                                                VkSurfaceKHR       presentation_surface,
                                                                uint32_t         & queue_family_index );

} // namespace VulkanCookbook

#endif // SELECTING_A_QUEUE_FAMILY_THAT_SUPPORTS_PRESENTATION_TO_A_GIVEN_SURFACE
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

#ifndef CREATING_A_LOGICAL_DEVICE_WITH_WSI_EXTENSIONS_ENABLED
#define CREATING_A_LOGICAL_DEVICE_WITH_WSI_EXTENSIONS_ENABLED

#include "01_Instance_and_Devices/compacte.h"

namespace VulkanCookbook {

  bool CreateLogicalDeviceWithWsiExtensionsEnabled( VkPhysicalDevice            physical_device,
                                                    std::vector< QueueInfo >    queue_infos,
                                                    std::vector<char const *> & desired_extensions,
                                                    VkPhysicalDeviceFeatures  * desired_features,
                                                    VkDevice                  & logical_device );

} // namespace VulkanCookbook

#endif // CREATING_A_LOGICAL_DEVICE_WITH_WSI_EXTENSIONS_ENABLED
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

#ifndef SELECTING_A_DESIRED_PRESENTATION_MODE
#define SELECTING_A_DESIRED_PRESENTATION_MODE

#include "Common.h"

namespace VulkanCookbook {

  bool SelectDesiredPresentationMode( VkPhysicalDevice   physical_device,
                                      VkSurfaceKHR       presentation_surface,
                                      VkPresentModeKHR   desired_present_mode,
                                      VkPresentModeKHR & present_mode );

} // namespace VulkanCookbook

#endif // SELECTING_A_DESIRED_PRESENTATION_MODE
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

#ifndef GETTING_CAPABILITIES_OF_A_PRESENTATION_SURFACE
#define GETTING_CAPABILITIES_OF_A_PRESENTATION_SURFACE

#include "Common.h"

namespace VulkanCookbook {

  bool GetCapabilitiesOfPresentationSurface( VkPhysicalDevice           physical_device,
                                             VkSurfaceKHR               presentation_surface,
                                             VkSurfaceCapabilitiesKHR & surface_capabilities );

} // namespace VulkanCookbook

#endif // GETTING_CAPABILITIES_OF_A_PRESENTATION_SURFACE
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

#ifndef SELECTING_A_NUMBER_OF_SWAPCHAIN_IMAGES
#define SELECTING_A_NUMBER_OF_SWAPCHAIN_IMAGES

#include "Common.h"

namespace VulkanCookbook {

  bool SelectNumberOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                      uint32_t                       & number_of_images );

} // namespace VulkanCookbook

#endif // SELECTING_A_NUMBER_OF_SWAPCHAIN_IMAGES
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

#ifndef CHOOSING_A_SIZE_OF_SWAPCHAIN_IMAGES
#define CHOOSING_A_SIZE_OF_SWAPCHAIN_IMAGES

#include "Common.h"

namespace VulkanCookbook {

  bool ChooseSizeOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                    VkExtent2D                     & size_of_images );

} // namespace VulkanCookbook

#endif // CHOOSING_A_SIZE_OF_SWAPCHAIN_IMAGES
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

#ifndef SELECTING_DESIRED_USAGE_SCENARIOS_OF_SWAPCHAIN_IMAGES
#define SELECTING_DESIRED_USAGE_SCENARIOS_OF_SWAPCHAIN_IMAGES

#include "Common.h"

namespace VulkanCookbook {

  bool SelectDesiredUsageScenariosOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                                     VkImageUsageFlags                desired_usages,
                                                     VkImageUsageFlags              & image_usage );

} // namespace VulkanCookbook

#endif // SELECTING_DESIRED_USAGE_SCENARIOS_OF_SWAPCHAIN_IMAGES
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

#ifndef SELECTING_A_TRANSFORMATION_OF_SWAPCHAIN_IMAGES
#define SELECTING_A_TRANSFORMATION_OF_SWAPCHAIN_IMAGES

#include "Common.h"

namespace VulkanCookbook {

  bool SelectTransformationOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                              VkSurfaceTransformFlagBitsKHR    desired_transform,
                                              VkSurfaceTransformFlagBitsKHR  & surface_transform );

} // namespace VulkanCookbook

#endif // SELECTING_A_TRANSFORMATION_OF_SWAPCHAIN_IMAGES
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

#ifndef SELECTING_A_FORMAT_OF_SWAPCHAIN_IMAGES
#define SELECTING_A_FORMAT_OF_SWAPCHAIN_IMAGES

#include "Common.h"

namespace VulkanCookbook {

  bool SelectFormatOfSwapchainImages( VkPhysicalDevice     physical_device,
                                      VkSurfaceKHR         presentation_surface,
                                      VkSurfaceFormatKHR   desired_surface_format,
                                      VkFormat           & image_format,
                                      VkColorSpaceKHR    & image_color_space );

} // namespace VulkanCookbook

#endif // SELECTING_A_FORMAT_OF_SWAPCHAIN_IMAGES
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

#ifndef CREATING_A_SWAPCHAIN
#define CREATING_A_SWAPCHAIN

#include "Common.h"

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
                        VkSwapchainKHR                & swapchain );

} // namespace VulkanCookbook

#endif // CREATING_A_SWAPCHAIN
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

#ifndef GETTING_HANDLES_OF_SWAPCHAIN_IMAGES
#define GETTING_HANDLES_OF_SWAPCHAIN_IMAGES

#include "Common.h"

namespace VulkanCookbook {

  bool GetHandlesOfSwapchainImages( VkDevice               logical_device,
                                    VkSwapchainKHR         swapchain,
                                    std::vector<VkImage> & swapchain_images );

} // namespace VulkanCookbook

#endif // GETTING_HANDLES_OF_SWAPCHAIN_IMAGES
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

#ifndef CREATING_A_SWAPCHAIN_WITH_R8G8B8A8_FORMAT_AND_A_MAILBOX_PRESENT_MODE
#define CREATING_A_SWAPCHAIN_WITH_R8G8B8A8_FORMAT_AND_A_MAILBOX_PRESENT_MODE

#include "Common.h"

namespace VulkanCookbook {

  bool CreateSwapchainWithR8G8B8A8FormatAndMailboxPresentMode( VkPhysicalDevice       physical_device,
                                                               VkSurfaceKHR           presentation_surface,
                                                               VkDevice               logical_device,
                                                               VkImageUsageFlags      swapchain_image_usage,
                                                               VkExtent2D           & image_size,
                                                               VkFormat             & image_format,
                                                               VkSwapchainKHR       & old_swapchain,
                                                               VkSwapchainKHR       & swapchain,
                                                               std::vector<VkImage> & swapchain_images  );

} // namespace VulkanCookbook

#endif // CREATING_A_SWAPCHAIN_WITH_R8G8B8A8_FORMAT_AND_A_MAILBOX_PRESENT_MODE
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

#ifndef ACQUIRING_A_SWAPCHAIN_IMAGE
#define ACQUIRING_A_SWAPCHAIN_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  bool AcquireSwapchainImage( VkDevice         logical_device,
                              VkSwapchainKHR   swapchain,
                              VkSemaphore      semaphore,
                              VkFence          fence,
                              uint32_t       & image_index );

} // namespace VulkanCookbook

#endif // ACQUIRING_A_SWAPCHAIN_IMAGE
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

#ifndef PRESENTING_AN_IMAGE
#define PRESENTING_AN_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  struct PresentInfo {
    VkSwapchainKHR  Swapchain;
    uint32_t        ImageIndex;
  };

  bool PresentImage( VkQueue                  queue,
                     std::vector<VkSemaphore> rendering_semaphores,
                     std::vector<PresentInfo> images_to_present );

} // namespace VulkanCookbook

#endif // PRESENTING_AN_IMAGE
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

#ifndef DESTROYING_A_SWAPCHAIN
#define DESTROYING_A_SWAPCHAIN

#include "Common.h"

namespace VulkanCookbook {

  void DestroySwapchain( VkDevice         logical_device,
                         VkSwapchainKHR & swapchain );

} // namespace VulkanCookbook

#endif // DESTROYING_A_SWAPCHAIN
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

#ifndef DESTROYING_A_PRESENTATION_SURFACE
#define DESTROYING_A_PRESENTATION_SURFACE

#include "Common.h"

namespace VulkanCookbook {

  void DestroyPresentationSurface( VkInstance     instance,
                                   VkSurfaceKHR & presentation_surface );

} // namespace VulkanCookbook

#endif // DESTROYING_A_PRESENTATION_SURFACE
