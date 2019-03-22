/********************************************************************************
** Form generated from reading UI file 'tournamentsettingswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURNAMENTSETTINGSWIDGET_H
#define UI_TOURNAMENTSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TournamentSettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *m_roundRobinRadio;
    QRadioButton *m_gauntletRadio;
    QRadioButton *m_knockoutRadio;
    QRadioButton *m_pyramidRadio;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_2;
    QSpinBox *m_seedsSpin;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *m_gamesPerEncounterSpin;
    QLabel *label_2;
    QSpinBox *m_roundsSpin;
    QLabel *label_3;
    QDoubleSpinBox *m_waitSpin;
    QCheckBox *m_repeatCheck;
    QCheckBox *m_recoverCheck;
    QCheckBox *m_saveUnfinishedGamesCheck;

    void setupUi(QWidget *TournamentSettingsWidget)
    {
        if (TournamentSettingsWidget->objectName().isEmpty())
            TournamentSettingsWidget->setObjectName(QString::fromUtf8("TournamentSettingsWidget"));
        TournamentSettingsWidget->resize(400, 314);
        verticalLayout = new QVBoxLayout(TournamentSettingsWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(TournamentSettingsWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_roundRobinRadio = new QRadioButton(groupBox);
        m_roundRobinRadio->setObjectName(QString::fromUtf8("m_roundRobinRadio"));
        m_roundRobinRadio->setChecked(true);

        horizontalLayout_2->addWidget(m_roundRobinRadio);

        m_gauntletRadio = new QRadioButton(groupBox);
        m_gauntletRadio->setObjectName(QString::fromUtf8("m_gauntletRadio"));

        horizontalLayout_2->addWidget(m_gauntletRadio);

        m_knockoutRadio = new QRadioButton(groupBox);
        m_knockoutRadio->setObjectName(QString::fromUtf8("m_knockoutRadio"));

        horizontalLayout_2->addWidget(m_knockoutRadio);

        m_pyramidRadio = new QRadioButton(groupBox);
        m_pyramidRadio->setObjectName(QString::fromUtf8("m_pyramidRadio"));

        horizontalLayout_2->addWidget(m_pyramidRadio);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        m_seedsSpin = new QSpinBox(groupBox);
        m_seedsSpin->setObjectName(QString::fromUtf8("m_seedsSpin"));
        m_seedsSpin->setEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, m_seedsSpin);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);


        verticalLayout_2->addLayout(formLayout_2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TournamentSettingsWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        m_gamesPerEncounterSpin = new QSpinBox(groupBox_2);
        m_gamesPerEncounterSpin->setObjectName(QString::fromUtf8("m_gamesPerEncounterSpin"));
        m_gamesPerEncounterSpin->setMinimum(1);
        m_gamesPerEncounterSpin->setMaximum(999999);

        formLayout->setWidget(0, QFormLayout::FieldRole, m_gamesPerEncounterSpin);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        m_roundsSpin = new QSpinBox(groupBox_2);
        m_roundsSpin->setObjectName(QString::fromUtf8("m_roundsSpin"));
        m_roundsSpin->setMinimum(1);
        m_roundsSpin->setMaximum(999999);

        formLayout->setWidget(1, QFormLayout::FieldRole, m_roundsSpin);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        m_waitSpin = new QDoubleSpinBox(groupBox_2);
        m_waitSpin->setObjectName(QString::fromUtf8("m_waitSpin"));

        formLayout->setWidget(2, QFormLayout::FieldRole, m_waitSpin);

        m_repeatCheck = new QCheckBox(groupBox_2);
        m_repeatCheck->setObjectName(QString::fromUtf8("m_repeatCheck"));

        formLayout->setWidget(3, QFormLayout::FieldRole, m_repeatCheck);

        m_recoverCheck = new QCheckBox(groupBox_2);
        m_recoverCheck->setObjectName(QString::fromUtf8("m_recoverCheck"));

        formLayout->setWidget(4, QFormLayout::FieldRole, m_recoverCheck);

        m_saveUnfinishedGamesCheck = new QCheckBox(groupBox_2);
        m_saveUnfinishedGamesCheck->setObjectName(QString::fromUtf8("m_saveUnfinishedGamesCheck"));
        m_saveUnfinishedGamesCheck->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, m_saveUnfinishedGamesCheck);


        verticalLayout->addWidget(groupBox_2);

#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(m_seedsSpin);
        label->setBuddy(m_gamesPerEncounterSpin);
        label_2->setBuddy(m_roundsSpin);
        label_3->setBuddy(m_waitSpin);
#endif // QT_NO_SHORTCUT

        retranslateUi(TournamentSettingsWidget);

        QMetaObject::connectSlotsByName(TournamentSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *TournamentSettingsWidget)
    {
        TournamentSettingsWidget->setWindowTitle(QApplication::translate("TournamentSettingsWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("TournamentSettingsWidget", "Tournament type", nullptr));
#ifndef QT_NO_TOOLTIP
        m_roundRobinRadio->setToolTip(QApplication::translate("TournamentSettingsWidget", "Round-robin tournament", nullptr));
#endif // QT_NO_TOOLTIP
        m_roundRobinRadio->setText(QApplication::translate("TournamentSettingsWidget", "Round Robin", nullptr));
#ifndef QT_NO_TOOLTIP
        m_gauntletRadio->setToolTip(QApplication::translate("TournamentSettingsWidget", "First engine plays against the rest", nullptr));
#endif // QT_NO_TOOLTIP
        m_gauntletRadio->setText(QApplication::translate("TournamentSettingsWidget", "Gauntlet", nullptr));
#ifndef QT_NO_TOOLTIP
        m_knockoutRadio->setToolTip(QApplication::translate("TournamentSettingsWidget", "Single-elimination tournament", nullptr));
#endif // QT_NO_TOOLTIP
        m_knockoutRadio->setText(QApplication::translate("TournamentSettingsWidget", "Knockout", nullptr));
#ifndef QT_NO_TOOLTIP
        m_pyramidRadio->setToolTip(QApplication::translate("TournamentSettingsWidget", "Every engine plays against all of its predecessors", nullptr));
#endif // QT_NO_TOOLTIP
        m_pyramidRadio->setText(QApplication::translate("TournamentSettingsWidget", "Pyramid", nullptr));
#ifndef QT_NO_TOOLTIP
        m_seedsSpin->setToolTip(QApplication::translate("TournamentSettingsWidget", "At most this many players from the top of the players list will be seeded in the tournament.", nullptr));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("TournamentSettingsWidget", "Seeds:", nullptr));
        groupBox_2->setTitle(QApplication::translate("TournamentSettingsWidget", "Rounds", nullptr));
        label->setText(QApplication::translate("TournamentSettingsWidget", "Games per encounter:", nullptr));
        label_2->setText(QApplication::translate("TournamentSettingsWidget", "Rounds:", nullptr));
        label_3->setText(QApplication::translate("TournamentSettingsWidget", "Wait between games:", nullptr));
        m_waitSpin->setSuffix(QApplication::translate("TournamentSettingsWidget", " s", nullptr));
        m_repeatCheck->setText(QApplication::translate("TournamentSettingsWidget", "Play each opening twice", nullptr));
#ifndef QT_NO_TOOLTIP
        m_recoverCheck->setToolTip(QApplication::translate("TournamentSettingsWidget", "If enabled, crashed engines are restarted and the tournament is not stopped.", nullptr));
#endif // QT_NO_TOOLTIP
        m_recoverCheck->setText(QApplication::translate("TournamentSettingsWidget", "Recover crashed engines", nullptr));
        m_saveUnfinishedGamesCheck->setText(QApplication::translate("TournamentSettingsWidget", "Save unfinished games", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TournamentSettingsWidget: public Ui_TournamentSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURNAMENTSETTINGSWIDGET_H
