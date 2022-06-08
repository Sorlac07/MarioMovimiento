#pragma once
#include <iostream>

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguna };

//gravedad
#define Gravedad 9

using namespace System::Drawing;

class Personaje  {
private:
	int x, y, dx, dy;
	int Ancho, Alto;
	int Fila, Columna;

public:

	Personaje() {
		x = 80;
		y = 250;
		dx = 0;
		dy = 0;
		Fila = 1;
		Columna = 1;
	};
	~Personaje() {};
	void Mover(Direccion direccion, Graphics^ g) {

		if (direccion == Arriba && y>= 300) { y -= 80;; }
		//if (direccion == Abajo && y + dy  + 70 < g->VisibleClipBounds.Height) { y += dy; Fila = 0; std::cout << "abajo"; }
		if (direccion == Derecha && x + dx  + 70 < g->VisibleClipBounds.Width) { x += dx; Fila = 1; }
		if (direccion == Izquierda && x - dx > 0) { x -= dx; Fila = 2; }
		//if (direccion == Ninguna) { Columna = 0; }
		
	
	}
	void Dibujar(Graphics^ g, Bitmap^ img) {
		Alto = img->Height / 4;
		Ancho = img->Width / 4;
		Rectangle molde = Rectangle(Columna * Ancho, Fila * Alto, Ancho, Alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		if (!(dx == 0 && dy == 0) || x>g->VisibleClipBounds.Width/2 || x<=70) {
			Columna++;
		}
		if (Columna == 4) { Columna = 0; }

		//Gravedad
		y = y + Gravedad;
		if (y >= 300) {
			y = 300;
		}

	}

	//Getter de los atributos 
	int GetX() { return x; }
	int GetY() { return y; }
	int GetDx() { return dx; }
	int GetDy() { return dy; }
	int GetAncho() { return Ancho; }
	int GetAlto() { return Alto; }
	int GetFila() { return Fila; }
	int GetColumna() { return Columna; }
	//Setter de los atributos
	void SetX(int dato) { x = dato; }
	void SetY(int dato) { y = dato; }
	void SetDx(int dato) { dx = dato; }
	void SetDy(int dato) { dy = dato; }
	void SetAncho(int dato) { Ancho = dato; }
	void SetAlto(int dato) { Alto = dato; }
	void SetFila(int dato) { Fila = dato; }
	void SetColumna(int dato) { Columna = dato; }

};


