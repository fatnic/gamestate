#include "test_state.h"
#include <iostream>

void test_state::Initialize(sf::RenderWindow* window)
{
  this->font.loadFromFile("assets/font.ttf");
  this->title = sf::Text("The Title", font, 128U);
  this->title.setOrigin(this->title.getGlobalBounds().width / 2, this->title.getGlobalBounds().height / 2);
  this->title.setPosition(window->getSize().x / 2, window->getSize().y / 4);

  this->play = sf::Text("Play", font, 48U);
  this->play.setOrigin(this->play.getGlobalBounds().width / 2, this->play.getGlobalBounds().height / 2);
  this->play.setPosition(window->getSize().x / 2, this->title.getPosition().y + 150);

  this->quit = sf::Text("Quit", font, 48U);
  this->quit.setOrigin(this->quit.getGlobalBounds().width / 2, this->quit.getGlobalBounds().height / 2);
  this->quit.setPosition(window->getSize().x / 2, this->play.getPosition().y + 60);
}

void test_state::Update(sf::RenderWindow* window)
{
}

void test_state::Render(sf::RenderWindow* window)
{
  this->play.setColor(sf::Color::White);
  this->quit.setColor(sf::Color::White);
  switch(this->selected)
    {
    case 0:
      this->play.setColor(sf::Color::Green);
      break;
    case 1:
      this->quit.setColor(sf::Color::Green);
      break;
    }

  window->draw(this->title);
  window->draw(this->play);
  window->draw(this->quit);
}


void test_state::Destroy(sf::RenderWindow* window)
{
}

