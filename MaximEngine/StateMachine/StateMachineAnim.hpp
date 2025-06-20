#include <iostream>
#include <fstream>
#include <vector>

#include "CookbookSampleFramework.h"
#include "OrbitingCamera.h"

#include "TextEngine.hpp"

using namespace VulkanCookbook;

class StateMachineAnimation
{
  
  VkDestroyer(VkBuffer)               VertexBuffer;
  VkDestroyer(VkDeviceMemory)         BufferMemory;
  
  VkDestroyer(VkImage)                Image;
  VkDestroyer(VkImageView)            ImageView;
  VkDestroyer(VkDeviceMemory)         ImageMemory;
  
  VkDestroyer(VkSampler)              Sampler;
  
  VkDestroyer(VkDescriptorSetLayout)  DescriptorSetLayout;
  VkDestroyer(VkDescriptorPool)       DescriptorPool;
  std::vector<VkDescriptorSet>        DescriptorSets;
  
  VkDestroyer(VkRenderPass)           RenderPass;
  VkDestroyer(VkPipelineLayout)       PipelineLayout;
  VkDestroyer(VkPipeline)             GraphicsPipeline;
  
  public:
  
  bool Initialize(std::string text, int fontSize, int fontColor, int backGColor, float pos_x0, float pos_x1, float pos_y0, float pos_y1, int width, int height, VkDevice LogicalDevice, VkPhysicalDevice PhysicalDevice, QueueParameters& GraphicsQueue, 
                    VkCommandBuffer& CommandBuffer, SwapchainParameters& Swapchain)
    {
      
      //VkDestroyer(VkDevice) LogicalDevice;
      //InitVkDestroyer(LogicalDevice);
      //LogicalDevice.Object.Handle = logicalDevice;

      // Combined image sampler
      
      TextEngine plage;

      std::vector<unsigned char> image_data = plage.sdlTextEngineT(width, height, fontSize, 0x00FFFFFF, 0x00000000, text);
      
      InitVkDestroyer( LogicalDevice, Sampler);
      InitVkDestroyer( LogicalDevice, ImageMemory );
      //InitVkDestroyer( LogicalDevice, ImageView );
      if( !CreateCombinedImageSampler( PhysicalDevice, LogicalDevice, VK_IMAGE_TYPE_2D, VK_FORMAT_R8G8B8A8_UNORM, { (uint32_t)width, (uint32_t)height, 1 },
        1, 1, VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT, false, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_ASPECT_COLOR_BIT, VK_FILTER_LINEAR,
        VK_FILTER_LINEAR, VK_SAMPLER_MIPMAP_MODE_NEAREST, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, 0.0f, false, 1.0f, false, VK_COMPARE_OP_ALWAYS, 0.0f, 1.0f, VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
        false, *Sampler, *Image, *ImageMemory, *ImageView ) ) {
        return false;
      }

      VkImageSubresourceLayers image_subresource_layer = {
        VK_IMAGE_ASPECT_COLOR_BIT,    // VkImageAspectFlags     aspectMask
        0,                            // uint32_t               mipLevel
        0,                            // uint32_t               baseArrayLayer
        1                             // uint32_t               layerCount
      };

      if( !UseStagingBufferToUpdateImageWithDeviceLocalMemoryBound( PhysicalDevice, LogicalDevice, static_cast<VkDeviceSize>(image_data.size()),
        &image_data[0], *Image, image_subresource_layer, { 0, 0, 0 }, { (uint32_t)width, (uint32_t)height, 1 }, VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, 0, VK_ACCESS_SHADER_READ_BIT, VK_IMAGE_ASPECT_COLOR_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, GraphicsQueue.Handle, CommandBuffer, {} ) ) {
        return false;
      }

      

      // Descriptor set with combined image sampler
      VkDescriptorSetLayoutBinding descriptor_set_layout_binding = {
        0,                                          // uint32_t             binding
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,  // VkDescriptorType     descriptorType
        1,                                          // uint32_t             descriptorCount
        VK_SHADER_STAGE_FRAGMENT_BIT,               // VkShaderStageFlags   stageFlags
        nullptr                                     // const VkSampler    * pImmutableSamplers
      };
      
      //InitVkDestroyer( LogicalDevice, DescriptorSetLayout );
      if( !CreateDescriptorSetLayout( LogicalDevice, { descriptor_set_layout_binding }, *DescriptorSetLayout ) ) {
        return false;
      }

      VkDescriptorPoolSize descriptor_pool_size = {
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,  // VkDescriptorType     type
        1                                           // uint32_t             descriptorCount
      };
      
      //InitVkDestroyer( LogicalDevice, DescriptorPool );
      if( !CreateDescriptorPool( LogicalDevice, false, 1, { descriptor_pool_size }, *DescriptorPool ) ) {
        return false;
      }

      if( !AllocateDescriptorSets( LogicalDevice, *DescriptorPool, { *DescriptorSetLayout }, DescriptorSets ) ) {

        return false;
      }

      ImageDescriptorInfo image_descriptor_update = {
        DescriptorSets[0],                          // VkDescriptorSet                      TargetDescriptorSet
        0,                                          // uint32_t                             TargetDescriptorBinding
        0,                                          // uint32_t                             TargetArrayElement
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,  // VkDescriptorType                     TargetDescriptorType
        {                                           // std::vector<VkDescriptorImageInfo>   ImageInfos
          {
            *Sampler,                                 // VkSampler                            sampler
            *ImageView,                               // VkImageView                          imageView
            VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL  // VkImageLayout                        imageLayout
          }
        }
      };

      UpdateDescriptorSets( LogicalDevice, { image_descriptor_update }, {}, {}, {} );

      // Render pass
      std::vector<VkAttachmentDescription> attachment_descriptions = {
        {
          0,                                // VkAttachmentDescriptionFlags     flags
          Swapchain.Format,                 // VkFormat                         format
          VK_SAMPLE_COUNT_1_BIT,            // VkSampleCountFlagBits            samples
          VK_ATTACHMENT_LOAD_OP_CLEAR,      // VkAttachmentLoadOp               loadOp
          VK_ATTACHMENT_STORE_OP_STORE,     // VkAttachmentStoreOp              storeOp
          VK_ATTACHMENT_LOAD_OP_DONT_CARE,  // VkAttachmentLoadOp               stencilLoadOp
          VK_ATTACHMENT_STORE_OP_DONT_CARE, // VkAttachmentStoreOp              stencilStoreOp
          VK_IMAGE_LAYOUT_UNDEFINED,        // VkImageLayout                    initialLayout
          VK_IMAGE_LAYOUT_PRESENT_SRC_KHR   // VkImageLayout                    finalLayout
        }
      };

      std::vector<SubpassParameters> subpass_parameters = {
        {
          VK_PIPELINE_BIND_POINT_GRAPHICS,            // VkPipelineBindPoint                  PipelineType
          {},                                         // std::vector<VkAttachmentReference>   InputAttachments
          {
            {                                         // std::vector<VkAttachmentReference>   ColorAttachments
              0,                                        // uint32_t                             attachment
              VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, // VkImageLayout                        layout
            }
          },
          {},                                         // std::vector<VkAttachmentReference>   ResolveAttachments
          nullptr,                                    // VkAttachmentReference const        * DepthStencilAttachment
          {}                                          // std::vector<uint32_t>                PreserveAttachments
        }
      };

      std::vector<VkSubpassDependency> subpass_dependencies = {
        {
          VK_SUBPASS_EXTERNAL,                            // uint32_t                   srcSubpass
          0,                                              // uint32_t                   dstSubpass
          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,              // VkPipelineStageFlags       srcStageMask
          VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,  // VkPipelineStageFlags       dstStageMask
          VK_ACCESS_MEMORY_READ_BIT,                      // VkAccessFlags              srcAccessMask
          VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,           // VkAccessFlags              dstAccessMask
          VK_DEPENDENCY_BY_REGION_BIT                     // VkDependencyFlags          dependencyFlags
        },
        {
          0,                                              // uint32_t                   srcSubpass
          VK_SUBPASS_EXTERNAL,                            // uint32_t                   dstSubpass
          VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,  // VkPipelineStageFlags       srcStageMask
          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,              // VkPipelineStageFlags       dstStageMask
          VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,           // VkAccessFlags              srcAccessMask
          VK_ACCESS_MEMORY_READ_BIT,                      // VkAccessFlags              dstAccessMask
          VK_DEPENDENCY_BY_REGION_BIT                     // VkDependencyFlags          dependencyFlags
        }
      };


      //InitVkDestroyer( LogicalDevice, RenderPass );
      if( !CreateRenderPass( LogicalDevice, attachment_descriptions, subpass_parameters, subpass_dependencies, *RenderPass ) ) {
        return false;
      }

      // Graphics pipeline
      std::vector<unsigned char> vertex_shader_spirv;
      if( !GetBinaryFileContents( "Data/Shaders/shader.vert.spv", vertex_shader_spirv ) ) {
        return false;
      }

      VkDestroyer(VkShaderModule) vertex_shader_module;
      InitVkDestroyer( LogicalDevice, vertex_shader_module );
      if( !CreateShaderModule( LogicalDevice, vertex_shader_spirv, *vertex_shader_module ) ) {
        return false;
      }

      std::vector<unsigned char> fragment_shader_spirv;
      if( !GetBinaryFileContents( "Data/Shaders/shader.frag.spv", fragment_shader_spirv ) ) {
        return false;
      }
      VkDestroyer(VkShaderModule) fragment_shader_module;
      InitVkDestroyer( LogicalDevice, fragment_shader_module );
      if( !CreateShaderModule( LogicalDevice, fragment_shader_spirv, *fragment_shader_module ) ) {
        return false;
      }

      std::vector<ShaderStageParameters> shader_stage_params = {
        {
          VK_SHADER_STAGE_VERTEX_BIT,   // VkShaderStageFlagBits        ShaderStage
          *vertex_shader_module,        // VkShaderModule               ShaderModule
          "main",                       // char const                 * EntryPointName;
          nullptr                       // VkSpecializationInfo const * SpecializationInfo;
        },
        {
          VK_SHADER_STAGE_FRAGMENT_BIT, // VkShaderStageFlagBits        ShaderStage
          *fragment_shader_module,      // VkShaderModule               ShaderModule
          "main",                       // char const                 * EntryPointName
          nullptr                       // VkSpecializationInfo const * SpecializationInfo
        }
      };

      std::vector<VkPipelineShaderStageCreateInfo> shader_stage_create_infos;
      SpecifyPipelineShaderStages( shader_stage_params, shader_stage_create_infos );

      std::vector<VkVertexInputBindingDescription> vertex_input_binding_descriptions = {
        {
          0,                            // uint32_t                     binding
          5 * sizeof( float ),          // uint32_t                     stride
          VK_VERTEX_INPUT_RATE_VERTEX   // VkVertexInputRate            inputRate
        }
      };

      std::vector<VkVertexInputAttributeDescription> vertex_attribute_descriptions = {
        {
          0,                            // uint32_t                     location
          0,                            // uint32_t                     binding
          VK_FORMAT_R32G32B32_SFLOAT,   // VkFormat                     format
          0                             // uint32_t                     offset
        },
        {
          1,                            // uint32_t                     location
          0,                            // uint32_t                     binding
          VK_FORMAT_R32G32_SFLOAT,      // VkFormat                     format
          3 * sizeof( float )           // uint32_t                     offset
        }
      };

      VkPipelineVertexInputStateCreateInfo vertex_input_state_create_info;
      SpecifyPipelineVertexInputState( vertex_input_binding_descriptions, vertex_attribute_descriptions, vertex_input_state_create_info );

      VkPipelineInputAssemblyStateCreateInfo input_assembly_state_create_info;
      SpecifyPipelineInputAssemblyState( VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP, false, input_assembly_state_create_info );

     ViewportInfo viewport_infos = {
        {                     // std::vector<VkViewport>   Viewports
          {
            0.0f,               // float          x
            0.0f,               // float          y
            500.0f,             // float          width
            500.0f,             // float          height
            0.0f,               // float          minDepth
            1.0f                // float          maxDepth
          }
        },
        {                     // std::vector<VkRect2D>     Scissors
          {
            {                   // VkOffset2D     offset
              0,                  // int32_t        x
              0                   // int32_t        y
            },
            {                   // VkExtent2D     extent
              500,                // uint32_t       width
              500                 // uint32_t       height
            }
          }
        }
      };
      VkPipelineViewportStateCreateInfo viewport_state_create_info;
      SpecifyPipelineViewportAndScissorTestState( viewport_infos, viewport_state_create_info );

      VkPipelineRasterizationStateCreateInfo rasterization_state_create_info;
      SpecifyPipelineRasterizationState( false, false, VK_POLYGON_MODE_FILL, VK_CULL_MODE_BACK_BIT, VK_FRONT_FACE_COUNTER_CLOCKWISE, false, 0.0f, 0.0f, 0.0f, 1.0f, rasterization_state_create_info );

      VkPipelineMultisampleStateCreateInfo multisample_state_create_info;
      SpecifyPipelineMultisampleState( VK_SAMPLE_COUNT_1_BIT, false, 0.0f, nullptr, false, false, multisample_state_create_info );

      std::vector<VkPipelineColorBlendAttachmentState> attachment_blend_states = {
        {
          false,                          // VkBool32                 blendEnable
          VK_BLEND_FACTOR_ONE,            // VkBlendFactor            srcColorBlendFactor
          VK_BLEND_FACTOR_ONE,            // VkBlendFactor            dstColorBlendFactor
          VK_BLEND_OP_ADD,                // VkBlendOp                colorBlendOp
          VK_BLEND_FACTOR_ONE,            // VkBlendFactor            srcAlphaBlendFactor
          VK_BLEND_FACTOR_ONE,            // VkBlendFactor            dstAlphaBlendFactor
          VK_BLEND_OP_ADD,                // VkBlendOp                alphaBlendOp
          VK_COLOR_COMPONENT_R_BIT |      // VkColorComponentFlags    colorWriteMask
          VK_COLOR_COMPONENT_G_BIT |
          VK_COLOR_COMPONENT_B_BIT |
          VK_COLOR_COMPONENT_A_BIT
        }
      };
      VkPipelineColorBlendStateCreateInfo blend_state_create_info;
      SpecifyPipelineBlendState( false, VK_LOGIC_OP_COPY, attachment_blend_states, { 1.0f, 1.0f, 1.0f, 1.0f }, blend_state_create_info );

      std::vector<VkDynamicState> dynamic_states = {
        VK_DYNAMIC_STATE_VIEWPORT,
        VK_DYNAMIC_STATE_SCISSOR
      };
      VkPipelineDynamicStateCreateInfo dynamic_state_create_info;
      SpecifyPipelineDynamicStates( dynamic_states, dynamic_state_create_info );

      //InitVkDestroyer( LogicalDevice, PipelineLayout );
      if( !CreatePipelineLayout( LogicalDevice, { *DescriptorSetLayout }, {}, *PipelineLayout ) ) {
        return false;
      }

      VkGraphicsPipelineCreateInfo graphics_pipeline_create_info;
      SpecifyGraphicsPipelineCreationParameters( 0, shader_stage_create_infos, vertex_input_state_create_info, input_assembly_state_create_info,
        nullptr, &viewport_state_create_info, rasterization_state_create_info, &multisample_state_create_info, nullptr, &blend_state_create_info,
        &dynamic_state_create_info, *PipelineLayout, *RenderPass, 0, VK_NULL_HANDLE, -1, graphics_pipeline_create_info );

      std::vector<VkPipeline> graphics_pipeline;
      if( !CreateGraphicsPipelines( LogicalDevice, { graphics_pipeline_create_info }, VK_NULL_HANDLE, graphics_pipeline ) ) {
        return false;
      }
      //InitVkDestroyer( LogicalDevice, GraphicsPipeline );
      *GraphicsPipeline = graphics_pipeline[0];

      // Vertex data
      std::vector<float> vertices = {
        // positions          // texcoords
        pos_x0, pos_y0, 0.0f, 0.0f, 0.0f,
        pos_x0, pos_y1, 0.0f, 0.0f, 1.0f,
        pos_x1, pos_y0, 0.0f, 1.0f, 0.0f,
        pos_x1, pos_y1, 0.0f, 1.0f, 1.0f,
      };

      //InitVkDestroyer( LogicalDevice, VertexBuffer );
      if( !CreateBuffer( LogicalDevice, sizeof(vertices[0]) * vertices.size(), VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, *VertexBuffer ) ) {
        return false;
      }

      InitVkDestroyer( LogicalDevice, BufferMemory );
      if( !AllocateAndBindMemoryObjectToBuffer( PhysicalDevice, LogicalDevice, *VertexBuffer, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, *BufferMemory ) ) {
        return false;
      }

      if( !UseStagingBufferToUpdateBufferWithDeviceLocalMemoryBound( PhysicalDevice, LogicalDevice, sizeof( vertices[0] ) * vertices.size(), &vertices[0], *VertexBuffer, 0, 0,
        VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_VERTEX_INPUT_BIT, GraphicsQueue.Handle, CommandBuffer, {} ) ) {
        return false;
      }
      
      return true;
    }    

    bool draw_2(VkCommandBuffer& command_buffer)
    {

      BindPipelineObject( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, *GraphicsPipeline );

      BindDescriptorSets( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, *PipelineLayout, 0, DescriptorSets, {} );

      BindVertexBuffers( command_buffer, 0, { { *VertexBuffer, 0 } } );

      DrawGeometry( command_buffer, 4, 1, 0, 0 );

      return true;
    }

};