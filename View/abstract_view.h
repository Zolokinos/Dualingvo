#ifndef DUALINGVO__ABSTRACT_VIEW_H_
#define DUALINGVO__ABSTRACT_VIEW_H_

#include <QMainWindow>

class AbstractView : public QMainWindow {
 public:
  virtual void SetUpInterface() = 0;
  virtual void ChangeDifficulty(int i) = 0;
};

#endif //DUALINGVO__ABSTRACT_VIEW_H_
