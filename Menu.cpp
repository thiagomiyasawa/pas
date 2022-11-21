#include "menu.h"

Menu::Menu(sf::RenderWindow* janela){
    window = janela;
  font = new sf::Font();
  image = new sf::Texture();
  bg = new sf::Sprite();

  set_values();
}

Menu::~Menu(){
  delete window;
  delete winclose;
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  window->setPosition(sf::Vector2i(0,0));

  pos = 0;
  pressed = theselect = false;
  font->loadFromFile("./times-new-roman-bold-italic.ttf");
  image->loadFromFile("./menu.png");

  bg->setTexture(*image);


  options = {"zelda++", "1 jogador", "2 jogadores"};
  texts.resize(3);
  coords = {{677,55},{655,247},{655,453}};
  sizes = {124,103,103,};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setFillColor(sf::Color(228, 58, 20));
   texts[i].setOutlineColor(sf::Color::White);
   texts[i].setPosition(coords[i]);
  }
  texts[1].setOutlineThickness(4);
  pos = 1;

}

void Menu::loop_events(int* estado){
  sf::Event event;
  while(window->pollEvent(event)){
    if( event.type == sf::Event::Closed){
      window->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < 2){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos > 1){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if (pos == 1) {
          *estado = 1;
      }
      if (pos == 2) {
          *estado = 2;
      }
    }

  }
}

void Menu::draw_all(){
  window->clear();
  window->draw(*bg);
  for(auto t : texts){
   window->draw(t); 
  }
  window->display();
}

void Menu::run_menu(int* estado){
    loop_events(estado);
    draw_all();
}
