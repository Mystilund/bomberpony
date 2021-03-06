//
// Forme.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:50:30 2013 florian dewulf
// Last update Sun May 26 01:49:33 2013 florian dewulf
//

#ifndef		FORME_HPP__
# define	FORME_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>
#include	<string>
#include	<iostream>

#include	"Image.hpp"
#include	"AObject.hpp"
#include	"Vector3f.hpp"

/* ------------ */

class		Triangle : public AObject
{
public:
  Triangle(const Vector3f &, const Vector3f &, const Vector3f &, const Vector3f &);
  virtual void		initialize();
  virtual void		update();
  virtual void		draw();
  void		setTranslation(const Vector3f &);
  Vector3f	getTranslation() const;

private:
  Vector3f	_pt1;
  Vector3f	_pt2;
  Vector3f	_pt3;
  Vector3f	_color;
  float		_rotation;
  Vector3f	_translation;
};

/* ------------ */

class		Rectangle : public AObject
{
public:
  Rectangle(const Vector3f &, const Vector3f &, const std::string &);
  virtual	~Rectangle();

public:
  virtual void		initialize();
  virtual void		update();
  virtual void		draw(void);

public:
  static void	draw_rect(const Vector3f &, const Vector3f &, float, float, float);
  static void	draw_rect(const Vector3f &, const Vector3f &, gdl::Image &);
  static void	draw_plan(const Vector3f &, const Vector3f &, float, float, float);
  static void	draw_plan(const Vector3f &, const Vector3f &, gdl::Image &);

private:
  Vector3f	_origin;
  Vector3f	_opposite;
  gdl::Image	_texture;
};

/* ------------ */

class		Cube : public AObject
{
public:
  Cube(const Vector3f &, const Vector3f &, const std::string &texture = "");
  virtual	~Cube();

public:
  virtual void		initialize();
  virtual void		update();
  virtual void		draw(void);

private:
  Vector3f	_origin;
  Vector3f	_opposite;
  gdl::Image	_texture;
  bool		_stateTexture;
};

#endif
