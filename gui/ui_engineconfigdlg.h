/********************************************************************************
** Form generated from reading UI file 'engineconfigdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINECONFIGDLG_H
#define UI_ENGINECONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngineConfigurationDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *m_tabs;
    QWidget *tab;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *m_nameEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_commandEdit;
    QPushButton *m_browseCmdBtn;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *m_workingDirEdit;
    QPushButton *m_browseWorkingDirBtn;
    QLabel *label_3;
    QComboBox *m_protocolCombo;
    QLabel *label_5;
    QPlainTextEdit *m_initStringEdit;
    QCheckBox *m_whitePovCheck;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QTreeView *m_optionsView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_restoreBtn;
    QPushButton *m_detectBtn;
    QProgressBar *m_progressBar;
    QDialogButtonBox *m_buttonBox;

    void setupUi(QDialog *EngineConfigurationDialog)
    {
        if (EngineConfigurationDialog->objectName().isEmpty())
            EngineConfigurationDialog->setObjectName(QString::fromUtf8("EngineConfigurationDialog"));
        EngineConfigurationDialog->resize(480, 400);
        verticalLayout_3 = new QVBoxLayout(EngineConfigurationDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_tabs = new QTabWidget(EngineConfigurationDialog);
        m_tabs->setObjectName(QString::fromUtf8("m_tabs"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayout = new QFormLayout(tab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        m_nameEdit = new QLineEdit(tab);
        m_nameEdit->setObjectName(QString::fromUtf8("m_nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, m_nameEdit);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_commandEdit = new QLineEdit(tab);
        m_commandEdit->setObjectName(QString::fromUtf8("m_commandEdit"));

        horizontalLayout->addWidget(m_commandEdit);

        m_browseCmdBtn = new QPushButton(tab);
        m_browseCmdBtn->setObjectName(QString::fromUtf8("m_browseCmdBtn"));

        horizontalLayout->addWidget(m_browseCmdBtn);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_workingDirEdit = new QLineEdit(tab);
        m_workingDirEdit->setObjectName(QString::fromUtf8("m_workingDirEdit"));

        horizontalLayout_2->addWidget(m_workingDirEdit);

        m_browseWorkingDirBtn = new QPushButton(tab);
        m_browseWorkingDirBtn->setObjectName(QString::fromUtf8("m_browseWorkingDirBtn"));

        horizontalLayout_2->addWidget(m_browseWorkingDirBtn);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        m_protocolCombo = new QComboBox(tab);
        m_protocolCombo->setObjectName(QString::fromUtf8("m_protocolCombo"));

        formLayout->setWidget(3, QFormLayout::FieldRole, m_protocolCombo);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        m_initStringEdit = new QPlainTextEdit(tab);
        m_initStringEdit->setObjectName(QString::fromUtf8("m_initStringEdit"));
        m_initStringEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        formLayout->setWidget(4, QFormLayout::FieldRole, m_initStringEdit);

        m_whitePovCheck = new QCheckBox(tab);
        m_whitePovCheck->setObjectName(QString::fromUtf8("m_whitePovCheck"));
        m_whitePovCheck->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, m_whitePovCheck);

        m_tabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_optionsView = new QTreeView(tab_2);
        m_optionsView->setObjectName(QString::fromUtf8("m_optionsView"));
        m_optionsView->setAlternatingRowColors(true);
        m_optionsView->setRootIsDecorated(false);

        verticalLayout->addWidget(m_optionsView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        m_restoreBtn = new QPushButton(tab_2);
        m_restoreBtn->setObjectName(QString::fromUtf8("m_restoreBtn"));
        m_restoreBtn->setEnabled(false);

        horizontalLayout_3->addWidget(m_restoreBtn);

        m_detectBtn = new QPushButton(tab_2);
        m_detectBtn->setObjectName(QString::fromUtf8("m_detectBtn"));

        horizontalLayout_3->addWidget(m_detectBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        m_tabs->addTab(tab_2, QString());

        verticalLayout_3->addWidget(m_tabs);

        m_progressBar = new QProgressBar(EngineConfigurationDialog);
        m_progressBar->setObjectName(QString::fromUtf8("m_progressBar"));
        m_progressBar->setEnabled(true);
        m_progressBar->setMaximum(1);
        m_progressBar->setValue(0);
        m_progressBar->setTextVisible(false);

        verticalLayout_3->addWidget(m_progressBar);

        m_buttonBox = new QDialogButtonBox(EngineConfigurationDialog);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setOrientation(Qt::Horizontal);
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(m_buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(m_nameEdit);
        label_2->setBuddy(m_commandEdit);
        label_4->setBuddy(m_workingDirEdit);
        label_3->setBuddy(m_protocolCombo);
        label_5->setBuddy(m_initStringEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(EngineConfigurationDialog);
        QObject::connect(m_buttonBox, SIGNAL(rejected()), EngineConfigurationDialog, SLOT(reject()));

        m_tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EngineConfigurationDialog);
    } // setupUi

    void retranslateUi(QDialog *EngineConfigurationDialog)
    {
        label->setText(QApplication::translate("EngineConfigurationDialog", "&Name:", nullptr));
        label_2->setText(QApplication::translate("EngineConfigurationDialog", "Co&mmand:", nullptr));
        m_browseCmdBtn->setText(QApplication::translate("EngineConfigurationDialog", "Browse...", nullptr));
        label_4->setText(QApplication::translate("EngineConfigurationDialog", "Working &Directory:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_browseWorkingDirBtn->setToolTip(QApplication::translate("EngineConfigurationDialog", "Browse working directory.", nullptr));
#endif // QT_NO_TOOLTIP
        m_browseWorkingDirBtn->setText(QApplication::translate("EngineConfigurationDialog", "Browse...", nullptr));
        label_3->setText(QApplication::translate("EngineConfigurationDialog", "&Protocol:", nullptr));
        label_5->setText(QApplication::translate("EngineConfigurationDialog", "&Init Strings:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_whitePovCheck->setToolTip(QApplication::translate("EngineConfigurationDialog", "This option should be checked for Xboard/Winboard engines that report their scores from white's perspective.", nullptr));
#endif // QT_NO_TOOLTIP
        m_whitePovCheck->setText(QApplication::translate("EngineConfigurationDialog", "Scores from &white's perspective", nullptr));
        m_tabs->setTabText(m_tabs->indexOf(tab), QApplication::translate("EngineConfigurationDialog", "Basic", nullptr));
#ifndef QT_NO_TOOLTIP
        m_restoreBtn->setToolTip(QApplication::translate("EngineConfigurationDialog", "Restore the default value for each option", nullptr));
#endif // QT_NO_TOOLTIP
        m_restoreBtn->setText(QApplication::translate("EngineConfigurationDialog", "Restore defaults", nullptr));
#ifndef QT_NO_TOOLTIP
        m_detectBtn->setToolTip(QApplication::translate("EngineConfigurationDialog", "Detect the engine's options and supported features", nullptr));
#endif // QT_NO_TOOLTIP
        m_detectBtn->setText(QApplication::translate("EngineConfigurationDialog", "Detect", nullptr));
        m_tabs->setTabText(m_tabs->indexOf(tab_2), QApplication::translate("EngineConfigurationDialog", "Advanced", nullptr));
        Q_UNUSED(EngineConfigurationDialog);
    } // retranslateUi

};

namespace Ui {
    class EngineConfigurationDialog: public Ui_EngineConfigurationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINECONFIGDLG_H
