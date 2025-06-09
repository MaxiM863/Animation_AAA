#ifndef ENGINE
#define ENGINE

#ifdef _WIN32

#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#endif

#include <iostream>
#include <fstream>
#include <vector>

#include "CookbookSampleFramework.h"
#include "OrbitingCamera.h"

#ifndef _WIN32
#include <freetype/freetype.h>
#endif
#include <gdiplusinit.h>

#ifdef _WIN32

using namespace Gdiplus;
//using namespace VulkanCookbook;

#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t fileType{0x4D42}; // 'BM'
    uint32_t fileSize{0};
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    uint32_t offsetData{54};
};
#pragma pack(pop)

struct BMPInfoHeader {
    uint32_t size{40}; // Header size
    int32_t width{0};
    int32_t height{0};
    uint16_t planes{1};
    uint16_t bitCount{32}; // Bits per pixel
    uint32_t compression{0};
    uint32_t sizeImage{0};
    int32_t xPixelsPerMeter{0};
    int32_t yPixelsPerMeter{0};
    uint32_t colorsUsed{0};
    uint32_t colorsImportant{0};
};

#endif


class TextEngine
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

    OrbitingCamera Camera;

    public:

        VkPipelineLayout getPipelineLayout() { return PipelineLayout.Object.Handle; };

        VkPipeline getGraphicsPipeline() { return GraphicsPipeline.Object.Handle; };

        VkDescriptorSetLayout getDescriptorSetLayout() { return DescriptorSetLayout.Object.Handle; };

        VkDescriptorPool getDescriptorPool() { return DescriptorPool.Object.Handle; };

        std::vector<VkDescriptorSet> getDescriptorSet() { return DescriptorSets; };

        VkRenderPass getRenderPass() { return RenderPass.Object.Handle; };

        VkBuffer getVertexBuffer() { return VertexBuffer.Object.Handle; };
    
        TextEngine(){};   
    
        std::vector<uint8_t> sdlTextEngineT(int width, int height, int fontSize, int fontColor, int backGColor, std::string s) {

          #ifdef _WIN32

          GdiplusStartupInput gdiplusStartupInput;
          ULONG_PTR gdiplusToken;
          GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
      
          // Create a font
          tagLOGFONTW logfont = {0};
          logfont.lfHeight = fontSize; // Font height
          wcscpy_s(logfont.lfFaceName, 6, L"Arial"); // Font name
      
          HFONT hFont = CreateFontIndirectW(&logfont);
      
          //HDC hdc = GetDC(hWnd);

          // Create a compatible DC, which is used in a BitBlt from the window DC.
          HDC hdc = CreateCompatibleDC(NULL);

          // Create a memory device context
          // = CreateCompatibleDC(nullptr);
          SelectObject(hdc, hFont);
      
          // Create a bitmap
          HBITMAP hBitmap = CreateBitmap(width, height, 1, 32, nullptr);
          SelectObject(hdc, hBitmap);
      
          // Set text color and background
          
          SetTextColor(hdc, fontColor);
          SetBkColor(hdc, backGColor);
          RECT rect = {0, 0, width, height};
          
          FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
      
          
          // Draw text

          std::wstring stemp = std::wstring(s.begin(), s.end());
          LPCWSTR sw = stemp.c_str();

          DrawTextW(hdc, sw, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
      
          // Save the bitmap to a file
          std::vector<uint8_t> dataR = HBitmapToArray(hBitmap, width, height);
      
          // Cleanup
          DeleteObject(hBitmap);
          DeleteObject(hFont);
          DeleteDC(hdc);
          GdiplusShutdown(gdiplusToken);
        
          return dataR;

          #endif

          #ifndef _WIN32

          FT_Library library;
          FT_Init_FreeType(&library);

          FT_Face face;
          FT_New_Face(library, "arial.ttf", 0, &face);

          FT_Set_Pixel_Sizes(face, 0, fontSize);

          std::vector<unsigned char> myBitmap(4 * width * height);

          for(int i = 0; i < width * height; i++)
          {
            myBitmap[4 * i + 0] = 255;
            myBitmap[4 * i + 1] = 255;
            myBitmap[4 * i + 2] = 255;
            myBitmap[4 * i + 3] = 255;
          } 
          
          int x = 0;
          int y = height;

          std::string text = "aalo";
          for (char c : text) {
              if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
                  // Handle error
                  continue;
              }
              FT_Bitmap glyphBitmap = face->glyph->bitmap;
              for (int row = 0; row < glyphBitmap.rows; ++row) {
                  for (int col = 0; col < glyphBitmap.width; ++col) {
                      // Calculate position in the target bitmap and copy the pixel
                      int targetX = x + col;
                      int targetY = y - row - 1;
                      if(targetX < width && targetY < height){

                        if(glyphBitmap.buffer[(glyphBitmap.rows - row - 1) * glyphBitmap.width + col] > 0)
                        {
                          myBitmap[4*(targetY * width + targetX) + 0] = glyphBitmap.buffer[(glyphBitmap.rows - row - 1) * glyphBitmap.width + col];
                          myBitmap[4*(targetY * width + targetX) + 1] = 0;
                          myBitmap[4*(targetY * width + targetX) + 2] = 0;
                          myBitmap[4*(targetY * width + targetX) + 3] = 255;
                        }
                        else
                        {
                          myBitmap[4*(targetY * width + targetX) + 0] = 255;
                          myBitmap[4*(targetY * width + targetX) + 1] = 255;
                          myBitmap[4*(targetY * width + targetX) + 2] = 255;
                          myBitmap[4*(targetY * width + targetX) + 3] = 255;
                        }
                        
                      }
                  }
              }
              x += face->glyph->advance.x >> 6;
          }

          return myBitmap; 
          
          #endif
    }

    #ifdef _WIN32

    std::vector<BYTE> HBitmapToArray(HBITMAP hBitmap, int width, int height) {
        
      BITMAP bmp;
      GetObjectW(hBitmap, sizeof(BITMAP), &bmp);
  
      BITMAPINFOHEADER bi;
      ZeroMemory(&bi, sizeof(BITMAPINFOHEADER));
      bi.biSize = sizeof(BITMAPINFOHEADER);
      bi.biWidth = bmp.bmWidth;
      bi.biHeight = -bmp.bmHeight; // Negative to indicate top-down bitmap
      bi.biPlanes = 1;
      bi.biBitCount = 32; // Assuming 24-bit bitmap
      bi.biCompression = BI_RGB;
  
      int imageSize = bmp.bmWidth * bmp.bmHeight * 4; // 3 bytes per pixel for 24-bit
      std::vector<BYTE> buffer(imageSize);
  
      HDC hdc = GetDC(NULL);
      GetDIBits(hdc, hBitmap, 0, bmp.bmHeight, buffer.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS);
      ReleaseDC(NULL, hdc);
     

      //createBMP(buffer, width, height, "output.bmp");
  
      return buffer;
    }

    

    void createBMP(const std::vector<uint8_t>& pixelData, int width, int height, const std::string& filename) {

      BMPFileHeader fileHeader;
      BMPInfoHeader infoHeader;
  
      infoHeader.width = width;
      infoHeader.height = height;
      fileHeader.fileSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + pixelData.size();
      infoHeader.sizeImage = pixelData.size();
  
      // Write the header to a file
      FILE *file = fopen("output.bmp", "wb");
      if (file == NULL) {
          perror("Failed to open file");
      }

      fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
      fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
      fwrite(&pixelData[0], pixelData.size(), 1, file);

      fclose(file);
      printf("BMP header written to output.bmp\n");
    }

    #endif
    
    bool Initialize(std::string text, int fontSize, int fontColor, int backGColor, float pos_x0, float pos_x1, float pos_y0, float pos_y1, int width, int height, VkDevice LogicalDevice, VkPhysicalDevice PhysicalDevice, QueueParameters& GraphicsQueue, 
                    VkCommandBuffer& CommandBuffer, SwapchainParameters& Swapchain)
    {
      
      //VkDestroyer(VkDevice) LogicalDevice;
      //InitVkDestroyer(LogicalDevice);
      //LogicalDevice.Object.Handle = logicalDevice;

      

      // Combined image sampler
      
      std::vector<unsigned char> image_data = sdlTextEngineT(width, height, fontSize, fontColor, backGColor, text);

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

      BindPipelineObject( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, getGraphicsPipeline() );

      BindDescriptorSets( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, getPipelineLayout(), 0, getDescriptorSet(), {} );

      BindVertexBuffers( command_buffer, 0, { { getVertexBuffer(), 0 } } );

      DrawGeometry( command_buffer, 4, 1, 0, 0 );

      return true;
    }
};

#endif