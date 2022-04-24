#ifndef DUALINGVO__CONTROLLER_H__
#define DUALINGVO__CONTROLLER_H__

#include <QWidget>
#include "View/abstract_view.h"
#include "Model/model.h"

class Controller : public QWidget {
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

  explicit Controller(AbstractView* view);
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
  AbstractView* view_;
};

#endif //DUALINGVO__CONTROLLER_H__
