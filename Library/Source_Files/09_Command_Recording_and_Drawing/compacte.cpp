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
// Chapter: 09 Command Recording and Drawing
// Recipe:  01 Clearing a color image

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void ClearColorImage( VkCommandBuffer                              command_buffer,
                        VkImage                                      image,
                        VkImageLayout                                image_layout,
                        std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                        VkClearColorValue                          & clear_color ) {
    vkCmdClearColorImage( command_buffer, image, image_layout, &clear_color, static_cast<uint32_t>(image_subresource_ranges.size()), image_subresource_ranges.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  02 Clearing a depth-stencil image

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void ClearDepthStencilImage( VkCommandBuffer                              command_buffer,
                               VkImage                                      image,
                               VkImageLayout                                image_layout,
                               std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                               VkClearDepthStencilValue                   & clear_value ) {
    vkCmdClearDepthStencilImage( command_buffer, image, image_layout, &clear_value, static_cast<uint32_t>(image_subresource_ranges.size()), image_subresource_ranges.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  03 Clearing render pass attachments

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void ClearRenderPassAttachments( VkCommandBuffer                        command_buffer,
                                   std::vector<VkClearAttachment> const & attachments,
                                   std::vector<VkClearRect> const       & rects ) {
    vkCmdClearAttachments( command_buffer, static_cast<uint32_t>(attachments.size()), attachments.data(), static_cast<uint32_t>(rects.size()), rects.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  04 Binding vertex buffers

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void BindVertexBuffers( VkCommandBuffer                             command_buffer,
                          uint32_t                                    first_binding,
                          std::vector<VertexBufferParameters> const & buffers_parameters ) {
    if( buffers_parameters.size() > 0 ) {
      std::vector<VkBuffer>     buffers;
      std::vector<VkDeviceSize> offsets;
      for( auto & buffer_parameters : buffers_parameters ) {
        buffers.push_back( buffer_parameters.Buffer );
        offsets.push_back( buffer_parameters.MemoryOffset );
      }
      vkCmdBindVertexBuffers( command_buffer, first_binding, static_cast<uint32_t>(buffers_parameters.size()), buffers.data(), offsets.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  05 Binding an index buffer

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void BindIndexBuffer( VkCommandBuffer   command_buffer,
                        VkBuffer          buffer,
                        VkDeviceSize      memory_offset,
                        VkIndexType       index_type ) {
    vkCmdBindIndexBuffer( command_buffer, buffer, memory_offset, index_type );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  06 Providing data to shaders through push constants

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void ProvideDataToShadersThroughPushConstants( VkCommandBuffer      command_buffer,
                                                 VkPipelineLayout     pipeline_layout,
                                                 VkShaderStageFlags   pipeline_stages,
                                                 uint32_t             offset,
                                                 uint32_t             size,
                                                 void               * data ) {
    vkCmdPushConstants( command_buffer, pipeline_layout, pipeline_stages, offset, size, data );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  07 Setting viewport state dynamically

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void SetViewportStateDynamically( VkCommandBuffer                 command_buffer,
                                    uint32_t                        first_viewport,
                                    std::vector<VkViewport> const & viewports ) {
    vkCmdSetViewport( command_buffer, first_viewport, static_cast<uint32_t>(viewports.size()), viewports.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  08 Setting scissor state dynamically

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void SetScissorStateDynamically( VkCommandBuffer               command_buffer,
                                    uint32_t                      first_scissor,
                                    std::vector<VkRect2D> const & scissors ) {
    vkCmdSetScissor( command_buffer, first_scissor, static_cast<uint32_t>(scissors.size()), scissors.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  09 Setting line width state dynamically

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void SetLineWidthStateDynamically( VkCommandBuffer command_buffer,
                                     float           line_width ) {
    vkCmdSetLineWidth( command_buffer, line_width );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  10 Setting depth bias state dynamically

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void SetDepthBiasStateDynamically( VkCommandBuffer command_buffer,
                                     float           constant_factor,
                                     float           clamp,
                                     float           slope_factor ) {
    vkCmdSetDepthBias( command_buffer, constant_factor, clamp, slope_factor );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  11 Setting blend constants state dynamically

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void SetBlendConstantsStateDynamically( VkCommandBuffer              command_buffer,
                                          std::array<float, 4> const & blend_constants ) {
    vkCmdSetBlendConstants( command_buffer, blend_constants.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  12 Drawing a geometry

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void DrawGeometry( VkCommandBuffer command_buffer,
                     uint32_t        vertex_count,
                     uint32_t        instance_count,
                     uint32_t        first_vertex,
                     uint32_t        first_instance ) {
    vkCmdDraw( command_buffer, vertex_count, instance_count, first_vertex, first_instance );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  13 Drawing an indexed geometry

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void DrawIndexedGeometry( VkCommandBuffer command_buffer,
                            uint32_t        index_count,
                            uint32_t        instance_count,
                            uint32_t        first_index,
                            uint32_t        vertex_offset,
                            uint32_t        first_instance ) {
    vkCmdDrawIndexed( command_buffer, index_count, instance_count, first_index, vertex_offset, first_instance );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  14 Dispatching compute work

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void DispatchComputeWork( VkCommandBuffer command_buffer,
                            uint32_t        x_size,
                            uint32_t        y_size,
                            uint32_t        z_size ) {
    vkCmdDispatch( command_buffer, x_size, y_size, z_size );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  15 Executing secondary command buffer inside a primary command buffer

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  void ExecuteSecondaryCommandBufferInsidePrimaryCommandBuffer( VkCommandBuffer                      command_buffer,
                                                                std::vector<VkCommandBuffer> const & secondary_command_buffers ) {
    if( secondary_command_buffers.size() > 0 ) {
      vkCmdExecuteCommands( command_buffer, static_cast<uint32_t>(secondary_command_buffers.size()), secondary_command_buffers.data() );
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  16 Recording a command buffer that draws a geometry with dynamic viewport and scissor states

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "04_Resources_and_Memory/compacte.h"
#include "05_Descriptor_Sets/compacte.h"
#include "06_Render_Passes_and_Framebuffers/compacte.h"
#include "06_Render_Passes_and_Framebuffers/compacte.h"
#include "08_Graphics_and_Compute_Pipelines/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  bool RecordCommandBufferThatDrawsGeometryWithDynamicViewportAndScissorStates( VkCommandBuffer                             command_buffer,
                                                                                VkImage                                     swapchain_image,
                                                                                uint32_t                                    present_queue_family_index,
                                                                                uint32_t                                    graphics_queue_family_index,
                                                                                VkRenderPass                                render_pass,
                                                                                VkFramebuffer                               framebuffer,
                                                                                VkExtent2D                                  framebuffer_size,
                                                                                std::vector<VkClearValue> const &           clear_values,
                                                                                VkPipeline                                  graphics_pipeline,
                                                                                uint32_t                                    first_vertex_buffer_binding,
                                                                                std::vector<VertexBufferParameters> const & vertex_buffers_parameters,
                                                                                VkPipelineLayout                            pipeline_layout,
                                                                                std::vector<VkDescriptorSet> const &        descriptor_sets,
                                                                                uint32_t                                    index_for_first_descriptor_set,
                                                                                Mesh const &                                geometry,
                                                                                uint32_t                                    instance_count,
                                                                                uint32_t                                    first_instance ) {
    if( !BeginCommandBufferRecordingOperation( command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr ) ) {
      return false;
    }

    if( present_queue_family_index != graphics_queue_family_index ) {
      ImageTransition image_transition_before_drawing = {
        swapchain_image,                          // VkImage              Image
        VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        CurrentAccess
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,     // VkAccessFlags        NewAccess
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        CurrentLayout
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        NewLayout
        present_queue_family_index,               // uint32_t             CurrentQueueFamily
        graphics_queue_family_index,              // uint32_t             NewQueueFamily
        VK_IMAGE_ASPECT_COLOR_BIT                 // VkImageAspectFlags   Aspect
      };
      SetImageMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, { image_transition_before_drawing } );
    }

    BeginRenderPass( command_buffer, render_pass, framebuffer, { { 0, 0 }, framebuffer_size }, clear_values, VK_SUBPASS_CONTENTS_INLINE );

    BindPipelineObject( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline );

    VkViewport viewport = {
      0.0f,                                         // float          x
      0.0f,                                         // float          y
      static_cast<float>(framebuffer_size.width),   // float          width
      static_cast<float>(framebuffer_size.height),  // float          height
      0.0f,                                         // float          minDepth
      1.0f,                                         // float          maxDepth
    };
    SetViewportStateDynamically( command_buffer, 0, { viewport } );

    VkRect2D scissor = {
      {                                             // VkOffset2D     offset
        0,                                            // int32_t        x
        0                                             // int32_t        y
      },
      {                                             // VkExtent2D     extent
        framebuffer_size.width,                         // uint32_t       width
        framebuffer_size.height                         // uint32_t       height
      }
    };
    SetScissorStateDynamically( command_buffer, 0, { scissor } );

    BindVertexBuffers( command_buffer, first_vertex_buffer_binding, vertex_buffers_parameters );

    if( descriptor_sets.size() > 0 ) {
      BindDescriptorSets( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_layout, index_for_first_descriptor_set, descriptor_sets, {} );
    }

    for( size_t i = 0; i < geometry.Parts.size(); ++i ) {
      DrawGeometry( command_buffer, geometry.Parts[i].VertexCount, instance_count, geometry.Parts[i].VertexOffset, first_instance );
    }

    EndRenderPass( command_buffer );

    if( present_queue_family_index != graphics_queue_family_index ) {
      ImageTransition image_transition_before_present = {
        swapchain_image,                          // VkImage              Image
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,     // VkAccessFlags        CurrentAccess
        VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        NewAccess
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        CurrentLayout
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        NewLayout
        graphics_queue_family_index,              // uint32_t             CurrentQueueFamily
        present_queue_family_index,               // uint32_t             NewQueueFamily
        VK_IMAGE_ASPECT_COLOR_BIT                 // VkImageAspectFlags   Aspect
      };
      SetImageMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, { image_transition_before_present } );
    }

    if( !EndCommandBufferRecordingOperation( command_buffer ) ) {
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  17 Recording command buffers on multiple threads

#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  bool RecordCommandBuffersOnMultipleThreads( std::vector<CommandBufferRecordingThreadParameters> const & threads_parameters,
                                              VkQueue                                                     queue,
                                              std::vector<WaitSemaphoreInfo>                              wait_semaphore_infos,
                                              std::vector<VkSemaphore>                                    signal_semaphores,
                                              VkFence                                                     fence ) {

    std::vector<std::thread> threads( threads_parameters.size() );
    for( size_t i = 0; i < threads_parameters.size(); ++i ) {
      threads[i] = std::thread( threads_parameters[i].RecordingFunction, threads_parameters[i].CommandBuffer );
    }

    std::vector<VkCommandBuffer> command_buffers( threads_parameters.size() );
    for( size_t i = 0; i < threads_parameters.size(); ++i ) {
      threads[i].join();
      command_buffers[i] = threads_parameters[i].CommandBuffer;
    }

    if( !SubmitCommandBuffersToQueue( queue, wait_semaphore_infos, command_buffers, signal_semaphores, fence ) ) {
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  18 Preparing a single frame of animation

#include "02_Image_Presentation/compacte.h"
#include "02_Image_Presentation/compacte.h"
#include "06_Render_Passes_and_Framebuffers/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  bool PrepareSingleFrameOfAnimation( VkDevice                                                        logical_device,
                                      VkQueue                                                         graphics_queue,
                                      VkQueue                                                         present_queue,
                                      VkSwapchainKHR                                                  swapchain,
                                      VkExtent2D                                                      swapchain_size,
                                      std::vector<VkImageView> const                                & swapchain_image_views,
                                      VkImageView                                                     depth_attachment,
                                      std::vector<WaitSemaphoreInfo> const                          & wait_infos,
                                      VkSemaphore                                                     image_acquired_semaphore,
                                      VkSemaphore                                                     ready_to_present_semaphore,
                                      VkFence                                                         finished_drawing_fence,
                                      std::function<bool(std::vector<VkCommandBuffer>, uint32_t, VkFramebuffer)>   record_command_buffer,
                                      std::vector<VkCommandBuffer>                                  command_buffer,
                                      VkRenderPass                                                    render_pass,
                                      VkDestroyer(VkFramebuffer)                                    & framebuffer ) {
    uint32_t image_index;
    if( !AcquireSwapchainImage( logical_device, swapchain, image_acquired_semaphore, VK_NULL_HANDLE, image_index ) ) {
      return false;
    }

    std::vector<VkImageView> attachments = { swapchain_image_views[image_index] };
    if( VK_NULL_HANDLE != depth_attachment ) {
      attachments.push_back( depth_attachment );
    }
    if( !CreateFramebuffer( logical_device, render_pass, attachments, swapchain_size.width, swapchain_size.height, 1, *framebuffer ) ) {
      return false;
    }

    if( !record_command_buffer( command_buffer, image_index, *framebuffer ) ) {
        return false;
      }
    

    std::vector<WaitSemaphoreInfo> wait_semaphore_infos = wait_infos;
    wait_semaphore_infos.push_back( {
      image_acquired_semaphore,                     // VkSemaphore            Semaphore
      VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT // VkPipelineStageFlags   WaitingStage
    } );

    if( !SubmitCommandBuffersToQueue( graphics_queue, wait_semaphore_infos, command_buffer, { ready_to_present_semaphore }, finished_drawing_fence ) ) {
      return false;
    }
    
    PresentInfo present_info = {
      swapchain,                                    // VkSwapchainKHR         Swapchain
      image_index                                   // uint32_t               ImageIndex
    };
    if( !PresentImage( present_queue, { ready_to_present_semaphore }, { present_info } ) ) {
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
// Chapter: 09 Command Recording and Drawing
// Recipe:  19 Increasing the performance through increasing the number of separately rendered frames

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "06_Render_Passes_and_Framebuffers/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"
#include "09_Command_Recording_and_Drawing/compacte.h"

namespace VulkanCookbook {

  bool IncreasePerformanceThroughIncreasingTheNumberOfSeparatelyRenderedFrames( VkDevice                                                        logical_device,
                                                                                VkQueue                                                         graphics_queue,
                                                                                VkQueue                                                         present_queue,
                                                                                VkSwapchainKHR                                                  swapchain,
                                                                                VkExtent2D                                                      swapchain_size,
                                                                                std::vector<VkImageView> const                                & swapchain_image_views,
                                                                                VkRenderPass                                                    render_pass,
                                                                                std::vector<WaitSemaphoreInfo> const                          & wait_infos,
                                                                                std::function<bool(std::vector<VkCommandBuffer>, uint32_t, VkFramebuffer)>   record_command_buffer,
                                                                                std::vector<FrameResources>                                   & frame_resources ) {
    static uint32_t frame_index = 0;
    FrameResources & current_frame = frame_resources[frame_index];

    if( !WaitForFences( logical_device, { *current_frame.DrawingFinishedFence }, false, 2000000000 ) ) {
      return false;
    }
    if( !ResetFences( logical_device, { *current_frame.DrawingFinishedFence } ) ) {
      return false;
    }

    InitVkDestroyer( logical_device, current_frame.Framebuffer );

    if( !PrepareSingleFrameOfAnimation( logical_device, graphics_queue, present_queue, swapchain, swapchain_size, swapchain_image_views,
      *current_frame.DepthAttachment, wait_infos, *current_frame.ImageAcquiredSemaphore, *current_frame.ReadyToPresentSemaphore,
      *current_frame.DrawingFinishedFence, record_command_buffer, current_frame.CommandBuffer, render_pass, current_frame.Framebuffer ) ) {
      return false;
    }

    frame_index = (frame_index + 1) % frame_resources.size();
    return true;
  }

} // namespace VulkanCookbook
