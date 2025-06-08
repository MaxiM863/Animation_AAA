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

#ifndef CLEARING_A_COLOR_IMAGE
#define CLEARING_A_COLOR_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  void ClearColorImage( VkCommandBuffer                              command_buffer,
                        VkImage                                      image,
                        VkImageLayout                                image_layout,
                        std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                        VkClearColorValue                          & clear_color );

} // namespace VulkanCookbook

#endif // CLEARING_A_COLOR_IMAGE
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

#ifndef CLEARING_A_DEPTH_STENCIL_IMAGE
#define CLEARING_A_DEPTH_STENCIL_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  void ClearDepthStencilImage( VkCommandBuffer                              command_buffer,
                               VkImage                                      image,
                               VkImageLayout                                image_layout,
                               std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                               VkClearDepthStencilValue                   & clear_value );

} // namespace VulkanCookbook

#endif // CLEARING_A_DEPTH_STENCIL_IMAGE
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

#ifndef CLEARING_RENDER_PASS_ATTACHMENTS
#define CLEARING_RENDER_PASS_ATTACHMENTS

#include "Common.h"

namespace VulkanCookbook {

  void ClearRenderPassAttachments( VkCommandBuffer                        command_buffer,
                                   std::vector<VkClearAttachment> const & attachments,
                                   std::vector<VkClearRect> const       & rects );

} // namespace VulkanCookbook

#endif // CLEARING_RENDER_PASS_ATTACHMENTS
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

#ifndef BINDING_VERTEX_BUFFERS
#define BINDING_VERTEX_BUFFERS

#include "Common.h"

namespace VulkanCookbook {

  struct VertexBufferParameters {
    VkBuffer      Buffer;
    VkDeviceSize  MemoryOffset;
  };

  void BindVertexBuffers( VkCommandBuffer                             command_buffer,
                          uint32_t                                    first_binding,
                          std::vector<VertexBufferParameters> const & buffers_parameters );

} // namespace VulkanCookbook

#endif // BINDING_VERTEX_BUFFERS
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

#ifndef BINDING_AN_INDEX_BUFFER
#define BINDING_AN_INDEX_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  void BindIndexBuffer( VkCommandBuffer   command_buffer,
                        VkBuffer          buffer,
                        VkDeviceSize      memory_offset,
                        VkIndexType       index_type );

} // namespace VulkanCookbook

#endif // BINDING_AN_INDEX_BUFFER
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

#ifndef PROVIDING_DATA_TO_SHADERS_THROUGH_PUSH_CONSTANTS
#define PROVIDING_DATA_TO_SHADERS_THROUGH_PUSH_CONSTANTS

#include "Common.h"

namespace VulkanCookbook {

  void ProvideDataToShadersThroughPushConstants( VkCommandBuffer      command_buffer,
                                                 VkPipelineLayout     pipeline_layout,
                                                 VkShaderStageFlags   pipeline_stages,
                                                 uint32_t             offset,
                                                 uint32_t             size,
                                                 void               * data );

} // namespace VulkanCookbook

#endif // PROVIDING_DATA_TO_SHADERS_THROUGH_PUSH_CONSTANTS
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

#ifndef SETTING_VIEWPORT_STATE_DYNAMICALLY
#define SETTING_VIEWPORT_STATE_DYNAMICALLY

#include "Common.h"

namespace VulkanCookbook {

  void SetViewportStateDynamically( VkCommandBuffer                 command_buffer,
                                    uint32_t                        first_viewport,
                                    std::vector<VkViewport> const & viewports );

} // namespace VulkanCookbook

#endif // SETTING_VIEWPORT_STATE_DYNAMICALLY
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

#ifndef SETTING_SCISSORS_STATE_DYNAMICALLY
#define SETTING_SCISSORS_STATE_DYNAMICALLY

#include "Common.h"

namespace VulkanCookbook {

  void SetScissorStateDynamically( VkCommandBuffer               command_buffer,
                                    uint32_t                      first_scissor,
                                    std::vector<VkRect2D> const & scissors );

} // namespace VulkanCookbook

#endif // SETTING_SCISSORS_STATE_DYNAMICALLY
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

#ifndef SETTING_LINE_WIDTH_STATE_DYNAMICALLY
#define SETTING_LINE_WIDTH_STATE_DYNAMICALLY

#include "Common.h"

namespace VulkanCookbook {

  void SetLineWidthStateDynamically( VkCommandBuffer command_buffer,
                                     float           line_width );

} // namespace VulkanCookbook

#endif // SETTING_LINE_WIDTH_STATE_DYNAMICALLY
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

#ifndef SETTING_DEPTH_BIAS_STATE_DYNAMICALLY
#define SETTING_DEPTH_BIAS_STATE_DYNAMICALLY

#include "Common.h"

namespace VulkanCookbook {

  void SetDepthBiasStateDynamically( VkCommandBuffer command_buffer,
                                     float           constant_factor,
                                     float           clamp_value,
                                     float           slope_factor );

} // namespace VulkanCookbook

#endif // SETTING_DEPTH_BIAS_STATE_DYNAMICALLY
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

#ifndef SETTING_BLEND_CONSTANTS_STATE_DYNAMICALLY
#define SETTING_BLEND_CONSTANTS_STATE_DYNAMICALLY

#include "Common.h"

namespace VulkanCookbook {

  void SetBlendConstantsStateDynamically( VkCommandBuffer              command_buffer,
                                          std::array<float, 4> const & blend_constants );

} // namespace VulkanCookbook

#endif // SETTING_BLEND_CONSTANTS_STATE_DYNAMICALLY
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

#ifndef DRAWING_A_GEOMETRY
#define DRAWING_A_GEOMETRY

#include "Common.h"

namespace VulkanCookbook {

  void DrawGeometry( VkCommandBuffer command_buffer,
                     uint32_t        vertex_count,
                     uint32_t        instance_count,
                     uint32_t        first_vertex,
                     uint32_t        first_instance );

} // namespace VulkanCookbook

#endif // DRAWING_A_GEOMETRY
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

#ifndef DRAWING_AN_INDEXED_GEOMETRY
#define DRAWING_AN_INDEXED_GEOMETRY

#include "Common.h"

namespace VulkanCookbook {

  void DrawIndexedGeometry( VkCommandBuffer command_buffer,
                            uint32_t        index_count,
                            uint32_t        instance_count,
                            uint32_t        first_index,
                            uint32_t        vertex_offset,
                            uint32_t        first_instance );

} // namespace VulkanCookbook

#endif // DRAWING_AN_INDEXED_GEOMETRY
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

#ifndef DISPATCHING_A_COMPUTE_WORK
#define DISPATCHING_A_COMPUTE_WORK

#include "Common.h"

namespace VulkanCookbook {

  void DispatchComputeWork( VkCommandBuffer command_buffer,
                            uint32_t        x_size,
                            uint32_t        y_size,
                            uint32_t        z_size );

} // namespace VulkanCookbook

#endif // DISPATCHING_A_COMPUTE_WORK
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

#ifndef EXECUTING_SECONDARY_COMMAND_BUFFER_INSIDE_A_PRIMARY_COMMAND_BUFFER
#define EXECUTING_SECONDARY_COMMAND_BUFFER_INSIDE_A_PRIMARY_COMMAND_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  void ExecuteSecondaryCommandBufferInsidePrimaryCommandBuffer( VkCommandBuffer                      primary_command_buffer,
                                                                std::vector<VkCommandBuffer> const & secondary_command_buffers );

} // namespace VulkanCookbook

#endif // EXECUTING_SECONDARY_COMMAND_BUFFER_INSIDE_A_PRIMARY_COMMAND_BUFFER
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

#ifndef RECORDING_A_COMMAND_BUFFER_THAT_DRAWS_A_GEOMETRY_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_STATES
#define RECORDING_A_COMMAND_BUFFER_THAT_DRAWS_A_GEOMETRY_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_STATES

#include "09_Command_Recording_and_Drawing/compacte.h"
#include "10_Helper_Recipes/compacte.h"

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
                                                                                uint32_t                                    first_instance );

} // namespace VulkanCookbook

#endif // RECORDING_A_COMMAND_BUFFER_THAT_DRAWS_A_GEOMETRY_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_STATES
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

#ifndef RECORDING_COMMAND_BUFFERS_ON_MULTIPLE_THREADS
#define RECORDING_COMMAND_BUFFERS_ON_MULTIPLE_THREADS

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "Common.h"

namespace VulkanCookbook {

  struct CommandBufferRecordingThreadParameters {
    VkCommandBuffer                         CommandBuffer;
    std::function<bool( VkCommandBuffer )>  RecordingFunction;
  };

  bool RecordCommandBuffersOnMultipleThreads( std::vector<CommandBufferRecordingThreadParameters> const & threads_parameters,
                                              VkQueue                                                     queue,
                                              std::vector<WaitSemaphoreInfo>                              wait_semaphore_infos,
                                              std::vector<VkSemaphore>                                    signal_semaphores,
                                              VkFence                                                     fence );

} // namespace VulkanCookbook

#endif // RECORDING_COMMAND_BUFFERS_ON_MULTIPLE_THREADS
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

#ifndef PREPARING_A_SINGLE_FRAME_OF_ANIMATION
#define PREPARING_A_SINGLE_FRAME_OF_ANIMATION

#include "03_Command_Buffers_and_Synchronization/compacte.h"
#include "Common.h"

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
                                      std::function<bool(VkCommandBuffer, uint32_t, VkFramebuffer)>   record_command_buffer,
                                      VkCommandBuffer                                                 command_buffer,
                                      VkRenderPass                                                    render_pass,
                                      VkDestroyer(VkFramebuffer)                                    & framebuffer );

} // namespace VulkanCookbook

#endif // PREPARING_A_SINGLE_FRAME_OF_ANIMATION
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

#ifndef INCREASING_THE_PERFORMANCE_THROUGH_INCREASING_THE_NUMBER_OF_SEPARATELY_RENDERED_FRAMES
#define INCREASING_THE_PERFORMANCE_THROUGH_INCREASING_THE_NUMBER_OF_SEPARATELY_RENDERED_FRAMES

#include "Common.h"
#include "03_Command_Buffers_and_Synchronization/compacte.h"


namespace VulkanCookbook {

  struct FrameResources {
    std::vector<VkCommandBuffer> CommandBuffer;
    VkDestroyer(VkSemaphore)    ImageAcquiredSemaphore;
    VkDestroyer(VkSemaphore)    ReadyToPresentSemaphore;
    VkDestroyer(VkFence)        DrawingFinishedFence;
    VkDestroyer(VkImageView)    DepthAttachment;
    VkDestroyer(VkFramebuffer)  Framebuffer;

    FrameResources( std::vector<VkCommandBuffer>            command_buffer,
                    VkDestroyer(VkSemaphore)   & image_acquired_semaphore,
                    VkDestroyer(VkSemaphore)   & ready_to_present_semaphore,
                    VkDestroyer(VkFence)       & drawing_finished_fence,
                    VkDestroyer(VkImageView)   & depth_attachment) :
      CommandBuffer( command_buffer ),
      ImageAcquiredSemaphore( std::move(image_acquired_semaphore) ),
      ReadyToPresentSemaphore( std::move(ready_to_present_semaphore) ),
      DrawingFinishedFence( std::move( drawing_finished_fence ) ),
      DepthAttachment( std::move( depth_attachment ) ),
      Framebuffer( std::move( VkDestroyer(VkFramebuffer)() ) ) {
    }

    FrameResources( FrameResources && other ) {
      *this = std::move( other );
    }

    FrameResources& operator=(FrameResources && other) {
      if( this != &other ) {
        std::vector<VkCommandBuffer> command_buffer = CommandBuffer;

        CommandBuffer = other.CommandBuffer;
        other.CommandBuffer = command_buffer;
        ImageAcquiredSemaphore = std::move( other.ImageAcquiredSemaphore );
        ReadyToPresentSemaphore = std::move( other.ReadyToPresentSemaphore );
        DrawingFinishedFence = std::move( other.DrawingFinishedFence );
        DepthAttachment = std::move( other.DepthAttachment );
        Framebuffer = std::move( other.Framebuffer );
      }
      return *this;
    }

    FrameResources( FrameResources const & ) = delete;
    FrameResources& operator=(FrameResources const &) = delete;
  };

  bool IncreasePerformanceThroughIncreasingTheNumberOfSeparatelyRenderedFrames( VkDevice                                                        logical_device,
                                                                                VkQueue                                                         graphics_queue,
                                                                                VkQueue                                                         present_queue,
                                                                                VkSwapchainKHR                                                  swapchain,
                                                                                VkExtent2D                                                      swapchain_size,
                                                                                std::vector<VkImageView> const                                & swapchain_image_views,
                                                                                VkRenderPass                                                    render_pass,
                                                                                std::vector<WaitSemaphoreInfo> const                          & wait_infos,
                                                                                std::function<bool(std::vector<VkCommandBuffer>, uint32_t, VkFramebuffer)>   record_command_buffer,
                                                                                std::vector<FrameResources>                                   & frame_resources );

} // namespace VulkanCookbook

#endif // INCREASING_THE_PERFORMANCE_THROUGH_INCREASING_THE_NUMBER_OF_SEPARATELY_RENDERED_FRAMES
