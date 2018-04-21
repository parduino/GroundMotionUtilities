#include "IntensityMeasureWidget.h"

IntensityMeasureWidget::IntensityMeasureWidget(IntensityMeasure &im, QWidget *parent): QWidget(parent), m_intensityMeasure(im)
{
    QGridLayout* layout = new QGridLayout();
    QGroupBox* gmpeGroupBox = new QGroupBox(this);
    gmpeGroupBox->setTitle("Ground Motion Prediction Equation");
    gmpeGroupBox->setStyleSheet("QGroupBox { font-weight: bold; }");

    QFormLayout* formLayout = new QFormLayout();
    m_typeBox = new QComboBox(this);

    formLayout->addRow(tr("Type:"), this->m_typeBox);
    gmpeGroupBox->setLayout(formLayout);

    layout->addWidget(gmpeGroupBox);
    this->setLayout(layout);

    const QStringList validType = this->m_intensityMeasure.validTypes();

    QStringListModel* typeModel = new QStringListModel(validType);
    m_typeBox->setModel(typeModel);
    this->setupConnections();
}

void IntensityMeasureWidget::setupConnections()
{
    connect(this->m_typeBox, &QComboBox::currentTextChanged,
            &this->m_intensityMeasure, &IntensityMeasure::setType);

    connect(&this->m_intensityMeasure, &IntensityMeasure::typeChanged,
            this->m_typeBox, &QComboBox::setCurrentText);
}
