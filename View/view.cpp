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
  ConnectChildWidgets();
  ConnectActions();
  SetWindows();
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
  show();
}

void View::ChangeVoice() {
  if(sound_->text() == "Turned on") {
    sound_->setText("Turned off");
  } else {
    sound_->setText("Turned on");
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
    emit NewDifficulty(easy);
  });
  connect(difficulty_actions_[medium], &QAction::triggered, this, [&] {
    emit NewDifficulty(medium);
  });
  connect(difficulty_actions_[hard], &QAction::triggered, this, [&] {
    emit NewDifficulty(hard);
  });

  connect(sound_, &QAction::triggered, this, [&]{
    emit ChangeSound();
    ChangeVoice();
  });
}

void View::ConnectChildWidgets() {
  menu_->ConnectDependencies();
  gameplay_screen_->ConnectDependencies();
  ConnectDependencies();
}

void View::SetWindows() {
  stacked_widget_->addWidget(menu_->GetWidgetMainMenu());
  stacked_widget_->addWidget(menu_->GetWidgetSelect());
  stacked_widget_->addWidget(gameplay_screen_->GetWidgetTask());

  stacked_widget_->setCurrentIndex(main_menu);
  setCentralWidget(stacked_widget_);
}

void View::ConnectDependencies() {
  connect(menu_, &Menu::ToMainMenu, this, [&] {
    emit ToMainMenu();
  });

  connect(menu_, &Menu::ToChoiceTypeGame, this, [&] {
    emit ToChoiceTypeGame();
  });

  // connect(gameplay_screen_, &GameplayScreen::ToMainMenu, this, [&] {
  //   stacked_widget_->setCurrentIndex(main_menu);
  //   setCentralWidget(stacked_widget_);
  // });
}

QStackedWidget* View::GetStackedWidget() {
  return stacked_widget_;
}

// void Exit();
// void ModSelected(int mod);
// void BackToMenu();
// void Check();

void View::ToMainMenuF() {
  stacked_widget_->setCurrentIndex(main_menu);
  setCentralWidget(stacked_widget_);
}

void View::ToChoiceTypeGameF() {
  stacked_widget_->setCurrentIndex(main_menu);
  setCentralWidget(stacked_widget_);
}

