#ifndef DUALINGVO_VIEW_GAMEPLAY_SCREEN_H__
#define DUALINGVO_VIEW_GAMEPLAY_SCREEN_H__

#include <QMainWindow>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>

class GameplayScreen : public QMainWindow {
 Q_OBJECT
 public:
  explicit GameplayScreen();
  void SetUpInterface();
  void ConnectDependencies();
  QWidget* GetWidgetTask();

  signals:
  void BackToMenu();
  void Check();

 private:

  QWidget* widget_task_;
  QVBoxLayout* divide_progressbar_;
  QVBoxLayout* basic_layout_left_;
  QVBoxLayout* basic_layout_right_;
  QHBoxLayout* basic_link_layout_;
  QProgressBar* progress_bar_;
  QPushButton* leave_;
  QPushButton* solve_;
  QLabel* word_try_;
  QLabel* tries_;
  QHBoxLayout* try_layout_;
  QWidget* changeable_part_widget_;
};

#endif //DUALINGVO_VIEW_GAMEPLAY_SCREEN_H__
