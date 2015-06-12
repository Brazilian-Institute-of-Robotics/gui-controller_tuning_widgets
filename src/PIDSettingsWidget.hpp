#ifndef CONTROLLER_TUNING_WIDGETS_PIDSETTINGSWIDGET_HPP
#define CONTROLLER_TUNING_WIDGETS_PIDSETTINGSWIDGET_HPP

#include <QWidget>
#include <motor_controller/PID.hpp>

namespace Ui {
    class PIDSettingsWidget;
}

namespace controller_tuning_widgets {
    using motor_controller::PIDSettings;

    class PIDSettingsWidget : public QWidget
    {
        Q_OBJECT

    public:
        PIDSettingsWidget(QWidget* parent = NULL);
        ~PIDSettingsWidget();

    public slots:
        void set(motor_controller::PIDSettings const& settings);

        // Note: it is important to keep the motor_controller:: here as
        // otherwise it does not end up in the Qt metadata and it breaks dynamic
        // slot calls
        motor_controller::PIDSettings get() const;

    signals:
        void updated();

    private slots: 
        void applyClicked();

    private:
        PIDSettings readFromWidgets() const;

        Ui::PIDSettingsWidget* ui;
        PIDSettings current;
    };
}

#endif

