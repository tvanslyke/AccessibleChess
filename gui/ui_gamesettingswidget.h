/********************************************************************************
** Form generated from reading UI file 'gamesettingswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESETTINGSWIDGET_H
#define UI_GAMESETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameSettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QComboBox *m_variantCombo;
    QLabel *m_variantLabel;
    QPushButton *m_timeControlBtn;
    QLabel *m_timeControlLabel;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_4;
    QLabel *m_pgnEpdLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *m_openingSuiteEdit;
    QPushButton *m_browseOpeningSuiteBtn;
    QLabel *m_openingOrderLabel;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *m_seqOrderRadio;
    QRadioButton *m_randomOrderRadio;
    QSpacerItem *horizontalSpacer;
    QLabel *m_openingSuiteDepth;
    QSpinBox *m_openingSuiteDepthSpin;
    QLabel *m_fenLabel;
    QLineEdit *m_fenEdit;
    QGroupBox *m_openingBookGroup;
    QFormLayout *formLayout_5;
    QLabel *m_polyglotFileLabel;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *m_polyglotFileEdit;
    QPushButton *m_browsePolyglotFile;
    QLabel *m_polyglotDepthLabel;
    QSpinBox *m_polyglotDepthSpin;
    QLabel *m_polyglotAccessMode;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *m_ramAccessRadio;
    QRadioButton *m_diskAccessRadio;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_6;
    QGroupBox *m_drawAdjudicationGroup;
    QFormLayout *formLayout;
    QLabel *m_drawMoveNumberLabel;
    QSpinBox *m_drawMoveNumberSpin;
    QLabel *m_drawMoveCountLabel;
    QSpinBox *m_drawMoveCountSpin;
    QLabel *m_drawScoreLabel;
    QSpinBox *m_drawScoreSpin;
    QGroupBox *m_resignAdjudicationGroup;
    QFormLayout *formLayout_3;
    QLabel *m_resignMoveCountLabel;
    QSpinBox *m_resignMoveCountSpin;
    QLabel *m_resignScoreLabel;
    QSpinBox *m_resignScoreSpin;
    QRadioButton *m_resignNormalRadio;
    QRadioButton *m_resignTwoSidedRadio;
    QGroupBox *m_gameLengthGroup;
    QHBoxLayout *horizontalLayout;
    QLabel *m_maxGameLengthLabel;
    QSpinBox *m_maxGameLengthSpin;
    QCheckBox *m_tbCheck;
    QCheckBox *m_ponderingCheck;

    void setupUi(QWidget *GameSettingsWidget)
    {
        if (GameSettingsWidget->objectName().isEmpty())
            GameSettingsWidget->setObjectName(QString::fromUtf8("GameSettingsWidget"));
        GameSettingsWidget->resize(426, 637);
        verticalLayout = new QVBoxLayout(GameSettingsWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        m_variantCombo = new QComboBox(GameSettingsWidget);
        m_variantCombo->setObjectName(QString::fromUtf8("m_variantCombo"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_variantCombo);

        m_variantLabel = new QLabel(GameSettingsWidget);
        m_variantLabel->setObjectName(QString::fromUtf8("m_variantLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, m_variantLabel);

        m_timeControlBtn = new QPushButton(GameSettingsWidget);
        m_timeControlBtn->setObjectName(QString::fromUtf8("m_timeControlBtn"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, m_timeControlBtn);

        m_timeControlLabel = new QLabel(GameSettingsWidget);
        m_timeControlLabel->setObjectName(QString::fromUtf8("m_timeControlLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, m_timeControlLabel);


        verticalLayout->addLayout(formLayout_2);

        groupBox_3 = new QGroupBox(GameSettingsWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        formLayout_4 = new QFormLayout(groupBox_3);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        m_pgnEpdLabel = new QLabel(groupBox_3);
        m_pgnEpdLabel->setObjectName(QString::fromUtf8("m_pgnEpdLabel"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, m_pgnEpdLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_openingSuiteEdit = new QLineEdit(groupBox_3);
        m_openingSuiteEdit->setObjectName(QString::fromUtf8("m_openingSuiteEdit"));

        horizontalLayout_2->addWidget(m_openingSuiteEdit);

        m_browseOpeningSuiteBtn = new QPushButton(groupBox_3);
        m_browseOpeningSuiteBtn->setObjectName(QString::fromUtf8("m_browseOpeningSuiteBtn"));

        horizontalLayout_2->addWidget(m_browseOpeningSuiteBtn);


        formLayout_4->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        m_openingOrderLabel = new QLabel(groupBox_3);
        m_openingOrderLabel->setObjectName(QString::fromUtf8("m_openingOrderLabel"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, m_openingOrderLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_seqOrderRadio = new QRadioButton(groupBox_3);
        m_seqOrderRadio->setObjectName(QString::fromUtf8("m_seqOrderRadio"));
        m_seqOrderRadio->setEnabled(false);
        m_seqOrderRadio->setChecked(true);

        horizontalLayout_3->addWidget(m_seqOrderRadio);

        m_randomOrderRadio = new QRadioButton(groupBox_3);
        m_randomOrderRadio->setObjectName(QString::fromUtf8("m_randomOrderRadio"));
        m_randomOrderRadio->setEnabled(false);

        horizontalLayout_3->addWidget(m_randomOrderRadio);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        formLayout_4->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        m_openingSuiteDepth = new QLabel(groupBox_3);
        m_openingSuiteDepth->setObjectName(QString::fromUtf8("m_openingSuiteDepth"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, m_openingSuiteDepth);

        m_openingSuiteDepthSpin = new QSpinBox(groupBox_3);
        m_openingSuiteDepthSpin->setObjectName(QString::fromUtf8("m_openingSuiteDepthSpin"));
        m_openingSuiteDepthSpin->setEnabled(false);
        m_openingSuiteDepthSpin->setMinimum(1);
        m_openingSuiteDepthSpin->setMaximum(999);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, m_openingSuiteDepthSpin);

        m_fenLabel = new QLabel(groupBox_3);
        m_fenLabel->setObjectName(QString::fromUtf8("m_fenLabel"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, m_fenLabel);

        m_fenEdit = new QLineEdit(groupBox_3);
        m_fenEdit->setObjectName(QString::fromUtf8("m_fenEdit"));
        m_fenEdit->setMaxLength(128);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, m_fenEdit);


        verticalLayout->addWidget(groupBox_3);

        m_openingBookGroup = new QGroupBox(GameSettingsWidget);
        m_openingBookGroup->setObjectName(QString::fromUtf8("m_openingBookGroup"));
        m_openingBookGroup->setEnabled(false);
        formLayout_5 = new QFormLayout(m_openingBookGroup);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        m_polyglotFileLabel = new QLabel(m_openingBookGroup);
        m_polyglotFileLabel->setObjectName(QString::fromUtf8("m_polyglotFileLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, m_polyglotFileLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_polyglotFileEdit = new QLineEdit(m_openingBookGroup);
        m_polyglotFileEdit->setObjectName(QString::fromUtf8("m_polyglotFileEdit"));

        horizontalLayout_4->addWidget(m_polyglotFileEdit);

        m_browsePolyglotFile = new QPushButton(m_openingBookGroup);
        m_browsePolyglotFile->setObjectName(QString::fromUtf8("m_browsePolyglotFile"));

        horizontalLayout_4->addWidget(m_browsePolyglotFile);


        formLayout_5->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        m_polyglotDepthLabel = new QLabel(m_openingBookGroup);
        m_polyglotDepthLabel->setObjectName(QString::fromUtf8("m_polyglotDepthLabel"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, m_polyglotDepthLabel);

        m_polyglotDepthSpin = new QSpinBox(m_openingBookGroup);
        m_polyglotDepthSpin->setObjectName(QString::fromUtf8("m_polyglotDepthSpin"));
        m_polyglotDepthSpin->setEnabled(false);
        m_polyglotDepthSpin->setMinimum(1);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, m_polyglotDepthSpin);

        m_polyglotAccessMode = new QLabel(m_openingBookGroup);
        m_polyglotAccessMode->setObjectName(QString::fromUtf8("m_polyglotAccessMode"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, m_polyglotAccessMode);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_ramAccessRadio = new QRadioButton(m_openingBookGroup);
        m_ramAccessRadio->setObjectName(QString::fromUtf8("m_ramAccessRadio"));
        m_ramAccessRadio->setEnabled(false);
        m_ramAccessRadio->setChecked(true);

        horizontalLayout_5->addWidget(m_ramAccessRadio);

        m_diskAccessRadio = new QRadioButton(m_openingBookGroup);
        m_diskAccessRadio->setObjectName(QString::fromUtf8("m_diskAccessRadio"));
        m_diskAccessRadio->setEnabled(false);

        horizontalLayout_5->addWidget(m_diskAccessRadio);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        formLayout_5->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);


        verticalLayout->addWidget(m_openingBookGroup);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        m_drawAdjudicationGroup = new QGroupBox(GameSettingsWidget);
        m_drawAdjudicationGroup->setObjectName(QString::fromUtf8("m_drawAdjudicationGroup"));
        m_drawAdjudicationGroup->setEnabled(false);
        formLayout = new QFormLayout(m_drawAdjudicationGroup);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        m_drawMoveNumberLabel = new QLabel(m_drawAdjudicationGroup);
        m_drawMoveNumberLabel->setObjectName(QString::fromUtf8("m_drawMoveNumberLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, m_drawMoveNumberLabel);

        m_drawMoveNumberSpin = new QSpinBox(m_drawAdjudicationGroup);
        m_drawMoveNumberSpin->setObjectName(QString::fromUtf8("m_drawMoveNumberSpin"));
        m_drawMoveNumberSpin->setMinimum(0);
        m_drawMoveNumberSpin->setMaximum(999);
        m_drawMoveNumberSpin->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, m_drawMoveNumberSpin);

        m_drawMoveCountLabel = new QLabel(m_drawAdjudicationGroup);
        m_drawMoveCountLabel->setObjectName(QString::fromUtf8("m_drawMoveCountLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, m_drawMoveCountLabel);

        m_drawMoveCountSpin = new QSpinBox(m_drawAdjudicationGroup);
        m_drawMoveCountSpin->setObjectName(QString::fromUtf8("m_drawMoveCountSpin"));
        m_drawMoveCountSpin->setEnabled(false);
        m_drawMoveCountSpin->setMaximum(999);

        formLayout->setWidget(1, QFormLayout::FieldRole, m_drawMoveCountSpin);

        m_drawScoreLabel = new QLabel(m_drawAdjudicationGroup);
        m_drawScoreLabel->setObjectName(QString::fromUtf8("m_drawScoreLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, m_drawScoreLabel);

        m_drawScoreSpin = new QSpinBox(m_drawAdjudicationGroup);
        m_drawScoreSpin->setObjectName(QString::fromUtf8("m_drawScoreSpin"));
        m_drawScoreSpin->setEnabled(false);
        m_drawScoreSpin->setMaximum(999);

        formLayout->setWidget(2, QFormLayout::FieldRole, m_drawScoreSpin);


        formLayout_6->setWidget(1, QFormLayout::LabelRole, m_drawAdjudicationGroup);

        m_resignAdjudicationGroup = new QGroupBox(GameSettingsWidget);
        m_resignAdjudicationGroup->setObjectName(QString::fromUtf8("m_resignAdjudicationGroup"));
        m_resignAdjudicationGroup->setEnabled(false);
        formLayout_3 = new QFormLayout(m_resignAdjudicationGroup);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        m_resignMoveCountLabel = new QLabel(m_resignAdjudicationGroup);
        m_resignMoveCountLabel->setObjectName(QString::fromUtf8("m_resignMoveCountLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, m_resignMoveCountLabel);

        m_resignMoveCountSpin = new QSpinBox(m_resignAdjudicationGroup);
        m_resignMoveCountSpin->setObjectName(QString::fromUtf8("m_resignMoveCountSpin"));
        m_resignMoveCountSpin->setMaximum(999);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, m_resignMoveCountSpin);

        m_resignScoreLabel = new QLabel(m_resignAdjudicationGroup);
        m_resignScoreLabel->setObjectName(QString::fromUtf8("m_resignScoreLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, m_resignScoreLabel);

        m_resignScoreSpin = new QSpinBox(m_resignAdjudicationGroup);
        m_resignScoreSpin->setObjectName(QString::fromUtf8("m_resignScoreSpin"));
        m_resignScoreSpin->setEnabled(false);
        m_resignScoreSpin->setMaximum(9999);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, m_resignScoreSpin);

        m_resignNormalRadio = new QRadioButton(m_resignAdjudicationGroup);
        m_resignNormalRadio->setObjectName(QString::fromUtf8("m_resignNormalRadio"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_resignNormalRadio->sizePolicy().hasHeightForWidth());
        m_resignNormalRadio->setSizePolicy(sizePolicy);
        m_resignNormalRadio->setChecked(true);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, m_resignNormalRadio);

        m_resignTwoSidedRadio = new QRadioButton(m_resignAdjudicationGroup);
        m_resignTwoSidedRadio->setObjectName(QString::fromUtf8("m_resignTwoSidedRadio"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, m_resignTwoSidedRadio);


        formLayout_6->setWidget(1, QFormLayout::FieldRole, m_resignAdjudicationGroup);

        m_gameLengthGroup = new QGroupBox(GameSettingsWidget);
        m_gameLengthGroup->setObjectName(QString::fromUtf8("m_gameLengthGroup"));
        m_gameLengthGroup->setEnabled(false);
        horizontalLayout = new QHBoxLayout(m_gameLengthGroup);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_maxGameLengthLabel = new QLabel(m_gameLengthGroup);
        m_maxGameLengthLabel->setObjectName(QString::fromUtf8("m_maxGameLengthLabel"));

        horizontalLayout->addWidget(m_maxGameLengthLabel);

        m_maxGameLengthSpin = new QSpinBox(m_gameLengthGroup);
        m_maxGameLengthSpin->setObjectName(QString::fromUtf8("m_maxGameLengthSpin"));
        m_maxGameLengthSpin->setToolTipDuration(-1);
        m_maxGameLengthSpin->setWrapping(true);
        m_maxGameLengthSpin->setMinimum(0);
        m_maxGameLengthSpin->setMaximum(5000);
        m_maxGameLengthSpin->setValue(0);

        horizontalLayout->addWidget(m_maxGameLengthSpin);


        formLayout_6->setWidget(2, QFormLayout::LabelRole, m_gameLengthGroup);


        verticalLayout->addLayout(formLayout_6);

        m_tbCheck = new QCheckBox(GameSettingsWidget);
        m_tbCheck->setObjectName(QString::fromUtf8("m_tbCheck"));
        m_tbCheck->setEnabled(false);

        verticalLayout->addWidget(m_tbCheck);

        m_ponderingCheck = new QCheckBox(GameSettingsWidget);
        m_ponderingCheck->setObjectName(QString::fromUtf8("m_ponderingCheck"));
        m_ponderingCheck->setEnabled(false);

        verticalLayout->addWidget(m_ponderingCheck);

#ifndef QT_NO_SHORTCUT
        m_variantLabel->setBuddy(m_variantCombo);
        m_timeControlLabel->setBuddy(m_timeControlBtn);
        m_pgnEpdLabel->setBuddy(m_openingSuiteEdit);
        m_openingOrderLabel->setBuddy(m_seqOrderRadio);
        m_fenLabel->setBuddy(m_fenEdit);
        m_polyglotFileLabel->setBuddy(m_polyglotFileEdit);
        m_polyglotDepthLabel->setBuddy(m_polyglotDepthSpin);
        m_polyglotAccessMode->setBuddy(m_ramAccessRadio);
        m_drawMoveNumberLabel->setBuddy(m_drawMoveNumberSpin);
        m_drawMoveCountLabel->setBuddy(m_drawMoveCountSpin);
        m_drawScoreLabel->setBuddy(m_drawScoreSpin);
        m_resignMoveCountLabel->setBuddy(m_resignMoveCountSpin);
        m_resignScoreLabel->setBuddy(m_resignScoreSpin);
#endif // QT_NO_SHORTCUT

        retranslateUi(GameSettingsWidget);

        QMetaObject::connectSlotsByName(GameSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *GameSettingsWidget)
    {
        GameSettingsWidget->setWindowTitle(QApplication::translate("GameSettingsWidget", "Form", nullptr));
        m_variantLabel->setText(QApplication::translate("GameSettingsWidget", "Variant:", nullptr));
        m_timeControlBtn->setText(QString());
        m_timeControlLabel->setText(QApplication::translate("GameSettingsWidget", "Time Control:", nullptr));
        groupBox_3->setTitle(QApplication::translate("GameSettingsWidget", "Opening suite", nullptr));
        m_pgnEpdLabel->setText(QApplication::translate("GameSettingsWidget", "PGN/EPD file:", nullptr));
        m_browseOpeningSuiteBtn->setText(QApplication::translate("GameSettingsWidget", "Browse...", nullptr));
        m_openingOrderLabel->setText(QApplication::translate("GameSettingsWidget", "Opening order:", nullptr));
        m_seqOrderRadio->setText(QApplication::translate("GameSettingsWidget", "Sequential", nullptr));
        m_randomOrderRadio->setText(QApplication::translate("GameSettingsWidget", "Random", nullptr));
        m_openingSuiteDepth->setText(QApplication::translate("GameSettingsWidget", "Depth:", nullptr));
        m_openingSuiteDepthSpin->setSuffix(QApplication::translate("GameSettingsWidget", " plies", nullptr));
        m_fenLabel->setText(QApplication::translate("GameSettingsWidget", "FEN string:", nullptr));
        m_openingBookGroup->setTitle(QApplication::translate("GameSettingsWidget", "Opening book", nullptr));
        m_polyglotFileLabel->setText(QApplication::translate("GameSettingsWidget", "Polyglot file:", nullptr));
        m_browsePolyglotFile->setText(QApplication::translate("GameSettingsWidget", "Browse...", nullptr));
        m_polyglotDepthLabel->setText(QApplication::translate("GameSettingsWidget", "Depth:", nullptr));
        m_polyglotDepthSpin->setSuffix(QApplication::translate("GameSettingsWidget", " full moves", nullptr));
        m_polyglotAccessMode->setText(QApplication::translate("GameSettingsWidget", "Access mode:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_ramAccessRadio->setToolTip(QApplication::translate("GameSettingsWidget", "The whole book is loaded in memory. This makes book access a bit faster but uses more memory.", nullptr));
#endif // QT_NO_TOOLTIP
        m_ramAccessRadio->setText(QApplication::translate("GameSettingsWidget", "Ram", nullptr));
#ifndef QT_NO_TOOLTIP
        m_diskAccessRadio->setToolTip(QApplication::translate("GameSettingsWidget", "The book is accessed directly from disk. This is a good choice for very large books.", nullptr));
#endif // QT_NO_TOOLTIP
        m_diskAccessRadio->setText(QApplication::translate("GameSettingsWidget", "Disk", nullptr));
        m_drawAdjudicationGroup->setTitle(QApplication::translate("GameSettingsWidget", "Draw adjudication", nullptr));
        m_drawMoveNumberLabel->setText(QApplication::translate("GameSettingsWidget", "Move number:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_drawMoveNumberSpin->setToolTip(QApplication::translate("GameSettingsWidget", "The game can be adjudicated as a draw after this many full moves have been played. A value of 0 disables draw adjudication.", nullptr));
#endif // QT_NO_TOOLTIP
        m_drawMoveNumberSpin->setSpecialValueText(QApplication::translate("GameSettingsWidget", "Off", nullptr));
        m_drawMoveCountLabel->setText(QApplication::translate("GameSettingsWidget", "Move count:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_drawMoveCountSpin->setToolTip(QApplication::translate("GameSettingsWidget", "The scores of both players need to be within the chosen threshold for this many consecutive moves. Captures and pawn moves will reset the counters.", nullptr));
#endif // QT_NO_TOOLTIP
        m_drawScoreLabel->setText(QApplication::translate("GameSettingsWidget", "Score:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_drawScoreSpin->setToolTip(QApplication::translate("GameSettingsWidget", "Both players' scores must be within this many centipawns from zero.", nullptr));
#endif // QT_NO_TOOLTIP
        m_drawScoreSpin->setSuffix(QApplication::translate("GameSettingsWidget", " cp", nullptr));
        m_resignAdjudicationGroup->setTitle(QApplication::translate("GameSettingsWidget", "Resign adjudication", nullptr));
        m_resignMoveCountLabel->setText(QApplication::translate("GameSettingsWidget", "Move count:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_resignMoveCountSpin->setToolTip(QApplication::translate("GameSettingsWidget", "Resign adjudication is used if an engine's score is below the threshold for at least this many consecutive moves.", nullptr));
#endif // QT_NO_TOOLTIP
        m_resignMoveCountSpin->setSpecialValueText(QApplication::translate("GameSettingsWidget", "Off", nullptr));
        m_resignScoreLabel->setText(QApplication::translate("GameSettingsWidget", "Score:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_resignScoreSpin->setToolTip(QApplication::translate("GameSettingsWidget", "The score must be at least this many centipawns below zero.", nullptr));
#endif // QT_NO_TOOLTIP
        m_resignScoreSpin->setSpecialValueText(QString());
        m_resignScoreSpin->setSuffix(QApplication::translate("GameSettingsWidget", " cp", nullptr));
#ifndef QT_NO_TOOLTIP
        m_resignNormalRadio->setToolTip(QApplication::translate("GameSettingsWidget", "Resignation is only based on losing side's scores.", nullptr));
#endif // QT_NO_TOOLTIP
        m_resignNormalRadio->setText(QApplication::translate("GameSettingsWidget", "Normal", nullptr));
#ifndef QT_NO_TOOLTIP
        m_resignTwoSidedRadio->setToolTip(QApplication::translate("GameSettingsWidget", "Both sides are needed to indicate decisive scores.", nullptr));
#endif // QT_NO_TOOLTIP
        m_resignTwoSidedRadio->setText(QApplication::translate("GameSettingsWidget", "Two-Sided", nullptr));
        m_gameLengthGroup->setTitle(QApplication::translate("GameSettingsWidget", "Game Length", nullptr));
        m_maxGameLengthLabel->setText(QApplication::translate("GameSettingsWidget", "Limit:", nullptr));
#ifndef QT_NO_TOOLTIP
        m_maxGameLengthSpin->setToolTip(QApplication::translate("GameSettingsWidget", "The game will be adjucated as drawn when move limit is reached", nullptr));
#endif // QT_NO_TOOLTIP
        m_maxGameLengthSpin->setSpecialValueText(QApplication::translate("GameSettingsWidget", "Off", nullptr));
        m_maxGameLengthSpin->setSuffix(QApplication::translate("GameSettingsWidget", " moves", nullptr));
        m_tbCheck->setText(QApplication::translate("GameSettingsWidget", "Tablebase adjudication", nullptr));
        m_ponderingCheck->setText(QApplication::translate("GameSettingsWidget", "Thinking on opponent's time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameSettingsWidget: public Ui_GameSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESETTINGSWIDGET_H
