#include <QApplication>
#include <QScreen>
#include "view.h"

View::View() :
    menu_(new Menu()),
    gameplay_screen_(new GameplayScreen()),
    stacked_widget_(new QStackedWidget(this)) {
  move(200, 100);
  resize(1500, 750);
  setMaximumSize(1500, 750);
  setMinimumSize(500, 250);

  CreateMenu();
  SetUpInterface();
  ConnectWidgets();
  ConnectActions();

}

void View::CreateMenu() {
  difficulty_ = menuBar()->addMenu("Difficulty: Easy");
  sound_ = menuBar()->addAction("Turned on");

  difficulty_actions_.push_back(difficulty_->addAction("Easy"));
  difficulty_actions_.push_back(difficulty_->addAction("Medium"));
  difficulty_actions_.push_back(difficulty_->addAction("Hard"));
}

void View::SetUpInterface() {
  menu_->SetUpInterface();
  gameplay_screen_->SetUpInterface();
}

void View::ChangeVoice() {
  if(sound_->text() == "Turned on") {
    sound_->text() = "Turned off";
  } else {
    sound_->text() = "Turned on";
  }
}

void View::ChangeDifficulty(int statement) {
  if (statement == easy) {
    difficulty_->setTitle("Difficulty: Easy");
  } else if (statement == medium) {
    difficulty_->setTitle("Difficulty: Medium");
  } else {
    difficulty_->setTitle("Difficulty: Hard");
  }
}

void View::ConnectActions() {
  connect(difficulty_actions_[easy], &QAction::triggered, this, [&] {
    controller_->ChangeDifficulty(easy);
  });

  connect(difficulty_actions_[medium], &QAction::triggered, this, [&] {
    controller_->ChangeDifficulty(medium);
  });

  connect(difficulty_actions_[hard], &QAction::triggered, this, [&] {
    controller_->ChangeDifficulty(hard);
  });

  connect(sound_, &QAction::triggered, this, [&] {
    controller_->ChangeSound();
  });
}

void View::ConnectWidgets() {
  menu_->ConnectWidgets();
  gameplay_screen_->ConnectWidgets();
}

void View::ToChoiceTypeGame() {
  menu_->ToChoiceTypeGame();
}

void View::ToMainMenu() {
  menu_->ToMainMenu();
}

void View::SetWindows() {
  stacked_widget_->addWidget(menu_->GetWidgetMainMenu());
  stacked_widget_->addWidget(menu_->GetWidgetSelect());
  stacked_widget_->addWidget(gameplay_screen_->GetWidgetTask());
}

