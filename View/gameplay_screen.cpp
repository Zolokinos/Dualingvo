#include "gameplay_screen.h"
GameplayScreen::GameplayScreen(AbstractView* parent) :
    parent_(parent),
    widget_task_(new QWidget(this)),
    divide_progressbar_(new QVBoxLayout()),
    basic_layout_left_(new QVBoxLayout()),
    basic_layout_right_(new QVBoxLayout()),
    basic_link_layout_(new QHBoxLayout()),
    progress_bar_(new QProgressBar(widget_task_)),
    leave_(new QPushButton("Leave", widget_task_)),
    solve_(new QPushButton("Solve", widget_task_)),
    word_try_(new QLabel("Tries: ", widget_task_)),
    tries_(new QLabel("5", widget_task_)),
    try_layout_(new QHBoxLayout()),
    changeable_part_widget_(new QWidget(widget_task_)) {}

void GameplayScreen::SetController(Controller* controller) {
    controller_ = controller;
}

void GameplayScreen::SetUpInterface() {
  basic_layout_left_->addWidget(leave_, 1);
  basic_layout_left_->addStretch(16);

  try_layout_->addWidget(word_try_);
  try_layout_->addWidget(tries_);
  try_layout_->addStretch();

  basic_layout_right_->addStretch(12);
  basic_layout_right_->addLayout(try_layout_);
  basic_layout_right_->addWidget(solve_, 3);
  
  basic_link_layout_->addLayout(basic_layout_left_, 1);
  basic_link_layout_->addWidget(changeable_part_widget_, 7);
  basic_link_layout_->addLayout(basic_layout_right_, 2);
  
  divide_progressbar_->addWidget(progress_bar_);
  divide_progressbar_->addLayout(basic_link_layout_);

  QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  leave_->setSizePolicy(policy);
  solve_->setSizePolicy(policy);

  widget_task_->setLayout(divide_progressbar_);

  // ToTask();
}

void GameplayScreen::ToTask(int num) {
  parent_->setCentralWidget(widget_task_);
}

void GameplayScreen::ConnectWidgets() {
  connect(leave_, &QPushButton::clicked, widget_task_, [&] {
    controller_->BackToMenu();
  });

  connect(solve_, &QPushButton::clicked, widget_task_, [&] {
    controller_->Check();
  });
}
