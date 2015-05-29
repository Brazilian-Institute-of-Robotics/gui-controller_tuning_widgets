#ifndef CONTROLLER_TUNING_WIDGETS_PIDSETTINGSWIDGETPLUGIN_HPP
#define CONTROLLER_TUNING_WIDGETS_PIDSETTINGSWIDGETPLUGIN_HPP

#include <QtGui>
#include <QtDesigner/QDesignerCustomWidgetInterface>

class PIDSettingsWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    PIDSettingsWidgetPlugin(QObject *parent = 0);
    virtual ~PIDSettingsWidgetPlugin();

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget* createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized; 
};

#endif
