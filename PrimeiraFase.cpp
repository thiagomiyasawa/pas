#include "PrimeiraFase.h"

PrimeiraFase::PrimeiraFase(RenderWindow* w, Jogador* j, bool nova) : Fase(w, j) {
	if (nova) {
		criaMapa();
		inicializaElementos();
	}
	
}

PrimeiraFase::PrimeiraFase(RenderWindow* w, Jogador* J1, Jogador* J2,float tempo, bool nova)
	: Fase(w, J1, J2,tempo) {
	if (nova) {
		criaMapa();
		inicializaElementos();
	}
}

PrimeiraFase::~PrimeiraFase()
{
}

void PrimeiraFase::criaMapa() {
	int i;

	Vector2f coordenada;
	Vector2f tamanho(50.f, 50.f);



	//meio
	coordenada = Vector2f(465, 370);
	for (i = 0; i < 7; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//inferior esquerda
	coordenada = Vector2f(15, 520);
	for (i = 0; i < 8; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//inferior direita
	coordenada = Vector2f(865, 520);
	for (i = 0; i < 8; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//superior esquerda
	coordenada = Vector2f(15, 220);
	for (i = 0; i < 7; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//superior direita
	coordenada = Vector2f(915, 220);
	for (i = 0; i < 7; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//gera um numero aleatorio de plataformas falsas entre 3 e 20% das plaataformas
	srand(time(NULL));
	convertePlatF(rand() % (listaObstaculos->getSize() / 5 - 3) + 3);

	//gera um numero aleatorio de plataformas falsas entre 3 e 20% das plataformas
	converteEsp(rand() % (listaObstaculos->getSize() / 5 - 3) + 3);

	//adiciona a lava

	coordenada = Vector2f(-60., 650.);
	tamanho = Vector2f(70., 70.);

	for (i = 0; i < 20; i++) {
		Obstaculo* temp = new Lava(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 70.;
	}

	//gera o contorno da fase
	coordenada = Vector2f(-100., 0.);
	tamanho = Vector2f(10., 820.);
	Obstaculo* temp = new Plataforma(coordenada, tamanho);
	listaObstaculos->push(temp);

	coordenada = Vector2f(-100., 820.);
	tamanho = Vector2f(1280., 30.);
	temp = new Plataforma(coordenada, tamanho);
	listaObstaculos->push(temp);

	coordenada = Vector2f(1370., 0);
	tamanho = Vector2f(10., 820.);
	temp = new Plataforma(coordenada, tamanho);
	listaObstaculos->push(temp);

	for (int i = 0; i < listaObstaculos->getSize(); i++) {
		Obstaculo* temp = listaObstaculos->getItem(i);
		colisoes->addObstaculo(temp);
	}

	for (int i = 0; i < 3; i++) {
		geraMoa();
	}

	for (int i = 0; i < 3; i++) {
		geraOctorok();
	}
}



void PrimeiraFase::geraInimigoAleatorio() {
	int tipo = rand() % 2;
	if (tipo == 1) {
		geraMoa();
	}
	else {
		geraOctorok();
	}
}

void PrimeiraFase::geraMoa() {
	Moa* moa = nullptr;
	int area = rand() % 4;
	if (area == 0) {
		moa = new Moa(1, Vector2f(20 + rand() % 1180, rand() % 140));
	}
	else if (area == 1) {
		moa = new Moa(1, Vector2f(400 + rand() % 500, rand() % 70 + 210));
	}
	else if (area == 2) {
		moa = new Moa(1, Vector2f(20 + rand() % 380, rand() % 80 + 290));
	}
	else if (area == 3) {
		moa = new Moa(1, Vector2f(900 + rand() % 380, rand() % 80 + 290));
	}
	colisoes->addInimigo(moa);
	listaEntidades->push(moa);
}

void PrimeiraFase::geraOctorok() {
	Octorok* octorok = nullptr;
	int area = rand() % 4;
	if (area == 0) {
		octorok = new Octorok(1, Vector2f(20 + rand() % 1180, rand() % 140));
	}
	else if (area == 1) {
		octorok = new Octorok(1, Vector2f(400 + rand() % 500, rand() % 70 + 210));
	}
	else if (area == 2) {
		octorok = new Octorok(1, Vector2f(20 + rand() % 380, rand() % 80 + 290));
	}
	else if (area == 3) {
		octorok = new Octorok(1, Vector2f(900 + rand() % 380, rand() % 80 + 290));
	}
	colisoes->addInimigo(octorok);
	listaEntidades->push(octorok);
	colisoes->addProjetil(octorok->getProjetil());
	listaEntidades->push(octorok->getProjetil());
}

void PrimeiraFase::salvar(int pontos) {
	ofstream gravador("save/fase.dat", ios::app);

	if (!gravador)
	{
		return;
	}
	gravador << 1 << ' '
			 << pontos <<
			 endl;
	gravador.close();

	for (int i = 0; i < listaEntidades->getSize(); i++) {
		Entidade* temp = listaEntidades->getItem(i);
		if (temp->getId() != 41) {
			temp->gravar();
		}
		
	}
}

PrimeiraFase* PrimeiraFase::recuperar(RenderWindow* w) {
	Jogador* j1 = Jogador::recuperar();
	Jogador* j2 = Jogador::recuperar();
	PrimeiraFase* fase;

	if (j2 != nullptr) {
		fase = new PrimeiraFase(w, j1, j2, false);
	}
	else {
		fase = new PrimeiraFase(w, j1, false);
	}
	
	ListaEntidades* LEs = fase->getListaEntidades();
	GerenciadorColisoes* c = fase->getGerenciadorColisoes();
	
	Moa* m = Moa::recuperar();
	while (m != nullptr) {
		c->addInimigo(m);
		LEs->push(m);
		m = Moa::recuperar();	
	}

	Octorok* o = Octorok::recuperar();
	while (o != nullptr) {
		c->addInimigo(o);
		LEs->push(o);
		o = Octorok::recuperar();
	}

	Plataforma* p = Plataforma::recuperar();
	while (p != nullptr) {
		c->addObstaculo(p);
		LEs->push(p);
		p = Plataforma::recuperar();
	}

	PlataformaFalsa* pf = PlataformaFalsa::recuperar();
	while (pf != nullptr) {
		c->addObstaculo(pf);
		LEs->push(pf);
		pf = PlataformaFalsa::recuperar();
	}

	Espinhos* e = Espinhos::recuperar();
	while (e != nullptr) {
		c->addObstaculo(e);
		LEs->push(e);
		e = Espinhos::recuperar();
	}

	Lava* l = Lava::recuperar();
	while (l != nullptr) {
		c->addObstaculo(l);
		LEs->push(l);
		l = Lava::recuperar();
	}

	return fase;
}
 