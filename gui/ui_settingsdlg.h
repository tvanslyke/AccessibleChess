/********************************************************************************
** Form generated from reading UI file 'settingsdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDLG_H
#define UI_SETTINGSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/enginemanagementwidget.h"
#include "src/gamesettingswidget.h"
#include "src/tournamentsettingswidget.h"

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *m_generalTab;
    QFormLayout *formLayout;
    QCheckBox *m_highlightLegalMovesCheck;
    QCheckBox *m_closeUnusedInitialTabCheck;
    QCheckBox *m_useFullUserNameCheck;
    QCheckBox *m_playersSidesOnClocksCheck;
    QCheckBox *m_humanCanPlayAfterTimeoutCheck;
    QLabel *m_siteLabel;
    QLineEdit *m_siteEdit;
    QLabel *m_defaultPgnOutFileLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *m_defaultPgnOutFileEdit;
    QPushButton *m_defaultPgnOutFileBtn;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_tbPathEdit;
    QPushButton *m_browseTbPathBtn;
    QLabel *m_tbPathLabel;
    QWidget *m_enginesTab;
    QVBoxLayout *verticalLayout;
    EngineManagementWidget *m_engineManagementWidget;
    QWidget *m_gamesTab;
    QVBoxLayout *verticalLayout_3;
    GameSettingsWidget *m_gameSettings;
    QWidget *m_tournamentsTab;
    QVBoxLayout *verticalLayout_4;
    TournamentSettingsWidget *m_tournamentSettings;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_2;
    QLabel *m_concurrencyLabel;
    QSpinBox *m_concurrencySpin;
    QLabel *m_tournamentDefaultPgnOutFileLabel;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *m_tournamentDefaultPgnOutFileEdit;
    QPushButton *m_tournamentDefaultPgnOutFileBtn;
    QLabel *m_tournamentDefaultEpdOutFileLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *m_tournamentDefaultEpdOutFileEdit;
    QPushButton *m_tournamentDefaultEpdOutFileBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(527, 395);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(90);
        sizePolicy.setHeightForWidth(SettingsDialog->sizePolicy().hasHeightForWidth());
        SettingsDialog->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(SettingsDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(SettingsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        m_generalTab = new QWidget();
        m_generalTab->setObjectName(QString::fromUtf8("m_generalTab"));
        formLayout = new QFormLayout(m_generalTab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        m_highlightLegalMovesCheck = new QCheckBox(m_generalTab);
        m_highlightLegalMovesCheck->setObjectName(QString::fromUtf8("m_highlightLegalMovesCheck"));
        m_highlightLegalMovesCheck->setChecked(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, m_highlightLegalMovesCheck);

        m_closeUnusedInitialTabCheck = new QCheckBox(m_generalTab);
        m_closeUnusedInitialTabCheck->setObjectName(QString::fromUtf8("m_closeUnusedInitialTabCheck"));
        m_closeUnusedInitialTabCheck->setChecked(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, m_closeUnusedInitialTabCheck);

        m_useFullUserNameCheck = new QCheckBox(m_generalTab);
        m_useFullUserNameCheck->setObjectName(QString::fromUtf8("m_useFullUserNameCheck"));
        m_useFullUserNameCheck->setChecked(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, m_useFullUserNameCheck);

        m_playersSidesOnClocksCheck = new QCheckBox(m_generalTab);
        m_playersSidesOnClocksCheck->setObjectName(QString::fromUtf8("m_playersSidesOnClocksCheck"));

        formLayout->setWidget(4, QFormLayout::FieldRole, m_playersSidesOnClocksCheck);

        m_humanCanPlayAfterTimeoutCheck = new QCheckBox(m_generalTab);
        m_humanCanPlayAfterTimeoutCheck->setObjectName(QString::fromUtf8("m_humanCanPlayAfterTimeoutCheck"));
        m_humanCanPlayAfterTimeoutCheck->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, m_humanCanPlayAfterTimeoutCheck);

        m_siteLabel = new QLabel(m_generalTab);
        m_siteLabel->setObjectName(QString::fromUtf8("m_siteLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, m_siteLabel);

        m_siteEdit = new QLineEdit(m_generalTab);
        m_siteEdit->setObjectName(QString::fromUtf8("m_siteEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, m_siteEdit);

        m_defaultPgnOutFileLabel = new QLabel(m_generalTab);
        m_defaultPgnOutFileLabel->setObjectName(QString::fromUtf8("m_defaultPgnOutFileLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, m_defaultPgnOutFileLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_defaultPgnOutFileEdit = new QLineEdit(m_generalTab);
        m_defaultPgnOutFileEdit->setObjectName(QString::fromUtf8("m_defaultPgnOutFileEdit"));

        horizontalLayout_2->addWidget(m_defaultPgnOutFileEdit);

        m_defaultPgnOutFileBtn = new QPushButton(m_generalTab);
        m_defaultPgnOutFileBtn->setObjectName(QString::fromUtf8("m_defaultPgnOutFileBtn"));

        horizontalLayout_2->addWidget(m_defaultPgnOutFileBtn);


        formLayout->setLayout(10, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_tbPathEdit = new QLineEdit(m_generalTab);
        m_tbPathEdit->setObjectName(QString::fromUtf8("m_tbPathEdit"));

        horizontalLayout->addWidget(m_tbPathEdit);

        m_browseTbPathBtn = new QPushButton(m_generalTab);
        m_browseTbPathBtn->setObjectName(QString::fromUtf8("m_browseTbPathBtn"));

        horizontalLayout->addWidget(m_browseTbPathBtn);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout);

        m_tbPathLabel = new QLabel(m_generalTab);
        m_tbPathLabel->setObjectName(QString::fromUtf8("m_tbPathLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, m_tbPathLabel);

        tabWidget->addTab(m_generalTab, QString());
        m_enginesTab = new QWidget();
        m_enginesTab->setObjectName(QString::fromUtf8("m_enginesTab"));
        verticalLayout = new QVBoxLayout(m_enginesTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        m_engineManagementWidget = new EngineManagementWidget(m_enginesTab);
        m_engineManagementWidget->setObjectName(QString::fromUtf8("m_engineManagementWidget"));

        verticalLayout->addWidget(m_engineManagementWidget);

        tabWidget->addTab(m_enginesTab, QString());
        m_gamesTab = new QWidget();
        m_gamesTab->setObjectName(QString::fromUtf8("m_gamesTab"));
        verticalLayout_3 = new QVBoxLayout(m_gamesTab);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        m_gameSettings = new GameSettingsWidget(m_gamesTab);
        m_gameSettings->setObjectName(QString::fromUtf8("m_gameSettings"));

        verticalLayout_3->addWidget(m_gameSettings);

        tabWidget->addTab(m_gamesTab, QString());
        m_tournamentsTab = new QWidget();
        m_tournamentsTab->setObjectName(QString::fromUtf8("m_tournamentsTab"));
        verticalLayout_4 = new QVBoxLayout(m_tournamentsTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_tournamentSettings = new TournamentSettingsWidget(m_tournamentsTab);
        m_tournamentSettings->setObjectName(QString::fromUtf8("m_tournamentSettings"));

        verticalLayout_4->addWidget(m_tournamentSettings);

        groupBox = new QGroupBox(m_tournamentsTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        m_concurrencyLabel = new QLabel(groupBox);
        m_concurrencyLabel->setObjectName(QString::fromUtf8("m_concurrencyLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, m_concurrencyLabel);

        m_concurrencySpin = new QSpinBox(groupBox);
        m_concurrencySpin->setObjectName(QString::fromUtf8("m_concurrencySpin"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_concurrencySpin->sizePolicy().hasHeightForWidth());
        m_concurrencySpin->setSizePolicy(sizePolicy2);
        m_concurrencySpin->setMinimum(1);
        m_concurrencySpin->setMaximum(128);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_concurrencySpin);

        m_tournamentDefaultPgnOutFileLabel = new QLabel(groupBox);
        m_tournamentDefaultPgnOutFileLabel->setObjectName(QString::fromUtf8("m_tournamentDefaultPgnOutFileLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, m_tournamentDefaultPgnOutFileLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_tournamentDefaultPgnOutFileEdit = new QLineEdit(groupBox);
        m_tournamentDefaultPgnOutFileEdit->setObjectName(QString::fromUtf8("m_tournamentDefaultPgnOutFileEdit"));

        horizontalLayout_5->addWidget(m_tournamentDefaultPgnOutFileEdit);

        m_tournamentDefaultPgnOutFileBtn = new QPushButton(groupBox);
        m_tournamentDefaultPgnOutFileBtn->setObjectName(QString::fromUtf8("m_tournamentDefaultPgnOutFileBtn"));

        horizontalLayout_5->addWidget(m_tournamentDefaultPgnOutFileBtn);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        m_tournamentDefaultEpdOutFileLabel = new QLabel(groupBox);
        m_tournamentDefaultEpdOutFileLabel->setObjectName(QString::fromUtf8("m_tournamentDefaultEpdOutFileLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, m_tournamentDefaultEpdOutFileLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_tournamentDefaultEpdOutFileEdit = new QLineEdit(groupBox);
        m_tournamentDefaultEpdOutFileEdit->setObjectName(QString::fromUtf8("m_tournamentDefaultEpdOutFileEdit"));

        horizontalLayout_3->addWidget(m_tournamentDefaultEpdOutFileEdit);

        m_tournamentDefaultEpdOutFileBtn = new QPushButton(groupBox);
        m_tournamentDefaultEpdOutFileBtn->setObjectName(QString::fromUtf8("m_tournamentDefaultEpdOutFileBtn"));

        horizontalLayout_3->addWidget(m_tournamentDefaultEpdOutFileBtn);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout_5->addLayout(formLayout_2);


        verticalLayout_4->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        tabWidget->addTab(m_tournamentsTab, QString());

        verticalLayout_2->addWidget(tabWidget);

#ifndef QT_NO_SHORTCUT
        m_siteLabel->setBuddy(m_siteEdit);
        m_tbPathLabel->setBuddy(m_tbPathEdit);
        m_concurrencyLabel->setBuddy(m_concurrencySpin);
#endif // QT_NO_SHORTCUT

        retranslateUi(SettingsDialog);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", nullptr));
        m_highlightLegalMovesCheck->setText(QApplication::translate("SettingsDialog", "Highlight legal moves", nullptr));
        m_closeUnusedInitialTabCheck->setText(QApplication::translate("SettingsDialog", "Close initial game tab if unused", nullptr));
        m_useFullUserNameCheck->setText(QApplication::translate("SettingsDialog", "Use full name of human player", nullptr));
        m_playersSidesOnClocksCheck->setText(QApplication::translate("SettingsDialog", "Display players' sides on clocks ", nullptr));
        m_humanCanPlayAfterTimeoutCheck->setText(QApplication::translate("SettingsDialog", "Human player can play after timeout", nullptr));
        m_siteLabel->setText(QApplication::translate("SettingsDialog", "PGN Site:", nullptr));
        m_defaultPgnOutFileLabel->setText(QApplication::translate("SettingsDialog", "PGN output for single games:", nullptr));
        m_defaultPgnOutFileEdit->setText(QApplication::translate("SettingsDialog", "games.pgn", nullptr));
        m_defaultPgnOutFileBtn->setText(QApplication::translate("SettingsDialog", "Browse...", nullptr));
#ifndef QT_NO_SHORTCUT
        m_defaultPgnOutFileBtn->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        m_browseTbPathBtn->setText(QApplication::translate("SettingsDialog", "Browse...", nullptr));
        m_tbPathLabel->setText(QApplication::translate("SettingsDialog", "Syzygy tablebases path:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(m_generalTab), QApplication::translate("SettingsDialog", "General", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(m_enginesTab), QApplication::translate("SettingsDialog", "Engines", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(m_gamesTab), QApplication::translate("SettingsDialog", "Games", nullptr));
        groupBox->setTitle(QApplication::translate("SettingsDialog", "Games", nullptr));
        m_concurrencyLabel->setText(QApplication::translate("SettingsDialog", "Concurrent games:", nullptr));
        m_tournamentDefaultPgnOutFileLabel->setText(QApplication::translate("SettingsDialog", "PGN output:", nullptr));
        m_tournamentDefaultPgnOutFileEdit->setText(QApplication::translate("SettingsDialog", "tournaments.pgn", nullptr));
        m_tournamentDefaultPgnOutFileBtn->setText(QApplication::translate("SettingsDialog", "Browse...", nullptr));
        m_tournamentDefaultEpdOutFileLabel->setText(QApplication::translate("SettingsDialog", "EPD output:", nullptr));
        m_tournamentDefaultEpdOutFileEdit->setText(QApplication::translate("SettingsDialog", "tournaments.epd", nullptr));
        m_tournamentDefaultEpdOutFileBtn->setText(QApplication::translate("SettingsDialog", "Browse...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(m_tournamentsTab), QApplication::translate("SettingsDialog", "Tournaments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDLG_H
