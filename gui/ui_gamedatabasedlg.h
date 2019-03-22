/********************************************************************************
** Form generated from reading UI file 'gamedatabasedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEDATABASEDLG_H
#define UI_GAMEDATABASEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameDatabaseDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *m_searchEdit;
    QPushButton *m_clearBtn;
    QPushButton *m_advancedSearchBtn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *m_importBtn;
    QPushButton *m_exportBtn;
    QPushButton *m_createOpeningBookBtn;
    QPushButton *m_copyGameBtn;
    QPushButton *m_copyFenBtn;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QSplitter *m_splitter;
    QTreeView *m_databasesListView;
    QTreeView *m_gamesListView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *m_viewerLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QLabel *m_eventLabel;
    QLabel *label_5;
    QLabel *m_siteLabel;
    QLabel *label_2;
    QLabel *m_whiteLabel;
    QLabel *label_3;
    QLabel *m_blackLabel;
    QLabel *label_9;
    QLabel *m_resultLabel;
    QLabel *label_variant;
    QLabel *m_variantLabel;

    void setupUi(QDialog *GameDatabaseDialog)
    {
        if (GameDatabaseDialog->objectName().isEmpty())
            GameDatabaseDialog->setObjectName(QString::fromUtf8("GameDatabaseDialog"));
        GameDatabaseDialog->resize(760, 520);
        gridLayout = new QGridLayout(GameDatabaseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(GameDatabaseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        m_searchEdit = new QLineEdit(GameDatabaseDialog);
        m_searchEdit->setObjectName(QString::fromUtf8("m_searchEdit"));

        horizontalLayout_2->addWidget(m_searchEdit);

        m_clearBtn = new QPushButton(GameDatabaseDialog);
        m_clearBtn->setObjectName(QString::fromUtf8("m_clearBtn"));
        m_clearBtn->setEnabled(false);

        horizontalLayout_2->addWidget(m_clearBtn);

        m_advancedSearchBtn = new QPushButton(GameDatabaseDialog);
        m_advancedSearchBtn->setObjectName(QString::fromUtf8("m_advancedSearchBtn"));
        m_advancedSearchBtn->setEnabled(false);

        horizontalLayout_2->addWidget(m_advancedSearchBtn);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_importBtn = new QPushButton(GameDatabaseDialog);
        m_importBtn->setObjectName(QString::fromUtf8("m_importBtn"));

        horizontalLayout_3->addWidget(m_importBtn);

        m_exportBtn = new QPushButton(GameDatabaseDialog);
        m_exportBtn->setObjectName(QString::fromUtf8("m_exportBtn"));
        m_exportBtn->setEnabled(false);

        horizontalLayout_3->addWidget(m_exportBtn);

        m_createOpeningBookBtn = new QPushButton(GameDatabaseDialog);
        m_createOpeningBookBtn->setObjectName(QString::fromUtf8("m_createOpeningBookBtn"));
        m_createOpeningBookBtn->setEnabled(false);

        horizontalLayout_3->addWidget(m_createOpeningBookBtn);

        m_copyGameBtn = new QPushButton(GameDatabaseDialog);
        m_copyGameBtn->setObjectName(QString::fromUtf8("m_copyGameBtn"));
        m_copyGameBtn->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_copyGameBtn->sizePolicy().hasHeightForWidth());
        m_copyGameBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(m_copyGameBtn);

        m_copyFenBtn = new QPushButton(GameDatabaseDialog);
        m_copyFenBtn->setObjectName(QString::fromUtf8("m_copyFenBtn"));
        m_copyFenBtn->setEnabled(false);
        sizePolicy.setHeightForWidth(m_copyFenBtn->sizePolicy().hasHeightForWidth());
        m_copyFenBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(m_copyFenBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(GameDatabaseDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        horizontalLayout_3->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        m_splitter = new QSplitter(GameDatabaseDialog);
        m_splitter->setObjectName(QString::fromUtf8("m_splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_splitter->sizePolicy().hasHeightForWidth());
        m_splitter->setSizePolicy(sizePolicy1);
        m_splitter->setOrientation(Qt::Horizontal);
        m_databasesListView = new QTreeView(m_splitter);
        m_databasesListView->setObjectName(QString::fromUtf8("m_databasesListView"));
        m_databasesListView->setMinimumSize(QSize(100, 0));
        m_databasesListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_databasesListView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_databasesListView->setRootIsDecorated(false);
        m_splitter->addWidget(m_databasesListView);
        m_gamesListView = new QTreeView(m_splitter);
        m_gamesListView->setObjectName(QString::fromUtf8("m_gamesListView"));
        m_gamesListView->setMinimumSize(QSize(100, 0));
        m_gamesListView->setRootIsDecorated(false);
        m_splitter->addWidget(m_gamesListView);
        verticalLayoutWidget = new QWidget(m_splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        m_viewerLayout = new QVBoxLayout(verticalLayoutWidget);
        m_viewerLayout->setObjectName(QString::fromUtf8("m_viewerLayout"));
        m_viewerLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(verticalLayoutWidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 102, 428));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout_2->setContentsMargins(4, 4, 4, 4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(6);
        label_7 = new QLabel(scrollAreaWidgetContents_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        m_eventLabel = new QLabel(scrollAreaWidgetContents_2);
        m_eventLabel->setObjectName(QString::fromUtf8("m_eventLabel"));
        QFont font1;
        font1.setUnderline(true);
        m_eventLabel->setFont(font1);
        m_eventLabel->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, m_eventLabel);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        m_siteLabel = new QLabel(scrollAreaWidgetContents_2);
        m_siteLabel->setObjectName(QString::fromUtf8("m_siteLabel"));
        m_siteLabel->setFont(font1);
        m_siteLabel->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_siteLabel);

        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        m_whiteLabel = new QLabel(scrollAreaWidgetContents_2);
        m_whiteLabel->setObjectName(QString::fromUtf8("m_whiteLabel"));
        m_whiteLabel->setFont(font1);
        m_whiteLabel->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, m_whiteLabel);

        label_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_3);

        m_blackLabel = new QLabel(scrollAreaWidgetContents_2);
        m_blackLabel->setObjectName(QString::fromUtf8("m_blackLabel"));
        m_blackLabel->setFont(font1);
        m_blackLabel->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, m_blackLabel);

        label_9 = new QLabel(scrollAreaWidgetContents_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_9);

        m_resultLabel = new QLabel(scrollAreaWidgetContents_2);
        m_resultLabel->setObjectName(QString::fromUtf8("m_resultLabel"));
        m_resultLabel->setFont(font1);
        m_resultLabel->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, m_resultLabel);

        label_variant = new QLabel(scrollAreaWidgetContents_2);
        label_variant->setObjectName(QString::fromUtf8("label_variant"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(true);
        label_variant->setFont(font2);
        label_variant->setVisible(false);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_variant);

        m_variantLabel = new QLabel(scrollAreaWidgetContents_2);
        m_variantLabel->setObjectName(QString::fromUtf8("m_variantLabel"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, m_variantLabel);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        m_viewerLayout->addWidget(scrollArea_2);

        m_splitter->addWidget(verticalLayoutWidget);

        gridLayout->addWidget(m_splitter, 1, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(m_searchEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(GameDatabaseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GameDatabaseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GameDatabaseDialog, SLOT(reject()));
        QObject::connect(m_clearBtn, SIGNAL(clicked()), m_searchEdit, SLOT(clear()));
        QObject::connect(m_clearBtn, SIGNAL(clicked(bool)), m_searchEdit, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(GameDatabaseDialog);
    } // setupUi

    void retranslateUi(QDialog *GameDatabaseDialog)
    {
        GameDatabaseDialog->setWindowTitle(QApplication::translate("GameDatabaseDialog", "Game Database", nullptr));
        label->setText(QApplication::translate("GameDatabaseDialog", "&Search:", nullptr));
        m_clearBtn->setText(QApplication::translate("GameDatabaseDialog", "&Clear", nullptr));
        m_advancedSearchBtn->setText(QApplication::translate("GameDatabaseDialog", "Advanced...", nullptr));
        m_importBtn->setText(QApplication::translate("GameDatabaseDialog", "Import...", nullptr));
#ifndef QT_NO_TOOLTIP
        m_exportBtn->setToolTip(QApplication::translate("GameDatabaseDialog", "Export filtered games in PGN format", nullptr));
#endif // QT_NO_TOOLTIP
        m_exportBtn->setText(QApplication::translate("GameDatabaseDialog", "Export...", nullptr));
        m_createOpeningBookBtn->setText(QApplication::translate("GameDatabaseDialog", "Create opening book...", nullptr));
        m_copyGameBtn->setText(QApplication::translate("GameDatabaseDialog", "Copy PGN", nullptr));
        m_copyFenBtn->setText(QApplication::translate("GameDatabaseDialog", "Copy FEN", nullptr));
        label_7->setText(QApplication::translate("GameDatabaseDialog", "Event:", nullptr));
        m_eventLabel->setText(QString());
        label_5->setText(QApplication::translate("GameDatabaseDialog", "Site:", nullptr));
        m_siteLabel->setText(QString());
        label_2->setText(QApplication::translate("GameDatabaseDialog", "White:", nullptr));
        m_whiteLabel->setText(QString());
        label_3->setText(QApplication::translate("GameDatabaseDialog", "Black:", nullptr));
        m_blackLabel->setText(QString());
        label_9->setText(QApplication::translate("GameDatabaseDialog", "Result:", nullptr));
        m_resultLabel->setText(QString());
        label_variant->setText(QApplication::translate("GameDatabaseDialog", "Variant:", nullptr));
        m_variantLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameDatabaseDialog: public Ui_GameDatabaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEDATABASEDLG_H
