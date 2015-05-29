rock_find_qt4()
rock_vizkit_widget(pid_settings_widget
    HEADERS PIDSettingsWidget.hpp PIDSettingsWidgetPlugin.hpp
    SOURCES PIDSettingsWidget.cpp PIDSettingsWidgetPlugin.cpp
    DEPS_PKGCONFIG motor_controller
    MOC PIDSettingsWidget.hpp PIDSettingsWidgetPlugin.hpp
    UI PIDSettingsWidget.ui)

