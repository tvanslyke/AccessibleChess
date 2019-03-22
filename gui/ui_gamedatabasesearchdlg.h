/********************************************************************************
** Form generated from reading UI file 'gamedatabasesearchdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEDATABASESEARCHDLG_H
#define UI_GAMEDATABASESEARCHDLG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GameDatabaseSearchDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *m_eventEdit;
    QLabel *label_2;
    QLineEdit *m_siteEdit;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_minDateCheck;
    QDateEdit *m_minDateEdit;
    QLabel *label_8;
    QCheckBox *m_maxDateCheck;
    QDateEdit *m_maxDateEdit;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *m_minRoundSpin;
    QLabel *label_9;
    QSpinBox *m_maxRoundSpin;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *m_playerSideCombo;
    QLineEdit *m_playerEdit;
    QLabel *label_6;
    QLineEdit *m_opponentEdit;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *m_invertResultCheck;
    QComboBox *m_resultCombo;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GameDatabaseSearchDialog)
    {
        if (GameDatabaseSearchDialog->objectName().isEmpty())
            GameDatabaseSearchDialog->setObjectName(QString::fromUtf8("GameDatabaseSearchDialog"));
        GameDatabaseSearchDialog->resize(394, 296);
        verticalLayout = new QVBoxLayout(GameDatabaseSearchDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(GameDatabaseSearchDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        m_eventEdit = new QLineEdit(GameDatabaseSearchDialog);
        m_eventEdit->setObjectName(QString::fromUtf8("m_eventEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, m_eventEdit);

        label_2 = new QLabel(GameDatabaseSearchDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        m_siteEdit = new QLineEdit(GameDatabaseSearchDialog);
        m_siteEdit->setObjectName(QString::fromUtf8("m_siteEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, m_siteEdit);

        label_3 = new QLabel(GameDatabaseSearchDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_minDateCheck = new QCheckBox(GameDatabaseSearchDialog);
        m_minDateCheck->setObjectName(QString::fromUtf8("m_minDateCheck"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_minDateCheck->sizePolicy().hasHeightForWidth());
        m_minDateCheck->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(m_minDateCheck);

        m_minDateEdit = new QDateEdit(GameDatabaseSearchDialog);
        m_minDateEdit->setObjectName(QString::fromUtf8("m_minDateEdit"));
        m_minDateEdit->setEnabled(false);
        m_minDateEdit->setDate(QDate(1900, 1, 1));
        m_minDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(m_minDateEdit);

        label_8 = new QLabel(GameDatabaseSearchDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        m_maxDateCheck = new QCheckBox(GameDatabaseSearchDialog);
        m_maxDateCheck->setObjectName(QString::fromUtf8("m_maxDateCheck"));
        sizePolicy.setHeightForWidth(m_maxDateCheck->sizePolicy().hasHeightForWidth());
        m_maxDateCheck->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(m_maxDateCheck);

        m_maxDateEdit = new QDateEdit(GameDatabaseSearchDialog);
        m_maxDateEdit->setObjectName(QString::fromUtf8("m_maxDateEdit"));
        m_maxDateEdit->setEnabled(false);
        m_maxDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(m_maxDateEdit);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        label_4 = new QLabel(GameDatabaseSearchDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_minRoundSpin = new QSpinBox(GameDatabaseSearchDialog);
        m_minRoundSpin->setObjectName(QString::fromUtf8("m_minRoundSpin"));
        m_minRoundSpin->setMaximum(100000);

        horizontalLayout_3->addWidget(m_minRoundSpin);

        label_9 = new QLabel(GameDatabaseSearchDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);

        m_maxRoundSpin = new QSpinBox(GameDatabaseSearchDialog);
        m_maxRoundSpin->setObjectName(QString::fromUtf8("m_maxRoundSpin"));
        m_maxRoundSpin->setMaximum(100000);

        horizontalLayout_3->addWidget(m_maxRoundSpin);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        label_5 = new QLabel(GameDatabaseSearchDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_playerSideCombo = new QComboBox(GameDatabaseSearchDialog);
        m_playerSideCombo->addItem(QString());
        m_playerSideCombo->addItem(QString());
        m_playerSideCombo->addItem(QString());
        m_playerSideCombo->setObjectName(QString::fromUtf8("m_playerSideCombo"));

        horizontalLayout_2->addWidget(m_playerSideCombo);

        m_playerEdit = new QLineEdit(GameDatabaseSearchDialog);
        m_playerEdit->setObjectName(QString::fromUtf8("m_playerEdit"));

        horizontalLayout_2->addWidget(m_playerEdit);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_2);

        label_6 = new QLabel(GameDatabaseSearchDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        m_opponentEdit = new QLineEdit(GameDatabaseSearchDialog);
        m_opponentEdit->setObjectName(QString::fromUtf8("m_opponentEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, m_opponentEdit);

        label_7 = new QLabel(GameDatabaseSearchDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_invertResultCheck = new QCheckBox(GameDatabaseSearchDialog);
        m_invertResultCheck->setObjectName(QString::fromUtf8("m_invertResultCheck"));
        m_invertResultCheck->setEnabled(false);
        sizePolicy.setHeightForWidth(m_invertResultCheck->sizePolicy().hasHeightForWidth());
        m_invertResultCheck->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(m_invertResultCheck);

        m_resultCombo = new QComboBox(GameDatabaseSearchDialog);
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->addItem(QString());
        m_resultCombo->setObjectName(QString::fromUtf8("m_resultCombo"));

        horizontalLayout_4->addWidget(m_resultCombo);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_4);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(GameDatabaseSearchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(m_eventEdit);
        label_2->setBuddy(m_siteEdit);
        label_3->setBuddy(m_minDateCheck);
        label_4->setBuddy(m_minRoundSpin);
        label_5->setBuddy(m_playerSideCombo);
        label_6->setBuddy(m_opponentEdit);
        label_7->setBuddy(m_resultCombo);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(buttonBox, m_eventEdit);
        QWidget::setTabOrder(m_eventEdit, m_siteEdit);
        QWidget::setTabOrder(m_siteEdit, m_minDateCheck);
        QWidget::setTabOrder(m_minDateCheck, m_minDateEdit);
        QWidget::setTabOrder(m_minDateEdit, m_maxDateCheck);
        QWidget::setTabOrder(m_maxDateCheck, m_maxDateEdit);
        QWidget::setTabOrder(m_maxDateEdit, m_minRoundSpin);
        QWidget::setTabOrder(m_minRoundSpin, m_maxRoundSpin);
        QWidget::setTabOrder(m_maxRoundSpin, m_playerSideCombo);
        QWidget::setTabOrder(m_playerSideCombo, m_playerEdit);
        QWidget::setTabOrder(m_playerEdit, m_opponentEdit);
        QWidget::setTabOrder(m_opponentEdit, m_invertResultCheck);
        QWidget::setTabOrder(m_invertResultCheck, m_resultCombo);

        retranslateUi(GameDatabaseSearchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GameDatabaseSearchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GameDatabaseSearchDialog, SLOT(reject()));
        QObject::connect(m_minDateCheck, SIGNAL(toggled(bool)), m_minDateEdit, SLOT(setEnabled(bool)));
        QObject::connect(m_maxDateCheck, SIGNAL(toggled(bool)), m_maxDateEdit, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(GameDatabaseSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *GameDatabaseSearchDialog)
    {
        GameDatabaseSearchDialog->setWindowTitle(QApplication::translate("GameDatabaseSearchDialog", "Advanced Search", nullptr));
        label->setText(QApplication::translate("GameDatabaseSearchDialog", "Event:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_eventEdit->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The name of the tournament or match event", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("GameDatabaseSearchDialog", "Site:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_siteEdit->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The location of the event", nullptr));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("GameDatabaseSearchDialog", "Date:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_minDateCheck->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "Enable minimum date", nullptr));
#endif // QT_NO_TOOLTIP
        m_minDateCheck->setText(QString());
#ifndef QT_NO_TOOLTIP
        m_minDateEdit->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "Minimum starting date of the games", nullptr));
#endif // QT_NO_TOOLTIP
        m_minDateEdit->setDisplayFormat(QApplication::translate("GameDatabaseSearchDialog", "M/d/yyyy", nullptr));
        label_8->setText(QApplication::translate("GameDatabaseSearchDialog", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        m_maxDateCheck->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "Enable maximum date", nullptr));
#endif // QT_NO_TOOLTIP
        m_maxDateCheck->setText(QString());
#ifndef QT_NO_TOOLTIP
        m_maxDateEdit->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "Maximum starting date of the games", nullptr));
#endif // QT_NO_TOOLTIP
        m_maxDateEdit->setDisplayFormat(QApplication::translate("GameDatabaseSearchDialog", "M/d/yyyy", nullptr));
        label_4->setText(QApplication::translate("GameDatabaseSearchDialog", "Round:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_minRoundSpin->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The minimum round ordinal of the games within the event", nullptr));
#endif // QT_NO_TOOLTIP
        m_minRoundSpin->setSpecialValueText(QApplication::translate("GameDatabaseSearchDialog", "null", nullptr));
        label_9->setText(QApplication::translate("GameDatabaseSearchDialog", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        m_maxRoundSpin->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The maximum round ordinal of the games within the event", nullptr));
#endif // QT_NO_TOOLTIP
        m_maxRoundSpin->setSpecialValueText(QApplication::translate("GameDatabaseSearchDialog", "null", nullptr));
        m_maxRoundSpin->setSuffix(QString());
        label_5->setText(QApplication::translate("GameDatabaseSearchDialog", "Player:", nullptr));
        m_playerSideCombo->setItemText(0, QApplication::translate("GameDatabaseSearchDialog", "Any side", nullptr));
        m_playerSideCombo->setItemText(1, QApplication::translate("GameDatabaseSearchDialog", "White", nullptr));
        m_playerSideCombo->setItemText(2, QApplication::translate("GameDatabaseSearchDialog", "Black", nullptr));

#ifndef QT_NO_TOOLTIP
        m_playerSideCombo->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The side the player plays on", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_playerEdit->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The first player's name, in \"lastname, firstname\" format", nullptr));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("GameDatabaseSearchDialog", "Opponent:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_opponentEdit->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The second player's name, in \"lastname, firstname\" format", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("GameDatabaseSearchDialog", "Result:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_invertResultCheck->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "Search for the inverse of the chosen result", nullptr));
#endif // QT_NO_TOOLTIP
        m_invertResultCheck->setText(QApplication::translate("GameDatabaseSearchDialog", "Not", nullptr));
        m_resultCombo->setItemText(0, QApplication::translate("GameDatabaseSearchDialog", "Any result", nullptr));
        m_resultCombo->setItemText(1, QApplication::translate("GameDatabaseSearchDialog", "Any player wins", nullptr));
        m_resultCombo->setItemText(2, QApplication::translate("GameDatabaseSearchDialog", "White wins", nullptr));
        m_resultCombo->setItemText(3, QApplication::translate("GameDatabaseSearchDialog", "Black wins", nullptr));
        m_resultCombo->setItemText(4, QApplication::translate("GameDatabaseSearchDialog", "First player wins", nullptr));
        m_resultCombo->setItemText(5, QApplication::translate("GameDatabaseSearchDialog", "First player loses", nullptr));
        m_resultCombo->setItemText(6, QApplication::translate("GameDatabaseSearchDialog", "Draw", nullptr));
        m_resultCombo->setItemText(7, QApplication::translate("GameDatabaseSearchDialog", "Unfinished", nullptr));

#ifndef QT_NO_TOOLTIP
        m_resultCombo->setToolTip(QApplication::translate("GameDatabaseSearchDialog", "The result of the games", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class GameDatabaseSearchDialog: public Ui_GameDatabaseSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEDATABASESEARCHDLG_H
