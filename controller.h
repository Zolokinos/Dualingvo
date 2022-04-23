#ifndef DUALINGVO__CONTROLLER_H__
#define DUALINGVO__CONTROLLER_H__

#include <QWidget>

class Controller : public QWidget {
 public:
  Controller();
  void ToChoiceTypeGame();
  void ChangeSound();
  void Exit();
  void ToMainMenu();
  void ChangeDifficulty();
};

#endif //DUALINGVO__CONTROLLER_H__
