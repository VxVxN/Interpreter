#pragma once
#include <string>
#include <list>
#include <cstdlib>

#include "LexicalAnalyzer.h"
#include "Token.h"
#include "IExpression.h"
#include "ValueExpression.h"
#include "BinaryExpression.h"
#include "SyntaxAnalyzer.h"
#include "AssignmentStatement.h"

namespace Interpreter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ‚˚ÔÓÎÌËÚ¸ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBoxError;

	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::TextBox^  textBoxConsol;

	private: System::Windows::Forms::Splitter^  splitter2;
	private: System::Windows::Forms::TextBox^  textBoxProg;

	protected:


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ÔÓÎÌËÚ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxError = (gcnew System::Windows::Forms::TextBox());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->textBoxConsol = (gcnew System::Windows::Forms::TextBox());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->textBoxProg = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Ù‡ÈÎToolStripMenuItem,
					this->‚˚ÔÓÎÌËÚ¸ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(682, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// ‚˚ÔÓÎÌËÚ¸ToolStripMenuItem
			// 
			this->‚˚ÔÓÎÌËÚ¸ToolStripMenuItem->Name = L"‚˚ÔÓÎÌËÚ¸ToolStripMenuItem";
			this->‚˚ÔÓÎÌËÚ¸ToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->‚˚ÔÓÎÌËÚ¸ToolStripMenuItem->Text = L"¬˚ÔÓÎÌËÚ¸";
			this->‚˚ÔÓÎÌËÚ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::‚˚ÔÓÎÌËÚ¸ToolStripMenuItem_Click);
			// 
			// textBoxError
			// 
			this->textBoxError->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBoxError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxError->Location = System::Drawing::Point(0, 456);
			this->textBoxError->Multiline = true;
			this->textBoxError->Name = L"textBoxError";
			this->textBoxError->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxError->Size = System::Drawing::Size(682, 67);
			this->textBoxError->TabIndex = 1;
			// 
			// splitter1
			// 
			this->splitter1->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->splitter1->Location = System::Drawing::Point(0, 446);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(682, 10);
			this->splitter1->TabIndex = 2;
			this->splitter1->TabStop = false;
			// 
			// textBoxConsol
			// 
			this->textBoxConsol->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBoxConsol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxConsol->Location = System::Drawing::Point(0, 253);
			this->textBoxConsol->Multiline = true;
			this->textBoxConsol->Name = L"textBoxConsol";
			this->textBoxConsol->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxConsol->Size = System::Drawing::Size(682, 193);
			this->textBoxConsol->TabIndex = 3;
			// 
			// splitter2
			// 
			this->splitter2->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitter2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->splitter2->Location = System::Drawing::Point(0, 243);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(682, 10);
			this->splitter2->TabIndex = 4;
			this->splitter2->TabStop = false;
			// 
			// textBoxProg
			// 
			this->textBoxProg->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxProg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxProg->Location = System::Drawing::Point(0, 24);
			this->textBoxProg->Multiline = true;
			this->textBoxProg->Name = L"textBoxProg";
			this->textBoxProg->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBoxProg->Size = System::Drawing::Size(682, 219);
			this->textBoxProg->TabIndex = 5;
			this->textBoxProg->Text = L"word = 2 + 3\r\nword2 = PI + word\r\nprint \"word = \" + word + \"\\n\"\r\nprint \"word2 = \" "
				L"+ word2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 523);
			this->Controls->Add(this->textBoxProg);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->textBoxConsol);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->textBoxError);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"»ÌÚÂÔÂÚ‡ÚÓ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		std::string SystemToStr(String ^s)
		{
			using namespace Runtime::InteropServices;
			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			return std::string(ptr);
		}

		String ^ StrToSystem(std::string &s)
		{
			return gcnew System::String(s.c_str());
		}

		String ^ StrToSystem(const char *s)
		{
			return gcnew System::String(s);
		}

	private: System::Void ‚˚ÔÓÎÌËÚ¸ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		textBoxConsol->Text = "";
		textBoxError->Text = "";
		std::string input = SystemToStr(textBoxProg->Text);
		LexicalAnalyzer lexicalAnalyzer(input);
		try
		{
			std::list<Token> tokenList = lexicalAnalyzer.tokenize();

			SyntaxAnalyzer *syntaxAnalyzer = new SyntaxAnalyzer(tokenList);
			std::list<std::unique_ptr<IStatement>> statements(syntaxAnalyzer->parse());

			for (std::unique_ptr<IStatement> &statement : statements) {
				if (statement->execute() != "")
					textBoxConsol->AppendText(StrToSystem(statement->execute()));
			}
		}
		catch (const char *ex)
		{
			textBoxError->AppendText(StrToSystem(ex));
		}
		Variables::clear();
	}
};
}
