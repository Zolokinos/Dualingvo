#ifndef DUALINGVO__CONTROLLER_H__
#define DUALINGVO__CONTROLLER_H__

#include <QWidget>
#include "View/view.h"
#include "Model/model.h"

class Controller {
 public:
  enum difficulty_statements {
    easy,
    medium,
    hard,
  };

  enum modes_variants {
    Pick_an_Option,
    Input_answer,
    Audio,
    Mixed,
  };

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

 private:
  View* view_;
  Models* models_;
};

#endif //DUALINGVO__CONTROLLER_H__
