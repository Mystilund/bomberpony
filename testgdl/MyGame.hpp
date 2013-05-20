////////////////////////////////////////////////////////////////////////////////
/// Declaration de la classe MyGame
////////////////////////////////////////////////////////////////////////////////


#include <list>
#include "Camera.hpp"
#include "AObject.hpp"
#include "Forme.hpp"
#include "Game.hpp"
#include "Model.hpp"

class MyGame : public gdl::Game
{
public:
  void initialize(void);
  void update(void);
  void draw(void);
  void unload(void);

private:
  Camera camera_;
  std::list<AObject*>  objects_;
  gdl::Model		model;
};