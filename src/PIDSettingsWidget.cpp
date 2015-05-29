#include <controller_tuning_widgets/PIDSettingsWidget.hpp>
#include "ui_PIDSettingsWidget.h"
#include <QMessageBox>

using namespace controller_tuning_widgets;

PIDSettingsWidget::PIDSettingsWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::PIDSettingsWidget)
{
    ui->setupUi(this);
    current = readFromWidgets();
    connect(ui->apply, SIGNAL(clicked()), this, SLOT(applyClicked()));
}

PIDSettingsWidget::~PIDSettingsWidget()
{
    delete ui;
}

void PIDSettingsWidget::set(PIDSettings const& settings)
{
    ui->editTs ->setText(QString::number(settings.Ts));
    ui->editK  ->setText(QString::number(settings.K));
    ui->editTi ->setText(QString::number(settings.Ti));
    ui->editTd ->setText(QString::number(settings.Td));
    ui->editN  ->setText(QString::number(settings.N));
    ui->editB  ->setText(QString::number(settings.B));
    ui->editTt ->setText(QString::number(settings.Tt));
    ui->editMax->setText(QString::number(settings.YMax));
    ui->editMin->setText(QString::number(settings.YMin));
    current = settings;
}

PIDSettings PIDSettingsWidget::get() const
{
    return current;
}

PIDSettings PIDSettingsWidget::readFromWidgets() const
{
    PIDSettings settings;

    bool check;
    settings.Ts  = ui->editTs->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to Ts");
    settings.K   = ui->editK->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to K");
    settings.Ti  = ui->editTi->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to Ti");
    settings.Td  = ui->editTd->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to Td");
    settings.N   = ui->editN->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to N");
    settings.B   = ui->editB->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to B");
    settings.Tt  = ui->editTt->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to Tt");
    settings.YMax = ui->editMax->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to Max");
    settings.YMin = ui->editMin->text().toDouble(&check);
    if (!check) throw std::invalid_argument("non-numeric value given to Min");

    return settings;
}

void PIDSettingsWidget::applyClicked()
{
    try {
        current = readFromWidgets();
    }
    catch(std::invalid_argument const& error) 
    {
        QMessageBox::critical(this, "PID Settings", QString::fromStdString(error.what()));
        return;
    }
    emit updated();
}

