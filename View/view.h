#ifndef DUALINGVO__VIEW_H__
#define DUALINGVO__VIEW_H__

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QPushButton>
#include <QStackedWidget>

#include "gameplay_screen.h"
#include "menu.h"

class View : public QMainWindow {
  Q_OBJECT
 public:
  View();
  void CreateMenu();
  void SetUpInterface();
  void ConnectWidgets();
  void ConnectActions();
  void SetWindows();

  enum difficulty_statements {
    easy,
    medium,
    hard,
  };

  enum windows {
    main_menu,
    select_game,
    game,
  };

  signals:
  void ChangeVoice();
  void ChangeDifficulty(int statement);
  void ToChoiceTypeGame();
  void ToMainMenu();

 private:
  Menu* menu_;
  GameplayScreen* gameplay_screen_;
  QAction* sound_{};
  QMenu* difficulty_{};
  std::vector<QAction*> difficulty_actions_;
  QStackedWidget* stacked_widget_;
};

#endif // DUALINGVO__VIEW_H__
