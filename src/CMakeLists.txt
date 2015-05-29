rock_library(controller_tuning_widgets
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(controller_tuning_widgets_bin Main.cpp
    DEPS controller_tuning_widgets)

