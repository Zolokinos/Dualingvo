#ifndef DUALINGVO__MENU_H__
#define DUALINGVO__MENU_H__

#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

#include "Controller/controller.h"
#include "abstract_view.h"

class Menu : public QMainWindow {
 public:
  explicit Menu(AbstractView* parent);
  void SetUpInterface();
  void ConnectWidgets();
  void ToChoiceTypeGame();
  void ToMainMenu();
  void SetController(Controller* controller);

 private:
  AbstractView* parent_;
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
  Controller* controller_{nullptr};
};

#endif //DUALINGVO__MENU_H__
