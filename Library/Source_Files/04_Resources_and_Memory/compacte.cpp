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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  01 Creating a buffer

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool CreateBuffer( VkDevice             logical_device,
                     VkDeviceSize         size,
                     VkBufferUsageFlags   usage,
                     VkBuffer           & buffer ) {
    VkBufferCreateInfo buffer_create_info = {
      VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,   // VkStructureType        sType
      nullptr,                                // const void           * pNext
      0,                                      // VkBufferCreateFlags    flags
      size,                                   // VkDeviceSize           size
      usage,                                  // VkBufferUsageFlags     usage
      VK_SHARING_MODE_EXCLUSIVE,              // VkSharingMode          sharingMode
      0,                                      // uint32_t               queueFamilyIndexCount
      nullptr                                 // const uint32_t       * pQueueFamilyIndices
    };

    //VkBuffer* buffer2 = &buffer;

    VkResult result = vkCreateBuffer( logical_device, &buffer_create_info, nullptr, &buffer );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not create a buffer." << std::endl;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  02 Allocating and binding memory object to a buffer

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool AllocateAndBindMemoryObjectToBuffer( VkPhysicalDevice           physical_device,
                                            VkDevice                   logical_device,
                                            VkBuffer                   buffer,
                                            VkMemoryPropertyFlagBits   memory_properties,
                                            VkDeviceMemory           & memory_object ) {
    VkPhysicalDeviceMemoryProperties physical_device_memory_properties;
    vkGetPhysicalDeviceMemoryProperties( physical_device, &physical_device_memory_properties );

    VkMemoryRequirements memory_requirements;
    vkGetBufferMemoryRequirements( logical_device, buffer, &memory_requirements );

    memory_object = VK_NULL_HANDLE;
    for( uint32_t type = 0; type < physical_device_memory_properties.memoryTypeCount; ++type ) {
      if( (memory_requirements.memoryTypeBits & (1 << type)) &&
          ((physical_device_memory_properties.memoryTypes[type].propertyFlags & memory_properties) == memory_properties) ) {

        VkMemoryAllocateInfo buffer_memory_allocate_info = {
          VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,   // VkStructureType    sType
          nullptr,                                  // const void       * pNext
          memory_requirements.size,                 // VkDeviceSize       allocationSize
          type                                      // uint32_t           memoryTypeIndex
        };

        VkDeviceMemory* k = &memory_object;

        VkResult result = vkAllocateMemory( logical_device, &buffer_memory_allocate_info, nullptr, k );
        if( VK_SUCCESS == result ) {
          break;
        }
      }
    }

    if( VK_NULL_HANDLE == memory_object ) {
      std::cout << "Could not allocate memory for a buffer." << std::endl;
      return false;
    }

    VkResult result = vkBindBufferMemory( logical_device, buffer, memory_object, 0 );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not bind memory object to a buffer." << std::endl;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  03 Setting a buffer memory barrier

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void SetBufferMemoryBarrier( VkCommandBuffer               command_buffer,
                               VkPipelineStageFlags          generating_stages,
                               VkPipelineStageFlags          consuming_stages,
                               std::vector<BufferTransition> buffer_transitions ) {

    std::vector<VkBufferMemoryBarrier> buffer_memory_barriers;

    for( auto & buffer_transition : buffer_transitions ) {
      buffer_memory_barriers.push_back( {
        VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,    // VkStructureType    sType
        nullptr,                                    // const void       * pNext
        buffer_transition.CurrentAccess,            // VkAccessFlags      srcAccessMask
        buffer_transition.NewAccess,                // VkAccessFlags      dstAccessMask
        buffer_transition.CurrentQueueFamily,       // uint32_t           srcQueueFamilyIndex
        buffer_transition.NewQueueFamily,           // uint32_t           dstQueueFamilyIndex
        buffer_transition.Buffer,                   // VkBuffer           buffer
        0,                                          // VkDeviceSize       offset
        VK_WHOLE_SIZE                               // VkDeviceSize       size
      } );
    }

    if( buffer_memory_barriers.size() > 0 ) {
      vkCmdPipelineBarrier( command_buffer, generating_stages, consuming_stages, 0, 0, nullptr, static_cast<uint32_t>(buffer_memory_barriers.size()), buffer_memory_barriers.data(), 0, nullptr );
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  04 Creating a buffer view

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool CreateBufferView( VkDevice       logical_device,
                         VkBuffer       buffer,
                         VkFormat       format,
                         VkDeviceSize   memory_offset,
                         VkDeviceSize   memory_range,
                         VkBufferView & buffer_view ) {
    VkBufferViewCreateInfo buffer_view_create_info = {
      VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO,    // VkStructureType            sType
      nullptr,                                      // const void               * pNext
      0,                                            // VkBufferViewCreateFlags    flags
      buffer,                                       // VkBuffer                   buffer
      format,                                       // VkFormat                   format
      memory_offset,                                // VkDeviceSize               offset
      memory_range                                  // VkDeviceSize               range
    };

    VkResult result = vkCreateBufferView( logical_device, &buffer_view_create_info, nullptr, &buffer_view );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not creat buffer view." << std::endl;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  05 Creating an image

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool CreateImage( VkDevice                logical_device,
                    VkImageType             type,
                    VkFormat                format,
                    VkExtent3D              size,
                    uint32_t                num_mipmaps,
                    uint32_t                num_layers,
                    VkSampleCountFlagBits   samples,
                    VkImageUsageFlags       usage_scenarios,
                    bool                    cubemap,
                    VkImage               & image ) {
    VkImageCreateInfo image_create_info = {
      VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,                // VkStructureType          sType
      nullptr,                                            // const void             * pNext
      cubemap ? VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT : 0u, // VkImageCreateFlags       flags
      type,                                               // VkImageType              imageType
      format,                                             // VkFormat                 format
      size,                                               // VkExtent3D               extent
      num_mipmaps,                                        // uint32_t                 mipLevels
      cubemap ? 6 * num_layers : num_layers,              // uint32_t                 arrayLayers
      samples,                                            // VkSampleCountFlagBits    samples
      VK_IMAGE_TILING_OPTIMAL,                            // VkImageTiling            tiling
      usage_scenarios,                                    // VkImageUsageFlags        usage
      VK_SHARING_MODE_EXCLUSIVE,                          // VkSharingMode            sharingMode
      0,                                                  // uint32_t                 queueFamilyIndexCount
      nullptr,                                            // const uint32_t         * pQueueFamilyIndices
      VK_IMAGE_LAYOUT_UNDEFINED                           // VkImageLayout            initialLayout
    };

    VkResult result = vkCreateImage( logical_device, &image_create_info, nullptr, &image );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not create an image." << std::endl;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  06 Allocating and binding memory object to an image

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool AllocateAndBindMemoryObjectToImage( VkPhysicalDevice           physical_device,
                                           VkDevice                   logical_device,
                                           VkImage                    image,
                                           VkMemoryPropertyFlagBits   memory_properties,
                                           VkDeviceMemory           & memory_object ) {
    VkPhysicalDeviceMemoryProperties physical_device_memory_properties;
    vkGetPhysicalDeviceMemoryProperties( physical_device, &physical_device_memory_properties );

    VkMemoryRequirements memory_requirements;
    vkGetImageMemoryRequirements( logical_device, image, &memory_requirements );

    memory_object = VK_NULL_HANDLE;
    for( uint32_t type = 0; type < physical_device_memory_properties.memoryTypeCount; ++type ) {
      if( (memory_requirements.memoryTypeBits & (1 << type)) &&
        ((physical_device_memory_properties.memoryTypes[type].propertyFlags & memory_properties) == memory_properties) ) {

        VkMemoryAllocateInfo image_memory_allocate_info = {
          VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,   // VkStructureType    sType
          nullptr,                                  // const void       * pNext
          memory_requirements.size,                 // VkDeviceSize       allocationSize
          type                                      // uint32_t           memoryTypeIndex
        };

        VkResult result = vkAllocateMemory( logical_device, &image_memory_allocate_info, nullptr, &memory_object );
        if( VK_SUCCESS == result ) {
          break;
        }
      }
    }

    if( VK_NULL_HANDLE == memory_object ) {
      std::cout << "Could not allocate memory for an image." << std::endl;
      return false;
    }

    VkResult result = vkBindImageMemory( logical_device, image, memory_object, 0 );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not bind memory object to an image." << std::endl;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  07 Setting an image memory barrier

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void SetImageMemoryBarrier( VkCommandBuffer              command_buffer,
                              VkPipelineStageFlags         generating_stages,
                              VkPipelineStageFlags         consuming_stages,
                              std::vector<ImageTransition> image_transitions ) {
    std::vector<VkImageMemoryBarrier> image_memory_barriers;

    for( auto & image_transition : image_transitions ) {
      image_memory_barriers.push_back( {
        VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,   // VkStructureType            sType
        nullptr,                                  // const void               * pNext
        image_transition.CurrentAccess,           // VkAccessFlags              srcAccessMask
        image_transition.NewAccess,               // VkAccessFlags              dstAccessMask
        image_transition.CurrentLayout,           // VkImageLayout              oldLayout
        image_transition.NewLayout,               // VkImageLayout              newLayout
        image_transition.CurrentQueueFamily,      // uint32_t                   srcQueueFamilyIndex
        image_transition.NewQueueFamily,          // uint32_t                   dstQueueFamilyIndex
        image_transition.Image,                   // VkImage                    image
        {                                         // VkImageSubresourceRange    subresourceRange
          image_transition.Aspect,                  // VkImageAspectFlags         aspectMask
          0,                                        // uint32_t                   baseMipLevel
          VK_REMAINING_MIP_LEVELS,                  // uint32_t                   levelCount
          0,                                        // uint32_t                   baseArrayLayer
          VK_REMAINING_ARRAY_LAYERS                 // uint32_t                   layerCount
        }
      } );
    }

    if( image_memory_barriers.size() > 0 ) {
      vkCmdPipelineBarrier( command_buffer, generating_stages, consuming_stages, 0, 0, nullptr, 0, nullptr, static_cast<uint32_t>(image_memory_barriers.size()), image_memory_barriers.data() );
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  08 Creating an image view

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool CreateImageView( VkDevice             logical_device,
                        VkImage              image,
                        VkImageViewType      view_type,
                        VkFormat             format,
                        VkImageAspectFlags   aspect,
                        VkImageView        & image_view ) {
    VkImageViewCreateInfo image_view_create_info = {
      VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,   // VkStructureType            sType
      nullptr,                                    // const void               * pNext
      0,                                          // VkImageViewCreateFlags     flags
      image,                                      // VkImage                    image
      view_type,                                  // VkImageViewType            viewType
      format,                                     // VkFormat                   format
      {                                           // VkComponentMapping         components
        VK_COMPONENT_SWIZZLE_IDENTITY,              // VkComponentSwizzle         r
        VK_COMPONENT_SWIZZLE_IDENTITY,              // VkComponentSwizzle         g
        VK_COMPONENT_SWIZZLE_IDENTITY,              // VkComponentSwizzle         b
        VK_COMPONENT_SWIZZLE_IDENTITY               // VkComponentSwizzle         a
      },
      {                                           // VkImageSubresourceRange    subresourceRange
        aspect,                                     // VkImageAspectFlags         aspectMask
        0,                                          // uint32_t                   baseMipLevel
        VK_REMAINING_MIP_LEVELS,                    // uint32_t                   levelCount
        0,                                          // uint32_t                   baseArrayLayer
        VK_REMAINING_ARRAY_LAYERS                   // uint32_t                   layerCount
      }
    };

    VkResult result = vkCreateImageView( logical_device, &image_view_create_info, nullptr, &image_view );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not create an image view." << std::endl;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  09 Creating a 2D image and view

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool Create2DImageAndView( VkPhysicalDevice        physical_device,
                             VkDevice                logical_device,
                             VkFormat                format,
                             VkExtent2D              size,
                             uint32_t                num_mipmaps,
                             uint32_t                num_layers,
                             VkSampleCountFlagBits   samples,
                             VkImageUsageFlags       usage,
                             VkImageAspectFlags      aspect,
                             VkImage               & image,
                             VkDeviceMemory        & memory_object,
                             VkImageView           & image_view ) {
    if( !CreateImage( logical_device, VK_IMAGE_TYPE_2D, format, { size.width, size.height, 1 }, num_mipmaps, num_layers, samples, usage, false, image ) ) {
      return false;
    }

    if( !AllocateAndBindMemoryObjectToImage( physical_device, logical_device, image, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
      return false;
    }

    if( !CreateImageView( logical_device, image, VK_IMAGE_VIEW_TYPE_2D, format, aspect, image_view ) ) {
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  10 Creating a layered 2D image with a CUBEMAP view

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool CreateLayered2DImageWithCubemapView( VkPhysicalDevice    physical_device,
                                            VkDevice            logical_device,
                                            uint32_t            size,
                                            uint32_t            num_mipmaps,
                                            VkImageUsageFlags   usage,
                                            VkImageAspectFlags  aspect,
                                            VkImage           & image,
                                            VkDeviceMemory    & memory_object,
                                            VkImageView       & image_view ) {
    if( !CreateImage( logical_device, VK_IMAGE_TYPE_2D, VK_FORMAT_R8G8B8A8_UNORM, { size, size, 1 }, num_mipmaps, 6, VK_SAMPLE_COUNT_1_BIT, usage, true, image ) ) {
      return false;
    }

    if( !AllocateAndBindMemoryObjectToImage( physical_device, logical_device, image, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
      return false;
    }

    if( !CreateImageView( logical_device, image, VK_IMAGE_VIEW_TYPE_CUBE, VK_FORMAT_R8G8B8A8_UNORM, aspect, image_view ) ) {
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  11 Mapping, updating and unmapping host-visible memory

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool MapUpdateAndUnmapHostVisibleMemory( VkDevice             logical_device,
                                           VkDeviceMemory       memory_object,
                                           VkDeviceSize         offset,
                                           VkDeviceSize         data_size,
                                           void               * data,
                                           bool                 unmap,
                                           void             * * pointer ) {
    VkResult result;
    void * local_pointer;
    result = vkMapMemory( logical_device, memory_object, offset, data_size, 0, &local_pointer );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not map memory object." << std::endl;
      return false;
    }

    std::memcpy( local_pointer, data, static_cast<size_t>(data_size) );

    std::vector<VkMappedMemoryRange> memory_ranges = {
      {
        VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,  // VkStructureType    sType
        nullptr,                                // const void       * pNext
        memory_object,                          // VkDeviceMemory     memory
        offset,                                 // VkDeviceSize       offset
        VK_WHOLE_SIZE                           // VkDeviceSize       size
      }
    };

    vkFlushMappedMemoryRanges( logical_device, static_cast<uint32_t>(memory_ranges.size()), memory_ranges.data() );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not flush mapped memory." << std::endl;
      return false;
    }

    if( unmap ) {
      vkUnmapMemory( logical_device, memory_object );
    } else if( nullptr != pointer ) {
      *pointer = local_pointer;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  12 Copying data between buffers

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void CopyDataBetweenBuffers( VkCommandBuffer           command_buffer,
                               VkBuffer                  source_buffer,
                               VkBuffer                  destination_buffer,
                               std::vector<VkBufferCopy> regions ) {
    if( regions.size() > 0 ) {
      vkCmdCopyBuffer( command_buffer, source_buffer, destination_buffer, static_cast<uint32_t>(regions.size()), regions.data() );
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  13 Copying data from a buffer to an image

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void CopyDataFromBufferToImage( VkCommandBuffer                command_buffer,
                                  VkBuffer                       source_buffer,
                                  VkImage                        destination_image,
                                  VkImageLayout                  image_layout,
                                  std::vector<VkBufferImageCopy> regions ) {
    if( regions.size() > 0 ) {
      vkCmdCopyBufferToImage( command_buffer, source_buffer, destination_image, image_layout, static_cast<uint32_t>(regions.size()), regions.data() );
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  14 Copying data from an image to a buffer

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void CopyDataFromImageToBuffer( VkCommandBuffer                command_buffer,
                                  VkImage                        source_image,
                                  VkImageLayout                  image_layout,
                                  VkBuffer                       destination_buffer,
                                  std::vector<VkBufferImageCopy> regions ) {
    if( regions.size() > 0 ) {
      vkCmdCopyImageToBuffer( command_buffer, source_image, image_layout, destination_buffer, static_cast<uint32_t>(regions.size()), regions.data() );
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  15 Using staging buffer to update buffer with a device-local memory bound

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool UseStagingBufferToUpdateBufferWithDeviceLocalMemoryBound( VkPhysicalDevice           physical_device,
                                                                 VkDevice                   logical_device,
                                                                 VkDeviceSize               data_size,
                                                                 void                     * data,
                                                                 VkBuffer                   destination_buffer,
                                                                 VkDeviceSize               destination_offset,
                                                                 VkAccessFlags              destination_buffer_current_access,
                                                                 VkAccessFlags              destination_buffer_new_access,
                                                                 VkPipelineStageFlags       destination_buffer_generating_stages,
                                                                 VkPipelineStageFlags       destination_buffer_consuming_stages,
                                                                 VkQueue                    queue,
                                                                 VkCommandBuffer            command_buffer,
                                                                 std::vector<VkSemaphore>   signal_semaphores ) {

    VkDestroyer(VkBuffer) staging_buffer;
    InitVkDestroyer( logical_device, staging_buffer );
    if( !CreateBuffer( logical_device, data_size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, *staging_buffer ) ) {
      return false;
    }

    VkDestroyer(VkDeviceMemory) memory_object;
    InitVkDestroyer( logical_device, memory_object );
    if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, *staging_buffer, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, *memory_object ) ) {
      return false;
    }

    if( !MapUpdateAndUnmapHostVisibleMemory( logical_device, *memory_object, 0, data_size, data, true, nullptr ) ) {
      return false;
    }

    if( !BeginCommandBufferRecordingOperation( command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr ) ) {
      return false;
    }

    SetBufferMemoryBarrier( command_buffer, destination_buffer_generating_stages, VK_PIPELINE_STAGE_TRANSFER_BIT, { { destination_buffer, destination_buffer_current_access, VK_ACCESS_TRANSFER_WRITE_BIT, VK_QUEUE_FAMILY_IGNORED, VK_QUEUE_FAMILY_IGNORED } } );

    CopyDataBetweenBuffers( command_buffer, *staging_buffer, destination_buffer, { { 0, destination_offset, data_size } } );

    SetBufferMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, destination_buffer_consuming_stages, { { destination_buffer, VK_ACCESS_TRANSFER_WRITE_BIT, destination_buffer_new_access, VK_QUEUE_FAMILY_IGNORED, VK_QUEUE_FAMILY_IGNORED } } );

    if( !EndCommandBufferRecordingOperation( command_buffer ) ) {
      return false;
    }

    VkDestroyer(VkFence) fence;
    InitVkDestroyer( logical_device, fence );
    if( !CreateFence( logical_device, false, *fence ) ) {
      return false;
    }

    if( !SubmitCommandBuffersToQueue( queue, {}, { command_buffer }, signal_semaphores, *fence ) ) {
      return false;
    }

    if( !WaitForFences( logical_device, { *fence }, VK_FALSE, 500000000 ) ) {
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  16 Using staging buffer to update an image with a device-local memory bound

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  bool UseStagingBufferToUpdateImageWithDeviceLocalMemoryBound( VkPhysicalDevice           physical_device,
                                                                VkDevice                   logical_device,
                                                                VkDeviceSize               data_size,
                                                                void                     * data,
                                                                VkImage                    destination_image,
                                                                VkImageSubresourceLayers   destination_image_subresource,
                                                                VkOffset3D                 destination_image_offset,
                                                                VkExtent3D                 destination_image_size,
                                                                VkImageLayout              destination_image_current_layout,
                                                                VkImageLayout              destination_image_new_layout,
                                                                VkAccessFlags              destination_image_current_access,
                                                                VkAccessFlags              destination_image_new_access,
                                                                VkImageAspectFlags         destination_image_aspect,
                                                                VkPipelineStageFlags       destination_image_generating_stages,
                                                                VkPipelineStageFlags       destination_image_consuming_stages,
                                                                VkQueue                    queue,
                                                                VkCommandBuffer            command_buffer,
                                                                std::vector<VkSemaphore>   signal_semaphores ) {

    VkDestroyer(VkBuffer) staging_buffer;
    InitVkDestroyer( logical_device, staging_buffer );
    if( !CreateBuffer( logical_device, data_size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, *staging_buffer ) ) {
      return false;
    }

    VkDestroyer(VkDeviceMemory) memory_object;
    InitVkDestroyer( logical_device, memory_object );
    if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, *staging_buffer, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, *memory_object ) ) {
      return false;
    }

    if( !MapUpdateAndUnmapHostVisibleMemory( logical_device, *memory_object, 0, data_size, data, true, nullptr ) ) {
      return false;
    }

    if( !BeginCommandBufferRecordingOperation( command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr ) ) {
      return false;
    }

    SetImageMemoryBarrier( command_buffer, destination_image_generating_stages, VK_PIPELINE_STAGE_TRANSFER_BIT,
    {
      {
        destination_image,                        // VkImage            Image
        destination_image_current_access,         // VkAccessFlags      CurrentAccess
        VK_ACCESS_TRANSFER_WRITE_BIT,             // VkAccessFlags      NewAccess
        destination_image_current_layout,         // VkImageLayout      CurrentLayout
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,     // VkImageLayout      NewLayout
        VK_QUEUE_FAMILY_IGNORED,                  // uint32_t           CurrentQueueFamily
        VK_QUEUE_FAMILY_IGNORED,                  // uint32_t           NewQueueFamily
        destination_image_aspect                  // VkImageAspectFlags Aspect
      } } );

    CopyDataFromBufferToImage( command_buffer, *staging_buffer, destination_image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
    {
      {
        0,                                        // VkDeviceSize               bufferOffset
        0,                                        // uint32_t                   bufferRowLength
        0,                                        // uint32_t                   bufferImageHeight
        destination_image_subresource,            // VkImageSubresourceLayers   imageSubresource
        destination_image_offset,                 // VkOffset3D                 imageOffset
        destination_image_size,                   // VkExtent3D                 imageExtent
      } } );

    SetImageMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, destination_image_consuming_stages,
    {
      {
        destination_image,                        // VkImage            Image
        VK_ACCESS_TRANSFER_WRITE_BIT,             // VkAccessFlags      CurrentAccess
        destination_image_new_access,             // VkAccessFlags      NewAccess
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,     // VkImageLayout      CurrentLayout
        destination_image_new_layout,             // VkImageLayout      NewLayout
        VK_QUEUE_FAMILY_IGNORED,                  // uint32_t           CurrentQueueFamily
        VK_QUEUE_FAMILY_IGNORED,                  // uint32_t           NewQueueFamily
        destination_image_aspect                  // VkImageAspectFlags Aspect
      } } );

    if( !EndCommandBufferRecordingOperation( command_buffer ) ) {
      return false;
    }

    VkDestroyer(VkFence) fence;
    InitVkDestroyer( logical_device, fence );
    if( !CreateFence( logical_device, false, *fence ) ) {
      return false;
    }

    if( !SubmitCommandBuffersToQueue( queue, {}, { command_buffer }, signal_semaphores, *fence ) ) {
      return false;
    }

    if( !WaitForFences( logical_device, { *fence }, VK_FALSE, 500000000 ) ) {
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  17 Destroying an image view

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void DestroyImageView( VkDevice      logical_device,
                         VkImageView & image_view ) {
    if( VK_NULL_HANDLE != image_view ) {
      vkDestroyImageView( logical_device, image_view, nullptr );
      image_view = VK_NULL_HANDLE;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  18 Destroying an image

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void DestroyImage( VkDevice   logical_device,
                     VkImage  & image ) {
    if( VK_NULL_HANDLE != image ) {
      vkDestroyImage( logical_device, image, nullptr );
      image = VK_NULL_HANDLE;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  19 Destroying a buffer view

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void DestroyBufferView( VkDevice       logical_device,
                          VkBufferView & buffer_view ) {
    if( VK_NULL_HANDLE != buffer_view ) {
      vkDestroyBufferView( logical_device, buffer_view, nullptr );
      buffer_view = VK_NULL_HANDLE;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  20 Freeing a memory object

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void FreeMemoryObject( VkDevice         logical_device,
                         VkDeviceMemory & memory_object ) {
    if( VK_NULL_HANDLE != memory_object ) {
      vkFreeMemory( logical_device, memory_object, nullptr );
      memory_object = VK_NULL_HANDLE;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 04 Resources and Memory
// Recipe:  21 Destroying a buffer

#include "04_Resources_and_Memory/compacte.h"

namespace VulkanCookbook {

  void DestroyBuffer( VkDevice   logical_device,
                      VkBuffer & buffer ) {
    if( VK_NULL_HANDLE != buffer ) {
      vkDestroyBuffer( logical_device, buffer, nullptr );
      buffer = VK_NULL_HANDLE;
    }
  }

} // namespace VulkanCookbook
