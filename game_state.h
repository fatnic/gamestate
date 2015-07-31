#pragma once

#include <SFML/Graphics.hpp>

class tiny_state
{
public:
  virtual void Initialize(sf::RenderWindow* window) {}
  virtual void Update(sf::RenderWindow* window) {}
  virtual void Render(sf::RenderWindow* window) {}
  virtual void Destroy(sf::RenderWindow* window) {}
};


class game_state
{
public:
  game_state()
  {
    this->state = NULL;
  }

  void Update()
  {
    if (this->state != NULL) { this->state->Update(this->window); }
  }

  void Render()
  {
    if (this->state != NULL) { this->state->Render(this->window); };
  }

  void setState(tiny_state* state)
  {
    if (this->state != NULL) { this->state->Destroy(this->window); }
    this->state = state;
    if (this->state != NULL) { this->state->Initialize(this->window); }
  }

  void setWindow(sf::RenderWindow* window)
  {
    this->window = window;
  }

  ~game_state()
  {
    if (this->state != NULL) { this->state->Destroy(this->window); };
  }

private:
  tiny_state* state;
  sf::RenderWindow* window;
};

extern game_state corestate;
