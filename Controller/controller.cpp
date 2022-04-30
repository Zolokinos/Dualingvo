#include <QMessageBox>
#include "controller.h"
Controller::Controller() :
  view_(new View()),
  models_(new Models()) {
  stacked_widget_ = view_->GetStackedWidget();
}

void Controller::ToChoiceTypeGame() {

}

void Controller::ChangeSound() {

}

void Controller::Exit() {
    auto answer = QMessageBox::question(view_, "Exit",
                                        "Are you sure you want to leave?");
  if (answer == QMessageBox::Yes)
    view_->close();
}

void Controller::ToMainMenu() {

}

void Controller::ChangeDifficulty(int difficulty) {
  view_->ChangeDifficulty(difficulty);
}

void Controller::ModSelected(int variant) {

}

void Controller::BackToMenu() {

}

void Controller::Check() {

}

void Controller::SetMenuBarVisible(bool flag) {

}

void Controller::ConnectDependencies() {
  connect(view_, &View::ToMainMenu, view_, &View::ToMainMenuF);
  connect(view_, &View::ChangeSound, this, [&]{

  });
  connect(view_, &View::NewDifficulty, this, &Controller::ChangeDifficulty);
  connect(view_, &View::ToChoiceTypeGame, view_, &View::ToChoiceTypeGameF);
}
