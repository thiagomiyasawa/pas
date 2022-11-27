#include "SegundaFase.h"

SegundaFase::SegundaFase(RenderWindow* w, Jogador* J1, float tempo, bool nova)
	: Fase(w, J1, nullptr, tempo) {
	if (nova) {
		criaMapa();
		inicializaElementos();
		tempoRestante = 90;
	}
}
SegundaFase::SegundaFase(RenderWindow* w, Jogador* J1, Jogador* J2,float tempo, bool nova)
	: Fase(w, J1, J2,tempo) {
	if (nova) {
		criaMapa();
		inicializaElementos();
		tempoRestante = 90;
	}
}

SegundaFase::~SegundaFase()
{
}

void SegundaFase::criaMapa()
{
	int i;

	Vector2f coordenada;
	Vector2f tamanho(50.f, 50.f);
	
	
	//inferior
	coordenada = Vector2f(-35, 550);
	for (i = 0; i < 27; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//superior
	coordenada = Vector2f(375, 300);
	for (i = 0; i < 11; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//quina esquerda
	coordenada = Vector2f(265, 350);
	for (i = 0; i < 3; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//quina direita
	coordenada = Vector2f(865, 350);
	for (i = 0; i < 3; i++) {
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
		geraGanon();
	}

}

void SegundaFase::geraInimigoAleatorio()
{
	int tipo = rand() % 2;
	if (tipo == 1) {
		geraMoa();
	}
	else {
		geraGanon();
	}
}

void SegundaFase::geraMoa()
{
	Moa* moa = nullptr;
	int area = rand() % 3;
	if (area == 0) {
		moa = new Moa(1, Vector2f( rand() % 1230, rand() % 250));
	}
	else if (area == 1) {
		moa = new Moa(1, Vector2f( rand() % 210, rand() % 100 + 300));
	}
	else if (area == 2) {
		moa = new Moa(1, Vector2f(1020 + rand() % 210, rand() % 100 + 300));
	}
	colisoes->addInimigo(moa);
	listaEntidades->push(moa);
}

void SegundaFase::geraGanon() {
	Ganondorf* ganon = nullptr;
	int area = rand() % 3;
	if (area == 0) {
		ganon = new Ganondorf(1, Vector2f(20 + rand() % 1230, rand() % 200));
	}
	else if (area == 1) {
		ganon = new Ganondorf(1, Vector2f(rand() % 210, rand() % 50 + 300));
	}
	else if (area == 2) {
		ganon = new Ganondorf(1, Vector2f(1020 + rand() % 210, rand() % 50 + 300));
	}
	colisoes->addInimigo(ganon);
	listaEntidades->push(ganon);
}

void SegundaFase::salvar(int pontos, float tempo) {
	ofstream gravador("save/fase.dat", ios::trunc);

	if (!gravador)
	{
		return;
	}
	setTempoRestante(90 - (tempo - tempoInicial));
	gravador << 2 << ' '
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

	gravador.open("save/ganondorf.dat", ios::trunc);
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

SegundaFase* SegundaFase::recuperar(RenderWindow* w, float tempo) {
	Lista<Jogador>* lj = Jogador::recuperar();
	SegundaFase* fase;
	if (lj->getSize() == 2) {

		fase = new SegundaFase(w, lj->getItem(0), lj->getItem(1), tempo, false);

	}
	else {

		fase = new SegundaFase(w, lj->getItem(0), tempo, false);
	}
	ListaEntidades* LEs = fase->getListaEntidades();
	GerenciadorColisoes* c = fase->getGerenciadorColisoes();

	Lista<Moa>* m = Moa::recuperar();
	for (int i = 0; i < m->getSize(); i++) {
		Moa* temp = m->getItem(i);
		LEs->push(temp);
		c->addInimigo(temp);
	}

	Lista<Ganondorf>* g = Ganondorf::recuperar();
	for (int i = 0; i < g->getSize(); i++) {
		Ganondorf* temp = g->getItem(i);
		LEs->push(temp);
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
