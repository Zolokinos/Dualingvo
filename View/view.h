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
#include "Helpers/enums.h"
#include "menu.h"

class View : public QMainWindow {
  Q_OBJECT
 public:
  View();
  void CreateMenu();
  void SetUpInterface();
  void ConnectChildWidgets();
  void ConnectDependencies();
  void ConnectActions();
  void SetWindows();
  void ChangeVoice();
  QStackedWidget* GetStackedWidget();
  void ToMainMenuF();
  void ToChoiceTypeGameF();

  void ChangeDifficulty(int statement);

 signals:
  void ToMainMenu();
  void NewDifficulty(int diff);
  void ChangeSound();

  void ToChoiceTypeGame();
  void Exit();
  void ModSelected(int mod);
  void BackToMenu();
  void Check();

 public slots:

 private:
  Menu* menu_;
  GameplayScreen* gameplay_screen_;
  QAction* sound_{};
  QMenu* difficulty_{};
  std::vector<QAction*> difficulty_actions_;
  QStackedWidget* stacked_widget_;
};

#endif // DUALINGVO__VIEW_H__
