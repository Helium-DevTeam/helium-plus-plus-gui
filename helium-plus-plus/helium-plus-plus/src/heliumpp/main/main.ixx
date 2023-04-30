module;

#include <xtd/xtd.forms>
#include <gsl/gsl>

export module heliumpp.main;

import heliumpp.gui.forms.main_form;
import heliumpp.shared.helium_object;

export namespace heliumpp
{
	class helium_main_class : public helium_object_class {
	public:
		static auto main() -> int
		{
			xtd::forms::application::run(helium_main_form_class());
			return 0;
		}
	};
}