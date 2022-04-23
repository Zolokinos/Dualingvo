#ifndef DUALINGVO__VIEW_H__
#define DUALINGVO__VIEW_H__

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>

#include "abstract_view.h"
#include "controller.h"
#include "model.h"

class View : public AbstractView {
  Q_OBJECT
 public:
  View();

  enum difficulty_statements {
    easy,
    medium,
    hard,
  };
 private:
  void CreateMenu() override;
  void SetUpInterface() override;
  void ChangeVoice();
  void ChangeDifficulty(int statement);
  void ToChoiceTypeGame();
  void ToMainMenu();
  void ConnectWidgets();

  void ConnectActions();
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
  QAction* sound_;
  std::vector<QPushButton*> modes_;
  QMenu* difficulty_;

  std::vector<QAction*> difficulty_actions_;
};

#endif // DUALINGVO__VIEW_H__
