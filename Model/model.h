#ifndef DUALINGVO__MODELS_H__
#define DUALINGVO__MODELS_H__

#include <QObject>

class Models : public QObject {
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
  Models() = default;

 private:
  int scores_num_{};
  bool is_music_on_{true};
  int current_difficulty_{easy};
  int current_mode_{};
};

#endif //DUALINGVO__MODELS_H__
