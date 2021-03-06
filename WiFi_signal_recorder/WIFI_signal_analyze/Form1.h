#pragma once
#include"stdafx.h"
#include <stdlib.h>
#include"function.h"


namespace WIFI_signal_analyze {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;



	/// <summary>
	/// Form1 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
		
	public:
		bool Form1::ScanSSID();
		bool Form1::AUTO_SCAN();
		void Form1::showlog(String ^data);
		int Form1::Chart_Refresh();
		int Form1::DataGridView_Refresh();
		bool Form1::set_interface();
		void Form1::delay(int Seconds);
		void Form1::SaveDatatoFile(String ^File);
		void Form1::ResizeDatagrid(int width, bool flag);
		
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼

			
			//
		}
		
		
#pragma region
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Set_Button;
	protected: 

	protected: 

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  scan_button;
	private: System::Windows::Forms::Button^  stop_button;


	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripSplitButton^  toolStripSplitButton1;


	private: System::Windows::Forms::ToolStripMenuItem^  RSSItoolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  signalStrenghToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  ChanneltoolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  AuthStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  DataRatetoolStripMenuItem;

	private: System::Windows::Forms::ToolStripSplitButton^  toolStripSplitButton2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  Save_toolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Show;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Color;



	private: System::ComponentModel::IContainer^  components;


	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Set_Button = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Show = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Color = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->scan_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->RSSItoolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signalStrenghToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ChanneltoolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AuthStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DataRatetoolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSplitButton2 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->Save_toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Set_Button
			// 
			this->Set_Button->Location = System::Drawing::Point(12, 54);
			this->Set_Button->Name = L"Set_Button";
			this->Set_Button->Size = System::Drawing::Size(245, 25);
			this->Set_Button->TabIndex = 0;
			this->Set_Button->Text = L"Set Card";
			this->Set_Button->UseVisualStyleBackColor = true;
			this->Set_Button->Click += gcnew System::EventHandler(this, &Form1::Set_Button_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(263, 28);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(157, 24);
			this->textBox2->TabIndex = 3;
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->Show, this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Color});
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnF2;
			this->dataGridView1->Location = System::Drawing::Point(10, 82);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(703, 265);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellClick);
			// 
			// Show
			// 
			this->Show->HeaderText = L"";
			this->Show->MinimumWidth = 50;
			this->Show->Name = L"Show";
			this->Show->ReadOnly = true;
			this->Show->Width = 50;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"MAC";
			this->Column1->MinimumWidth = 100;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"SSID";
			this->Column2->MinimumWidth = 200;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column2->Width = 200;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"RSSI";
			this->Column3->MinimumWidth = 52;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column3->Width = 52;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"SIGNAL";
			this->Column4->MinimumWidth = 52;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column4->Width = 52;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Channel";
			this->Column5->MinimumWidth = 70;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column5->Width = 70;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"AuthType";
			this->Column6->MinimumWidth = 70;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column6->Width = 70;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"DataRate";
			this->Column7->MinimumWidth = 52;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column7->Width = 53;
			// 
			// Color
			// 
			this->Color->HeaderText = L"";
			this->Color->MinimumWidth = 30;
			this->Color->Name = L"Color";
			this->Color->ReadOnly = true;
			this->Color->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Color->Width = 30;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Seconds;
			chartArea1->AxisY->Interval = 5;
			chartArea1->AxisY->MajorGrid->Interval = 10;
			chartArea1->AxisY->Maximum = -30;
			chartArea1->AxisY->Minimum = -100;
			chartArea1->AxisY->MinorGrid->Interval = 1;
			chartArea1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::SystemColors::Control;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(10, 353);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			this->chart1->Size = System::Drawing::Size(703, 214);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			// 
			// timer1
			// 
			this->timer1->Interval = 3000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// scan_button
			// 
			this->scan_button->Enabled = false;
			this->scan_button->Location = System::Drawing::Point(263, 55);
			this->scan_button->Name = L"scan_button";
			this->scan_button->Size = System::Drawing::Size(76, 24);
			this->scan_button->TabIndex = 6;
			this->scan_button->Text = L"Record";
			this->scan_button->UseVisualStyleBackColor = true;
			this->scan_button->Click += gcnew System::EventHandler(this, &Form1::scan_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->Enabled = false;
			this->stop_button->Location = System::Drawing::Point(345, 55);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(75, 25);
			this->stop_button->TabIndex = 7;
			this->stop_button->Text = L"Stop";
			this->stop_button->UseVisualStyleBackColor = true;
			this->stop_button->Click += gcnew System::EventHandler(this, &Form1::stop_button_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 30);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(245, 20);
			this->comboBox1->TabIndex = 8;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripSplitButton1, 
				this->toolStripSplitButton2});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(732, 25);
			this->toolStrip1->TabIndex = 9;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripSplitButton1
			// 
			this->toolStripSplitButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripSplitButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->RSSItoolStripMenuItem, 
				this->signalStrenghToolStripMenuItem, this->ChanneltoolStripMenuItem, this->AuthStripMenuItem, this->DataRatetoolStripMenuItem});
			this->toolStripSplitButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripSplitButton1.Image")));
			this->toolStripSplitButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton1->Name = L"toolStripSplitButton1";
			this->toolStripSplitButton1->Size = System::Drawing::Size(51, 22);
			this->toolStripSplitButton1->Text = L"View";
			// 
			// RSSItoolStripMenuItem
			// 
			this->RSSItoolStripMenuItem->Checked = true;
			this->RSSItoolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->RSSItoolStripMenuItem->Name = L"RSSItoolStripMenuItem";
			this->RSSItoolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->RSSItoolStripMenuItem->Text = L"RSSI";
			this->RSSItoolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::RSSItoolStripMenuItem_Click);
			// 
			// signalStrenghToolStripMenuItem
			// 
			this->signalStrenghToolStripMenuItem->Checked = true;
			this->signalStrenghToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->signalStrenghToolStripMenuItem->Name = L"signalStrenghToolStripMenuItem";
			this->signalStrenghToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->signalStrenghToolStripMenuItem->Text = L"Signal Strengh";
			this->signalStrenghToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::signalStrenghToolStripMenuItem_Click);
			// 
			// ChanneltoolStripMenuItem
			// 
			this->ChanneltoolStripMenuItem->Checked = true;
			this->ChanneltoolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ChanneltoolStripMenuItem->Name = L"ChanneltoolStripMenuItem";
			this->ChanneltoolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->ChanneltoolStripMenuItem->Text = L"Channel";
			this->ChanneltoolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ChanneltoolStripMenuItem_Click);
			// 
			// AuthStripMenuItem
			// 
			this->AuthStripMenuItem->Checked = true;
			this->AuthStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->AuthStripMenuItem->Name = L"AuthStripMenuItem";
			this->AuthStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->AuthStripMenuItem->Text = L"Auth Type";
			this->AuthStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::AuthStripMenuItem_Click);
			// 
			// DataRatetoolStripMenuItem
			// 
			this->DataRatetoolStripMenuItem->Checked = true;
			this->DataRatetoolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->DataRatetoolStripMenuItem->Name = L"DataRatetoolStripMenuItem";
			this->DataRatetoolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->DataRatetoolStripMenuItem->Text = L"Data rate";
			this->DataRatetoolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::DataRatetoolStripMenuItem_Click);
			// 
			// toolStripSplitButton2
			// 
			this->toolStripSplitButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripSplitButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->Save_toolStripMenuItem});
			this->toolStripSplitButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripSplitButton2.Image")));
			this->toolStripSplitButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton2->Name = L"toolStripSplitButton2";
			this->toolStripSplitButton2->Size = System::Drawing::Size(51, 22);
			this->toolStripSplitButton2->Text = L"Save";
			// 
			// Save_toolStripMenuItem
			// 
			this->Save_toolStripMenuItem->Name = L"Save_toolStripMenuItem";
			this->Save_toolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->Save_toolStripMenuItem->Text = L"Save as";
			this->Save_toolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Save_toolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(439, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 27);
			this->label1->TabIndex = 10;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 572);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->scan_button);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->Set_Button);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
			 this->set_interface();
				 
			 this->dataGridView1->Enabled = false;
			 ResizeDatagrid(0, true);
			 if ( System::Environment::OSVersion->Version->Major <= 5 )
			 {	 
				 this->label1->Text = "Only Supported Vista\n and above";
				 
				 this->label1->ForeColor = Color::FromArgb(229,20,0);
				 this->Save_toolStripMenuItem->Enabled = false;
			 }

				 
			
		 }
private: System::Void Set_Button_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->scan_button->Enabled = false;
			 this->stop_button->Enabled = false;
			 this->Set_Button->Enabled = false;
			 this->comboBox1->Enabled = false;
			 
			 if (!this->ScanSSID()) {
				 this->Set_Button->Enabled = true;
				 this->comboBox1->Enabled = true;
				 return;
			 }
			 this->comboBox1->Enabled = true;
			 this->scan_button->Enabled = true;
			 this->Set_Button->Enabled = true;
		 }
private: System::Void scan_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Set_Button->Enabled = false;
			 this->comboBox1->Enabled = false;
			 this->scan_button->Enabled = false;
			 this->stop_button->Enabled = true;
			 this->timer1->Start();
		 }
private: System::Void stop_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->timer1->Stop();
			 this->Set_Button->Enabled = true;
			 this->stop_button->Enabled = false;
			 this->comboBox1->Enabled = true;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(this->AUTO_SCAN())
			 {
				this->Chart_Refresh();
				this->DataGridView_Refresh();
			 }
		 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 this->timer1->Stop();
		 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if ((bool)this->dataGridView1->Rows[this->dataGridView1->CurrentCell->RowIndex]->Cells[CheckCell]->Value == true)
				 this->dataGridView1->Rows[this->dataGridView1->CurrentCell->RowIndex]->Cells[CheckCell]->Value = false;
			 else 
				 this->dataGridView1->Rows[this->dataGridView1->CurrentCell->RowIndex]->Cells[CheckCell]->Value = true;
		 }
private: System::Void signalStrenghToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->signalStrenghToolStripMenuItem->Checked)
			 {
				this->dataGridView1->Columns[SSCell]->Visible = false;
				this->signalStrenghToolStripMenuItem->Checked = false;
				ResizeDatagrid(this->dataGridView1->Columns[SSCell]->Width, false);
			 }
			 else
			 {
				 this->dataGridView1->Columns[SSCell]->Visible = true;
				 this->signalStrenghToolStripMenuItem->Checked = true;
				 ResizeDatagrid( -this->dataGridView1->Columns[SSCell]->Width, false);
			 }

		 }
private: System::Void RSSItoolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->RSSItoolStripMenuItem->Checked)
			 {
				this->dataGridView1->Columns[RSSICell]->Visible = false;
				this->RSSItoolStripMenuItem->Checked = false;
				ResizeDatagrid(this->dataGridView1->Columns[RSSICell]->Width, false);
			 }
			 else
			 {
				 this->dataGridView1->Columns[RSSICell]->Visible = true;
				 this->RSSItoolStripMenuItem->Checked = true;
				 ResizeDatagrid( -this->dataGridView1->Columns[RSSICell]->Width, false);
			 }
		 }

private: System::Void ChanneltoolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->ChanneltoolStripMenuItem->Checked)
			 {
				this->dataGridView1->Columns[ChannelCell]->Visible = false;
				this->ChanneltoolStripMenuItem->Checked = false;
				ResizeDatagrid(this->dataGridView1->Columns[ChannelCell]->Width, false);
			 }
			 else
			 {
				 this->dataGridView1->Columns[ChannelCell]->Visible = true;
				 this->ChanneltoolStripMenuItem->Checked = true;
				 ResizeDatagrid( -this->dataGridView1->Columns[ChannelCell]->Width, false);
			 }
		 }

private: System::Void AuthStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->AuthStripMenuItem->Checked)
			 {
				this->dataGridView1->Columns[AuthCell]->Visible = false;
				this->AuthStripMenuItem->Checked = false;
				ResizeDatagrid(this->dataGridView1->Columns[AuthCell]->Width, false);
			 }
			 else
			 {
				 this->dataGridView1->Columns[AuthCell]->Visible = true;
				 this->AuthStripMenuItem->Checked = true;
				 ResizeDatagrid( -this->dataGridView1->Columns[AuthCell]->Width, false);
			 }
		 }

private: System::Void DataRatetoolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->DataRatetoolStripMenuItem->Checked)
			 {
				this->dataGridView1->Columns[DataRateCell]->Visible = false;
				this->DataRatetoolStripMenuItem->Checked = false;
				ResizeDatagrid(this->dataGridView1->Columns[DataRateCell]->Width, false);
			 }
			 else
			 {
				 this->dataGridView1->Columns[DataRateCell]->Visible = true;
				 this->DataRatetoolStripMenuItem->Checked = true;
				 ResizeDatagrid( -this->dataGridView1->Columns[DataRateCell]->Width, false);
			 }
		 }

private: System::Void Save_toolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->saveFileDialog1->Filter = "TXT file|*.txt";
			 this->saveFileDialog1->Title = "Save TXT File";
			 this->saveFileDialog1->ShowDialog();
			 if(this->saveFileDialog1->FileName != "")
			 {
				 this->label1->Text = "Save File..";
				 this->label1->ForeColor = Color::FromArgb(229,20,0);
				 SaveDatatoFile(this->saveFileDialog1->FileName);
				 this->label1->Text = "File Saved!!";
				 this->label1->ForeColor = Color::FromArgb(96,169,23);
			 }
				
		 }


};

}

