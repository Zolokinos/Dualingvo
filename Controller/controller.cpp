#include <QMessageBox>
#include "controller.h"
Controller::Controller(AbstractView* view) : view_(view) {}

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
