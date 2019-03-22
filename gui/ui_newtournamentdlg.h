/********************************************************************************
** Form generated from reading UI file 'newtournamentdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTOURNAMENTDLG_H
#define UI_NEWTOURNAMENTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "src/gamesettingswidget.h"
#include "src/tournamentsettingswidget.h"

QT_BEGIN_NAMESPACE

class Ui_NewTournamentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *m_nameEdit;
    QLabel *label_4;
    QLineEdit *m_siteEdit;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *m_pgnoutEdit;
    QPushButton *m_browsePgnoutBtn;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_epdoutEdit;
    QPushButton *m_browseEpdoutBtn;
    TournamentSettingsWidget *m_tournamentSettings;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    GameSettingsWidget *m_gameSettings;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QListView *m_playersList;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QToolButton *m_moveEngineUpBtn;
    QToolButton *m_moveEngineDownBtn;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *m_addEngineBtn;
    QToolButton *m_removeEngineBtn;
    QToolButton *m_configureEngineBtn;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewTournamentDialog)
    {
        if (NewTournamentDialog->objectName().isEmpty())
            NewTournamentDialog->setObjectName(QString::fromUtf8("NewTournamentDialog"));
        NewTournamentDialog->resize(572, 203);
        verticalLayout = new QVBoxLayout(NewTournamentDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_3 = new QGroupBox(NewTournamentDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_2 = new QFormLayout(groupBox_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        m_nameEdit = new QLineEdit(groupBox_3);
        m_nameEdit->setObjectName(QString::fromUtf8("m_nameEdit"));
        m_nameEdit->setMaxLength(127);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, m_nameEdit);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        m_siteEdit = new QLineEdit(groupBox_3);
        m_siteEdit->setObjectName(QString::fromUtf8("m_siteEdit"));
        m_siteEdit->setMaxLength(127);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_siteEdit);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_pgnoutEdit = new QLineEdit(groupBox_3);
        m_pgnoutEdit->setObjectName(QString::fromUtf8("m_pgnoutEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pgnoutEdit->sizePolicy().hasHeightForWidth());
        m_pgnoutEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(m_pgnoutEdit);

        m_browsePgnoutBtn = new QPushButton(groupBox_3);
        m_browsePgnoutBtn->setObjectName(QString::fromUtf8("m_browsePgnoutBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_browsePgnoutBtn->sizePolicy().hasHeightForWidth());
        m_browsePgnoutBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(m_browsePgnoutBtn);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        m_epdoutEdit = new QLineEdit(groupBox_3);
        m_epdoutEdit->setObjectName(QString::fromUtf8("m_epdoutEdit"));

        horizontalLayout->addWidget(m_epdoutEdit);

        m_browseEpdoutBtn = new QPushButton(groupBox_3);
        m_browseEpdoutBtn->setObjectName(QString::fromUtf8("m_browseEpdoutBtn"));

        horizontalLayout->addWidget(m_browseEpdoutBtn);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout_5->addWidget(groupBox_3);

        m_tournamentSettings = new TournamentSettingsWidget(NewTournamentDialog);
        m_tournamentSettings->setObjectName(QString::fromUtf8("m_tournamentSettings"));

        verticalLayout_5->addWidget(m_tournamentSettings);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_7->addLayout(verticalLayout_5);

        groupBox_6 = new QGroupBox(NewTournamentDialog);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        m_gameSettings = new GameSettingsWidget(groupBox_6);
        m_gameSettings->setObjectName(QString::fromUtf8("m_gameSettings"));

        verticalLayout_6->addWidget(m_gameSettings);


        horizontalLayout_7->addWidget(groupBox_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(NewTournamentDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_playersList = new QListView(groupBox);
        m_playersList->setObjectName(QString::fromUtf8("m_playersList"));
        m_playersList->setMinimumSize(QSize(140, 0));
        m_playersList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_playersList->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_4->addWidget(m_playersList);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        m_moveEngineUpBtn = new QToolButton(groupBox);
        m_moveEngineUpBtn->setObjectName(QString::fromUtf8("m_moveEngineUpBtn"));
        m_moveEngineUpBtn->setEnabled(false);
        m_moveEngineUpBtn->setArrowType(Qt::UpArrow);

        verticalLayout_3->addWidget(m_moveEngineUpBtn);

        m_moveEngineDownBtn = new QToolButton(groupBox);
        m_moveEngineDownBtn->setObjectName(QString::fromUtf8("m_moveEngineDownBtn"));
        m_moveEngineDownBtn->setEnabled(false);
        m_moveEngineDownBtn->setArrowType(Qt::DownArrow);

        verticalLayout_3->addWidget(m_moveEngineDownBtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_addEngineBtn = new QToolButton(groupBox);
        m_addEngineBtn->setObjectName(QString::fromUtf8("m_addEngineBtn"));
        m_addEngineBtn->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_addEngineBtn->sizePolicy().hasHeightForWidth());
        m_addEngineBtn->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/toolbutton/add_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_addEngineBtn->setIcon(icon);

        horizontalLayout_3->addWidget(m_addEngineBtn);

        m_removeEngineBtn = new QToolButton(groupBox);
        m_removeEngineBtn->setObjectName(QString::fromUtf8("m_removeEngineBtn"));
        m_removeEngineBtn->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/toolbutton/remove_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_removeEngineBtn->setIcon(icon1);
        m_removeEngineBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_3->addWidget(m_removeEngineBtn);

        m_configureEngineBtn = new QToolButton(groupBox);
        m_configureEngineBtn->setObjectName(QString::fromUtf8("m_configureEngineBtn"));
        m_configureEngineBtn->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/toolbutton/configure_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_configureEngineBtn->setIcon(icon2);

        horizontalLayout_3->addWidget(m_configureEngineBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(groupBox);


        horizontalLayout_7->addLayout(verticalLayout_4);

        horizontalLayout_7->setStretch(0, 3);
        horizontalLayout_7->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_7);

        buttonBox = new QDialogButtonBox(NewTournamentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(m_nameEdit);
        label_4->setBuddy(m_siteEdit);
        label_5->setBuddy(m_pgnoutEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(NewTournamentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewTournamentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewTournamentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewTournamentDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTournamentDialog)
    {
        NewTournamentDialog->setWindowTitle(QApplication::translate("NewTournamentDialog", "New Tournament", nullptr));
        groupBox_3->setTitle(QApplication::translate("NewTournamentDialog", "General information", nullptr));
        label_3->setText(QApplication::translate("NewTournamentDialog", "Event:", nullptr));
        m_nameEdit->setText(QApplication::translate("NewTournamentDialog", "My Tournament", nullptr));
        label_4->setText(QApplication::translate("NewTournamentDialog", "Site:", nullptr));
        label_5->setText(QApplication::translate("NewTournamentDialog", "PGN output:", nullptr));
        m_pgnoutEdit->setText(QString());
        m_browsePgnoutBtn->setText(QApplication::translate("NewTournamentDialog", "Browse...", nullptr));
        label->setText(QApplication::translate("NewTournamentDialog", "EPD output:", nullptr));
        m_browseEpdoutBtn->setText(QApplication::translate("NewTournamentDialog", "Browse...", nullptr));
        groupBox_6->setTitle(QApplication::translate("NewTournamentDialog", "Games", nullptr));
        groupBox->setTitle(QApplication::translate("NewTournamentDialog", "Players", nullptr));
        m_moveEngineUpBtn->setText(QString());
        m_moveEngineDownBtn->setText(QString());
        m_addEngineBtn->setText(QApplication::translate("NewTournamentDialog", "Add", nullptr));
        m_removeEngineBtn->setText(QApplication::translate("NewTournamentDialog", "Remove", nullptr));
        m_configureEngineBtn->setText(QApplication::translate("NewTournamentDialog", "Configure...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTournamentDialog: public Ui_NewTournamentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTOURNAMENTDLG_H
