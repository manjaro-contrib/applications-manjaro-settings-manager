/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Roman Gilg <romangg@manjaro.org>
 *
 *  Manjaro Settings Manager is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Manjaro Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Manjaro Settings Manager.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class MsmMddPreviewWindow : public QWidget {
public:
  MsmMddPreviewWindow(QWidget *parent = nullptr) : QWidget(parent) {
    setWindowTitle("Data Preview");

    auto textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->append("Preview is being generated...");

    auto closeButton = new QPushButton("Close", this);
    connect(closeButton, &QPushButton::clicked, this, &QWidget::close);

    auto layout = new QVBoxLayout();
    layout->addWidget(textEdit);
    layout->addWidget(closeButton);
    setLayout(layout);

    this->textEdit = textEdit;
  }

  QTextEdit *textEdit;
};
