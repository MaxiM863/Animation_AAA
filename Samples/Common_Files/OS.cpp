// MIT License
//
// Copyright( c ) 2017 Packt
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// OS

#include "CookbookSampleFramework.h"

namespace VulkanCookbook {

#ifdef VK_USE_PLATFORM_WIN32_KHR

  namespace {
    enum UserMessage {
      USER_MESSAGE_RESIZE = WM_USER + 1,
      USER_MESSAGE_QUIT,
      USER_MESSAGE_MOUSE_CLICK,
      USER_MESSAGE_MOUSE_MOVE,
      USER_MESSAGE_MOUSE_WHEEL,
      USER_MESSAGE_SERVER_ON,
      USER_MESSAGE_KEY_ON,
      USER_MESSAGE_KEY_OFF
    };
  }

  LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam ) {
    switch( message ) {
    
    case WM_LBUTTONDOWN:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 0, 1 );
      break;
    case WM_LBUTTONUP:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 0, 0 );
      break;
    case WM_RBUTTONDOWN:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 1, 1 );
      break;
    case WM_RBUTTONUP:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_CLICK, 1, 0 );
      break;
    case WM_MOUSEMOVE:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_MOVE, LOWORD( lParam ), HIWORD( lParam ) );
      break;
    case WM_MOUSEWHEEL:
      PostMessage( hWnd, USER_MESSAGE_MOUSE_WHEEL, HIWORD( wParam ), 0 );
      break;
    case WM_SIZE:
    case WM_EXITSIZEMOVE:
      PostMessage( hWnd, USER_MESSAGE_RESIZE, wParam, lParam );
      break;
    case WM_KEYDOWN:
    {
      if( VK_ESCAPE == wParam ) {
        PostMessage( hWnd, USER_MESSAGE_QUIT, wParam, lParam );
      }
      else {
        PostMessage( hWnd, USER_MESSAGE_KEY_ON, wParam, lParam);
      }
      break;
    }
    case WM_KEYUP:
    {
      PostMessage( hWnd, USER_MESSAGE_KEY_OFF, wParam, lParam);
      
      break;
    }
    case WM_CLOSE:
      PostMessage( hWnd, USER_MESSAGE_QUIT, wParam, lParam );
      break;
    default:
      return DefWindowProc( hWnd, message, wParam, lParam );
    }
    return 0;
  }

  WindowFramework::WindowFramework( const char               * window_title,
                                    int                        x,
                                    int                        y,
                                    int                        width,
                                    int                        height,
                                    VulkanCookbookSampleBase & sample ) :
    WindowParams(),
    Sample( sample ),
    Created( false ) {
    WindowParams.HInstance = GetModuleHandle( nullptr );

    WNDCLASSEX window_class = {
      sizeof( WNDCLASSEX ),             // UINT         cbSize
                                        /* Win 3.x */
      CS_HREDRAW | CS_VREDRAW,          // UINT         style
      WindowProcedure,                  // WNDPROC      lpfnWndProc
      0,                                // int          cbClsExtra
      0,                                // int          cbWndExtra
      WindowParams.HInstance,           // HINSTANCE    hInstance
      nullptr,                          // HICON        hIcon
      LoadCursor( nullptr, IDC_ARROW ), // HCURSOR      hCursor
      (HBRUSH)(COLOR_WINDOW + 1),       // HBRUSH       hbrBackground
      nullptr,                          // LPCSTR       lpszMenuName
      "VulkanCookbook",                 // LPCSTR       lpszClassName
                                        /* Win 4.0 */
      nullptr                           // HICON        hIconSm
    };

    if( !RegisterClassEx( &window_class ) ) {
      return;
    }

    WindowParams.HWnd = CreateWindow( "VulkanCookbook", window_title, WS_OVERLAPPEDWINDOW, x, y, width, height, nullptr, nullptr, WindowParams.HInstance, nullptr );
    if( !WindowParams.HWnd ) {
      return;
    }


    Created = true;
  }

  WindowFramework::~WindowFramework() {
    if( WindowParams.HWnd ) {
      DestroyWindow( WindowParams.HWnd );
    }

    if( WindowParams.HInstance ) {
      UnregisterClass( "VulkanCookbook", WindowParams.HInstance );
    }
  }

  void WindowFramework::Render() {
    if( Created &&
        Sample.Initialize( WindowParams, WindowParams.HWnd ) ) {

      ShowWindow( WindowParams.HWnd, SW_SHOWNORMAL );
      UpdateWindow( WindowParams.HWnd );

      MSG message;
      bool loop = true;

      while( loop ) {        

        if( PeekMessage( &message, NULL, 0, 0, PM_REMOVE ) ) {
          switch( message.message ) {

          case USER_MESSAGE_SERVER_ON:
          {
            char* receivedStr = reinterpret_cast<char*>(message.lParam);
            
            Sample.ServerIn(receivedStr);

            // Free the allocated memory
            delete[] receivedStr;
            
            break;
          }
          case USER_MESSAGE_KEY_ON:
          {
            Sample.KeyboardIn(message.wParam);

            break;
          }
          case USER_MESSAGE_KEY_OFF:
          {
            Sample.KeyboardOut(message.wParam);

            break;
          }
          case USER_MESSAGE_MOUSE_CLICK:
            Sample.MouseClick( static_cast<size_t>(message.wParam), message.lParam > 0 );
            break;
          case USER_MESSAGE_MOUSE_MOVE:
            Sample.MouseMove( static_cast<int>(message.wParam), static_cast<int>(message.lParam) );
            break;
          case USER_MESSAGE_MOUSE_WHEEL:
            Sample.MouseWheel( static_cast<short>(message.wParam) * 0.002f );
            break;
          case USER_MESSAGE_RESIZE:
            if( !Sample.Resize() ) {
              loop = false;
            }
            break;
          case USER_MESSAGE_QUIT:
            loop = false;
            break;
          }
          TranslateMessage( &message );
          DispatchMessage( &message );
        } else {
          if( Sample.IsReady() ) {
            Sample.UpdateTime();
            Sample.Draw();
            Sample.MouseReset();
          }
        }
      }
    }

    Sample.Deinitialize();
  }
  
#else

void demo_run_xlib(VulkanCookbook::VulkanCookbookSampleBase& sample, WindowParameters wp, bool& test);

Atom xlib_wm_delete_window;

WindowFramework::WindowFramework( const char               * window_title,
                                    int                        x,
                                    int                        y,
                                    int                        width,
                                    int                        height,
                                    VulkanCookbookSampleBase & sample ) :
    WindowParams(),
    Sample( sample ),
    Created( false ) {
    WindowParams.Dpy = XOpenDisplay(nullptr);
    
    if(WindowParams.Dpy != NULL) std::cout << "!NULL";
    
    XInitThreads();
    
    

    long visualMask = VisualScreenMask;
    int numberOfVisuals;
    XVisualInfo vInfoTemplate = {};
    vInfoTemplate.screen = DefaultScreen(WindowParams.Dpy);
    XVisualInfo *visualInfo = XGetVisualInfo(WindowParams.Dpy, visualMask, &vInfoTemplate, &numberOfVisuals);

    Colormap colormap =
        XCreateColormap(WindowParams.Dpy, RootWindow(WindowParams.Dpy, vInfoTemplate.screen), visualInfo->visual, AllocNone);

    XSetWindowAttributes windowAttributes = {};
    windowAttributes.colormap = colormap;
    windowAttributes.background_pixel = 0xFFFFFFFF;
    windowAttributes.border_pixel = 0;
    windowAttributes.event_mask = KeyPressMask | KeyReleaseMask | StructureNotifyMask | ExposureMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask;

    WindowParams.WIndow = XCreateWindow(WindowParams.Dpy, RootWindow(WindowParams.Dpy, vInfoTemplate.screen), 0, 0, width,
                                      height, 0, visualInfo->depth, InputOutput, visualInfo->visual,
                                      CWBackPixel | CWBorderPixel | CWEventMask | CWColormap, &windowAttributes); 

    //XSelectInput(WindowParams.Dpy, WindowParams.WIndow, ExposureMask | KeyPressMask);


    XGrabPointer(WindowParams.Dpy, WindowParams.WIndow, True,
                  ButtonPressMask |
                  ButtonReleaseMask |
                  PointerMotionMask |
                  FocusChangeMask |
                  EnterWindowMask |
                  LeaveWindowMask,
               GrabModeAsync,
               GrabModeAsync,
               RootWindow(WindowParams.Dpy, DefaultScreen(WindowParams.Dpy)),
               None,
               CurrentTime);


    xlib_wm_delete_window = XInternAtom(WindowParams.Dpy, "WM_DELETE_WINDOW", False);
    
    Created = true;
  }

  WindowFramework::~WindowFramework() {
    
  }

  void WindowFramework::Render() {
    
    if( Created && Sample.Initialize( WindowParams ) ) {
	    
	    
	
      bool test = true;      

      XMapWindow(WindowParams.Dpy, WindowParams.WIndow);

      demo_run_xlib(Sample, WindowParams, test);
    }

    XFlush(WindowParams.Dpy);
    Sample.Deinitialize();
  }

  void demo_handle_xlib_event(VulkanCookbook::VulkanCookbookSampleBase& sample, XEvent *event, bool& test) {
    
    switch (event->type) {
        case ClientMessage:
            if ((Atom)event->xclient.data.l[0] == xlib_wm_delete_window) test = false;
            break;
        case KeyPress:
            switch (event->xkey.keycode) {
                case 0x9:  // Escape
                    
                    break;
                case 0x71:  // left arrow key
                    
                    break;
                case 0x72:  // right arrow key
                    
                    break;
                case 0x41:  // space bar
                    
                    break;
            }
            break;
        case MotionNotify:
        
          sample.MouseMove(event->xmotion.x, event->xmotion.y);
          
        break;
          
        case ButtonPress:
          if(event->xbutton.button == 3)
            sample.MouseClick(1, true);
          else sample.MouseClick(0, true);
        break;

        case ButtonRelease:
          if(event->xbutton.button == 3)
            sample.MouseClick(1, false);
          else sample.MouseClick(0, false);
        break;

        case ConfigureNotify:
            {
            }
            break;
        default:
            break;
    }
}

void demo_run_xlib(VulkanCookbook::VulkanCookbookSampleBase& sample, WindowParameters wp, bool& test) {
    
  while (test) {
  
    XEvent event;
    

    while (XPending(wp.Dpy) > 0) {
      
      XNextEvent(wp.Dpy, &event);
            
        demo_handle_xlib_event(sample, &event, test);
      }

    if( sample.IsReady() ) {
          
      sample.UpdateTime();
      if(!sample.Draw()) std::cout << "No draw!!!";
      sample.MouseReset();
    }
  }
}

#endif

} // namespace VulkanCookbook
