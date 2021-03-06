/*
** Bomberman.h for  in /home/lund/Projets/bomberpony
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon May 13 17:01:39 2013 florian dewulf
** Last update Sat May 25 01:40:33 2013 florian dewulf
*/

#ifndef		BOMBERMAN_H__
# define	BOMBERMAN_H__

enum {
  NOTHING = 0,
  MENU,
  BATTLE,
  GAME,
  SCORE,
  OPTION,
  SOUND,
  MAP_TYPE,
  MAP_OPTION,
  ONE,
  TWO,
  VICTORY,
  GAMEOVER,
  IA,
  LOAD,
  DEC_OPTION,
  INC_OPTION,
  END_INPUT,
  QUIT
};

typedef int	MenuType;

enum eMode {
  EASY,
  MEDIUM,
  HARD
};

#endif
