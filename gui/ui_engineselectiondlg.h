/********************************************************************************
** Form generated from reading UI file 'engineselectiondlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINESELECTIONDLG_H
#define UI_ENGINESELECTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EngineSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_engineFilterEdit;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QListView *m_enginesList;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EngineSelectionDialog)
    {
        if (EngineSelectionDialog->objectName().isEmpty())
            EngineSelectionDialog->setObjectName(QString::fromUtf8("EngineSelectionDialog"));
        EngineSelectionDialog->resize(322, 388);
        verticalLayout = new QVBoxLayout(EngineSelectionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(EngineSelectionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        m_engineFilterEdit = new QLineEdit(EngineSelectionDialog);
        m_engineFilterEdit->setObjectName(QString::fromUtf8("m_engineFilterEdit"));

        horizontalLayout->addWidget(m_engineFilterEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(1, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(EngineSelectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        m_enginesList = new QListView(EngineSelectionDialog);
        m_enginesList->setObjectName(QString::fromUtf8("m_enginesList"));
        m_enginesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        m_enginesList->setProperty("showDropIndicator", QVariant(true));
        m_enginesList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_enginesList->setSelectionBehavior(QAbstractItemView::SelectItems);

        verticalLayout->addWidget(m_enginesList);

        buttonBox = new QDialogButtonBox(EngineSelectionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(m_engineFilterEdit);
        label_2->setBuddy(m_enginesList);
#endif // QT_NO_SHORTCUT

        retranslateUi(EngineSelectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EngineSelectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EngineSelectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EngineSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *EngineSelectionDialog)
    {
        EngineSelectionDialog->setWindowTitle(QApplication::translate("EngineSelectionDialog", "Select Chess Engines", nullptr));
        label->setText(QApplication::translate("EngineSelectionDialog", "&Filter:", nullptr));
        label_2->setText(QApplication::translate("EngineSelectionDialog", "Configured chess engines:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EngineSelectionDialog: public Ui_EngineSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINESELECTIONDLG_H
