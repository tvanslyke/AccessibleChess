/********************************************************************************
** Form generated from reading UI file 'timecontroldlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMECONTROLDLG_H
#define UI_TIMECONTROLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeControlDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *m_tournamentRadio;
    QRadioButton *m_timePerMoveRadio;
    QRadioButton *m_infiniteRadio;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *m_movesSpin;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *m_timeSpin;
    QComboBox *m_timeUnitCombo;
    QLabel *label_3;
    QDoubleSpinBox *m_incrementSpin;
    QSpinBox *m_pliesSpin;
    QLabel *label_5;
    QSpinBox *m_nodesSpin;
    QLabel *label_4;
    QSpinBox *m_marginSpin;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TimeControlDialog)
    {
        if (TimeControlDialog->objectName().isEmpty())
            TimeControlDialog->setObjectName(QString::fromUtf8("TimeControlDialog"));
        TimeControlDialog->resize(284, 367);
        verticalLayout_2 = new QVBoxLayout(TimeControlDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(TimeControlDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_tournamentRadio = new QRadioButton(groupBox);
        m_tournamentRadio->setObjectName(QString::fromUtf8("m_tournamentRadio"));
        m_tournamentRadio->setChecked(true);

        verticalLayout_3->addWidget(m_tournamentRadio);

        m_timePerMoveRadio = new QRadioButton(groupBox);
        m_timePerMoveRadio->setObjectName(QString::fromUtf8("m_timePerMoveRadio"));

        verticalLayout_3->addWidget(m_timePerMoveRadio);

        m_infiniteRadio = new QRadioButton(groupBox);
        m_infiniteRadio->setObjectName(QString::fromUtf8("m_infiniteRadio"));

        verticalLayout_3->addWidget(m_infiniteRadio);


        verticalLayout_2->addWidget(groupBox);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(TimeControlDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        m_movesSpin = new QSpinBox(TimeControlDialog);
        m_movesSpin->setObjectName(QString::fromUtf8("m_movesSpin"));
        m_movesSpin->setMaximum(9999);
        m_movesSpin->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, m_movesSpin);

        label_2 = new QLabel(TimeControlDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_timeSpin = new QDoubleSpinBox(TimeControlDialog);
        m_timeSpin->setObjectName(QString::fromUtf8("m_timeSpin"));
        m_timeSpin->setDecimals(2);
        m_timeSpin->setMinimum(0.010000000000000);
        m_timeSpin->setMaximum(10000.000000000000000);
        m_timeSpin->setValue(0.010000000000000);

        horizontalLayout->addWidget(m_timeSpin);

        m_timeUnitCombo = new QComboBox(TimeControlDialog);
        m_timeUnitCombo->addItem(QString());
        m_timeUnitCombo->addItem(QString());
        m_timeUnitCombo->addItem(QString());
        m_timeUnitCombo->setObjectName(QString::fromUtf8("m_timeUnitCombo"));

        horizontalLayout->addWidget(m_timeUnitCombo);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        label_3 = new QLabel(TimeControlDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        m_incrementSpin = new QDoubleSpinBox(TimeControlDialog);
        m_incrementSpin->setObjectName(QString::fromUtf8("m_incrementSpin"));

        formLayout->setWidget(2, QFormLayout::FieldRole, m_incrementSpin);

        m_pliesSpin = new QSpinBox(TimeControlDialog);
        m_pliesSpin->setObjectName(QString::fromUtf8("m_pliesSpin"));
        m_pliesSpin->setMaximum(999);

        formLayout->setWidget(4, QFormLayout::FieldRole, m_pliesSpin);

        label_5 = new QLabel(TimeControlDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        m_nodesSpin = new QSpinBox(TimeControlDialog);
        m_nodesSpin->setObjectName(QString::fromUtf8("m_nodesSpin"));
        m_nodesSpin->setMaximum(2147483647);

        formLayout->setWidget(3, QFormLayout::FieldRole, m_nodesSpin);

        label_4 = new QLabel(TimeControlDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        m_marginSpin = new QSpinBox(TimeControlDialog);
        m_marginSpin->setObjectName(QString::fromUtf8("m_marginSpin"));
        m_marginSpin->setMaximum(9999);

        formLayout->setWidget(5, QFormLayout::FieldRole, m_marginSpin);

        label_6 = new QLabel(TimeControlDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);


        verticalLayout_2->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(TimeControlDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(m_movesSpin);
        label_2->setBuddy(m_timeSpin);
        label_3->setBuddy(m_incrementSpin);
        label_5->setBuddy(m_pliesSpin);
        label_4->setBuddy(m_nodesSpin);
        label_6->setBuddy(m_marginSpin);
#endif // QT_NO_SHORTCUT

        retranslateUi(TimeControlDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TimeControlDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TimeControlDialog, SLOT(reject()));

        m_timeUnitCombo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TimeControlDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeControlDialog)
    {
        TimeControlDialog->setWindowTitle(QApplication::translate("TimeControlDialog", "Time Controls", nullptr));
        groupBox->setTitle(QApplication::translate("TimeControlDialog", "Mode", nullptr));
#ifndef QT_NO_TOOLTIP
        m_tournamentRadio->setToolTip(QApplication::translate("TimeControlDialog", "Tournament time control", nullptr));
#endif // QT_NO_TOOLTIP
        m_tournamentRadio->setText(QApplication::translate("TimeControlDialog", "Tournament", nullptr));
#ifndef QT_NO_TOOLTIP
        m_timePerMoveRadio->setToolTip(QApplication::translate("TimeControlDialog", "Fixed time limit for each move", nullptr));
#endif // QT_NO_TOOLTIP
        m_timePerMoveRadio->setText(QApplication::translate("TimeControlDialog", "Time per move", nullptr));
#ifndef QT_NO_TOOLTIP
        m_infiniteRadio->setToolTip(QApplication::translate("TimeControlDialog", "Infinite thinking time", nullptr));
#endif // QT_NO_TOOLTIP
        m_infiniteRadio->setText(QApplication::translate("TimeControlDialog", "Infinite", nullptr));
        label->setText(QApplication::translate("TimeControlDialog", "Moves:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_movesSpin->setToolTip(QApplication::translate("TimeControlDialog", "The number of moves in a time control", nullptr));
#endif // QT_NO_TOOLTIP
        m_movesSpin->setSpecialValueText(QApplication::translate("TimeControlDialog", "Whole game", nullptr));
        label_2->setText(QApplication::translate("TimeControlDialog", "Time:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_timeSpin->setToolTip(QApplication::translate("TimeControlDialog", "Time limit for the chosen time control", nullptr));
#endif // QT_NO_TOOLTIP
        m_timeUnitCombo->setItemText(0, QApplication::translate("TimeControlDialog", "Seconds", nullptr));
        m_timeUnitCombo->setItemText(1, QApplication::translate("TimeControlDialog", "Minutes", nullptr));
        m_timeUnitCombo->setItemText(2, QApplication::translate("TimeControlDialog", "Hours", nullptr));

#ifndef QT_NO_TOOLTIP
        m_timeUnitCombo->setToolTip(QApplication::translate("TimeControlDialog", "Time unit for the time limit", nullptr));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("TimeControlDialog", "Increment:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_incrementSpin->setToolTip(QApplication::translate("TimeControlDialog", "Time increment per move in seconds", nullptr));
#endif // QT_NO_TOOLTIP
        m_incrementSpin->setSuffix(QApplication::translate("TimeControlDialog", " sec", nullptr));
#ifndef QT_NO_TOOLTIP
        m_pliesSpin->setToolTip(QApplication::translate("TimeControlDialog", "Maximum search depth in plies (engines only)", nullptr));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("TimeControlDialog", "Plies:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_nodesSpin->setToolTip(QApplication::translate("TimeControlDialog", "Maximum number of nodes to search (engines only)", nullptr));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("TimeControlDialog", "Nodes:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_marginSpin->setToolTip(QApplication::translate("TimeControlDialog", "The time limit can be exceeded by this many milliseconds", nullptr));
#endif // QT_NO_TOOLTIP
        m_marginSpin->setSuffix(QApplication::translate("TimeControlDialog", " ms", nullptr));
        label_6->setText(QApplication::translate("TimeControlDialog", "Margin:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeControlDialog: public Ui_TimeControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMECONTROLDLG_H
