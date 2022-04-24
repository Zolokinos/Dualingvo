#include "menu.h"
Menu::Menu() :
    start_layout_(new QGridLayout()),
    choice_mode_layout_(new QGridLayout()),
    total_scores_(new QHBoxLayout()),
    widget_main_menu_(new QWidget(this)),
    widget_select_(new QWidget(this)),
    scores_(new QLabel("0", widget_main_menu_)),
    scores_name_(new QLabel("Scores: ", widget_main_menu_)),
    start_(new QPushButton("Start", widget_main_menu_)),
    exit_(new QPushButton("Exit", widget_main_menu_)),
    back_(new QPushButton("Back", widget_select_)) {
  modes_.push_back(new QPushButton("Pick-an-Option", widget_select_));
  modes_.push_back(new QPushButton("Input-answer", widget_select_));
  modes_.push_back(new QPushButton("Audio", widget_select_));
  modes_.push_back(new QPushButton("Mixed", widget_select_));
}

void Menu::SetUpInterface() {
  total_scores_->addWidget(scores_name_);
  total_scores_->addWidget(scores_);

  start_layout_->addLayout(total_scores_, 0, 2, Qt::AlignRight | Qt::AlignTop);
  start_layout_->addWidget(start_, 1, 1);
  start_layout_->addWidget(exit_, 2, 1);

  QSizePolicy expanding_policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  QSizePolicy fixed_policy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  start_->setSizePolicy(expanding_policy);
  exit_->setSizePolicy(expanding_policy);

  start_layout_->setColumnStretch(0, 1);
  start_layout_->setColumnStretch(1, 3);
  start_layout_->setColumnStretch(2, 1);

  start_layout_->setRowStretch(0, 2);
  start_layout_->setRowStretch(1, 1);
  start_layout_->setRowStretch(2, 1);
  start_layout_->setRowStretch(3, 2);

  widget_main_menu_->setLayout(start_layout_);

  choice_mode_layout_->addWidget(back_, 0, 0, Qt::AlignTop | Qt::AlignLeft);
  for (int i = 0; i < 4; ++i) {
    choice_mode_layout_->addWidget(modes_[i], 1 + i, 1);
  }

  back_->setSizePolicy(fixed_policy);
  for (int i = 0; i < 4; ++i) {
    modes_[i]->setSizePolicy(expanding_policy);
  }

  choice_mode_layout_->setColumnStretch(0, 1);
  choice_mode_layout_->setColumnStretch(1, 3);
  choice_mode_layout_->setColumnStretch(2, 1);

  choice_mode_layout_->setRowStretch(0, 1);
  choice_mode_layout_->setRowStretch(5, 1);
  for (int i = 0; i < 4; ++i) {
    choice_mode_layout_->setRowStretch(1 + i, 1);
  }

  widget_select_->setLayout(choice_mode_layout_);
}

void Menu::ConnectWidgets() {
  connect(start_, &QPushButton::clicked, widget_main_menu_, [&] {
    controller_->ToChoiceTypeGame();
  });

  connect(exit_, &QPushButton::clicked, widget_main_menu_, [&] {
    controller_->Exit();
  });

  connect(back_, &QPushButton::clicked, widget_select_, [&] {
    controller_->ToMainMenu();
  });

  for (int i = 0; i < 4; ++i) {
    connect(modes_[i], &QPushButton::clicked, widget_select_, [&]{
      controller_->ModSelected(i);
    });
  }
}

QWidget* Menu::GetWidgetMainMenu() {
  return widget_main_menu_;
}

QWidget* Menu::GetWidgetSelect() {
  return widget_select_;
}
