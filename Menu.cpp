#include "menu.h"

Menu::Menu(sf::RenderWindow* janela){
    window = janela;
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    window->setPosition(sf::Vector2i(0, 0));

    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("./times-new-roman-bold-italic.ttf");
    image->loadFromFile("./menu.png");

    bg->setTexture(*image);
}


Menu::~Menu(){
  window=nullptr;
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(int tipo){

  if (tipo == 1) {
      options = { "zelda++", "iniciar", "ranking" };
      numOpcoes = 2;
      texts.resize(3);
      coords = { {677,55},{655,247},{655,453} };
      sizes = { 124,103,103, };
  }

  else if (tipo == 2) {
      options = { "zelda++",  "1 jogador", "2 jogadores"};
      numOpcoes = 2;
      texts.resize(3);
      coords = { {677,55},{655,247},{655,453} };
      sizes = { 124,103,103, };
  }

  else if (tipo == 3) {
      options = { "zelda++", "Fase 1", "Fase 2" };
      numOpcoes = 2;
      texts.resize(3);
      coords = { {677,55},{655,247},{655,453} };
      sizes = { 124,103,103, };
  }

  else if (tipo == 4) {
      options = { "Pause", "despausar", "menu","salvar e sair"};
      numOpcoes = 3;
      texts.resize(4);
      coords = { {654,58},{592,257},{592,415},{592,550} };
      sizes = { 124,103,103,103 };
  }
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

int Menu::loop_events(){
  sf::Event event;
  while(window->pollEvent(event)){
    if( event.type == sf::Event::Closed){
      window->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < numOpcoes){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
        return 0;
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
        return 0;
      }
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && theselect) {
        theselect = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      texts[pos].setOutlineThickness(0);
      return pos;
    }
    return 0;
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

int Menu::run_menu(){
    int output=loop_events();
    draw_all();
    return output;
}
