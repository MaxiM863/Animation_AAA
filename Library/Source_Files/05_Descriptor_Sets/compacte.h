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
// Chapter: 05 Descriptor Sets
// Recipe:  01 Creating a sampler

#ifndef CREATING_A_SAMPLER
#define CREATING_A_SAMPLER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateSampler( VkDevice               logical_device,
                      VkFilter               mag_filter,
                      VkFilter               min_filter,
                      VkSamplerMipmapMode    mipmap_mode,
                      VkSamplerAddressMode   u_address_mode,
                      VkSamplerAddressMode   v_address_mode,
                      VkSamplerAddressMode   w_address_mode,
                      float                  lod_bias,
                      bool                   anisotropy_enable,
                      float                  max_anisotropy,
                      bool                   compare_enable,
                      VkCompareOp            compare_operator,
                      float                  min_lod,
                      float                  max_lod,
                      VkBorderColor          border_color,
                      bool                   unnormalized_coords,
                      VkSampler            & sampler );

} // namespace VulkanCookbook

#endif // CREATING_A_SAMPLER
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
// Chapter: 05 Descriptor Sets
// Recipe:  02 Creating a sampled image

#ifndef CREATING_A_SAMPLED_IMAGE
#define CREATING_A_SAMPLED_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  bool CreateSampledImage( VkPhysicalDevice    physical_device,
                           VkDevice            logical_device,
                           VkImageType         type,
                           VkFormat            format,
                           VkExtent3D          size,
                           uint32_t            num_mipmaps,
                           uint32_t            num_layers,
                           VkImageUsageFlags   usage,
                           bool                cubemap,
                           VkImageViewType     view_type,
                           VkImageAspectFlags  aspect,
                           bool                linear_filtering,
                           VkImage           & sampled_image,
                           VkDeviceMemory    & memory_object,
                           VkImageView       & sampled_image_view );

} // namespace VulkanCookbook

#endif // CREATING_A_SAMPLED_IMAGE
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
// Chapter: 05 Descriptor Sets
// Recipe:  03 Creating a combined image sampler

#ifndef CREATING_A_COMBINED_IMAGE_SAMPLER
#define CREATING_A_COMBINED_IMAGE_SAMPLER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateCombinedImageSampler( VkPhysicalDevice       physical_device,
                                   VkDevice               logical_device,
                                   VkImageType            type,
                                   VkFormat               format,
                                   VkExtent3D             size,
                                   uint32_t               num_mipmaps,
                                   uint32_t               num_layers,
                                   VkImageUsageFlags      usage,
                                   bool                   cubemap,
                                   VkImageViewType        view_type,
                                   VkImageAspectFlags     aspect,
                                   VkFilter               mag_filter,
                                   VkFilter               min_filter,
                                   VkSamplerMipmapMode    mipmap_mode,
                                   VkSamplerAddressMode   u_address_mode,
                                   VkSamplerAddressMode   v_address_mode,
                                   VkSamplerAddressMode   w_address_mode,
                                   float                  lod_bias,
                                   bool                   anisotropy_enable,
                                   float                  max_anisotropy,
                                   bool                   compare_enable,
                                   VkCompareOp            compare_operator,
                                   float                  min_lod,
                                   float                  max_lod,
                                   VkBorderColor          border_color,
                                   bool                   unnormalized_coords,
                                   VkSampler            & sampler,
                                   VkImage              & sampled_image,
                                   VkDeviceMemory       & memory_object,
                                   VkImageView          & sampled_image_view );

} // namespace VulkanCookbook

#endif // CREATING_A_COMBINED_IMAGE_SAMPLER
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
// Chapter: 05 Descriptor Sets
// Recipe:  04 Creating a storage image

#ifndef CREATING_A_STORAGE_IMAGE
#define CREATING_A_STORAGE_IMAGE

#include "Common.h"

namespace VulkanCookbook {

  bool CreateStorageImage( VkPhysicalDevice    physical_device,
                           VkDevice            logical_device,
                           VkImageType         type,
                           VkFormat            format,
                           VkExtent3D          size,
                           uint32_t            num_mipmaps,
                           uint32_t            num_layers,
                           VkImageUsageFlags   usage,
                           VkImageViewType     view_type,
                           VkImageAspectFlags  aspect,
                           bool                atomic_operations,
                           VkImage           & storage_image,
                           VkDeviceMemory    & memory_object,
                           VkImageView       & storage_image_view );

} // namespace VulkanCookbook

#endif // CREATING_A_STORAGE_IMAGE
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
// Chapter: 05 Descriptor Sets
// Recipe:  05 Creating a uniform texel buffer

#ifndef CREATING_A_UNIFORM_TEXEL_BUFFER
#define CREATING_A_UNIFORM_TEXEL_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateUniformTexelBuffer( VkPhysicalDevice     physical_device,
                                 VkDevice             logical_device,
                                 VkFormat             format,
                                 VkDeviceSize         size,
                                 VkImageUsageFlags    usage,
                                 VkBuffer           & uniform_texel_buffer,
                                 VkDeviceMemory     & memory_object,
                                 VkBufferView       & uniform_texel_buffer_view );

} // namespace VulkanCookbook

#endif // CREATING_A_UNIFORM_TEXEL_BUFFER
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
// Chapter: 05 Descriptor Sets
// Recipe:  06 Creating a storage texel buffer

#ifndef CREATING_A_STORAGE_TEXEL_BUFFER
#define CREATING_A_STORAGE_TEXEL_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateStorageTexelBuffer( VkPhysicalDevice     physical_device,
                                 VkDevice             logical_device,
                                 VkFormat             format,
                                 VkDeviceSize         size,
                                 VkBufferUsageFlags   usage,
                                 bool                 atomic_operations,
                                 VkBuffer           & storage_texel_buffer,
                                 VkDeviceMemory     & memory_object,
                                 VkBufferView       & storage_texel_buffer_view );

} // namespace VulkanCookbook

#endif // CREATING_A_STORAGE_TEXEL_BUFFER
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
// Chapter: 05 Descriptor Sets
// Recipe:  07 Creating a uniform buffer

#ifndef CREATING_A_UNIFORM_BUFFER
#define CREATING_A_UNIFORM_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateUniformBuffer( VkPhysicalDevice     physical_device,
                            VkDevice             logical_device,
                            VkDeviceSize         size,
                            VkBufferUsageFlags   usage,
                            VkBuffer           & uniform_buffer,
                            VkDeviceMemory     & memory_object );

} // namespace VulkanCookbook

#endif // CREATING_A_UNIFORM_BUFFER
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
// Chapter: 05 Descriptor Sets
// Recipe:  08 Creating a storage buffer

#ifndef CREATING_A_STORAGE_BUFFER
#define CREATING_A_STORAGE_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateStorageBuffer( VkPhysicalDevice     physical_device,
                            VkDevice             logical_device,
                            VkDeviceSize         size,
                            VkBufferUsageFlags   usage,
                            VkBuffer           & storage_buffer,
                            VkDeviceMemory     & memory_object );

} // namespace VulkanCookbook

#endif // CREATING_A_STORAGE_BUFFER
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
// Chapter: 05 Descriptor Sets
// Recipe:  09 Creating an input attachment

#ifndef CREATING_AN_INPUT_ATTACHMENT
#define CREATING_AN_INPUT_ATTACHMENT

#include "Common.h"

namespace VulkanCookbook {

  bool CreateInputAttachment( VkPhysicalDevice     physical_device,
                              VkDevice             logical_device,
                              VkImageType          type,
                              VkFormat             format,
                              VkExtent3D           size,
                              VkImageUsageFlags    usage,
                              VkImageViewType      view_type,
                              VkImageAspectFlags   aspect,
                              VkImage            & input_attachment,
                              VkDeviceMemory     & memory_object,
                              VkImageView        & input_attachment_image_view );

} // namespace VulkanCookbook

#endif // CREATING_AN_INPUT_ATTACHMENT
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
// Chapter: 05 Descriptor Sets
// Recipe:  10 Creating a descriptor set layout

#ifndef CREATING_A_DESCRIPTOR_SET_LAYOUT
#define CREATING_A_DESCRIPTOR_SET_LAYOUT

#include "Common.h"

namespace VulkanCookbook {

  bool CreateDescriptorSetLayout( VkDevice                                          logical_device,
                                  std::vector<VkDescriptorSetLayoutBinding> const & bindings,
                                  VkDescriptorSetLayout                           & descriptor_set_layout );

} // namespace VulkanCookbook

#endif // CREATING_A_DESCRIPTOR_SET_LAYOUT
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
// Chapter: 05 Descriptor Sets
// Recipe:  11 Creating a descriptor pool

#ifndef CREATING_A_DESCRIPTOR_POOL
#define CREATING_A_DESCRIPTOR_POOL

#include "Common.h"

namespace VulkanCookbook {

  bool CreateDescriptorPool( VkDevice                                  logical_device,
                             bool                                      free_individual_sets,
                             uint32_t                                  max_sets_count,
                             std::vector<VkDescriptorPoolSize> const & descriptor_types,
                             VkDescriptorPool                        & descriptor_pool );

} // namespace VulkanCookbook

#endif // CREATING_A_DESCRIPTOR_POOL
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
// Chapter: 05 Descriptor Sets
// Recipe:  12 Allocating descriptor sets

#ifndef ALLOCATING_DESCRIPTOR_SETS
#define ALLOCATING_DESCRIPTOR_SETS

#include "Common.h"

namespace VulkanCookbook {

  bool AllocateDescriptorSets( VkDevice                                   logical_device,
                               VkDescriptorPool                           descriptor_pool,
                               std::vector<VkDescriptorSetLayout> const & descriptor_set_layouts,
                               std::vector<VkDescriptorSet>             & descriptor_sets );

} // namespace VulkanCookbook

#endif // ALLOCATING_DESCRIPTOR_SETS
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
// Chapter: 05 Descriptor Sets
// Recipe:  13 Updating descriptor sets

#ifndef UPDATING_DESCRIPTOR_SETS
#define UPDATING_DESCRIPTOR_SETS

#include "Common.h"

namespace VulkanCookbook {

  struct ImageDescriptorInfo {
    VkDescriptorSet                     TargetDescriptorSet;
    uint32_t                            TargetDescriptorBinding;
    uint32_t                            TargetArrayElement;
    VkDescriptorType                    TargetDescriptorType;
    std::vector<VkDescriptorImageInfo>  ImageInfos;
  };

  struct BufferDescriptorInfo {
    VkDescriptorSet                     TargetDescriptorSet;
    uint32_t                            TargetDescriptorBinding;
    uint32_t                            TargetArrayElement;
    VkDescriptorType                    TargetDescriptorType;
    std::vector<VkDescriptorBufferInfo> BufferInfos;
  };

  struct TexelBufferDescriptorInfo {
    VkDescriptorSet                     TargetDescriptorSet;
    uint32_t                            TargetDescriptorBinding;
    uint32_t                            TargetArrayElement;
    VkDescriptorType                    TargetDescriptorType;
    std::vector<VkBufferView>           TexelBufferViews;
  };

  struct CopyDescriptorInfo {
    VkDescriptorSet     TargetDescriptorSet;
    uint32_t            TargetDescriptorBinding;
    uint32_t            TargetArrayElement;
    VkDescriptorSet     SourceDescriptorSet;
    uint32_t            SourceDescriptorBinding;
    uint32_t            SourceArrayElement;
    uint32_t            DescriptorCount;
  };

  void UpdateDescriptorSets( VkDevice                                       logical_device,
                             std::vector<ImageDescriptorInfo> const       & image_descriptor_infos,
                             std::vector<BufferDescriptorInfo> const      & buffer_descriptor_infos,
                             std::vector<TexelBufferDescriptorInfo> const & texel_buffer_descriptor_infos,
                             std::vector<CopyDescriptorInfo> const        & copy_descriptor_infos );

} // namespace VulkanCookbook

#endif // UPDATING_DESCRIPTOR_SETS
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
// Chapter: 05 Descriptor Sets
// Recipe:  14 Binding descriptor sets

#ifndef BINDING_DESCRIPTOR_SETS
#define BINDING_DESCRIPTOR_SETS

#include "Common.h"

namespace VulkanCookbook {

  void BindDescriptorSets( VkCommandBuffer                      command_buffer,
                           VkPipelineBindPoint                  pipeline_type,
                           VkPipelineLayout                     pipeline_layout,
                           uint32_t                             index_for_first_set,
                           std::vector<VkDescriptorSet> const & descriptor_sets,
                           std::vector<uint32_t> const        & dynamic_offsets );

} // namespace VulkanCookbook

#endif // BINDING_DESCRIPTOR_SETS
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
// Chapter: 05 Descriptor Sets
// Recipe:  15 Creating descriptors with a texture and a uniform buffer

#ifndef CREATING_DESCRIPTORS_WITH_A_TEXTURE_AND_A_UNIFORM_BUFFER
#define CREATING_DESCRIPTORS_WITH_A_TEXTURE_AND_A_UNIFORM_BUFFER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateDescriptorsWithTextureAndUniformBuffer( VkPhysicalDevice               physical_device,
                                                     VkDevice                       logical_device,
                                                     VkExtent3D                     sampled_image_size,
                                                     uint32_t                       uniform_buffer_size,
                                                     VkSampler                    & sampler,
                                                     VkImage                      & sampled_image,
                                                     VkDeviceMemory               & sampled_image_memory_object,
                                                     VkImageView                  & sampled_image_view,
                                                     VkBuffer                     & uniform_buffer,
                                                     VkDeviceMemory               & uniform_buffer_memory_object,
                                                     VkDescriptorSetLayout        & descriptor_set_layout,
                                                     VkDescriptorPool             & descriptor_pool,
                                                     std::vector<VkDescriptorSet> & descriptor_sets );

} // namespace VulkanCookbook

#endif // CREATING_DESCRIPTORS_WITH_A_TEXTURE_AND_A_UNIFORM_BUFFER
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
// Chapter: 05 Descriptor Sets
// Recipe:  16 Freeing descriptor sets

#ifndef FREEING_DESCRIPTOR_SETS
#define FREEING_DESCRIPTOR_SETS

#include "Common.h"

namespace VulkanCookbook {

  bool FreeDescriptorSets( VkDevice                       logical_device,
                           VkDescriptorPool               descriptor_pool,
                           std::vector<VkDescriptorSet> & descriptor_sets );

} // namespace VulkanCookbook

#endif // FREEING_DESCRIPTOR_SETS
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
// Chapter: 05 Descriptor Sets
// Recipe:  17 Resetting a descriptor pool

#ifndef RESETTING_A_DESCRIPTOR_POOL
#define RESETTING_A_DESCRIPTOR_POOL

#include "Common.h"

namespace VulkanCookbook {

  bool ResetDescriptorPool( VkDevice          logical_device,
                            VkDescriptorPool  descriptor_pool );

} // namespace VulkanCookbook

#endif // RESETTING_A_DESCRIPTOR_POOL
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
// Chapter: 05 Descriptor Sets
// Recipe:  18 Destroying a descriptor pool

#ifndef DESTROYING_A_DESCRIPTOR_POOL
#define DESTROYING_A_DESCRIPTOR_POOL

#include "Common.h"

namespace VulkanCookbook {

  void DestroyDescriptorPool( VkDevice           logical_device,
                              VkDescriptorPool & descriptor_pool );

} // namespace VulkanCookbook

#endif // DESTROYING_A_DESCRIPTOR_POOL
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
// Chapter: 05 Descriptor Sets
// Recipe:  19 Destroying a descriptor set layout

#ifndef DESTROYING_A_DESCRIPTOR_SET_LAYOUT
#define DESTROYING_A_DESCRIPTOR_SET_LAYOUT

#include "Common.h"

namespace VulkanCookbook {

  void DestroyDescriptorSetLayout( VkDevice                logical_device,
                                   VkDescriptorSetLayout & descriptor_set_layout );

} // namespace VulkanCookbook

#endif // DESTROYING_A_DESCRIPTOR_SET_LAYOUT
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
// Chapter: 05 Descriptor Sets
// Recipe:  20 Destroying a sampler

#ifndef DESTROYING_A_SAMPLER
#define DESTROYING_A_SAMPLER

#include "Common.h"

namespace VulkanCookbook {

  void DestroySampler( VkDevice    logical_device,
                       VkSampler & sampler );

} // namespace VulkanCookbook

#endif // DESTROYING_A_SAMPLER
