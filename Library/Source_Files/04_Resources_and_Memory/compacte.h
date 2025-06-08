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
// Chapter: 04 Resources and Memory
// Recipe:  01 Creating a buffer

#ifndef CREATING_A_BUFFER
#define CREATING_A_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateBuffer( VkDevice             logical_device,
                     VkDeviceSize         size,
                     VkBufferUsageFlags   usage,
                     VkBuffer           & buffer );

} // namespace VulkanCookbook

#endif // CREATING_A_BUFFER
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
// Chapter: 04 Resources and Memory
// Recipe:  02 Allocating and binding memory object to a buffer

#ifndef ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_A_BUFFER
#define ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_A_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool AllocateAndBindMemoryObjectToBuffer( VkPhysicalDevice           physical_device,
                                            VkDevice                   logical_device,
                                            VkBuffer                   buffer,
                                            VkMemoryPropertyFlagBits   memory_properties,
                                            VkDeviceMemory           & memory_object );

} // namespace VulkanCookbook

#endif // ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_A_BUFFER
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
// Chapter: 04 Resources and Memory
// Recipe:  03 Setting a buffer memory barrier

#ifndef SETTING_A_BUFFER_MEMORY_BARRIER
#define SETTING_A_BUFFER_MEMORY_BARRIER

#include "Common.h"

namespace VulkanCookbook {

  struct BufferTransition {
    VkBuffer        Buffer;
    VkAccessFlags   CurrentAccess;
    VkAccessFlags   NewAccess;
    uint32_t        CurrentQueueFamily;
    uint32_t        NewQueueFamily;
  };

  void SetBufferMemoryBarrier( VkCommandBuffer               command_buffer,
                               VkPipelineStageFlags          generating_stages,
                               VkPipelineStageFlags          consuming_stages,
                               std::vector<BufferTransition> buffer_transitions );

} // namespace VulkanCookbook

#endif // SETTING_A_BUFFER_MEMORY_BARRIER
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
// Chapter: 04 Resources and Memory
// Recipe:  04 Creating a buffer view

#ifndef CREATING_A_BUFFER_VIEW
#define CREATING_A_BUFFER_VIEW

#include "Common.h"

namespace VulkanCookbook {

  bool CreateBufferView( VkDevice       logical_device,
                         VkBuffer       buffer,
                         VkFormat       format,
                         VkDeviceSize   memory_offset,
                         VkDeviceSize   memory_range,
                         VkBufferView & buffer_view );

} // namespace VulkanCookbook

#endif // CREATING_A_BUFFER_VIEW
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
// Chapter: 04 Resources and Memory
// Recipe:  05 Creating an image

#ifndef CREATING_AN_IMAGE
#define CREATING_AN_IMAGE

#include "Common.h"

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
                    VkImage               & image );

} // namespace VulkanCookbook

#endif // CREATING_AN_IMAGE
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
// Chapter: 04 Resources and Memory
// Recipe:  06 Allocating and binding memory object to an image

#ifndef ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_AN_IMAGE
#define ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_AN_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  bool AllocateAndBindMemoryObjectToImage( VkPhysicalDevice           physical_device,
                                           VkDevice                   logical_device,
                                           VkImage                    image,
                                           VkMemoryPropertyFlagBits   memory_properties,
                                           VkDeviceMemory           & memory_object );

} // namespace VulkanCookbook

#endif // ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_AN_IMAGE
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
// Chapter: 04 Resources and Memory
// Recipe:  07 Setting an image memory barrier

#ifndef SETTING_AN_IMAGE_MEMORY_BARRIER
#define SETTING_AN_IMAGE_MEMORY_BARRIER

#include "Common.h"

namespace VulkanCookbook {

  struct ImageTransition {
    VkImage             Image;
    VkAccessFlags       CurrentAccess;
    VkAccessFlags       NewAccess;
    VkImageLayout       CurrentLayout;
    VkImageLayout       NewLayout;
    uint32_t            CurrentQueueFamily;
    uint32_t            NewQueueFamily;
    VkImageAspectFlags  Aspect;
  };

  void SetImageMemoryBarrier( VkCommandBuffer              command_buffer,
                              VkPipelineStageFlags         generating_stages,
                              VkPipelineStageFlags         consuming_stages,
                              std::vector<ImageTransition> image_transitions );

} // namespace VulkanCookbook

#endif // SETTING_AN_IMAGE_MEMORY_BARRIER
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
// Chapter: 04 Resources and Memory
// Recipe:  08 Creating an image view

#ifndef CREATING_AN_IMAGE_VIEW
#define CREATING_AN_IMAGE_VIEW

#include "Common.h"

namespace VulkanCookbook {

  bool CreateImageView( VkDevice             logical_device,
                        VkImage              image,
                        VkImageViewType      view_type,
                        VkFormat             format,
                        VkImageAspectFlags   aspect,
                        VkImageView        & image_view );

} // namespace VulkanCookbook

#endif // CREATING_AN_IMAGE_VIEW
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
// Chapter: 04 Resources and Memory
// Recipe:  09 Creating a 2D image and view

#ifndef CREATING_A_2D_IMAGE_AND_VIEW
#define CREATING_A_2D_IMAGE_AND_VIEW

#include "Common.h"

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
                             VkImageView           & image_view );

} // namespace VulkanCookbook

#endif // CREATING_A_2D_IMAGE_AND_VIEW
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
// Chapter: 04 Resources and Memory
// Recipe:  10 Creating a layered 2D image with a CUBEMAP view

#ifndef CREATING_A_LAYERED_2D_IMAGE_WITH_CUBEMAP_VIEW
#define CREATING_A_LAYERED_2D_IMAGE_WITH_CUBEMAP_VIEW

#include "Common.h"

namespace VulkanCookbook {

  bool CreateLayered2DImageWithCubemapView( VkPhysicalDevice    physical_device,
                                            VkDevice            logical_device,
                                            uint32_t            size,
                                            uint32_t            num_mipmaps,
                                            VkImageUsageFlags   usage,
                                            VkImageAspectFlags  aspect,
                                            VkImage           & image,
                                            VkDeviceMemory    & memory_object,
                                            VkImageView       & image_view );

} // namespace VulkanCookbook

#endif // CREATING_A_LAYERED_2D_IMAGE_WITH_CUBEMAP_VIEW
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
// Chapter: 04 Resources and Memory
// Recipe:  11 Mapping, updating and unmapping host-visible memory

#ifndef MAPPING_UPDATING_AND_UNMAPPING_HOST_VISIBLE_MEMORY
#define MAPPING_UPDATING_AND_UNMAPPING_HOST_VISIBLE_MEMORY

#include "Common.h"

namespace VulkanCookbook {

  bool MapUpdateAndUnmapHostVisibleMemory( VkDevice             logical_device,
                                           VkDeviceMemory       memory_object,
                                           VkDeviceSize         offset,
                                           VkDeviceSize         data_size,
                                           void               * data,
                                           bool                 unmap,
                                           void             * * pointer );

} // namespace VulkanCookbook

#endif // MAPPING_UPDATING_AND_UNMAPPING_HOST_VISIBLE_MEMORY
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
// Chapter: 04 Resources and Memory
// Recipe:  12 Copying data between buffers

#ifndef COPYING_DATA_BETWEEN_BUFFERS
#define COPYING_DATA_BETWEEN_BUFFERS

#include "Common.h"

namespace VulkanCookbook {

  void CopyDataBetweenBuffers( VkCommandBuffer           command_buffer,
                               VkBuffer                  source_buffer,
                               VkBuffer                  destination_buffer,
                               std::vector<VkBufferCopy> regions );

} // namespace VulkanCookbook

#endif // COPYING_DATA_BETWEEN_BUFFERS
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
// Chapter: 04 Resources and Memory
// Recipe:  13 Copying data from a buffer to an image

#ifndef COPYING_DATA_FROM_A_BUFFER_TO_AN_IMAGE
#define COPYING_DATA_FROM_A_BUFFER_TO_AN_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  void CopyDataFromBufferToImage( VkCommandBuffer                command_buffer,
                                  VkBuffer                       source_buffer,
                                  VkImage                        destination_image,
                                  VkImageLayout                  image_layout,
                                  std::vector<VkBufferImageCopy> regions );

} // namespace VulkanCookbook

#endif // COPYING_DATA_FROM_A_BUFFER_TO_AN_IMAGE
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
// Chapter: 04 Resources and Memory
// Recipe:  14 Copying data from an image to a buffer

#ifndef COPYING_DATA_FROM_AN_IMAGE_TO_A_BUFFER
#define COPYING_DATA_FROM_AN_IMAGE_TO_A_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  void CopyDataFromImageToBuffer( VkCommandBuffer                command_buffer,
                                  VkImage                        source_image,
                                  VkImageLayout                  image_layout,
                                  VkBuffer                       destination_buffer,
                                  std::vector<VkBufferImageCopy> regions );

} // namespace VulkanCookbook

#endif // COPYING_DATA_FROM_AN_IMAGE_TO_A_BUFFER
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
// Chapter: 04 Resources and Memory
// Recipe:  15 Using staging buffer to update a buffer with a device-local memory bound

#ifndef USING_STAGING_BUFFER_TO_UPDATE_A_BUFFER_WITH_A_DEVICE_LOCAL_MEMORY_BOUND
#define USING_STAGING_BUFFER_TO_UPDATE_A_BUFFER_WITH_A_DEVICE_LOCAL_MEMORY_BOUND

#include "Common.h"

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
                                                                 std::vector<VkSemaphore>   signal_semaphores );

} // namespace VulkanCookbook

#endif // USING_STAGING_BUFFER_TO_UPDATE_A_BUFFER_WITH_A_DEVICE_LOCAL_MEMORY_BOUND
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
// Chapter: 04 Resources and Memory
// Recipe:  16 Using staging buffer to update an image with a device-local memory bound

#ifndef USING_STAGING_BUFFER_TO_UPDATE_AN_IMAGE_WITH_A_DEVICE_LOCAL_MEMORY_BOUND
#define USING_STAGING_BUFFER_TO_UPDATE_AN_IMAGE_WITH_A_DEVICE_LOCAL_MEMORY_BOUND

#include "Common.h"

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
                                                                std::vector<VkSemaphore>   signal_semaphores );

} // namespace VulkanCookbook

#endif // USING_STAGING_BUFFER_TO_UPDATE_AN_IMAGE_WITH_A_DEVICE_LOCAL_MEMORY_BOUND
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
// Chapter: 04 Resources and Memory
// Recipe:  17 Destroying an image view

#ifndef DESTROYING_AN_IMAGE_VIEW
#define DESTROYING_AN_IMAGE_VIEW

#include "Common.h"

namespace VulkanCookbook {

  void DestroyImageView( VkDevice      logical_device,
                         VkImageView & image_view );

} // namespace VulkanCookbook

#endif // DESTROYING_AN_IMAGE_VIEW
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
// Chapter: 04 Resources and Memory
// Recipe:  18 Destroying an image

#ifndef DESTROYING_AN_IMAGE
#define DESTROYING_AN_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  void DestroyImage( VkDevice   logical_device,
                     VkImage  & image );

} // namespace VulkanCookbook

#endif // DESTROYING_AN_IMAGE
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
// Chapter: 04 Resources and Memory
// Recipe:  19 Destroying a buffer view

#ifndef DESTROYING_A_BUFFER_VIEW
#define DESTROYING_A_BUFFER_VIEW

#include "Common.h"

namespace VulkanCookbook {

  void DestroyBufferView( VkDevice       logical_device,
                          VkBufferView & buffer_view );

} // namespace VulkanCookbook

#endif // DESTROYING_A_BUFFER_VIEW
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
// Chapter: 04 Resources and Memory
// Recipe:  20 Freeing a memory object

#ifndef FREEING_A_MEMORY_OBJECT
#define FREEING_A_MEMORY_OBJECT

#include "Common.h"

namespace VulkanCookbook {

  void FreeMemoryObject( VkDevice         logical_device,
                         VkDeviceMemory & memory_object );

} // namespace VulkanCookbook

#endif // FREEING_A_MEMORY_OBJECT
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
// Chapter: 04 Resources and Memory
// Recipe:  21 Destroying a buffer

#ifndef DESTROYING_A_BUFFER
#define DESTROYING_A_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  void DestroyBuffer( VkDevice   logical_device,
                      VkBuffer & buffer );

} // namespace VulkanCookbook

#endif // DESTROYING_A_BUFFER
