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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  01 Creating a shader module

#ifndef CREATING_A_SHADER_MODULE
#define CREATING_A_SHADER_MODULE

#include "Common.h"

namespace VulkanCookbook {

  bool CreateShaderModule( VkDevice                           logical_device,
                           std::vector<unsigned char> const & source_code,
                           VkShaderModule                   & shader_module );

} // namespace VulkanCookbook

#endif // CREATING_A_SHADER_MODULE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  02 Specifying pipeline shader stages

#ifndef SPECIFYING_PIPELINE_SHADER_STAGES
#define SPECIFYING_PIPELINE_SHADER_STAGES

#include "Common.h"

namespace VulkanCookbook {

  struct ShaderStageParameters {
    VkShaderStageFlagBits        ShaderStage;
    VkShaderModule               ShaderModule;
    char const                 * EntryPointName;
    VkSpecializationInfo const * SpecializationInfo;
  };

  void SpecifyPipelineShaderStages( std::vector<ShaderStageParameters> const     & shader_stage_params,
                                    std::vector<VkPipelineShaderStageCreateInfo> & shader_stage_create_infos );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_SHADER_STAGES
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  03 Specifying pipeline vertex input state

#ifndef SPECIFYING_PIPELINE_VERTEX_INPUT_STATE
#define SPECIFYING_PIPELINE_VERTEX_INPUT_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineVertexInputState( std::vector<VkVertexInputBindingDescription> const   & binding_descriptions,
                                        std::vector<VkVertexInputAttributeDescription> const & attribute_descriptions,
                                        VkPipelineVertexInputStateCreateInfo                 & vertex_input_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_VERTEX_INPUT_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  04 Specifying pipeline input assembly state

#ifndef SPECIFYING_PIPELINE_INPUT_ASSEMBLY_STATE
#define SPECIFYING_PIPELINE_INPUT_ASSEMBLY_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineInputAssemblyState( VkPrimitiveTopology                      topology,
                                          bool                                     primitive_restart_enable,
                                          VkPipelineInputAssemblyStateCreateInfo & input_assembly_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_INPUT_ASSEMBLY_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  05 Specifying pipeline tessellation state

#ifndef SPECIFYING_PIPELINE_TESSELLATION_STATE
#define SPECIFYING_PIPELINE_TESSELLATION_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineTessellationState( uint32_t                                patch_control_points_count,
                                         VkPipelineTessellationStateCreateInfo & tessellation_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_TESSELLATION_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  06 Specifying pipeline viewport and scissor test state

#ifndef SPECIFYING_PIPELINE_VIEWPORT_AND_SCISSOR_TEST_STATE
#define SPECIFYING_PIPELINE_VIEWPORT_AND_SCISSOR_TEST_STATE

#include "Common.h"

namespace VulkanCookbook {

  struct ViewportInfo {
    std::vector<VkViewport>   Viewports;
    std::vector<VkRect2D>     Scissors;
  };

  void SpecifyPipelineViewportAndScissorTestState( ViewportInfo const                & viewport_infos,
                                                   VkPipelineViewportStateCreateInfo & viewport_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_VIEWPORT_AND_SCISSOR_TEST_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  07 Specifying pipeline rasterization state

#ifndef SPECIFYING_PIPELINE_RASTERIZATION_STATE
#define SPECIFYING_PIPELINE_RASTERIZATION_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineRasterizationState( bool                                     depth_clamp_enable,
                                          bool                                     rasterizer_discard_enable,
                                          VkPolygonMode                            polygon_mode,
                                          VkCullModeFlags                          culling_mode,
                                          VkFrontFace                              front_face,
                                          bool                                     depth_bias_enable,
                                          float                                    depth_bias_constant_factor,
                                          float                                    depth_bias_clamp,
                                          float                                    depth_bias_slope_factor,
                                          float                                    line_width,
                                          VkPipelineRasterizationStateCreateInfo & rasterization_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_RASTERIZATION_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  08 Specifying pipeline multisample state

#ifndef SPECIFYING_PIPELINE_MULTISAMPLE_STATE
#define SPECIFYING_PIPELINE_MULTISAMPLE_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineMultisampleState( VkSampleCountFlagBits                  sample_count,
                                        bool                                   per_sample_shading_enable,
                                        float                                  min_sample_shading,
                                        VkSampleMask const                   * sample_masks,
                                        bool                                   alpha_to_coverage_enable,
                                        bool                                   alpha_to_one_enable,
                                        VkPipelineMultisampleStateCreateInfo & multisample_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_MULTISAMPLE_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  09 Specifying pipeline depth and stencil state

#ifndef SPECIFYING_PIPELINE_DEPTH_AND_STENCIL_STATE
#define SPECIFYING_PIPELINE_DEPTH_AND_STENCIL_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineDepthAndStencilState( bool                                    depth_test_enable,
                                            bool                                    depth_write_enable,
                                            VkCompareOp                             depth_compare_op,
                                            bool                                    depth_bounds_test_enable,
                                            float                                   min_depth_bounds,
                                            float                                   max_depth_bounds,
                                            bool                                    stencil_test_enable,
                                            VkStencilOpState                        front_stencil_test_parameters,
                                            VkStencilOpState                        back_stencil_test_parameters,
                                            VkPipelineDepthStencilStateCreateInfo & depth_and_stencil_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_DEPTH_AND_STENCIL_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  10 Specifying pipeline blend state

#ifndef SPECIFYING_PIPELINE_BLEND_STATE
#define SPECIFYING_PIPELINE_BLEND_STATE

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineBlendState( bool                                                     logic_op_enable,
                                  VkLogicOp                                                logic_op,
                                  std::vector<VkPipelineColorBlendAttachmentState> const & attachment_blend_states,
                                  std::array<float, 4> const                             & blend_constants,
                                  VkPipelineColorBlendStateCreateInfo                    & blend_state_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_BLEND_STATE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  11 Specifying pipeline dynamic states

#ifndef SPECIFYING_PIPELINE_DYNAMIC_STATES
#define SPECIFYING_PIPELINE_DYNAMIC_STATES

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyPipelineDynamicStates( std::vector<VkDynamicState> const & dynamic_states,
                                     VkPipelineDynamicStateCreateInfo  & dynamic_state_creat_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_PIPELINE_DYNAMIC_STATES
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  12 Creating a pipeline layout

#ifndef CREATING_A_PIPELINE_LAYOUT
#define CREATING_A_PIPELINE_LAYOUT

#include "Common.h"

namespace VulkanCookbook {

  bool CreatePipelineLayout( VkDevice                                   logical_device,
                             std::vector<VkDescriptorSetLayout> const & descriptor_set_layouts,
                             std::vector<VkPushConstantRange> const   & push_constant_ranges,
                             VkPipelineLayout                         & pipeline_layout );

} // namespace VulkanCookbook

#endif // CREATING_A_PIPELINE_LAYOUT
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  13 Specifying graphics pipeline creation parameters

#ifndef SPECIFYING_GRAPHICS_PIPELINE_CREATION_PARAMETERS
#define SPECIFYING_GRAPHICS_PIPELINE_CREATION_PARAMETERS

#include "Common.h"

namespace VulkanCookbook {

  void SpecifyGraphicsPipelineCreationParameters( VkPipelineCreateFlags                                additional_options,
                                                  std::vector<VkPipelineShaderStageCreateInfo> const & shader_stage_create_infos,
                                                  VkPipelineVertexInputStateCreateInfo const         & vertex_input_state_create_info,
                                                  VkPipelineInputAssemblyStateCreateInfo const       & input_assembly_state_create_info,
                                                  VkPipelineTessellationStateCreateInfo const        * tessellation_state_create_info,
                                                  VkPipelineViewportStateCreateInfo const            * viewport_state_create_info,
                                                  VkPipelineRasterizationStateCreateInfo const       & rasterization_state_create_info,
                                                  VkPipelineMultisampleStateCreateInfo const         * multisample_state_create_info,
                                                  VkPipelineDepthStencilStateCreateInfo const        * depth_and_stencil_state_create_info,
                                                  VkPipelineColorBlendStateCreateInfo const          * blend_state_create_info,
                                                  VkPipelineDynamicStateCreateInfo const             * dynamic_state_creat_info,
                                                  VkPipelineLayout                                     pipeline_layout,
                                                  VkRenderPass                                         render_pass,
                                                  uint32_t                                             subpass,
                                                  VkPipeline                                           base_pipeline_handle,
                                                  int32_t                                              base_pipeline_index,
                                                  VkGraphicsPipelineCreateInfo                       & graphics_pipeline_create_info );

} // namespace VulkanCookbook

#endif // SPECIFYING_GRAPHICS_PIPELINE_CREATION_PARAMETERS
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  14 Creating a pipeline cache object

#ifndef CREATING_A_PIPELINE_CACHE_OBJECT
#define CREATING_A_PIPELINE_CACHE_OBJECT

#include "Common.h"

namespace VulkanCookbook {

  bool CreatePipelineCacheObject( VkDevice                           logical_device,
                                  std::vector<unsigned char> const & cache_data,
                                  VkPipelineCache                  & pipeline_cache );

} // namespace VulkanCookbook

#endif // CREATING_A_PIPELINE_CACHE_OBJECT
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  15 Retrieving data from a pipeline cache

#ifndef RETRIEVING_DATA_FROM_A_PIPELINE_CACHE
#define RETRIEVING_DATA_FROM_A_PIPELINE_CACHE

#include "Common.h"

namespace VulkanCookbook {

  bool RetrieveDataFromPipelineCache( VkDevice                     logical_device,
                                      VkPipelineCache              pipeline_cache,
                                      std::vector<unsigned char> & pipeline_cache_data );

} // namespace VulkanCookbook

#endif // RETRIEVING_DATA_FROM_A_PIPELINE_CACHE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  16 Merging multiple pipeline cache objects

#ifndef MERGING_MULTIPLE_PIPELINE_CACHE_OBJECTS
#define MERGING_MULTIPLE_PIPELINE_CACHE_OBJECTS

#include "Common.h"

namespace VulkanCookbook {

  bool MergeMultiplePipelineCacheObjects( VkDevice                             logical_device,
                                          VkPipelineCache                      target_pipeline_cache,
                                          std::vector<VkPipelineCache> const & source_pipeline_caches );

} // namespace VulkanCookbook

#endif // MERGING_MULTIPLE_PIPELINE_CACHE_OBJECTS
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  17 Creating graphics pipelines

#ifndef CREATING_GRAPHICS_PIPELINES
#define CREATING_GRAPHICS_PIPELINES

#include "Common.h"

namespace VulkanCookbook {

  bool CreateGraphicsPipelines( VkDevice                                             logical_device,
                                std::vector<VkGraphicsPipelineCreateInfo> const    & graphics_pipeline_create_infos,
                                VkPipelineCache                                      pipeline_cache,
                                std::vector<VkPipeline>                            & graphics_pipelines );

} // namespace VulkanCookbook

#endif // CREATING_A_GRAPHICS_PIPELINE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  18 Creating a compute pipeline

#ifndef CREATING_A_COMPUTE_PIPELINE
#define CREATING_A_COMPUTE_PIPELINE

#include "Common.h"

namespace VulkanCookbook {

  bool CreateComputePipeline( VkDevice                                logical_device,
                              VkPipelineCreateFlags                   additional_options,
                              VkPipelineShaderStageCreateInfo const & compute_shader_stage,
                              VkPipelineLayout                        pipeline_layout,
                              VkPipeline                              base_pipeline_handle,
                              VkPipelineCache                         pipeline_cache,
                              VkPipeline                            & compute_pipeline );

} // namespace VulkanCookbook

#endif // CREATING_A_COMPUTE_PIPELINE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  19 Binding a pipeline object

#ifndef BINDING_A_PIPELINE_OBJECT
#define BINDING_A_PIPELINE_OBJECT

#include "Common.h"

namespace VulkanCookbook {

  void BindPipelineObject( VkCommandBuffer     command_buffer,
                           VkPipelineBindPoint pipeline_type,
                           VkPipeline          pipeline );

} // namespace VulkanCookbook

#endif // BINDING_A_PIPELINE_OBJECT
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  20 Creating a pipeline layout with a combined image sampler, a buffer and push constant ranges

#ifndef CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES
#define CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES

#include "Common.h"

namespace VulkanCookbook {

  bool CreatePipelineLayoutWithCombinedImageSamplerBufferAndPushConstantRanges( VkDevice                                 logical_device,
                                                                                std::vector<VkPushConstantRange> const & push_constant_ranges,
                                                                                VkDescriptorSetLayout                  & descriptor_set_layout,
                                                                                VkPipelineLayout                       & pipeline_layout );

} // namespace VulkanCookbook

#endif // CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  21 Creating a graphics pipeline with vertex and fragment shaders, depth test enabled, and with dynamic viewport and scissor tests

#ifndef CREATING_A_GRAPHICS_PIPELINE_WITH_VERTEX_AND_FRAGMENT_SHADERS_DEPTH_TEST_ENABLED_AND_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_TESTS
#define CREATING_A_GRAPHICS_PIPELINE_WITH_VERTEX_AND_FRAGMENT_SHADERS_DEPTH_TEST_ENABLED_AND_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_TESTS

#include "Common.h"

namespace VulkanCookbook {

  bool CreateGraphicsPipelineWithVertexAndFragmentShadersDepthTestEnabledAndWithDynamicViewportAndScissorTests( VkDevice                                                 logical_device,
                                                                                                                VkPipelineCreateFlags                                    additional_options,
                                                                                                                std::string const                                      & vertex_shader_filename,
                                                                                                                std::string const                                      & fragment_shader_filename,
                                                                                                                std::vector<VkVertexInputBindingDescription> const     & vertex_input_binding_descriptions,
                                                                                                                std::vector<VkVertexInputAttributeDescription> const   & vertex_attribute_descriptions,
                                                                                                                VkPrimitiveTopology                                      primitive_topology,
                                                                                                                bool                                                     primitive_restart_enable,
                                                                                                                VkPolygonMode                                            polygon_mode,
                                                                                                                VkCullModeFlags                                          culling_mode,
                                                                                                                VkFrontFace                                              front_face,
                                                                                                                bool                                                     logic_op_enable,
                                                                                                                VkLogicOp                                                logic_op,
                                                                                                                std::vector<VkPipelineColorBlendAttachmentState> const & attachment_blend_states,
                                                                                                                std::array<float, 4> const                             & blend_constants,
                                                                                                                VkPipelineLayout                                         pipeline_layout,
                                                                                                                VkRenderPass                                             render_pass,
                                                                                                                uint32_t                                                 subpass,
                                                                                                                VkPipeline                                               base_pipeline_handle,
                                                                                                                VkPipelineCache                                          pipeline_cache,
                                                                                                                std::vector<VkPipeline>                                & graphics_pipeline );

} // namespace VulkanCookbook

#endif // CREATING_A_GRAPHICS_PIPELINE_WITH_VERTEX_AND_FRAGMENT_SHADERS_DEPTH_TEST_ENABLED_AND_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_TESTS
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  22 Creating multiple graphics pipelines on multiple threads

#ifndef CREATING_MULTIPLE_GRAPHICS_PIPELINES_ON_MULTIPLE_THREADS
#define CREATING_MULTIPLE_GRAPHICS_PIPELINES_ON_MULTIPLE_THREADS

#include "Common.h"

namespace VulkanCookbook {

  bool CreateMultipleGraphicsPipelinesOnMultipleThreads( VkDevice                                                       logical_device,
                                                         std::string const                                            & pipeline_cache_filename,
                                                         std::vector<std::vector<VkGraphicsPipelineCreateInfo>> const & graphics_pipelines_create_infos,
                                                         std::vector<std::vector<VkPipeline>>                         & graphics_pipelines );

} // namespace VulkanCookbook

#endif // CREATING_MULTIPLE_GRAPHICS_PIPELINES_ON_MULTIPLE_THREADS
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  23 Destroying a pipeline

#ifndef DESTROYING_A_PIPELINE
#define DESTROYING_A_PIPELINE

#include "Common.h"

namespace VulkanCookbook {

  void DestroyPipeline( VkDevice     logical_device,
                        VkPipeline & pipeline );

} // namespace VulkanCookbook

#endif // DESTROYING_A_PIPELINE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  24 Destroying a pipeline cache

#ifndef DESTROYING_A_PIPELINE_CACHE
#define DESTROYING_A_PIPELINE_CACHE

#include "Common.h"

namespace VulkanCookbook {

  void DestroyPipelineCache( VkDevice          logical_device,
                             VkPipelineCache & pipeline_cache );

} // namespace VulkanCookbook

#endif // DESTROYING_A_PIPELINE_CACHE
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  25 Destroying a pipeline layout

#ifndef DESTROYING_A_PIPELINE_LAYOUT
#define DESTROYING_A_PIPELINE_LAYOUT

#include "Common.h"

namespace VulkanCookbook {

  void DestroyPipelineLayout( VkDevice           logical_device,
                              VkPipelineLayout & pipeline_layout );

} // namespace VulkanCookbook

#endif // DESTROYING_A_PIPELINE_LAYOUT
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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  26 Destroying a shader module

#ifndef DESTROYING_A_SHADER_MODULE
#define DESTROYING_A_SHADER_MODULE

#include "Common.h"

namespace VulkanCookbook {

  void DestroyShaderModule( VkDevice         logical_device,
                            VkShaderModule & shader_module );

} // namespace VulkanCookbook

#endif // CREATING_A_COMPUTE_PIPELINE
