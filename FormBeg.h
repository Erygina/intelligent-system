#pragma once
//#include <string>
namespace ISLB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormBeg
	/// </summary>
	public ref class FormBeg : public System::Windows::Forms::Form
	{
	public:
		FormBeg(void)
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
		~FormBeg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormBeg::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1104, 636);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::LightCyan;
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(348, 193);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(372, 236);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Cornsilk;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::MediumSeaGreen;
			this->button2->Location = System::Drawing::Point(110, 136);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 45);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Результат";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormBeg::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cornsilk;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::MediumSeaGreen;
			this->button1->Location = System::Drawing::Point(110, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 45);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Начать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormBeg::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightCyan;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::DarkOrange;
			this->label1->Location = System::Drawing::Point(488, 154);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 36);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Меню";
			// 
			// FormBeg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1128, 660);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FormBeg";
			this->Text = L"FormBeg";
			this->Load += gcnew System::EventHandler(this, &FormBeg::FormBeg_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		
	
private: System::Void FormBeg_Load(System::Object^ sender, System::EventArgs^ e) {
}
	
	private:static String^ LivingSpace;
	private:static String^ Location="";
	private:static String^ DesiredProperty = "";
	private:static String^ HavingChildren = "";
	private:static String^ GenderOfChildren = "";
	private:static String^ Car = "";
	private:static String^ Garage = "";
	private:static String^ AdditionalBuilding = "";
	

	private:static int NumberOfChildren=-2, MinimumAge=-2, Budget=-2, price=-2;


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	
	public: void livingSpace(String^ text)
	{
		LivingSpace = text;
	}
	public: void location(String^ text)
	{
		Location = text;
	}
	public: void havingChildren(String^ text)
	{
		HavingChildren = text;
	}
	public: void genderOfChildren(String^ text)
	{
		GenderOfChildren = text;
	}
	public: void numberOfChildren(int obj)
	{
		NumberOfChildren = obj;
	}
	public: void minimumAge(int obj)
	{
		MinimumAge = obj;
	}
	public: void car(String^ text)
	{
		Car = text;
	}
	public: void garage(String^ text)
	{
		Garage = text;
	}
	public: void budget(int obj)
	{
		Budget = obj;
	}
	public: void additionalBuilding(String^ text)
	{
		AdditionalBuilding = text;
	}


	public:	void inf_apartment();
	public:	void inf_garage();
	public:	void inf_house();
	public:	void inf_flat_and_garage();
	public:	template <typename T> void about_apartment(T* mass, int size, int* help);
	public:	void buy_apartment();
	public:	void buy_garage();
	public:	void buy_house();
	public:	void buy();

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);

	public: System::Void Q6();
	public: System::Void Q5();
	public: System::Void Q4();
	public: System::Void Q3();
	public: System::Void Q2();
	public: System::Void Q1();


};

	
template<typename T>
inline void FormBeg::about_apartment(T* mass, int size, int* help) //проверка описания квартир. одинаково для квартир с гаражом и без
{
	int i;
	if (find(Choice.begin(), Choice.end(), ">=2_room ") != Choice.end()) {
		for (i = 0; i < size; i++) {
			if (mass[i].rooms < 2) help[i] = -1;
		}

	}
	if (find(Choice.begin(), Choice.end(), "SchoolAndKindergarten ") != Choice.end()) {
		for (i = 0; i < size; i++) {
			if (mass[i].infrastructure != "школа и детский сад") {
				help[i] = -1;
			}
		}
	}
	if (find(Choice.begin(), Choice.end(), "School ") != Choice.end()) {
		for (i = 0; i < size; i++) {
			if (mass[i].infrastructure == "нет школы и детского сада")
				help[i] = -1;
		}
	}
	for (i = 0; i < size; i++) {       //Если бюджет покупателя больше или равен цены , то ее следует купить
		if (mass[i].price > Budget) help[i] = -1;
	}
}

}
