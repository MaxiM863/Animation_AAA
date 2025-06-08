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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  01 Specifying attachments descriptions

#ifndef SPECIFYING_ATTACHMENTS_DESCRIPTIONS
#define SPECIFYING_ATTACHMENTS_DESCRIPTIONS

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyAttachmentsDescriptions( std::vector<VkAttachmentDescription> const & attachments_descriptions );

} // namespace VulkanCookbook

#endif // SPECIFYING_ATTACHMENTS_DESCRIPTIONS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  02 Specifying subpass descriptions

#ifndef SPECIFYING_SUBPASS_DESCRIPTIONS
#define SPECIFYING_SUBPASS_DESCRIPTIONS

#include "Common.h"

namespace VulkanCookbook {

  struct SubpassParameters {
    VkPipelineBindPoint                  PipelineType;
    std::vector<VkAttachmentReference>   InputAttachments;
    std::vector<VkAttachmentReference>   ColorAttachments;
    std::vector<VkAttachmentReference>   ResolveAttachments;
    VkAttachmentReference const        * DepthStencilAttachment;
    std::vector<uint32_t>                PreserveAttachments;
  };

  void SpecifySubpassDescriptions( std::vector<SubpassParameters> const & subpass_parameters,
                                   std::vector<VkSubpassDescription>    & subpass_descriptions );

} // namespace VulkanCookbook

#endif // SPECIFYING_SUBPASS_DESCRIPTIONS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  03 Specifying dependencies between subpasses

#ifndef SPECIFYING_DEPENDENCIES_BETWEEN_SUBPASSES
#define SPECIFYING_DEPENDENCIES_BETWEEN_SUBPASSES

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyDependenciesBetweenSubpasses( std::vector<VkSubpassDependency> const & subpasses_dependencies );

} // namespace VulkanCookbook

#endif // SPECIFYING_DEPENDENCIES_BETWEEN_SUBPASSES
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  04 Creating a render pass

#ifndef CREATING_A_RENDER_PASS
#define CREATING_A_RENDER_PASS

#include "Common.h"
#include "06_Render_Passes_and_Framebuffers/compacte.h"

namespace VulkanCookbook {

  bool CreateRenderPass( VkDevice                                     logical_device,
                         std::vector<VkAttachmentDescription> const & attachments_descriptions,
                         std::vector<SubpassParameters> const       & subpass_parameters,
                         std::vector<VkSubpassDependency> const     & subpass_dependencies,
                         VkRenderPass                               & render_pass );

} // namespace VulkanCookbook

#endif // CREATING_A_RENDER_PASS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  05 Creating a framebuffer

#ifndef CREATING_A_FRAMEBUFFER
#define CREATING_A_FRAMEBUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateFramebuffer( VkDevice                         logical_device,
                          VkRenderPass                     render_pass,
                          std::vector<VkImageView> const & attachments,
                          uint32_t                         width,
                          uint32_t                         height,
                          uint32_t                         layers,
                          VkFramebuffer                  & framebuffer );

} // namespace VulkanCookbook

#endif // CREATING_A_FRAMEBUFFER
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  06 Preparing a render pass for geometry rendering and postprocess subpasses

#ifndef PREPARING_A_RENDER_PASS_FOR_GEOMETRY_RENDERING_AND_POSTPROCESS_SUBPASSES
#define PREPARING_A_RENDER_PASS_FOR_GEOMETRY_RENDERING_AND_POSTPROCESS_SUBPASSES

#include "Common.h"

namespace VulkanCookbook {

  bool PrepareRenderPassForGeometryRenderingAndPostprocessSubpasses( VkDevice     logical_device,
                                                                     VkRenderPass render_pass );

} // namespace VulkanCookbook

#endif // PREPARING_A_RENDER_PASS_FOR_GEOMETRY_RENDERING_AND_POSTPROCESS_SUBPASSES
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  07 Preparing a render pass and a framebuffer with color and depth attachments

#ifndef PREPARING_A_RENDER_PASS_AND_A_FRAMEBUFFER_WITH_COLOR_AND_DEPTH_ATTACHMENTS
#define PREPARING_A_RENDER_PASS_AND_A_FRAMEBUFFER_WITH_COLOR_AND_DEPTH_ATTACHMENTS

#include "Common.h"

namespace VulkanCookbook {

  bool PrepareRenderPassAndFramebufferWithColorAndDepthAttachments( VkPhysicalDevice        physical_device,
                                                                    VkDevice                logical_device,
                                                                    uint32_t                width,
                                                                    uint32_t                height,
                                                                    VkImage               & color_image,
                                                                    VkDeviceMemory        & color_image_memory_object,
                                                                    VkImageView           & color_image_view,
                                                                    VkImage               & depth_image,
                                                                    VkDeviceMemory        & depth_image_memory_object,
                                                                    VkImageView           & depth_image_view,
                                                                    VkRenderPass          & render_pass,
                                                                    VkFramebuffer         & framebuffer );

} // namespace VulkanCookbook

#endif // PREPARING_A_RENDER_PASS_AND_A_FRAMEBUFFER_WITH_COLOR_AND_DEPTH_ATTACHMENTS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  08 Beginning a render pass

#ifndef BEGINNING_A_RENDER_PASS
#define BEGINNING_A_RENDER_PASS

#include "Common.h"

namespace VulkanCookbook {

  void BeginRenderPass( VkCommandBuffer                   command_buffer,
                        VkRenderPass                      render_pass,
                        VkFramebuffer                     framebuffer,
                        VkRect2D                          render_area,
                        std::vector<VkClearValue> const & clear_values,
                        VkSubpassContents                 subpass_contents );

} // namespace VulkanCookbook

#endif // BEGINNING_A_RENDER_PASS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  09 Progressing to the next subpass

#ifndef PROGRESSING_TO_THE_NEXT_SUBPASS
#define PROGRESSING_TO_THE_NEXT_SUBPASS

#include "Common.h"

namespace VulkanCookbook {

  void ProgressToTheNextSubpass( VkCommandBuffer   command_buffer,
                                 VkSubpassContents subpass_contents );

} // namespace VulkanCookbook

#endif // PROGRESSING_TO_THE_NEXT_SUBPASS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  10 Ending a render pass

#ifndef ENDING_A_RENDER_PASS
#define ENDING_A_RENDER_PASS

#include "Common.h"

namespace VulkanCookbook {

  void EndRenderPass( VkCommandBuffer command_buffer );

} // namespace VulkanCookbook

#endif // ENDING_A_RENDER_PASS
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  11 Destroying a framebuffer

#ifndef DESTROYING_A_FRAMEBUFFER
#define DESTROYING_A_FRAMEBUFFER

#include "Common.h"

namespace VulkanCookbook {

  void DestroyFramebuffer( VkDevice        logical_device,
                           VkFramebuffer & framebuffer );

} // namespace VulkanCookbook

#endif // DESTROYING_A_FRAMEBUFFER
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
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  12 Destroying a render pass

#ifndef DESTROYING_A_RENDER_PASS
#define DESTROYING_A_RENDER_PASS

#include "Common.h"

namespace VulkanCookbook {

  void DestroyRenderPass( VkDevice       logical_device,
                          VkRenderPass & render_pass );

} // namespace VulkanCookbook

#endif // DESTROYING_A_RENDER_PASS
