/********************************************************************************
** Form generated from reading UI file 'newgamedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEDLG_H
#define UI_NEWGAMEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "src/gamesettingswidget.h"

QT_BEGIN_NAMESPACE

class Ui_NewGameDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *m_whitePlayerHumanRadio;
    QRadioButton *m_whitePlayerCpuRadio;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_1;
    QComboBox *m_whiteEngineComboBox;
    QPushButton *m_configureWhiteEngineButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *m_blackPlayerHumanRadio;
    QRadioButton *m_blackPlayerCpuRadio;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *m_blackEngineComboBox;
    QPushButton *m_configureBlackEngineButton;
    GameSettingsWidget *m_gameSettings;
    QDialogButtonBox *m_buttonBox;

    void setupUi(QDialog *NewGameDialog)
    {
        if (NewGameDialog->objectName().isEmpty())
            NewGameDialog->setObjectName(QString::fromUtf8("NewGameDialog"));
        NewGameDialog->resize(510, 242);
        verticalLayout_4 = new QVBoxLayout(NewGameDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(NewGameDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_whitePlayerHumanRadio = new QRadioButton(groupBox_2);
        m_whitePlayerHumanRadio->setObjectName(QString::fromUtf8("m_whitePlayerHumanRadio"));
        m_whitePlayerHumanRadio->setChecked(true);

        verticalLayout_3->addWidget(m_whitePlayerHumanRadio);

        m_whitePlayerCpuRadio = new QRadioButton(groupBox_2);
        m_whitePlayerCpuRadio->setObjectName(QString::fromUtf8("m_whitePlayerCpuRadio"));
        m_whitePlayerCpuRadio->setEnabled(false);

        verticalLayout_3->addWidget(m_whitePlayerCpuRadio);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_1 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_1);

        m_whiteEngineComboBox = new QComboBox(groupBox_2);
        m_whiteEngineComboBox->setObjectName(QString::fromUtf8("m_whiteEngineComboBox"));
        m_whiteEngineComboBox->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_whiteEngineComboBox->sizePolicy().hasHeightForWidth());
        m_whiteEngineComboBox->setSizePolicy(sizePolicy);
        m_whiteEngineComboBox->setEditable(true);

        horizontalLayout_3->addWidget(m_whiteEngineComboBox);

        m_configureWhiteEngineButton = new QPushButton(groupBox_2);
        m_configureWhiteEngineButton->setObjectName(QString::fromUtf8("m_configureWhiteEngineButton"));
        m_configureWhiteEngineButton->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_configureWhiteEngineButton->sizePolicy().hasHeightForWidth());
        m_configureWhiteEngineButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/toolbutton/configure_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_configureWhiteEngineButton->setIcon(icon);

        horizontalLayout_3->addWidget(m_configureWhiteEngineButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(NewGameDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_blackPlayerHumanRadio = new QRadioButton(groupBox);
        m_blackPlayerHumanRadio->setObjectName(QString::fromUtf8("m_blackPlayerHumanRadio"));
        m_blackPlayerHumanRadio->setChecked(true);

        verticalLayout->addWidget(m_blackPlayerHumanRadio);

        m_blackPlayerCpuRadio = new QRadioButton(groupBox);
        m_blackPlayerCpuRadio->setObjectName(QString::fromUtf8("m_blackPlayerCpuRadio"));
        m_blackPlayerCpuRadio->setEnabled(false);

        verticalLayout->addWidget(m_blackPlayerCpuRadio);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_blackEngineComboBox = new QComboBox(groupBox);
        m_blackEngineComboBox->setObjectName(QString::fromUtf8("m_blackEngineComboBox"));
        m_blackEngineComboBox->setEnabled(false);
        sizePolicy.setHeightForWidth(m_blackEngineComboBox->sizePolicy().hasHeightForWidth());
        m_blackEngineComboBox->setSizePolicy(sizePolicy);
        m_blackEngineComboBox->setEditable(true);

        horizontalLayout_2->addWidget(m_blackEngineComboBox);

        m_configureBlackEngineButton = new QPushButton(groupBox);
        m_configureBlackEngineButton->setObjectName(QString::fromUtf8("m_configureBlackEngineButton"));
        m_configureBlackEngineButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(m_configureBlackEngineButton->sizePolicy().hasHeightForWidth());
        m_configureBlackEngineButton->setSizePolicy(sizePolicy1);
        m_configureBlackEngineButton->setIcon(icon);

        horizontalLayout_2->addWidget(m_configureBlackEngineButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout);

        m_gameSettings = new GameSettingsWidget(NewGameDialog);
        m_gameSettings->setObjectName(QString::fromUtf8("m_gameSettings"));

        verticalLayout_4->addWidget(m_gameSettings);

        m_buttonBox = new QDialogButtonBox(NewGameDialog);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(m_buttonBox);


        retranslateUi(NewGameDialog);
        QObject::connect(m_buttonBox, SIGNAL(rejected()), NewGameDialog, SLOT(reject()));
        QObject::connect(m_buttonBox, SIGNAL(accepted()), NewGameDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(NewGameDialog);
    } // setupUi

    void retranslateUi(QDialog *NewGameDialog)
    {
        NewGameDialog->setWindowTitle(QApplication::translate("NewGameDialog", "New Game", nullptr));
        groupBox_2->setTitle(QApplication::translate("NewGameDialog", "White", nullptr));
        m_whitePlayerHumanRadio->setText(QApplication::translate("NewGameDialog", "Human", nullptr));
        m_whitePlayerCpuRadio->setText(QApplication::translate("NewGameDialog", "CPU", nullptr));
#ifndef QT_NO_TOOLTIP
        m_configureWhiteEngineButton->setToolTip(QApplication::translate("NewGameDialog", "Configure white engine", nullptr));
#endif // QT_NO_TOOLTIP
        m_configureWhiteEngineButton->setText(QString());
        groupBox->setTitle(QApplication::translate("NewGameDialog", "Black", nullptr));
        m_blackPlayerHumanRadio->setText(QApplication::translate("NewGameDialog", "Human", nullptr));
        m_blackPlayerCpuRadio->setText(QApplication::translate("NewGameDialog", "CPU", nullptr));
#ifndef QT_NO_TOOLTIP
        m_configureBlackEngineButton->setToolTip(QApplication::translate("NewGameDialog", "Configure black engine", nullptr));
#endif // QT_NO_TOOLTIP
        m_configureBlackEngineButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewGameDialog: public Ui_NewGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEDLG_H
