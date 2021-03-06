#include	"Camera.hpp"

////////////////////////////////////////////////////////////////////////////////
/// Definition de la classe Camera
////////////////////////////////////////////////////////////////////////////////
Camera::Camera(void)
  : position_(0.0f, 3360.0, 1575), rotation_(0.0f, 0.0f, 0.0f)
{
}
void Camera::initialize(void)
{
  ////////////////////////////////////////////////////////////////////////////////
  /// Configuration du frustum de la camera
  ////////////////////////////////////////////////////////////////////////////////
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);
  gluLookAt(position_.x, position_.y, position_.z,
	    0.0f, 0.0f, -1.0f,
	    0.0f, 1.0f, 0.0f);
  ////////////////////////////////////////////////////////////////////////////////
  /// Positionnement de la camera
  ////////////////////////////////////////////////////////////////////////////////
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  ////////////////////////////////////////////////////////////////////////////////
  /// Activation des tests de profondeur
  ////////////////////////////////////////////////////////////////////////////////
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}
 void
 Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
 {
 }
