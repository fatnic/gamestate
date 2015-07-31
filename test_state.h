#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "game_state.h"

class test_state : public tiny_state
{
public:
  void Initialize(sf::RenderWindow* window);
  void Update(sf::RenderWindow* window);
  void Render(sf::RenderWindow* window);
  void Destroy(sf::RenderWindow* window);
private:
  sf::Font font;

  sf::Text title;
  sf::Text play;
  sf::Text quit;

  int selected;

};

#endif // TEST_STATE_H
