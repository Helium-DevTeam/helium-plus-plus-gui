module;

#include <xtd/xtd.forms>

export module heliumpp.gui.forms.main_form;

export namespace heliumpp
{
	using namespace xtd;
	using namespace xtd::forms;
	using namespace std;

	class helium_main_form_class final : public form {
	public:
		/// @brief Initializes a new instance of the helium_main_form_class class.
		helium_main_form_class()
		{
			this->control::text("Helium++");
			this->control::size({ 800, 600 });

			this->form::start_position(form_start_position::center_screen);
			this->form::menu(this->main_menu_);

			this->list_box_.parent(*this);
			this->list_box_.dock(dock_style::fill);
		}

		/// @brief The main entry point for the application.
		static void main()
		{
			application::run(helium_main_form_class());
		}
	private:
		void on_menu_click(object& sender, const event_args& e) {
			this->list_box_.items().push_back(ustring::format("{} clicked", as<menu_item>(sender).text()));
			this->list_box_.selected_index(this->list_box_.items().size() - 1);
			if (reference_equals(this->file_exit_menu_item_, sender)) application::exit();
		}

		menu_item file_open_recent_file1_menu_item_{ "Path/File1", {*this, &helium_main_form_class::on_menu_click} };
		menu_item file_open_recent_file2_menu_item_{ "Path/File2", {*this, &helium_main_form_class::on_menu_click} };
		menu_item file_open_recent_file3_menu_item_{ "Path/File3", {*this, &helium_main_form_class::on_menu_click} };
		menu_item file_open_recent_file4_menu_item_{ "Path/File4", {*this, &helium_main_form_class::on_menu_click} };

		menu_item file_new_menu_item_{ system_texts::new_(), {*this, &helium_main_form_class::on_menu_click}, menu_images::file_new(), shortcut::cmd_n };
		menu_item file_separator1_menu_item_{ "-" };
		menu_item file_open_menu_item_{ system_texts::open(), {*this, &helium_main_form_class::on_menu_click}, menu_images::file_open(), shortcut::cmd_o };
		menu_item file_open_recent_menu_item_{ "Open recent", {file_open_recent_file1_menu_item_, file_open_recent_file2_menu_item_, file_open_recent_file3_menu_item_, file_open_recent_file4_menu_item_} };
		menu_item file_close_menu_item_{ system_texts::close(), {*this, &helium_main_form_class::on_menu_click}, shortcut::cmd_w };
		menu_item file_separator2_menu_item_{ "-" };
		menu_item file_save_menu_item_{ system_texts::save(), {*this, &helium_main_form_class::on_menu_click}, menu_images::file_save(), shortcut::cmd_s };
		menu_item file_save_as_menu_item_{ system_texts::save_as(), {*this, &helium_main_form_class::on_menu_click} };
		menu_item file_separator3_menu_item_{ "-" };
		menu_item file_page_setup_menu_item_{ "Page &Seup...", {*this, &helium_main_form_class::on_menu_click} };
		menu_item file_print_menu_item_{ system_texts::print(), {*this, &helium_main_form_class::on_menu_click}, menu_images::file_print(), shortcut::cmd_p };
		menu_item file_print_preview_menu_item_{ system_texts::print_preview(), {*this, &helium_main_form_class::on_menu_click}, menu_images::file_print_preview() };
		menu_item file_separator4_menu_item_{ "-" };
		menu_item file_exit_menu_item_{ system_texts::exit(), {*this, &helium_main_form_class::on_menu_click}, menu_images::file_exit(), shortcut::alt_f4 };

		menu_item edit_undo_menu_item_{ system_texts::undo(), {*this, &helium_main_form_class::on_menu_click}, menu_images::edit_undo(), shortcut::cmd_z };
		menu_item edit_redo_menu_item_{ system_texts::redo(), {*this, &helium_main_form_class::on_menu_click}, menu_images::edit_redo(), shortcut::cmd_shift_z };
		menu_item edit_separator1_menu_item_{ "-" };
		menu_item edit_cut_menu_item_{ system_texts::cut(), {*this, &helium_main_form_class::on_menu_click}, menu_images::edit_cut(), shortcut::cmd_x };
		menu_item edit_copy_menu_item_{ system_texts::copy(), {*this, &helium_main_form_class::on_menu_click}, menu_images::edit_copy(), shortcut::cmd_c };
		menu_item edit_paste_menu_item_{ system_texts::paste(), {*this, &helium_main_form_class::on_menu_click}, menu_images::edit_paste(), shortcut::cmd_v };
		menu_item edit_separator2_menu_item_{ "-" };
		menu_item edit_select_all_menu_item_{ system_texts::select_all(), {*this, &helium_main_form_class::on_menu_click}, shortcut::cmd_a };
		menu_item edit_separator3_menu_item_{ "-" };
		menu_item edit_options_menu_item_{ system_texts::options(), {*this, &helium_main_form_class::on_menu_click} };

		menu_item view_back_menu_item_{ system_texts::back(), {*this, &helium_main_form_class::on_menu_click}, menu_images::view_back() };
		menu_item view_forward_menu_item_{ system_texts::forward(), {*this, &helium_main_form_class::on_menu_click}, menu_images::view_forward() };
		menu_item view_separator1_menu_item_{ "-" };
		menu_item view_show_menu_item_{ "Show", {*this, &helium_main_form_class::on_menu_click} };
		menu_item view_hide_menu_item_{ "Hide", {*this, &helium_main_form_class::on_menu_click} };

		menu_item help_about_menu_item_{ system_texts::about(), {*this, &helium_main_form_class::on_menu_click} };

		menu_item file_menu_item_{ system_texts::file(), {file_new_menu_item_, file_separator1_menu_item_, file_open_menu_item_, file_open_recent_menu_item_, file_close_menu_item_, file_separator2_menu_item_, file_save_menu_item_, file_save_as_menu_item_, file_separator3_menu_item_, file_page_setup_menu_item_, file_print_menu_item_, file_print_preview_menu_item_, file_separator4_menu_item_, file_exit_menu_item_} };
		menu_item edit_menu_item_{ system_texts::edit(), {edit_undo_menu_item_, edit_redo_menu_item_, edit_separator1_menu_item_, edit_cut_menu_item_, edit_copy_menu_item_, edit_paste_menu_item_, edit_separator2_menu_item_, edit_select_all_menu_item_, edit_separator3_menu_item_, edit_options_menu_item_} };
		menu_item view_menu_item_{ system_texts::view(), {view_back_menu_item_, view_forward_menu_item_, view_separator1_menu_item_, view_show_menu_item_, view_hide_menu_item_} };
		menu_item help_menu_item_{ system_texts::help(), {help_about_menu_item_} };

		main_menu main_menu_{ file_menu_item_, edit_menu_item_, view_menu_item_, help_menu_item_ };

		list_box list_box_;
	};
}