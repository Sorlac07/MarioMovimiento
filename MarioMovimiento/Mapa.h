#pragma once

using namespace System::Drawing;

class Mapa {
private:
	int x, y, W, H, dx;
public:
	Mapa(Bitmap^ imgEscenario) {
		x = y = 0;
		W = imgEscenario->Width;
		H = imgEscenario->Height;
		dx = 0;
	}
	~Mapa() {}
	void Dibujar(Graphics^ gr, Bitmap^ imgEscenario) {
		Rectangle regionFondo = Rectangle(x, y, W, H);
		gr->DrawImage(imgEscenario, 0, 0, regionFondo, GraphicsUnit::Pixel);
		x = x + dx;
	}
	//metodos de acceso set and get
	//Getter de los atributos 
	int GetX() { return x; }
	int GetY() { return y; }
	int GetDx() { return dx; }

	//Setter de los atributos
	void SetX(int dato) { x = dato; }
	void SetY(int dato) { y = dato; }
	void SetDx(int dato) { dx = dato; }


};