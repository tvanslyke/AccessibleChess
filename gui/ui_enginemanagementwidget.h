/********************************************************************************
** Form generated from reading UI file 'enginemanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEMANAGEMENTWIDGET_H
#define UI_ENGINEMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngineManagementWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *m_defaultLocationEdit;
    QPushButton *m_browseDefaultLocationBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *m_searchEngineEdit;
    QListView *m_enginesList;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *m_addBtn;
    QToolButton *m_removeBtn;
    QToolButton *m_configureBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *m_engineCountLabel;

    void setupUi(QWidget *EngineManagementWidget)
    {
        if (EngineManagementWidget->objectName().isEmpty())
            EngineManagementWidget->setObjectName(QString::fromUtf8("EngineManagementWidget"));
        EngineManagementWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(EngineManagementWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(EngineManagementWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        m_defaultLocationEdit = new QLineEdit(EngineManagementWidget);
        m_defaultLocationEdit->setObjectName(QString::fromUtf8("m_defaultLocationEdit"));

        horizontalLayout->addWidget(m_defaultLocationEdit);

        m_browseDefaultLocationBtn = new QPushButton(EngineManagementWidget);
        m_browseDefaultLocationBtn->setObjectName(QString::fromUtf8("m_browseDefaultLocationBtn"));

        horizontalLayout->addWidget(m_browseDefaultLocationBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(EngineManagementWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_searchEngineEdit = new QLineEdit(EngineManagementWidget);
        m_searchEngineEdit->setObjectName(QString::fromUtf8("m_searchEngineEdit"));
        m_searchEngineEdit->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(m_searchEngineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        m_enginesList = new QListView(EngineManagementWidget);
        m_enginesList->setObjectName(QString::fromUtf8("m_enginesList"));

        verticalLayout->addWidget(m_enginesList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_addBtn = new QToolButton(EngineManagementWidget);
        m_addBtn->setObjectName(QString::fromUtf8("m_addBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/toolbutton/add_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_addBtn->setIcon(icon);

        horizontalLayout_3->addWidget(m_addBtn);

        m_removeBtn = new QToolButton(EngineManagementWidget);
        m_removeBtn->setObjectName(QString::fromUtf8("m_removeBtn"));
        m_removeBtn->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/toolbutton/remove_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_removeBtn->setIcon(icon1);

        horizontalLayout_3->addWidget(m_removeBtn);

        m_configureBtn = new QToolButton(EngineManagementWidget);
        m_configureBtn->setObjectName(QString::fromUtf8("m_configureBtn"));
        m_configureBtn->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/toolbutton/configure_16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_configureBtn->setIcon(icon2);

        horizontalLayout_3->addWidget(m_configureBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        m_engineCountLabel = new QLabel(EngineManagementWidget);
        m_engineCountLabel->setObjectName(QString::fromUtf8("m_engineCountLabel"));

        horizontalLayout_3->addWidget(m_engineCountLabel);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(EngineManagementWidget);

        QMetaObject::connectSlotsByName(EngineManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *EngineManagementWidget)
    {
        EngineManagementWidget->setWindowTitle(QApplication::translate("EngineManagementWidget", "Form", nullptr));
        label_2->setText(QApplication::translate("EngineManagementWidget", "Default location:", nullptr));
        m_browseDefaultLocationBtn->setText(QApplication::translate("EngineManagementWidget", "Browse...", nullptr));
        label->setText(QApplication::translate("EngineManagementWidget", "Configured chess engines:", nullptr));
        m_searchEngineEdit->setPlaceholderText(QApplication::translate("EngineManagementWidget", "Search", nullptr));
#ifndef QT_NO_TOOLTIP
        m_addBtn->setToolTip(QApplication::translate("EngineManagementWidget", "Add a new engine", nullptr));
#endif // QT_NO_TOOLTIP
        m_addBtn->setText(QApplication::translate("EngineManagementWidget", "Add", nullptr));
#ifndef QT_NO_TOOLTIP
        m_removeBtn->setToolTip(QApplication::translate("EngineManagementWidget", "Remove selected engine(s)", nullptr));
#endif // QT_NO_TOOLTIP
        m_removeBtn->setText(QApplication::translate("EngineManagementWidget", "Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        m_configureBtn->setToolTip(QApplication::translate("EngineManagementWidget", "Configure selected engine(s)", nullptr));
#endif // QT_NO_TOOLTIP
        m_configureBtn->setText(QApplication::translate("EngineManagementWidget", "Configure", nullptr));
        m_engineCountLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EngineManagementWidget: public Ui_EngineManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEMANAGEMENTWIDGET_H
