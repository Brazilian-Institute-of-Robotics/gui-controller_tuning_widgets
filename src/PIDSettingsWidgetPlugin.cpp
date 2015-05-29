#include "PIDSettingsWidgetPlugin.hpp"
#include "PIDSettingsWidget.hpp"

Q_EXPORT_PLUGIN2(PIDSettingsWidget, PIDSettingsWidgetPlugin)

PIDSettingsWidgetPlugin::PIDSettingsWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

PIDSettingsWidgetPlugin::~PIDSettingsWidgetPlugin()
{
}

bool PIDSettingsWidgetPlugin::isContainer() const
{
    return false;
}

bool PIDSettingsWidgetPlugin::isInitialized() const
{
    return initialized;
}

QIcon PIDSettingsWidgetPlugin::icon() const
{
    return QIcon("");
}

QString PIDSettingsWidgetPlugin::domXml() const
{
        return "<ui language=\"c++\">\n"
            " <widget class=\"controller_tuning_widgets::PIDSettingsWidget\" name=\"pidsettingswidgets\">\n"
            "  <property name=\"geometry\">\n"
            "   <rect>\n"
            "    <x>0</x>\n"
            "    <y>0</y>\n"
            "     <width>300</width>\n"
            "     <height>120</height>\n"
            "   </rect>\n"
            "  </property>\n"
//            "  <property name=\"toolTip\" >\n"
//            "   <string>PIDSettingsWidget</string>\n"
//            "  </property>\n"
//            "  <property name=\"whatsThis\" >\n"
//            "   <string>PIDSettingsWidget</string>\n"
//            "  </property>\n"
            " </widget>\n"
            "</ui>\n";
}

QString PIDSettingsWidgetPlugin::group() const {
    return "Rock-Robotics";
}

QString PIDSettingsWidgetPlugin::includeFile() const {
    return "controller_tuning_widgets/PIDSettingsWidget.hpp";
}

QString PIDSettingsWidgetPlugin::name() const {
    return "controller_tuning_widgets::PIDSettingsWidget";
}

QString PIDSettingsWidgetPlugin::toolTip() const {
    return whatsThis();
}

QString PIDSettingsWidgetPlugin::whatsThis() const
{
    return "";
}

QWidget* PIDSettingsWidgetPlugin::createWidget(QWidget *parent)
{
    return new controller_tuning_widgets::PIDSettingsWidget(parent);
}

void PIDSettingsWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
     if (initialized)
         return;
     initialized = true;
}
