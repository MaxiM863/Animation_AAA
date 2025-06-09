#include "Graphics.h"

using namespace VulkanCookbook;

class Graphics : public VulkanCookbook::VulkanCookbookSample
{
  bool UpdateUniformBuffer;

  TextEngine* textEngine;

  StateMachineAnimation* state_0;


  virtual bool Initialize( WindowParameters window_parameters ) override 
  { 
    
    if( !InitializeVulkan( window_parameters, nullptr, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, false ) ) {

      return false;
    }  

    textEngine = new TextEngine();

    float pos_x0 = -0.15f;
    float pos_x1 = 0.15f;
    float pos_y0 = 0.80f;
    float pos_y1 = 0.86f;

    textEngine->Initialize("test allo !", 36, 0xFFFF00FF, 0x0000FF00, pos_x0, pos_x1, pos_y0, pos_y1, 200, 40, LogicalDevice.Object.Handle, PhysicalDevice, GraphicsQueue, FramesResources.front().CommandBuffer[0], Swapchain);


    //*********************************

    state_0 = new StateMachineAnimation();

    state_0->Initialize("Etat-0", 1280, 0, 0, -0.25f, 0.25f, -0.3f, 0.2f, 1000, 1000, *LogicalDevice, PhysicalDevice, GraphicsQueue, FramesResources.front().CommandBuffer[0], Swapchain);

    //*********************************
    return true;
  }

virtual bool Draw() override {
  auto prepare_frame = [&]( std::vector<VkCommandBuffer> command_buffer, uint32_t swapchain_image_index, VkFramebuffer framebuffer ) {
    if( !BeginCommandBufferRecordingOperation( command_buffer[0], VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr ) ) {
      return false;
    }

    if( PresentQueue.FamilyIndex != GraphicsQueue.FamilyIndex ) {
      ImageTransition image_transition_before_drawing = {
        Swapchain.Images[swapchain_image_index],  // VkImage              Image
        VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        CurrentAccess
        VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        NewAccess
        VK_IMAGE_LAYOUT_UNDEFINED,                // VkImageLayout        CurrentLayout
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, // VkImageLayout        NewLayout
        PresentQueue.FamilyIndex,                 // uint32_t             CurrentQueueFamily
        GraphicsQueue.FamilyIndex,                // uint32_t             NewQueueFamily
        VK_IMAGE_ASPECT_COLOR_BIT                 // VkImageAspectFlags   Aspect
      };
      SetImageMemoryBarrier( command_buffer[0], VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, { image_transition_before_drawing } );
    }

    VkViewport viewport = {
      0.0f,                                       // float    x
      0.0f,                                       // float    y
      static_cast<float>(Swapchain.Size.width),   // float    width
      static_cast<float>(Swapchain.Size.height),  // float    height
      0.0f,                                       // float    minDepth
      1.0f,                                       // float    maxDepth
    };
    SetViewportStateDynamically( command_buffer[0], 0, { viewport } );

    VkRect2D scissor = {
      {                                           // VkOffset2D     offset
        0,                                          // int32_t        x
        0                                           // int32_t        y
      },
      {                                           // VkExtent2D     extent
        Swapchain.Size.width,                       // uint32_t       width
        Swapchain.Size.height                       // uint32_t       height
      }
    };
    SetScissorStateDynamically( command_buffer[0], 0, { scissor } );

    // Drawing
    BeginRenderPass( command_buffer[0], textEngine->getRenderPass(), framebuffer, { { 0, 0 }, Swapchain.Size }, { { 1.0f, 0.0f, 0.0f, 1.0f }, { 1.0f, 0 } }, VK_SUBPASS_CONTENTS_INLINE );

    textEngine->draw_2( command_buffer[0] );

    state_0->draw_2(command_buffer[0]);
    
    EndRenderPass( command_buffer[0] );

    if( PresentQueue.FamilyIndex != GraphicsQueue.FamilyIndex ) {
      ImageTransition image_transition_before_present = {
        Swapchain.Images[swapchain_image_index],  // VkImage              Image
        VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        CurrentAccess
        VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        NewAccess
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        CurrentLayout
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        NewLayout
        GraphicsQueue.FamilyIndex,                // uint32_t             CurrentQueueFamily
        PresentQueue.FamilyIndex,                 // uint32_t             NewQueueFamily
        VK_IMAGE_ASPECT_COLOR_BIT                 // VkImageAspectFlags   Aspect
      };
      SetImageMemoryBarrier( command_buffer[0], VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, { image_transition_before_present } );
    }

    if( !EndCommandBufferRecordingOperation( command_buffer[0] ) ) {
      return false;
    } 
    
    return true;
  };

  return IncreasePerformanceThroughIncreasingTheNumberOfSeparatelyRenderedFrames( *LogicalDevice, GraphicsQueue.Handle, PresentQueue.Handle, *Swapchain.Handle, Swapchain.Size, Swapchain.ImageViewsRaw, textEngine->getRenderPass(), {}, prepare_frame, FramesResources );
}

private:

  void OnMouseEvent() {

    if( MouseState.Buttons[0].IsPressed)
    {
      float horizontal_angle = 0.0f;
      float vertical_angle = 0.0f;
      
      horizontal_angle += 0.5f * MouseState.Position.Delta.X;
      vertical_angle -= 0.5f * MouseState.Position.Delta.Y;

      if( vertical_angle > 180.0f ) {
        vertical_angle = 180.0f;
      }

      if( vertical_angle < -180.0f ) {
        vertical_angle = -180.0f;
      }      
    }
  }

  void OnKeyEvent() {

    
  }

  void OnServerEvent() {

    
  }  

  bool Resize()
  {
      if (!CreateSwapchain()) {
          return false;
      }

      return true;
  }

  void Deinitialize() {

      if (LogicalDevice) {
          WaitForAllSubmittedCommandsToBeFinished(*LogicalDevice);
      }

  }

};