#include <QApplication>
#include <QScreen>
#include "view.h"

View::View() :
    menu_(new Menu(this)),
    gameplay_screen_(new GameplayScreen(this)),
    controller_(new Controller(this)) {
  move(200, 100);
  resize(1500, 750);
  setMaximumSize(1500, 750);
  setMinimumSize(500, 250);
  menu_->SetController(controller_);

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
    difficulty_->title() = "Difficulty: Easy";
  } else if (statement == medium) {
    difficulty_->title() = "Difficulty: Medium";
  } else {
    difficulty_->title() = "Difficulty: Hard";
  }
}

void View::ConnectActions() {
  for (int i = easy; i < 3; ++i) {
    connect(difficulty_actions_[i], &QAction::triggered, this, [&] {
      controller_->ChangeDifficulty(i);
    });}

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

void View::ToTask(int num) {
  gameplay_screen_->ToTask(num);
}

void View::SetMenuBarVisible(bool flag) {
  menuBar()->setVisible(flag);
}

