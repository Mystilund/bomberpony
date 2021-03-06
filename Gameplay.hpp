//
// Game.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 17 17:03:33 2013 florian dewulf
// Last update Sun May 26 23:03:11 2013 florian dewulf
//

#ifndef		GAMEPLAY_HPP__
# define	GAMEPLAY_HPP__

#include	<string>
#include	<list>
#include	<vector>

#include	"APlayer.hpp"
#include	"Obstacle.hpp"
#include	"Scene.hpp"
#include	"Vector3f.hpp"
#include	"Input.hpp"
#include	"GameClock.hpp"

class		Gameplay : public Scene
{
public:
  Gameplay(bool, bool, bool, eMode);
  Gameplay(bool, const std::list<std::string> &);
  virtual	~Gameplay();

public:
  virtual void		initialize(const std::string &, const Vector3f &, const Vector3f &);
  virtual MenuType	update(gdl::GameClock &, gdl::Input &);
  virtual void		draw();

private:
  void			newPlayer(unsigned int, unsigned int, unsigned int);

private:
  bool				_error;
  bool				_nb_j;
  bool				_sound;
  bool				_map_choice;
  eMode				_ia;
  Cube				*_plateau;
  std::list<APlayer *>		_players;
  std::list<Obstacle *>		_obs;
  std::list<Bonus *>		_bonus;
  std::list<Bombe *>		_bombe;
  std::list<Explosion *>	_explosion;
};

#endif
