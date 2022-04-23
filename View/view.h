#ifndef DUALINGVO__VIEW_H__
#define DUALINGVO__VIEW_H__

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QPushButton>

#include "abstract_view.h"
#include "gameplay_screen.h"
#include "Controller/controller.h"
#include "menu.h"
#include "Model/model.h"

class View : public AbstractView {
  Q_OBJECT
 public:
  View();
  void CreateMenu();
  void SetUpInterface() override;
  void ChangeVoice();
  void ChangeDifficulty(int statement);
  void ToChoiceTypeGame();
  void ToMainMenu();
  void ConnectWidgets();
  void ConnectActions();
  void ToTask(int num = 0);

  enum difficulty_statements {
    easy,
    medium,
    hard,
  };

 private:
  Menu* menu_;
  GameplayScreen* gameplay_screen_;
  Controller* controller_;
  Models* models_;
  QAction* sound_;
  QMenu* difficulty_;
  std::vector<QAction*> difficulty_actions_;
};

#endif // DUALINGVO__VIEW_H__
