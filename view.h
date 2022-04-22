#ifndef DUALINGVO__VIEW_H__
#define DUALINGVO__VIEW_H__

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>

#include "controller.h"
#include "model.h"

class View : public QMainWindow{
  Q_OBJECT
 public:
  View();

 private:
  void CreateMenu();
  void SetUpInterface();
  void ChangeVoice();
  void ChangeDifficulty();
  void ToChoiceTypeGame();
  void ToMainMenu();

  Controller* controller_;
  Models* models_;
  QGridLayout* start_layout_;
  QGridLayout* choice_mode_layout_;
  QHBoxLayout* total_scores_;
  QWidget* widget_main_menu_;
  QWidget* widget_select_;
  QLabel* scores_;
  QLabel* scores_name_;
  QPushButton* start_;
  QPushButton* exit_;
  QPushButton* back_;
  std::vector<QPushButton*> modes_;
  QMenu* sound_;
  QMenu* difficulty_;
};

#endif // DUALINGVO__VIEW_H__
