#pragma once
#include "Image_Filtering.h"
#include "Resize.h"
#include <opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <msclr\marshal_cppstd.h>
#include<stdio.h>
#include<string.h>
#include <opencv2/features2d.hpp>
#include <vector>
#include "Hamming.h"

using namespace msclr::interop;
namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;


	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label3;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 19.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(326, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(677, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Hamming distance between 2 images";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button1->Location = System::Drawing::Point(86, 394);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(247, 62);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Upload Photo1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(50, 115);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(326, 270);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->ImageLocation = "default.png";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(458, 115);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(326, 273);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			this->pictureBox2->ImageLocation = "default.png";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button2->Location = System::Drawing::Point(495, 394);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(247, 62);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Upload Photo2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button3->Location = System::Drawing::Point(157, 553);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(191, 56);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Add noise";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button4->Location = System::Drawing::Point(382, 553);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(191, 56);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Remove noise";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button5->Location = System::Drawing::Point(606, 553);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(191, 56);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Black and white";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button8->Location = System::Drawing::Point(682, 673);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(153, 38);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Reset";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(889, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(502, 150);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Instructions:\r\n\r\n1. Upload two pictures\r\n2. Apply a filter\r\n3. Click \"Hamming dis"
				L"tance\" button ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button9->Location = System::Drawing::Point(1016, 467);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(266, 74);
			this->button9->TabIndex = 12;
			this->button9->Text = L"Hamming distance";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(879, 115);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(556, 346);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 13;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(876, 575);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 14;
			this->label3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1511, 817);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"MyForm";
			this->Text = L"Proiect POO";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ initialPicture1;
		String^ initialPicture2;
		bool blur = false;
		bool clar = false;
		bool bandw = false;
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "jpeg files (*.jpeg)|*.jpeg|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				// Insert code to read the stream here.
				pictureBox1->ImageLocation = openFileDialog1->FileName;
				myStream->Close();
			}
		}
		initialPicture1 = pictureBox1->ImageLocation;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ myStream;
		OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog;

		openFileDialog2->InitialDirectory = "c:\\";
		openFileDialog2->Filter = "jpeg files (*.jpeg)|*.jpeg|All files (*.*)|*.*";
		openFileDialog2->FilterIndex = 2;
		openFileDialog2->RestoreDirectory = true;

		if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog2->OpenFile()) != nullptr)
			{
				// Insert code to read the stream here.
				pictureBox2->ImageLocation = openFileDialog2->FileName;
				myStream->Close();
			}
		}
		initialPicture2 = pictureBox2->ImageLocation;
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Filter_Image Image1(1);
		String^ sourcePath1 = initialPicture1;
		Image1.sourcePath = marshal_as<std::string>(sourcePath1);
		Image1.apply_filters();
		pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-1.png";
		Filter_Image Image2(2);
		String^ sourcePath2 = initialPicture2;
		Image2.sourcePath = marshal_as<std::string>(sourcePath2);
		Image2.apply_filters();
		pictureBox2->ImageLocation = "pooProg\\filteredImages\\poza2-1.png";
		blur = true;
		clar = false;
		bandw = false;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Filter_Image Image1(1);
		String^ sourcePath1 = initialPicture1;
		Image1.sourcePath = marshal_as<std::string>(sourcePath1);
		Image1.apply_filters();
		pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-2.png";
		Filter_Image Image2(2);
		String^ sourcePath2 = initialPicture2;
		Image2.sourcePath = marshal_as<std::string>(sourcePath2);
		Image2.apply_filters();
		pictureBox2->ImageLocation = "pooProg\\filteredImages\\poza2-2.png";
		blur = false;
		clar = true;
		bandw = false;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Filter_Image Image1(1);
		String^ sourcePath1 = initialPicture1;
		Image1.sourcePath = marshal_as<std::string>(sourcePath1);
		Image1.apply_filters();
		pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-0.png";
		Filter_Image Image2(2);
		String^ sourcePath2 = initialPicture2;
		Image2.sourcePath = marshal_as<std::string>(sourcePath2);
		Image2.apply_filters();
		pictureBox2->ImageLocation = "pooProg\\filteredImages\\poza2-0.png";
		blur = false;
		clar = false;
		bandw = true;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->ImageLocation != initialPicture1)
			pictureBox1->ImageLocation = initialPicture1;
		else {
			if (blur)pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-1.png";
			else if (clar)pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-2.png";
			else if (bandw)pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-0.png";
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->ImageLocation != initialPicture1)
			pictureBox1->ImageLocation = initialPicture1;
		else {
			if (blur)pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-1.png";
			else if (clar)pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-2.png";
			else if (bandw)pictureBox1->ImageLocation = "pooProg\\filteredImages\\poza1-0.png";
		}
	}
		   private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			   pictureBox1->ImageLocation = "default.png";
			   pictureBox2->ImageLocation = "default.png";
			   pictureBox3->Visible = false;
			   label2->Visible = true;
			   this->label3->Text = "";

		   }
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string img1 = marshal_as<std::string>(pictureBox1->ImageLocation);
		std::string img2 = marshal_as<std::string>(pictureBox2->ImageLocation);
		Images Image;
		Image.resize_Images(img1, img2);
		if (Image.k == 0)img1 = "pooProg\\Resized_Image1.png";
		else img2 = "pooProg\\Resized_Image2.png";
		Hamming Hamming(img1, img2);
		Hamming.master();
		this->label2->Visible = false;
		this->pictureBox3->ImageLocation = "pooProg\\test.jpg";
		this->pictureBox3->Visible = true;
		this->label3->Text = gcnew String(Hamming.print.data());
		this->label3->Visible = true;

	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}
