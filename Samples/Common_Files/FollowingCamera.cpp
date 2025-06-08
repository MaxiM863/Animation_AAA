#include "FollowingCamera.h"
#include "10_Helper_Recipes/02_Preparing_a_rotation_matrix.h"

namespace VulkanCookbook {

  Vector3 FollowingCamera::GetTarget() const {
    return Target;
  }

  void FollowingCamera::SetTarget(Vector3 target) {

    Target = target;
    Position = Target - Distance * ForwardVector;
    Dirty = true;
  }

  float FollowingCamera::GetDistance() const {
    return Distance;
  }

  float FollowingCamera::GetHorizontalAngle() const {
    return HorizontalAngle;
  }

  float FollowingCamera::GetVerticalAngle() const {
    return VerticalAngle;
  }

  void FollowingCamera::ChangeDistance( float distance_delta ) {
    /*Distance = distance_delta;
    if( Distance < 0.0f ) {
      Distance = 0.0f;
    }
    Position = Target - Distance * ForwardVector;
    Dirty = true;*/
  }

  void FollowingCamera::RotateHorizontally( float angle_delta ) {

    HorizontalAngleT += angle_delta;
    angle_delta = 90.0f * ((int)HorizontalAngleT / 90);

    if(angle_delta != LastAngleH) {

      LastAngleH = angle_delta;
      HorizontalAngleT = 0;
    }

    Matrix4x4 const rotation = PrepareRotationMatrix( angle_delta, { 0.0f, -1.0f, 0.0f } );

    // Comment by Anastazja:
    //
    // Mama i tata, i brat, i znow brat, i babcia, i dziadek, i wujek, i babcia prabacia, i ciocia.
    // Napisalam to ja z tata.

    HorizontalAngle = angle_delta;
    ForwardVector = ForwardVector * rotation;
    UpVector = UpVector * rotation;
    RightVector = RightVector * rotation;
    Target = Target * rotation;
    Dirty = true;
  }

  void FollowingCamera::RotateVertically( float angle_delta ) {
    
    VerticalAngleT += angle_delta;
    angle_delta = 90.0f * ((int)VerticalAngleT / 90);

    if(angle_delta != LastAngleV) {

      LastAngleV = angle_delta;
      VerticalAngleT = 0;
    }
    
    Matrix4x4 const rotation = PrepareRotationMatrix( angle_delta, RightVector );

    VerticalAngle = angle_delta;
    ForwardVector = ForwardVector * rotation;
    UpVector = UpVector * rotation;
    Target = Target * rotation;
    Dirty = true;
  }

  void FollowingCamera::TranslateX(float delta_X)
  {
    Position = Position + Vector3{ delta_X, 0.0f, 0.0f};
    Target = Target + Vector3{ delta_X, 0.0f, 0.0f};
    Dirty = true;
  }

  void FollowingCamera::TranslateY(float delta_Y)
  {
    Position = Position + Vector3{ 0.0f, delta_Y, 0.0f};
    Target = Target + Vector3{ 0.0f, delta_Y, 0.0f};
    Dirty = true;
  }

  void FollowingCamera::TranslateZ(float delta_Z)
  {
    Position = Position + Vector3{ 0.0f, 0.0f, delta_Z};
    Target = Target + Vector3{ 0.0f, 0.0f, delta_Z};
    Dirty = true;
  }

  FollowingCamera::FollowingCamera() :
    FollowingCamera( { 0.0f, 0.0f, 1.0f }, 1.0f, 0.0f, 0.0f ) {
  }

  FollowingCamera::FollowingCamera( Vector3 const & target,
                                  float           distance,
                                  float           horizontal_angle,
                                  float           vertical_angle ) :
    Camera( Vector3{ 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } ),
    Target( Vector3{ 0.0f, 0.0f, 1.0f } ),
    Distance( distance ),
    HorizontalAngle( 0.0f ),
    VerticalAngle( 0.0f ) 
  {
    //RotateHorizontally( horizontal_angle );
    //RotateVertically( vertical_angle );
  }

  FollowingCamera::FollowingCamera( FollowingCamera const & camera ) {
    *this = camera;
  }

  FollowingCamera::~FollowingCamera() {
  }

  FollowingCamera& FollowingCamera::operator=( FollowingCamera const & camera ) {
    if( this != &camera ) {
      Camera::operator=( camera );
      Target = camera.Target;
      Distance = camera.Distance;
      HorizontalAngle = camera.HorizontalAngle;
      VerticalAngle = camera.VerticalAngle;
    }
    return *this;
  }

} // namespace VulkanCookbook