#ifndef DUALINGVO__CONTROLLER_H__
#define DUALINGVO__CONTROLLER_H__

#include <QWidget>
#include "Helpers/enums.h"
#include "View/view.h"
#include "Model/model.h"

class Controller : public QWidget {
 Q_OBJECT
 public:
  explicit Controller();

  void ToChoiceTypeGame();
  void ChangeSound();
  void Exit();
  void ToMainMenu();
  void BackToMenu();
  void Check();
  void ChangeDifficulty(int difficulty);
  void ModSelected(int variant);
  void SetMenuBarVisible(bool flag);

  void ConnectDependencies();

 private:
  QStackedWidget* stacked_widget_;
  View* view_;
  Models* models_;
};

#endif //DUALINGVO__CONTROLLER_H__
