#pragma once
#include "Personaje.h"
#include "Mapa.h"



namespace MarioMovimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = this->CreateGraphics();
			imgPersonaje = gcnew Bitmap("img/Persona2.png");
			imgFondo = gcnew Bitmap("img/fondo.jpg");
			persona = new Personaje();
			mapa = new Mapa(imgFondo);
		
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ g;
		Personaje* persona;
		Mapa* mapa;
		Bitmap^ imgPersonaje;
		Bitmap^ imgFondo;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1011, 495);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->Clear(Color::White);
		
		mapa->Dibujar(bf->Graphics,imgFondo);
		persona->Dibujar(bf->Graphics, imgPersonaje);

		bf->Render(g);

		delete bf, bfc;

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	
		
			if (e->KeyCode == Keys::Up) {
				persona->SetDx(30);
				persona->SetDy(30);
				persona->Mover(Arriba, g);
			}

			if (e->KeyCode == Keys::Left) {
				if (persona->GetX() > 70) {

					persona->SetDx(30);
					persona->SetDy(30);
					persona->Mover(Izquierda, g);
				}

				else {
					persona->SetDx(0);
					persona->Mover(Izquierda, g);
					mapa->SetDx(-30);
				}
			}
			if (e->KeyCode == Keys::Right) {
				if (persona->GetX() <= g->VisibleClipBounds.Width / 2) {
				persona->SetDx(30);
				persona->SetDy(30);
				persona->Mover(Derecha, g);
				} 
				else{
					persona->SetDx(0);
					persona->Mover(Derecha,g);
					mapa->SetDx(30);
				}
			}
		
		
	
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		persona->SetDx(0);
		persona->SetDy(0);
		persona->Mover(Ninguna,g);
		mapa->SetDx(0);
	}
	};
}
