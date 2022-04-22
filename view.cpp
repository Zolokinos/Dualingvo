#include <QApplication>
#include <QScreen>

#include "view.h"

View::View() :
    QMainWindow(nullptr),
    start_layout_(new QGridLayout()),
    choice_mode_layout_(new QGridLayout()),
    total_scores_(new QHBoxLayout()),
    widget_main_menu_(new QWidget(this)),
    widget_select_(new QWidget(this)),
    scores_(new QLabel("0", widget_main_menu_)),
    scores_name_(new QLabel("Scores", widget_main_menu_)),
    start_(new QPushButton("Start", widget_main_menu_)),
    exit_(new QPushButton("Exit", widget_main_menu_)),
    back_(new QPushButton("Back", widget_select_)) {
  move(200, 100);
  resize(1500, 750);
  setMaximumSize(1500, 750);
  setMinimumSize(500, 250);

  modes_.push_back(new QPushButton("Pick-an-Option", widget_select_));
  modes_.push_back(new QPushButton("Input-answer", widget_select_));
  modes_.push_back(new QPushButton("Audio", widget_select_));
  modes_.push_back(new QPushButton("Mixed", widget_select_));

  CreateMenu();

  SetUpInterface();
}

void View::CreateMenu() {
  difficulty_ = menuBar()->addMenu("Difficulty: ");
  sound_ = menuBar()->addMenu("Turned on");

  QAction* easy = difficulty_->addAction("Easy");
  QAction* medium = difficulty_->addAction("Medium");
  QAction* hard = difficulty_->addAction("Hard");
}

void View::SetUpInterface() {
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
    choice_mode_layout_->addWidget(modes_[i], 2 + i, 1);
  }

  back_->setSizePolicy(fixed_policy);
  for (int i = 0; i < 4; ++i) {
    modes_[i]->setSizePolicy(expanding_policy);
  }

  choice_mode_layout_->setColumnStretch(0, 1);
  choice_mode_layout_->setColumnStretch(1, 3);
  choice_mode_layout_->setColumnStretch(2, 1);

  choice_mode_layout_->setRowStretch(0, 2);
  choice_mode_layout_->setRowStretch(1, 1);
  for (int i = 0; i < 4; ++i) {
    choice_mode_layout_->setColumnStretch(2 + i, 1);
  }

  widget_select_->setLayout(choice_mode_layout_);

  setCentralWidget(widget_main_menu_);
  ToChoiceTypeGame();
}

void View::ChangeVoice() {
  if(sound_->title() == "Turned on") {
    sound_->title() = "Turned off";
  } else {
    sound_->title() = "Turned on";
  }
}

void View::ChangeDifficulty() {
  /// todo
}

void View::ToChoiceTypeGame() {
  setCentralWidget(widget_select_);
}

void View::ToMainMenu() {

}
