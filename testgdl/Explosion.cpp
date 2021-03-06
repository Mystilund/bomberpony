//
// Explosion.cpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:44:23 2013 Maxime Wojciak
// Last update Sun May 26 02:25:52 2013 florian dewulf
//

#include	"Explosion.hpp"

Explosion::Explosion(const Vector3f &coord, unsigned int xplosize) : _time(0), _BombPos(coord), _Xplosize(xplosize) {

}

Explosion::~Explosion() {

}

void		Explosion::initialize() {
  Vector3f	pos = this->_BombPos;

  pos.x = pos.x - this->_Xplosize * 300;
  pos.y = 300;
  for (unsigned int tmp = this->_Xplosize * 2 + 1 ; tmp > 0; tmp--)
    {
      this->_explosion.push_back(new Rectangle(pos, Vector3f(pos.x + 300, 0, pos.z + 300), "./explosion.png"));
      pos.x += 300;
    }
  pos.x = this->_BombPos.x;
  pos.z = this->_BombPos.z - this->_Xplosize * 300;
  for (unsigned int tmp = this->_Xplosize * 2 + 1 ; tmp > 0; tmp--)
    {
      if (tmp != this->_Xplosize + 1)
	this->_explosion.push_back(new Rectangle(pos, Vector3f(pos.x + 300, 0, pos.z + 300), "./explosion.png"));
      pos.z += 300;
    }
}

bool		Explosion::update(gdl::GameClock &_clock) {
  if (this->_time == 0)
    this->_time = _clock.getTotalGameTime();
  if (this->_time + 2 < _clock.getTotalGameTime())
    return false;
  return true;
}

void		Explosion::draw() {
  for (std::list<Rectangle *>::iterator it = this->_explosion.begin() ; it != this->_explosion.end() ; ++it)
    (*it)->draw();
    /*
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
      glTranslatef(it_vector->x, it_vector->y, it_vector->z);
    it->draw();
    glPopMatrix();
    */
}
