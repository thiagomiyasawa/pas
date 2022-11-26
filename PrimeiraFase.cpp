#include "PrimeiraFase.h"
PrimeiraFase::PrimeiraFase(RenderWindow* w, Jogador* J1, float tempo, bool nova)
	: Fase(w, J1, nullptr, tempo) {
	if (nova) {
		criaMapa();
		inicializaElementos();
		tempoRestante = 90;
	}
}
PrimeiraFase::PrimeiraFase(RenderWindow* w, Jogador* J1, Jogador* J2,float tempo, bool nova)
	: Fase(w, J1, J2,tempo) {
	if (nova) {
		criaMapa();
		inicializaElementos();
		tempoRestante = 90;
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

void PrimeiraFase::salvar(int pontos, float tempo) {
	ofstream gravador("save/fase.dat", ios::trunc);

	if (!gravador)
	{
		return;
	}
	setTempoRestante(90 - (tempo - tempoInicial));
	gravador << 1 << ' '
			 << pontos << ' '
			 << tempoRestante << 
			 endl;
	gravador.close();

	gravador.open("save/espinhos.dat", ios::trunc);
	gravador.close();

	gravador.open("save/jogador.dat", ios::trunc);
	gravador.close();

	gravador.open("save/lava.dat", ios::trunc);
	gravador.close();

	gravador.open("save/moa.dat", ios::trunc);
	gravador.close();

	gravador.open("save/octorok.dat", ios::trunc);
	gravador.close();

	gravador.open("save/plataforma.dat", ios::trunc);
	gravador.close();

	gravador.open("save/plataformafalsa.dat", ios::trunc);
	gravador.close();

	gravador.open("save/projetil.dat", ios::trunc);
	gravador.close();

	for (int i = 0; i < listaEntidades->getSize(); i++) {
		Entidade* temp = listaEntidades->getItem(i);
		if (temp->getId() != 41) {
			temp->gravar();
		}
		
	}
	



}

PrimeiraFase* PrimeiraFase::recuperar(RenderWindow* w, float tempo) {
	Lista<Jogador>* lj = Jogador::recuperar();
	PrimeiraFase* fase;
	if (lj->getSize() == 2) {

		fase = new PrimeiraFase(w, lj->getItem(0), lj->getItem(1), tempo, false);

	}
	else {

		fase = new PrimeiraFase(w, lj->getItem(0), tempo, false);
	}
	ListaEntidades* LEs = fase->getListaEntidades();
	GerenciadorColisoes* c = fase->getGerenciadorColisoes();
	
	Lista<Moa>* m = Moa::recuperar();
	for (int i = 0; i < m->getSize(); i++) {
		Moa* temp = m->getItem(i);
		LEs->push(temp);
		c->addInimigo(temp);
	}

	Lista<Octorok>* o = Octorok::recuperar();
	Lista<Projetil>* pr = Projetil::recuperar();
	for (int i = 0; i < o->getSize(); i++) {
		Octorok* temp = o->getItem(i);
		Projetil* tempP = pr->getItem(i);
		temp->setProjetil(tempP);
		LEs->push(tempP);
		LEs->push(temp);
		c->addProjetil(tempP);
		c->addInimigo(temp);
	}
	
	Lista<Plataforma>* p = Plataforma::recuperar();
	for (int i = 0; i < p->getSize(); i++) {
		Plataforma* temp = p->getItem(i);
		LEs->push(temp);
		c->addObstaculo(temp);
	}

	Lista<PlataformaFalsa>* pf = PlataformaFalsa::recuperar();
	for (int i = 0; i < pf->getSize(); i++) {
		PlataformaFalsa* temp = pf->getItem(i);
		LEs->push(temp);
		c->addObstaculo(temp);
	}

	Lista<Espinhos>* e = Espinhos::recuperar();
	for (int i = 0; i < e->getSize(); i++) {
		Espinhos* temp = e->getItem(i);
		LEs->push(temp);
		c->addObstaculo(temp);
	}

	Lista<Lava>* l = Lava::recuperar();
	for (int i = 0; i < l->getSize(); i++) {
		Lava* temp = l->getItem(i);
		LEs->push(temp);
		c->addObstaculo(temp);
	}
	

	return fase;
}
 