#ifndef DUALINGVO__CONTROLLER_H__
#define DUALINGVO__CONTROLLER_H__

#include <QWidget>
#include "abstract_view.h"
#include "model.h"

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

  Controller(AbstractView* view);
  void ToChoiceTypeGame();
  void ChangeSound();
  void Exit();
  void ToMainMenu();
  void ChangeDifficulty(int difficulty);
  void ModSelected(int variant);

 private:
  AbstractView* view_;
};

#endif //DUALINGVO__CONTROLLER_H__
