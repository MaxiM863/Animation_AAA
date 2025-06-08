#ifndef FOLLOWING_CAMERA
#define FOLLOWING_CAMERA

#include "Camera.h"

namespace VulkanCookbook {

  class FollowingCamera : public Camera {
  public:
    virtual Vector3     GetTarget() const final;
    void                SetTarget(Vector3 target);
    virtual float       GetDistance() const final;
    virtual float       GetHorizontalAngle() const final;
    virtual float       GetVerticalAngle() const final;

    void                ChangeDistance( float distance_delta );
    void                RotateHorizontally( float angle_delta );
    void                RotateVertically( float angle_delta );
    void                TranslateX( float delta_X );
    void                TranslateY( float delta_Y );
    void                TranslateZ( float delta_Z );

              FollowingCamera();
              FollowingCamera( Vector3 const & target,
                              float           distance,                              
                              float           horizontal_angle = 0.0f,
                              float           vertical_angle = 0.0f );
              FollowingCamera( FollowingCamera const & other );

    virtual  ~FollowingCamera();

    FollowingCamera& operator=( FollowingCamera const &i_OrbitingCamera );

  private:

    Vector3             Target;
    float               Distance;
    float               HorizontalAngle;
    float               VerticalAngle;
    float               VerticalAngleT = 0.0f;
    float               HorizontalAngleT = 0.0f;
    int                 LastAngleH = 0;
    int                 LastAngleV = 0;
  };

} // namespace VulkanCookbook

#endif // ORBITING_CAMERA