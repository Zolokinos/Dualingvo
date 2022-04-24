#ifndef DUALINGVO__MENU_H__
#define DUALINGVO__MENU_H__

#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

class Menu : public QMainWindow {
 public:
  Menu();
  void SetUpInterface();
  void ConnectWidgets();
  QWidget* GetWidgetMainMenu();
  QWidget* GetWidgetSelect();

  signals:
  void ToChoiceTypeGame();
  void ToMainMenu();

 private:
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
};

#endif //DUALINGVO__MENU_H__
