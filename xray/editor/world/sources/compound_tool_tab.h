#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "tool_tab.h"

namespace xray {
namespace editor {
	ref class tool_compound;
	/// <summary>
	/// Summary for compound_tool_tab
	/// </summary>
	public ref class compound_tool_tab :	public System::Windows::Forms::UserControl,
											public tool_tab
	{
	public:
		compound_tool_tab(tool_compound^ t):m_tool(t)
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
		~compound_tool_tab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: tool_compound^	m_tool;
	private: System::Windows::Forms::ToolStripMenuItem^  remove_item_menu;
	protected: 
	public: xray::editor::controls::tree_view^  treeView;
	private: 
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	public: 
	private: System::Windows::Forms::ToolStripMenuItem^  new_item_menu;

	private: System::Windows::Forms::ToolStripMenuItem^  properties_item_menu;
	private: System::Windows::Forms::ImageList^  imageList1;


	private: 
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	public: 
	public: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: 
	private: System::ComponentModel::IContainer^  components;
	public: 

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
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L""));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(compound_tool_tab::typeid));
			this->remove_item_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->treeView = (gcnew xray::editor::controls::tree_view());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->new_item_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->properties_item_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->contextMenuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// remove_item_menu
			// 
			this->remove_item_menu->Name = L"remove_item_menu";
			this->remove_item_menu->Size = System::Drawing::Size(127, 22);
			this->remove_item_menu->Text = L"Remove";
			this->remove_item_menu->Click += gcnew System::EventHandler(this, &compound_tool_tab::on_remove);
			// 
			// treeView
			// 
			this->treeView->auto_expand_on_filter = false;
			this->treeView->ContextMenuStrip = this->contextMenuStrip1;
			this->treeView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView->filter_visible = false;
			this->treeView->HideSelection = false;
			this->treeView->ImageIndex = 0;
			this->treeView->ImageList = this->imageList1;
			this->treeView->Indent = 27;
			this->treeView->is_multiselect = false;
			this->treeView->ItemHeight = 20;
			this->treeView->Location = System::Drawing::Point(0, 0);
			this->treeView->Name = L"treeView";
			this->treeView->PathSeparator = L"/";
			treeNode1->Name = L"";
			treeNode1->Text = L"";
			this->treeView->root = treeNode1;
			this->treeView->SelectedImageIndex = 0;
			this->treeView->Size = System::Drawing::Size(230, 372);
			this->treeView->source = nullptr;
			this->treeView->TabIndex = 9;
			this->treeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &compound_tool_tab::on_after_select);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->new_item_menu, 
				this->remove_item_menu, this->properties_item_menu});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(128, 70);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &compound_tool_tab::on_context_menu_opening);
			// 
			// new_item_menu
			// 
			this->new_item_menu->Name = L"new_item_menu";
			this->new_item_menu->Size = System::Drawing::Size(127, 22);
			this->new_item_menu->Text = L"New";
			this->new_item_menu->Click += gcnew System::EventHandler(this, &compound_tool_tab::on_new_library_object);
			// 
			// properties_item_menu
			// 
			this->properties_item_menu->Name = L"properties_item_menu";
			this->properties_item_menu->Size = System::Drawing::Size(127, 22);
			this->properties_item_menu->Text = L"Properties";
			this->properties_item_menu->Click += gcnew System::EventHandler(this, &compound_tool_tab::on_edit_library_object);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"group");
			this->imageList1->Images->SetKeyName(1, L"mesh");
			this->imageList1->Images->SetKeyName(2, L"ambient_light");
			this->imageList1->Images->SetKeyName(3, L"area_light");
			this->imageList1->Images->SetKeyName(4, L"directional_light");
			this->imageList1->Images->SetKeyName(5, L"point_light");
			this->imageList1->Images->SetKeyName(6, L"spot_light");
			this->imageList1->Images->SetKeyName(7, L"volume_light");
			this->imageList1->Images->SetKeyName(8, L"camera");
			this->imageList1->Images->SetKeyName(9, L"curve");
			this->imageList1->Images->SetKeyName(10, L"default_object_set");
			this->imageList1->Images->SetKeyName(11, L"joint");
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 372);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(230, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(34, 17);
			this->toolStripStatusLabel1->Text = L"total:";
			// 
			// compound_tool_tab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->treeView);
			this->Controls->Add(this->statusStrip1);
			this->Name = L"compound_tool_tab";
			this->Size = System::Drawing::Size(230, 394);
			this->contextMenuStrip1->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void on_edit_library_object(System::Object^  sender, System::EventArgs^  e);
	private: System::Void on_new_library_object(System::Object^  sender, System::EventArgs^  e);
	private: System::Void on_remove(System::Object^  sender, System::EventArgs^  e);
	private: System::Void on_context_menu_opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
	private: System::Void on_after_select(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e);
	public:
	virtual System::Windows::Forms::UserControl^	frame () {return this;}

};
}
}
