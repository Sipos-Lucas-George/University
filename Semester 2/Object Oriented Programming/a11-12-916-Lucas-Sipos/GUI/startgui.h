#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class startGUI; }
QT_END_NAMESPACE

class startGUI : public QWidget {
Q_OBJECT

public:
    explicit startGUI(QWidget *parent = nullptr);

    ~startGUI() override;

    bool csvOrHtml() const;
private:
    bool csv;

    Ui::startGUI *ui;
    void connectSignals();
    void csvPushed();

    void htmlPushed();
};
