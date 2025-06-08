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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  01 Creating a command pool

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool CreateCommandPool( VkDevice                   logical_device,
                          VkCommandPoolCreateFlags   parameters,
                          uint32_t                   queue_family,
                          VkCommandPool            & command_pool ) {
    VkCommandPoolCreateInfo command_pool_create_info = {
      VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,   // VkStructureType              sType
      nullptr,                                      // const void                 * pNext
      parameters,                                   // VkCommandPoolCreateFlags     flags
      queue_family                                  // uint32_t                     queueFamilyIndex
    };

    VkResult result = vkCreateCommandPool( logical_device, &command_pool_create_info, nullptr, &command_pool );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not create command pool." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  02 Allocating command buffers

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool AllocateCommandBuffers( VkDevice                       logical_device,
                               VkCommandPool                  command_pool,
                               VkCommandBufferLevel           level,
                               uint32_t                       count,
                               std::vector<VkCommandBuffer> & command_buffers ) {
    VkCommandBufferAllocateInfo command_buffer_allocate_info = {
      VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,   // VkStructureType          sType
      nullptr,                                          // const void             * pNext
      command_pool,                                     // VkCommandPool            commandPool
      level,                                            // VkCommandBufferLevel     level
      count                                             // uint32_t                 commandBufferCount
    };

    command_buffers.resize( count );

    VkResult result = vkAllocateCommandBuffers( logical_device, &command_buffer_allocate_info, command_buffers.data() );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not allocate command buffers." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  03 Beginning a command buffer recording operation

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool BeginCommandBufferRecordingOperation( VkCommandBuffer                  command_buffer,
                                             VkCommandBufferUsageFlags        usage,
                                             VkCommandBufferInheritanceInfo * secondary_command_buffer_info ) {
    VkCommandBufferBeginInfo command_buffer_begin_info = {
      VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,    // VkStructureType                        sType
      nullptr,                                        // const void                           * pNext
      usage,                                          // VkCommandBufferUsageFlags              flags
      secondary_command_buffer_info                   // const VkCommandBufferInheritanceInfo * pInheritanceInfo
    };

    VkResult result = vkBeginCommandBuffer( command_buffer, &command_buffer_begin_info );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not begin command buffer recording operation." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  04 Ending a command buffer recording operation

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool EndCommandBufferRecordingOperation( VkCommandBuffer command_buffer ) {
    VkResult result = vkEndCommandBuffer( command_buffer );
    if( VK_SUCCESS != result ) {
      std::cout << "Error occurred during command buffer recording." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  05 Resetting a command buffer

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool ResetCommandBuffer( VkCommandBuffer command_buffer,
                           bool            release_resources ) {
    VkResult result = vkResetCommandBuffer( command_buffer, release_resources ? VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT : 0 );
    if( VK_SUCCESS != result ) {
      std::cout << "Error occurred during command buffer reset." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  06 Resetting a command pool

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool ResetCommandPool( VkDevice      logical_device,
                         VkCommandPool command_pool,
                         bool          release_resources ) {
    VkResult result = vkResetCommandPool( logical_device, command_pool, release_resources ? VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT : 0 );
    if( VK_SUCCESS != result ) {
      std::cout << "Error occurred during command pool reset." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  07 Creating a semaphore

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool CreateSemaphore( VkDevice      logical_device,
                        VkSemaphore & semaphore ) {
    VkSemaphoreCreateInfo semaphore_create_info = {
      VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,    // VkStructureType            sType
      nullptr,                                    // const void               * pNext
      0                                           // VkSemaphoreCreateFlags     flags
    };

    VkResult result = vkCreateSemaphore( logical_device, &semaphore_create_info, nullptr, &semaphore );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not create a semaphore." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  08 Creating a fence

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool CreateFence( VkDevice   logical_device,
                    bool       signaled,
                    VkFence  & fence ) {
    VkFenceCreateInfo fence_create_info = {
      VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,          // VkStructureType        sType
      nullptr,                                      // const void           * pNext
      signaled ? VK_FENCE_CREATE_SIGNALED_BIT : 0u, // VkFenceCreateFlags     flags
    };

    VkResult result = vkCreateFence( logical_device, &fence_create_info, nullptr, &fence );
    if( VK_SUCCESS != result ) {
      std::cout << "Could not create a fence." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  09 Waiting for fences

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool WaitForFences( VkDevice                     logical_device,
                      std::vector<VkFence> const & fences,
                      VkBool32                     wait_for_all,
                      uint64_t                     timeout ) {
    if( fences.size() > 0 ) {
      VkResult result = vkWaitForFences( logical_device, static_cast<uint32_t>(fences.size()), fences.data(), wait_for_all, timeout );
      if( VK_SUCCESS != result ) {
        std::cout << "Waiting on fence failed." << std::endl;
        return false;
      }
      return true;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  10 Resetting fences

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool ResetFences( VkDevice                     logical_device,
                    std::vector<VkFence> const & fences ) {
    if( fences.size() > 0 ) {
      VkResult result = vkResetFences( logical_device, static_cast<uint32_t>(fences.size()), fences.data() );
      if( VK_SUCCESS != result ) {
        std::cout << "Error occurred when tried to reset fences." << std::endl;
        return false;
      }
      return VK_SUCCESS == result;
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
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  11 Submitting command buffers to the queue

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool SubmitCommandBuffersToQueue( VkQueue                         queue,
                                    std::vector<WaitSemaphoreInfo>  wait_semaphore_infos,
                                    std::vector<VkCommandBuffer>    command_buffers,
                                    std::vector<VkSemaphore>        signal_semaphores,
                                    VkFence                         fence ) {
    std::vector<VkSemaphore>          wait_semaphore_handles;
    std::vector<VkPipelineStageFlags> wait_semaphore_stages;

    for( auto & wait_semaphore_info : wait_semaphore_infos ) {
      wait_semaphore_handles.emplace_back( wait_semaphore_info.Semaphore );
      wait_semaphore_stages.emplace_back( wait_semaphore_info.WaitingStage );
    }

    VkSubmitInfo submit_info = {
      VK_STRUCTURE_TYPE_SUBMIT_INFO,                        // VkStructureType                sType
      nullptr,                                              // const void                   * pNext
      static_cast<uint32_t>(wait_semaphore_infos.size()),   // uint32_t                       waitSemaphoreCount
      wait_semaphore_handles.data(),                        // const VkSemaphore            * pWaitSemaphores
      wait_semaphore_stages.data(),                         // const VkPipelineStageFlags   * pWaitDstStageMask
      static_cast<uint32_t>(command_buffers.size()),        // uint32_t                       commandBufferCount
      command_buffers.data(),                               // const VkCommandBuffer        * pCommandBuffers
      static_cast<uint32_t>(signal_semaphores.size()),      // uint32_t                       signalSemaphoreCount
      signal_semaphores.data()                              // const VkSemaphore            * pSignalSemaphores
    };

    VkResult result = vkQueueSubmit( queue, 1, &submit_info, fence );
    if( VK_SUCCESS != result ) {
      std::cout << "Error occurred during command buffer submission." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  12 Synchronizing two command buffers

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool SynchronizeTwoCommandBuffers( VkQueue                         first_queue,
                                     std::vector<WaitSemaphoreInfo>  first_wait_semaphore_infos,
                                     std::vector<VkCommandBuffer>    first_command_buffers,
                                     std::vector<WaitSemaphoreInfo>  synchronizing_semaphores,
                                     VkQueue                         second_queue,
                                     std::vector<VkCommandBuffer>    second_command_buffers,
                                     std::vector<VkSemaphore>        second_signal_semaphores,
                                     VkFence                         second_fence ) {
    std::vector<VkSemaphore> first_signal_semaphores;
    for( auto & semaphore_info : synchronizing_semaphores ) {
      first_signal_semaphores.emplace_back( semaphore_info.Semaphore );
    }
    if( !SubmitCommandBuffersToQueue( first_queue, first_wait_semaphore_infos, first_command_buffers, first_signal_semaphores, VK_NULL_HANDLE ) ) {
      return false;
    }

    if( !SubmitCommandBuffersToQueue( second_queue, synchronizing_semaphores, second_command_buffers, second_signal_semaphores, second_fence ) ) {
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  13 Checking if processing of a submitted command buffer has finished

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool CheckIfProcessingOfSubmittedCommandBufferHasFinished( VkDevice                         logical_device,
                                                             VkQueue                          queue,
                                                             std::vector<WaitSemaphoreInfo>   wait_semaphore_infos,
                                                             std::vector<VkCommandBuffer>     command_buffers,
                                                             std::vector<VkSemaphore>         signal_semaphores,
                                                             VkFence                          fence,
                                                             uint64_t                         timeout,
                                                             VkResult                       & wait_status ) {
    if( !SubmitCommandBuffersToQueue( queue, wait_semaphore_infos, command_buffers, signal_semaphores, fence ) ) {
      return false;
    }

    return WaitForFences( logical_device, { fence }, VK_FALSE, timeout );
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  14 Waiting until all commands submitted to a queue are finished

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool WaitUntilAllCommandsSubmittedToQueueAreFinished( VkQueue queue ) {
    VkResult result = vkQueueWaitIdle( queue );
    if( VK_SUCCESS != result ) {
      std::cout << "Waiting for all operations submitted to queue failed." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  15 Waiting for all submitted commands to be finished

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  bool WaitForAllSubmittedCommandsToBeFinished( VkDevice logical_device ) {
    VkResult result = vkDeviceWaitIdle( logical_device );
    if( VK_SUCCESS != result ) {
      std::cout << "Waiting on a device failed." << std::endl;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  16 Destroying a fence

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  void DestroyFence( VkDevice   logical_device,
                     VkFence  & fence ) {
    if( VK_NULL_HANDLE != fence ) {
      vkDestroyFence( logical_device, fence, nullptr );
      fence = VK_NULL_HANDLE;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  17 Destroying a semaphore

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  void DestroySemaphore( VkDevice      logical_device,
                         VkSemaphore & semaphore ) {
    if( VK_NULL_HANDLE != semaphore ) {
      vkDestroySemaphore( logical_device, semaphore, nullptr );
      semaphore = VK_NULL_HANDLE;
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  18 Freeing command buffers

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  void FreeCommandBuffers( VkDevice                       logical_device,
                           VkCommandPool                  command_pool,
                           std::vector<VkCommandBuffer> & command_buffers ) {
    if( command_buffers.size() > 0 ) {
      vkFreeCommandBuffers( logical_device, command_pool, static_cast<uint32_t>(command_buffers.size()), command_buffers.data() );
      command_buffers.clear();
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
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  19 Destroying a command pool

#include "03_Command_Buffers_and_Synchronization/compacte.h"

namespace VulkanCookbook {

  void DestroyCommandPool( VkDevice        logical_device,
                           VkCommandPool & command_pool ) {
    if( VK_NULL_HANDLE != command_pool ) {
      vkDestroyCommandPool( logical_device, command_pool, nullptr );
      command_pool = VK_NULL_HANDLE;
    }
  }

} // namespace VulkanCookbook
