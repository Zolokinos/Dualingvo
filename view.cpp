//
// Created by admin on 22/04/22.
//
#include <QApplication>
#include <QScreen>
#include <iostream>

#include "view.h"

View::View() : QMainWindow(nullptr) {
  move(200, 100);
  resize(1500, 750);
  setMaximumSize(1500, 750);
  setMinimumSize(500, 250);
}
