/********************************************************************************
** Form generated from reading UI file 'importprogressdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTPROGRESSDLG_H
#define UI_IMPORTPROGRESSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportProgressDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *m_fileNameLabel;
    QProgressBar *m_importProgressBar;
    QLabel *m_statusLabel;
    QDialogButtonBox *m_buttonBox;

    void setupUi(QDialog *ImportProgressDialog)
    {
        if (ImportProgressDialog->objectName().isEmpty())
            ImportProgressDialog->setObjectName(QString::fromUtf8("ImportProgressDialog"));
        ImportProgressDialog->resize(330, 122);
        ImportProgressDialog->setMinimumSize(QSize(330, 120));
        verticalLayout_2 = new QVBoxLayout(ImportProgressDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_fileNameLabel = new QLabel(ImportProgressDialog);
        m_fileNameLabel->setObjectName(QString::fromUtf8("m_fileNameLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_fileNameLabel->setFont(font);

        verticalLayout->addWidget(m_fileNameLabel);

        m_importProgressBar = new QProgressBar(ImportProgressDialog);
        m_importProgressBar->setObjectName(QString::fromUtf8("m_importProgressBar"));
        m_importProgressBar->setMaximum(0);
        m_importProgressBar->setValue(-1);

        verticalLayout->addWidget(m_importProgressBar);

        m_statusLabel = new QLabel(ImportProgressDialog);
        m_statusLabel->setObjectName(QString::fromUtf8("m_statusLabel"));

        verticalLayout->addWidget(m_statusLabel);


        verticalLayout_2->addLayout(verticalLayout);

        m_buttonBox = new QDialogButtonBox(ImportProgressDialog);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setOrientation(Qt::Horizontal);
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout_2->addWidget(m_buttonBox);


        retranslateUi(ImportProgressDialog);
        QObject::connect(m_buttonBox, SIGNAL(accepted()), ImportProgressDialog, SLOT(accept()));
        QObject::connect(m_buttonBox, SIGNAL(rejected()), ImportProgressDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImportProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ImportProgressDialog)
    {
        ImportProgressDialog->setWindowTitle(QApplication::translate("ImportProgressDialog", "Importing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportProgressDialog: public Ui_ImportProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTPROGRESSDLG_H
